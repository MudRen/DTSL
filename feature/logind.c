// /adm/daemons/logind.c
//modified by yanyan 2001.1  for DtSl. 

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <login.h>
#include <mudlib.h>
//#include <net/client.h>

inherit F_DBASE;
#include <badid.h>

#define SCORE_D "/adm/daemons/scored.c"

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name =
({"һ����Ե","�����","��˫","����","����","Ц","����","�̹�","ҹè","��ҹè","��ҹè",
  "����","������","������","��Сƽ"});
string *banned_site = ({});

string *allowed_player=({});

private void encoding(object ob);
private void get_id(string arg, object ob);
private void get_name(string arg, object ob);
private void yes_no(string arg, object ob,object user);
private void choose_gift(string arg, object ob,object user);
private void confirm_id(string yn, object ob);
private void get_passwd(string pass, object ob);
private void confirm_relogin(string yn, object ob, object user);
private void new_password(string pass, object ob);
private void confirm_password(string pass, object ob);
private void get_email(string email, object ob);
private void get_gender(string gender, object ob, object user);
object make_body(object ob);
private void init_new_player(object link, object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string make_passwd();
string good_pass,pass1,pass2;
int howmany_user();
int howmany_visitor();
void set_visitor(string num);
void get_cloth(object user);
void tell_news(object user);
//void team_lose(object me);
void check_member(object me);
void do_clear_test(object ob,object user);


void create() 
{
	string file;
	
	seteuid(getuid());
	set("channel_id", "���߾���");
	
	//file=read_file("/log/testid");
	//allowed_player=explode(file,"\n");

}

void logon(object ob)
{
	object *usr;int i,login_cnt;
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	login_cnt = 0;
	while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
	if (login_cnt >4&&!wizardp(ob)) {
	   write("������������ͬһ����ַ��¼�����Ժ����ԡ�\n");
		destruct(ob);
		return;
	}
	write(CLR);
	cat(WELCOME);
	INFO_CMD->main();
	
	encoding(ob);
	return;
}
void encoding(object ob)
{
	int i, wiz_cnt, ppl_cnt, login_cnt,user_num,user_ip_cnt;
	object *usr;string ip;
	ip = query_ip_name(ob);
	if(BAN_D->is_banned(ip)){
	write("Ŀǰ��ĵ�ַ��"+MUD_NAME+"���ܻ�ӭ��\n");
	destruct(ob);
	return;}
	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	user_ip_cnt = 0;
	user_num=0; 
	
	user_num=howmany_user();
	if(user_num!=0)
	{ 
		write(HIW"����˫��Ŀǰ����"+NOR+MAG+chinese_number(user_num)+HIW"����ʽע����û���\n"NOR);
	}
	for(i=0; i<sizeof(usr); i++) 
	{
		if(!environment(usr[i])) login_cnt++;
		else if(wizardp(usr[i])&&!usr[i]->query("env/invisibility")) wiz_cnt++;
		else ppl_cnt++;
		if (query_ip_name(usr[i]) == query_ip_name(ob) && !usr[i]->query_temp("netdead")) user_ip_cnt++;
		
	}
	printf("\nĿǰ����"+HIY+" %d"+NOR+" λ��ʦ��"+HIG+"%d"+NOR+" λ�������������ϣ��Լ� %d "  + "λʹ���߳���������\n", wiz_cnt, ppl_cnt, login_cnt);
	printf("�����ڴ�"+HIC+"%s"+NOR+"���IP���߽��롣�Ѿ��� "+HIW+"%d"+NOR+"��ͬ��IP�������С�\n"NOR, query_ip_name(ob),--user_ip_cnt);
	      
	write("\n����Ӣ�����֣�");
	input_to((: get_id :), ob);
}

int howmany_user() 
{ 
	int i, ppl_cnt; 
	string *dir,*ppls; 
	seteuid(getuid());
	ppl_cnt = 0; 
	dir = get_dir(DATA_DIR + "login/"); 
	for(i=0; i<sizeof(dir); i++)
	{ 
		reset_eval_cost(); 
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/"); 
		ppl_cnt += sizeof(ppls); 
	}
	return ppl_cnt; 
//according to the purge.c 
} 

int howmany_visitor() 
{ 
	int num;
	string content,format; 
	content=read_file(COUNTER); 
	sscanf(content,"%s %d",format,num); 
	if(format!="VISITOR" && wizardp(this_player())) 
	write("��ʦ��ע�⣬�����ߵ���Ŀ�п��ܲ��ԣ�" + "��쿴logind.c�е�howmany_visitor������\n"); 
	//the data file is in 
	//"/data/bbs/VISITOR_NUM" 
	//if problem occur please check there 
	return num; 
} 

void set_visitor(string num) 
{ 
	rm(COUNTER); 
	//only this method can take effect 
	//or bug here 
	//why num can't be used derectly??? 
	if(to_int(num) > 0) 
	write_file(COUNTER,"VISITOR "+num); 
	return; 
} 

private void get_id(string arg, object ob)
{
        object ppl,*usr;
 int i,same_id;
	string ip = query_ip_number(ob);

	arg = lower_case(arg);
	if(!check_legal_id(arg)) 
	{
		write("����Ӣ�����֣�");
		input_to((:get_id:), ob);
		return;
	}
		

	
      usr = filter_array(children(LOGIN_OB), (: interactive :));
      i = sizeof(usr);
      same_id = 0;
      while (i--) 
      if(usr[i]!=ob&&usr[i]->query("id") ==arg) {same_id++;break;}
      if(same_id>0){
        write("��������ʹ��ͬһ��ID���뻻һ��ID��¼��\n");
        write("����Ӣ�����֣�");
        input_to((:get_id:), ob);
        return;
      }
#ifdef MAX_USERS
	if((string)SECURITY_D->get_status(arg) == "(player)" && sizeof(users()) >= MAX_USERS) 
	{
		ppl = find_body(arg);
		// Only allow reconnect an interactive player 
		// when MAX_USERS exceeded.
		if(!ppl || !interactive(ppl)) 
		{
		       write("�Բ���" + MUD_NAME  + "��ʹ�����Ѿ�̫���ˣ������������\n");
		       destruct(ob);
		       return;
		}
	}
#endif
	//if(wiz_level(arg) < wiz_lock_level&&member_array(arg,allowed_player)==-1)
	/*if(wiz_level(arg) < wiz_lock_level) 
	{
		write("�Բ���" + MUD_NAME + "Ŀǰ�����ڽ������˵ȼ� " + WIZ_LOCK_LEVEL + " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}
	*/
	if((string)ob->set("id", arg) != arg) 
	{
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
	if(arg=="guest") 
	{
		// If guest, let them create the character.
		write("�Բ���"+MUD_NAME+"������Guest��¼��\n");
		destruct(ob);
		return;
	}
	else if(file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0)
	{
		if(ob->restore()) 
		{
			write("���������룺");
			input_to((:get_passwd:),ob);
			return;
		}
		write("�������ﴢ�浲����һЩ���⣬�뷢E-mail֪ͨ������ʦ������\n");
		destruct(ob);
		return;
	}
	
	write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
	input_to((:confirm_id:), ob);
	return;
}

private void get_passwd(string pass, object ob)
{
	string my_pass;
	object user;
	my_pass = ob->query("password");
	pass1=crypt(pass,my_pass);
	if(pass1 != my_pass) 
	{
		write("�������\n");
		destruct(ob);
		return;
	}
	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) 
	{
		if(user->query_temp("netdead")) 
		{
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to((:confirm_relogin:), ob, user);
		return;
	}
	if(objectp(user = make_body(ob))) 
	{
		if(user->restore()) 
		{
		/*	log_file("USAGE", sprintf("%s(%s) loggined from %s on %s\n",
				user->query("name"),
				user->query("id"),
				query_ip_name(ob), ctime(time())));*/
			/*�˴�Ϊ����Ƿ�Ϊ���� ID*/
			/*if(!user->query("pass_test")&&
			(string)SECURITY_D->get_status(ob->query("id")) == "(player)"){
			   do_clear_test(ob,user);
			   return;
			}
			*/
			enter_world(ob, user,2);
			return;
		} else {
			destruct(user);
		}
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if(yn == "") 
	{
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}       

	if(yn[0] != 'y' && yn[0] != 'Y') 
	{
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
				+ " )����ȡ���������Ƶ����\n");
		//log_file("USAGE", sprintf("%s(%s) replaced by %s on %s\n", 
		//	user->query("name"),user->query("id"),
		//	query_ip_name(ob), ctime(time())));
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if(old_link) 
	{
		exec(old_link, user);
		destruct(old_link);
	}
	reconnect(ob, user);
}

private void confirm_id(string yn, object ob )
{
	if(yn == "") 
	{
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}       
	if(yn[0] != 'y' && yn[0] != 'Y') 
	{
		write("�ðɣ�������������������Ӣ�����֣�");
		input_to((:get_id:), ob);
		return;
	}
	write( @TEXT


�������Լ����������������ҪȡһЩ���Ż�����������������ŵ�
���֡�������ֽ������������������󽫲����ٸ��ģ���������ء�
(��������֮�⣬�� mud ������ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)
		  ^^^^^^^^^^
TEXT
   );
	write("�����������֣�");
	input_to((:get_name:), ob);
}

private void get_name(string arg, object ob)

{
	if( !check_legal_name(arg))
	{
		write("�����������֣�");
		input_to((:get_name:), ob);
		return;
	}
	//printf("%O\n", ob);
	ob->set("name", arg);
	write(MUD_NAME+"֧�ֵ����볤��Ϊ"+HIG+"�嵽��"+NOR+"����Ԫ\n"+
				"���趨�������룺");
	input_to((:new_password:),ob);
}

private void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 )
	{
		write(MUD_NAME+"֧�ֵ����볤��Ϊ"+HIG+"�嵽��"+NOR+"����Ԫ���������������룺");
		input_to((:new_password:),ob);
		return;
	}
	if( strlen(pass)>8 )
	{
		write(MUD_NAME+"֧�ֵ����볤��Ϊ"+HIG+"�嵽��"+NOR+"����Ԫ���������������룺");
		input_to((:new_password:),ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ���");
	input_to((:confirm_password:),ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺");
		input_to((:new_password:),ob);
		return;
	}
	write("���ĵ����ʼ���ַ��");
	input_to((:get_email:),  ob);
}

private void get_email(string email, object ob)
{
	object user;
	ob->set("email", email);
	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob))) return;
	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to((:get_gender:), ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	if( gender=="" )
	{
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to((:get_gender:), ob, user);
		return;
	}
	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else
	{
		write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
		input_to((:get_gender:), ob, user);
		return;
	}
	//log_file( "USAGE", sprintf("%s was created from %s (%s)\n",user->query("id"),query_ip_name(ob), ctime(time()) ) );
	init_new_player(ob,user);
	return;
}

object make_body(object ob)
{
	string err;
	object user;
	user = new(ob->query("body"));
	if(!user) 
	{
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err + "\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object link, object user)
{
	
	
	printf(HIY"\n����������Ҫ�����ԣ�����֮�ͱ�����ڰ�ʮ�㣬ÿһ�������ʮ�㣬���ܴ�����ʮ�㡣\n"NOR);
	printf(HIC"\n���磺20 20 20 20\n"NOR);
	printf(HIG"\n����  ����  ����  ������\n"NOR);
	input_to((:choose_gift:), link, user);
	return;
}

private void choose_gift(string arg, object link,object user)
{
	int str,intl,con,dex;
	
	if(sscanf(arg,"%d %d %d %d",str,intl,con,dex)!=4){
	  printf(HIY"\n����������Ҫ�����ԣ�����֮�ͱ�����ڰ�ʮ�㣬ÿһ�������ʮ�㣬���ܴ�����ʮ�㣺\n"NOR);  			
	  input_to((:choose_gift:), link, user);
	  return;
	}
	if(str+intl+con+dex!=80){
	  printf(HIY"\n����������Ҫ�����ԣ�����֮�ͱ�����ڰ�ʮ�㣬ÿһ�������ʮ�㣬���ܴ�����ʮ�㣺\n"NOR);  			
	  input_to((:choose_gift:), link, user);
	  return;  
	
	}
	if(str<10||intl<10||con<10||dex<10){
		printf(HIY"\n����������Ҫ�����ԣ�����֮�ͱ�����ڰ�ʮ�㣬ÿһ�������ʮ�㣬���ܴ�����ʮ�㣺\n"NOR);  			
	  input_to((:choose_gift:), link, user);
	  return;	
		
	}	
	if(str>30||intl>30||con>30||dex>30){
		printf(HIY"\n����������Ҫ�����ԣ�����֮�ͱ�����ڰ�ʮ�㣬ÿһ�������ʮ�㣬���ܴ�����ʮ�㣺\n"NOR);  			
	  input_to((:choose_gift:), link, user);
	  return;	
		
	}
	user->set("str",str);
	user->set("int",intl);
	user->set("con",con);
	user->set("dex",dex);	
	
	printf("\n��ȷ����(Yes/No)\n");
	input_to((:yes_no:), link, user);
	return;
}
private void yes_no(string arg, object ob,object user)
{
	int food,water;
	
	if(arg=="Yes"||arg=="yes"||arg=="Y"||arg=="y")
	  printf("\n����ѡ����ϣ�\n");
	else
	if(arg=="No"||arg=="no"||arg=="N"||arg=="n"){
	  printf("\n�ðɣ�������ѡ��\n");
	  input_to((:choose_gift:), ob, user);
	  return;
	}
	else{
	  printf("\n��ȷ����(Yes/No)\n");
	  input_to((:yes_no:), ob, user);
	  return;
	}
		
	user->set("birthday", time());
	user->set("potential",100);
	user->set("max_pot",100);
	 food=user->max_food_capacity();
	water=user->max_water_capacity();
	user->set("food", 1000);
	user->set("water", 1000);
	user->set("channels", ({ "chat", "rumor", "dt","party","banghui","sale"}) );
	user->set("deposit",10);
	user->set("title","��ͨ����");	
  cat("/adm/etc/new_player");
  user->set("startroom","/d/newbie/door");
  enter_world(ob, user,2);
	return;
}


varargs void enter_world(object ob, object user, int silent)
{
	string startroom;
	
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->enable_player();
	if(base_name(user)!=USER_OB && getuid(ob)!=ROOT_UID) return;
	exec(user, ob);
	write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
	user->setup();
	user->save();
	ob->save();
	if (wizhood(user) == "(player)") get_cloth(user);

		cat(MOTD);
		tell_news(user);
		//check_member(user);
		write( HIY "�ϴ����ߵ�ַ: " + ob->query("last_from") +" ( " +
		ctime( ob->query("last_on")) + " )\n" NOR );
		
        	if(user->is_ghost())
			startroom = DEATH_ROOM;
		else if(!stringp(startroom = user->query("startroom")))
			startroom = START_ROOM;
		
		UPDATE_D->check_user(user);

		if(!catch(load_object(startroom)))
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(environment(user), user->query("name") + "���߽���������硣\n", ({user}));
	
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s(%s)��%s���߽��롣", user->name(),
			user->query("id"), query_ip_name(user)));
			
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);
	user->reconnect();
	if(!silent) 
	{
		tell_room(environment(user), user->query("name") 
			+ "�������߻ص�������硣\n", ({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s��%s�������߽��롣", 
			user->query("name"), query_ip_name(user)));
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if((strlen(id) < 3) || (strlen(id) > 8)) 
	{
		write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if(id[i]<'a' || id[i]>'z') 
		{
			write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}
	if(member_array(id,badid)!=-1){
	write("�Բ����벻Ҫʹ������Ӣ�����֡�\n");
        return 0;}
	return 1;
}

int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if((strlen(name) < 4) || (strlen(name) > 10)) 
	{
		write("�Բ�������������ֱ����� 2 �� 5 �������֡�\n");
		return 0;
	}
	while(i--) 
	{
		if(name[i] <= ' ') 
		{
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if(i%2 == 0 && !is_chinese(name[i..<0])) 
		{
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	if(member_array(name, banned_name)!=-1) 
	{
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if(objectp(ob = find_player(name)))
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if(userp(body[i])
		&& getuid(body[i]) == name ) return body[i];

	return 0;

}

int set_wizlock(int level)
{
	if(wiz_level(this_player(1)) <= level)
		return 0;
	if(geteuid(previous_object()) != ROOT_UID)
		return 0;
	wiz_lock_level = level;
	return 1;
}

void get_cloth(object user)
{
	object cloth,shoe;

	if (user->query("class")=="bonze")
	{
		if (user->query("gender")=="Ů��"){
			cloth = new("/obj/cloth/ni-cloth.c");
			shoe = new("/obj/cloth/ni-xie.c");
		}else{
			cloth = new("/obj/cloth/seng-cloth.c");
			shoe = new("/obj/cloth/seng-xie.c");
		}
	}else{
		if (user->query("class")=="taoist"){
			if ( user->query("gender")=="Ů��"){
				cloth = new("/obj/cloth/daogu-cloth.c");
				shoe = new("/obj/cloth/dao-xie.c");
			}else{
				cloth = new("/obj/cloth/dao-cloth.c");
				shoe = new("/obj/cloth/dao-xie.c");
			}
		}else{
			if (user->query("family")){
				if ( user->query("gender")=="Ů��"){
					cloth = new("/obj/cloth/woman"+user->query("class"));
					shoe = new("/obj/cloth/female-shoe.c");
				}else{
					cloth = new("/obj/cloth/man"+user->query("class"));
					shoe = new("/obj/cloth/male-shoe.c");
				}
			}else{
				if ( user->query("gender")=="Ů��"){
					shoe = new("/obj/cloth/female-shoe.c");
					switch (random(8)){
		case 1: cloth = new("/obj/cloth/female1-cloth.c");break;
		case 2: cloth = new("/obj/cloth/female2-cloth.c");break;
		case 3: cloth = new("/obj/cloth/female3-cloth.c");break;
		case 4: cloth = new("/obj/cloth/female4-cloth.c");break;
		case 5: cloth = new("/obj/cloth/female5-cloth.c");break;
		case 6: cloth = new("/obj/cloth/female6-cloth.c");break;
		case 7: cloth = new("/obj/cloth/female7-cloth.c");break;
		default: cloth = new("/obj/cloth/female8-cloth.c");
					}
				}else{
					shoe = new("/obj/cloth/male-shoe.c");
					switch (random(8)){
		case 1: cloth = new("/obj/cloth/male1-cloth.c");break;
		case 2: cloth = new("/obj/cloth/male2-cloth.c");break;
		case 3: cloth = new("/obj/cloth/male3-cloth.c");break;
		case 4: cloth = new("/obj/cloth/male4-cloth.c");break;
		case 5: cloth = new("/obj/cloth/male5-cloth.c");break;
		case 6: cloth = new("/obj/cloth/male6-cloth.c");break;
		case 7: cloth = new("/obj/cloth/male7-cloth.c");break;
		default: cloth = new("/obj/cloth/male8-cloth.c");
					}
				}
			}
		}
	}
	shoe->move(user);
	if(shoe->wear());
	if(objectp(cloth)){
	cloth->move(user);
	if(cloth->wear());}
}

void tell_news(object user)
{
	
	mapping *notes;object board;
        int i, unread, last_read_time;
	board=load_object("/obj/board/news_b");
			if(!board) 
			 tell_object(user,"����ϵͳ�������뱨����ʦ��\n");
	else{
         notes=board->query("notes");
         if( !pointerp(notes) || !sizeof(notes) )
         {tell_object(user," [ û���κ����� ]\n");
          }
         else {         
         last_read_time = (int)user->query("board_last_read/" + (string)board->query("board_id"));
         for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
         if( notes[i]["time"] <= last_read_time ) break;
         if( unread )
        {tell_object(user,sprintf(BLINK+HIY"����%d������û���Ķ�,����news�Ķ���\n"NOR,unread));
			}
        else tell_object(user,"Ŀǰû��ʲô���š�\n");
            }
        }
}
/*
void team_lose(object me)
{
   object sboard;int i;
   sboard=load_object(BOARD_PATH+me->query("shili/name"));
   if(!sboard) return;
   i=sboard->query("deadtimes");
   if(me->query("shili/deadtimes")==i) return;
   while(me->query("shili/deadtimes")<i)
   { 
     me->add("combat_exp",-me->query("combat_exp")/500);
     if(me->query("combat_exp")<0)
     me->set("combat_exp",0);
     //me->skill_death_penalty();
     me->add("shili/deadtimes",1);
   }
   tell_object(me,HIR"�������������˱�pk����ĸ�����ֵ�������ˣ�\n"NOR);
  return;
}
*/
void check_member(object me)
{
  object sboard;int i;
  mapping *mem;
  sboard=load_object(BOARD_PATH+me->query("shili/name"));
  if(!sboard) return;       
  mem=sboard->query("notes");  
  for(i=0;i<sizeof(mem);i++){
   reset_eval_cost(); 
   if(me->query("id")==mem[i]["id"]) break;}
   if(i==sizeof(mem))
    { me->delete("shili");
      tell_object(me,HIW"����ĳ��ԭ���㱻�ϳ���ᣬ���Ұ���ѯ�ʣ�\n"NOR);
      return;
    }
    return;
}


void set_email(object ob,string email)
{
   ob->set("email",email);
   ob->save();
   return;
}

string *get_allowed_player()
{
   return allowed_player;
   
}

void do_clear_test(object ob,object user)
{
   string id;
   
   write(HIY"\n����˺����ڲ����˺ţ����ڽ�ɾ�����˺š�\n"+
                       "������ʹ�ô��˺�ע���¼��Ȼ��ʹ�� help jiangli ���鿴��λ�ò��Խ�����\n"NOR);
   id=user->query("id");
   
   rm(DATA_DIR + "login/" + id[0..0] + "/" + id+".o" );
   rm(DATA_DIR + "user/" + id[0..0] + "/" + id+".o" );
   
   SCORE_D->givereward(this_object(),id,1);
   CHANNEL_D->do_channel(this_object(),"sys","����id "+id+"��¼���Ѿ���������ȴ�����ע�ᡣ\n");
   
   destruct(user);
   destruct(ob);
   
   return;
   
}