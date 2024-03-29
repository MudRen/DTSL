// LPMud Smtp Client v0.1a0 [for CCTX II by CuteRabbit Studio]
// add establish new passwd for user by lanxin@jianghu 1999-6-3
// add identify command by gmm@jianghu 1999-8-21

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit NPC;

nosave int my_socket,socket1,socket2;
nosave object me;
nosave int status=0;
nosave string smtp_ip="202.99.170.15 25";
nosave string smtp_domain="netgod.net.cn";
nosave string sender="jianghu";
nosave string rcpt,msg;
nosave string ID;
int write_message(string);
void tell_me(string arg)
{
        write(arg);
}

void chat(string arg)
{
    write(arg);
}

void create()
{
          set_name("小圆圆", ({ "yuan yuan","yuan" }) );
      set("long", "一个美丽可爱的女孩，专门在这里指引新玩家登记。\n");
          set("title",WHT"登记服务员"NOR);
          set("gender", "女性");
      set("age", 18);
      set("str", 100);
      set("int", 100);
      set("cor", 100);
      set("per",30);
      set("combat_exp",90000000);
      setup();
}

int accept_fight(object me)
{
    command("xixi " + this_player()->query("id"));
    command("say 不要着急啊，在您登记之后就可以在游戏里痛快地厮杀一场了。");
    return 0;
}

void init()
{
        object ob;

        if( interactive(ob = this_player()))
        {
//                add_action("close_socket","close");
//                add_action("write_message","/");
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
    if (!arg) return notify_fail(CYN"小圆圆说道：你得给我你的鉴定密码啊？\n"NOR);
    password = me->query("nwpassword");
    //password = crypt(arg,tempword);
    if (arg != password) return notify_fail(CYN"小圆圆摇摇头说道：这个不是你正确的鉴定密码，请重新鉴定或者登记吧！\n"NOR);
    else
    {
        me->set("registered",1);
        me->save();
        message_vision("$N对$n说道：辛苦您了，您现在可以到江湖的世界里面去了，祝您玩的愉快！",yuan,me);
        return 1;
    }
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )        socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
                        tell_me("邮件发送中,请不要离开........\n");
                        set("connected",1);
        }
        else
                        tell_me("Can't connect to " + arg + "\n");
        return 1;
}

int close_socket()
{
        if( query("connected") )  {
                        if( socket_close(my_socket) ) {
                               // tell_me("Closed telnet socket.\n");
                                delete("connected");
                        }
                        else
                                tell_me("Close telnet socket fail.\n");
                }
        else
                tell_me("Not connected.\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
       object ob;


    //tell_me( BOLD + "→" + NOR + message );
    switch(status)
    {
        case 0:
            if(sscanf(message,"220%*s"))
            {
                status++;
                write_message("HELO " +smtp_domain );
                //chat("发出HELO命令");
                return;
            }
            break;
        case 1:
            if(sscanf(message,"250%*s"))
            {
                status++;
                write_message("MAIL FROM:<mudadm@netease.com>");
                //chat("发出MAIL FROM命令");
                return ;
            }
            break;
        case 2:
            if(rcpt&&sscanf(message,"250%*s"))
            {
                status++;
                write_message("RCPT TO:<"+rcpt+">");
                //chat("发出RCPT TO命令");
                return ;
            }
            break;
        case 3:
            if(sscanf(message,"250%*s"))
            {
                status++;
                write_message("DATA");
                //chat("发送DATA命令");
                return;
            }
            break;
        case 4:
            if(sscanf(message,"354%*s"))
            {
                status++;
                if(sscanf(msg,"%*s\r\n.\r\n%*s"))
                    chat("包含非法数据，可能会无法发送。\n");
                //log_file("sendmail","\n试图发送数据:\n"+msg);
                //玩家的MailList
                log_file("sendmail",ID+","+rcpt+"\n");
                write_message(msg+"\n.\n");
                //chat("发送数据");
                return;
            }
            break;
        case 5:
            if(sscanf(message,"451%*s"))
                chat("Smtp Server接收数据出错！请另选服务器。\n");
            else
                chat("\n感谢您支持我们的工作，您的注册专递已经成功的发出了。\n"+
                    "请您过几分钟后再打开你的信箱查收。\n\n\t\t\t江湖网络游戏巫师组\n");
            break;
    }

    if(status!=5||!sscanf(message,"250%*s"))
        chat("发送出错");
    status=0;
    write_message("QUIT");
    //chat("恢复断线状态");
    close_socket();
    //由于tcpip连接不能重复,所以只好想一个笨方法reload Npc. shy xixi!!
    reload_object(this_object());

    return ;
}

void write_callback(int fd)
{
        int res;
        if(query("connect"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
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
    if( !dest||!sscanf(dest,"%*s@%*s.%*s") )
        return notify_fail("电子邮件地址错误。\n");
    rcpt=dest;
    status=0;
    if(!my_socket&&do_telnet(smtp_ip)==0)
        return notify_fail("无法连接邮件服务器。\n");


    //六重循环随机产生密码
    newpass = "";
       for(int i=0; i<6; i++) {
          j = random(sizeof(DP));
        newpass += DP[j..j];
     }
    PW = crypt(newpass,0);
    //设置用户注册属性
     me->set("startroom","/d/wiz/hotel");
     if( me != this_player(1) ) return 0;
         ID=me->query("id");
        ob = me->query_temp("link_ob");

         seteuid(ROOT_UID);
         ob->set("nwpassword", newpass);
         ob->set("email",dest);
         ob->save();

    //发出注册信件
    msg="\n亲爱的"+me->query("name")+"你好！欢迎光临江湖网络游戏！\n\n\n"+
        "    你已经成功地在本游戏注册，谢谢您提供真实的E-mail地址。\n"+
        "请使用下面提供的密码登录完成注册:\n\n"+
        "您的注册ID是："+
        me->query("id")+"\n"
        "你的鉴定密码是："+
          newpass+"\n\n"
        "    江湖网络游戏的Web站点是 http://jianghu.163.net 您在那\n"+
        "里可以得到更好的支持!江湖网络游戏正在诚聘巫师如果您有兴趣\n"+
        "请把您的个人简历E-mail到以下地址:\n\n"+
        "\tmudadm@21cn.com 或 hunter_liu@263.net\n\n"+
        "      祝您玩的愉快!\n\n"+
        "                             江湖巫师组\n\n\n"+
        "\t         "+CHINESE_D->chinese_newdate( time(), 1 );
    msg="TO:"+dest+"\n"+
        "SUBJECT:"+"江湖网络游戏注册专递！\n"+
        "FROM:"+"lanxin"+"@"+INTERMUD_MUD_NAME+"\n"+
        "MIME-Version:1.0\n"+
        "DATE:"+time()+"\n"+
        "X-MAILER:JiangHu Mud Lpc Smtp client v0.9\n"+"\n"+
        msg;

    return 1;
}
