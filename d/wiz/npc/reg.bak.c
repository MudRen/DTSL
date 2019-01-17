// LPMud Smtp Client v0.1a0 [for CCTX II by CuteRabbit Studio]
// Add establish new passwd for user by lanxin@jianghu 1999-6-3
// Last modified by Gmm@Jianghu 1999-8-20

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit NPC;
static int my_socket,socket1,socket2;
static object me;
static int status=0;
static string smtp_ip="202.99.170.3 25";
static string smtp_domain="public.qhptt.he.cn";
static string sender="jianghu";
static string rcpt,msg;
static string ID;
int write_message(string);

void tell_me(string arg)
{
        tell_object(this_object(),arg);
}

void chat(string arg)
{
	tell_me(arg);
	return;
}

void create()
{
	set_name("СԲԲ", ({ "yuan yuan","yuan" }));
	set("long","һ�������ɰ���Ů����ר��������ָ������ҵǼǡ�\n");
	set("title",WHT"���ÿɰ���"NOR);
	set("gender", "Ů��");
	set("age", 18);
	set("str", 100);
	set("int", 100);
	set("cor", 100);
	set("per", 30);
	set("attitude", "peaceful");
	set("combat_exp",9000);
	setup();
}

int accept_fight(object me)
{
	command("xixi " + this_player()->query("id"));
	command("say ��Ҫ�ż����������Ǽ�֮��Ϳ�������Ϸ��ʹ�����ɱһ���ˡ�");
	return 0;
}

void init()
{       
        object ob;
        if( interactive(ob = this_player()))
        {
                add_action("close_socket","close");
                add_action("write_message","/");
                add_action("do_register","register");
                add_action("do_identify","identify");
                me = ob;
        }
}

int do_identify(string arg)
{
	object me,yuan;
	string password,tempword;
	me = this_player();
	yuan = this_object();
	if (!arg) return notify_fail(CYN"СԲԲ˵������ø�����ļ������밡��\n"NOR);
	tempword = me->query("nwpassword");
	password = crypt(arg,tempword);
	if (password != tempword) return notify_fail(CYN"СԲԲҡҡͷ˵���������������ȷ�ļ������룬�����¼������ߵǼǰɣ�\n"NOR);
	else
	{
		me->set("registered",1);
		me->save();
		message_vision("$N��$n˵�����������ˣ������ڿ��Ե���������������ȥ�ˣ�ף�������죡",yuan,me);
		return 1;
	}
}

int do_telnet(string arg)
{
        int err;
        if (query("connected")) socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 )
        {
                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS )
        {
		tell_me(CYN+"СԲԲ˵���������ڸ������������룬����ǧ��Ҫ�����߶������֮���һ��������\n"+NOR);
		set("connected",1);
        }
        else tell_me("Can't connect to " + arg + "\n");
        return 1;
}

int close_socket()
{
        if(query("connected"))
        {
		if( socket_close(my_socket))
		{
			// tell_me("Closed telnet socket.\n");
			delete("connected");
		}
		else tell_me("Close telnet socket fail.\n");
	}
        else tell_me("Not connected.\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
	object ob;
	//tell_me( BOLD + "��" + NOR + message );
	switch(status)
	{
		case 0:
    		if(sscanf(message,"220%*s"))
    		{
    			status++;
    			write_message("HELO " +smtp_domain );
    			//chat("����HELO����");
    			return;
    		}
    		break;
	  	case 1:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("MAIL FROM:<mudadm@netease.com>");
    			//chat("����MAIL FROM����");
    			return ;
    		}
			break;
	    	case 2:
    		if(rcpt&&sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("RCPT TO:<"+rcpt+">");
    			//chat("����RCPT TO����");
    			return ;
    		}
    		break;
    		case 3:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("DATA");
    			//chat("����DATA����");
    			return;
    		}
    		break;
    		case 4:
    		if(sscanf(message,"354%*s"))
    		{
    			status++;
    			if(sscanf(msg,"%*s\r\n.\r\n%*s")) chat("�����Ƿ����ݣ����ܻ��޷����͡�\n");
    			//log_file("sendmail","\n��ͼ��������:\n"+msg);
    			//��ҵ�MailList 
    			log_file("sendmail",ID + "�������ַΪ" + rcpt + "\n");
    			write_message(msg+"\n.\n");
    			//chat("��������");
    			return;
    		}
    		break;
	    	case 5:
    		if(sscanf(message,"451%*s")) chat("Smtp Server�������ݳ�������ѡ��������\n");
    		else chat(CYN+"СԲԲ˵�������Ѿ����������뷢�����������ˣ������Ժ���գ��ǵ������������������\n"+NOR);
    		break;    			
	}
	if(status!=5||!sscanf(message,"250%*s")) chat("���ͳ���");
	status=0;
	write_message("QUIT");
	//chat("�ָ�����״̬");
	close_socket();
	reload_object(this_object()); //����tcpip���Ӳ����ظ�,����ֻ����һ��������Reload Npc. shy xixi!!
	return ;        			
}

void write_callback(int fd)
{
        int res;
        if(query("connect")) return;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK)
        {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        socket_write(my_socket,arg+"\n");
        return 1;
}

string make_password(string arg,string id)
{
	return id;
}

int do_register(string dest,object ob)
{
	object me;
	string DP = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST";
	string newpass,PW;
	int j;
	me=this_player(1);
	if( !dest || !sscanf(dest,"%*s@%*s.%*s")) return notify_fail("�����ʼ���ַ����\n");
	rcpt = dest;
	status = 0;
	if( !my_socket && do_telnet(smtp_ip)==0) return notify_fail("�޷������ʼ���������\n");
	//����ѭ�������������
	newpass = "";
	for(int i=0; i<6; i++)
	{
  		j = random(sizeof(DP));
		newpass += DP[j..j];
	}
 	PW = crypt(newpass,0);
	//�����û�ע������
	me->set("startroom","/d/longyan/hotel");
	if( me != this_player(1) ) return 0;
	ID = me->query("id");
        ob = me->query_temp("link_ob");
        seteuid(ROOT_UID);
        !ob->set("nwpassword", PW); 
	ob->set("email",dest);
	ob->save();
	//����ע���ż�
	msg="\n�װ���"+me->query("name")+"��ã���ӭ�����ٽ���������Ϸ��\n\n\n"+
		"    ���Ѿ��ɹ����ڱ���Ϸע�ᣬлл���ṩ��ʵ��E-mail��ַ��\n"+
		"��ʹ�������ṩ�ļ������뵽��Ϸ��СԲԲ������м�����\n\n"+
		"����ע��ID�ǣ�"+ me->query("id") +"\n"
		"��ļ��������ǣ�"+ newpass + "\n\n"
		"    �ڼ�����ɺ����Ϳ��Զ���������������ˣ��������\n"+
		"�����⣬��Email������ʦ��\n"+
		"    ����������Ϸ��Webվ���� http://jianghu.163.net ������\n"+
		"����Եõ����õ�֧�֣���������κμ��������⣬����ѯ����Ϸ\n"+
		"��ʦ���������һ��LPC������־Ը���뽭����ʦ�飬��E-mail��\n\n"+
		"\t mudadm@21cn.com (����) �� hunter_liu@263.net (������)\n\n"+
		"      ף�������죡\n\n"+
		"                             ������ʦ��\n\n\n"+
		"\t         "+CHINESE_D->chinese_newdate( time(), 1 );
	msg="TO:"+dest+"\n"+
		"SUBJECT:"+"����������Ϸע��ר�ݣ�\n"+
		"FROM:"+"lanxin"+"@"+INTERMUD_MUD_NAME+"\n"+
		"MIME-Version:1.0\n"+
		"DATE:"+time()+"\n"+
		"X-MAILER:JiangHu Mud Lpc Smtp Client v1.0\n"+"\n"+
		msg;
	return 1;
}
