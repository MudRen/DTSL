//marryd.c for dt.
//written by yanyan.

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
#include <badid.h>

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
   "�����", "����", "����", "������", "�����","������","��Сƽ","һ����Ե",
});



object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
private void yes_no(string arg, object me,object user,object ob);
private void choose_gift(string arg, object me,object user,object ob);

void create() 
{
   seteuid(getuid());
   set("channel_id", "��������");
   set("id", "marryd");
}
void do_birth(object me)
{
  object ob;
  
  tell_object(me,HIY"\n\n��ϲ�㣬Ҫ�������ˣ���Ϊ��ĺ���ѡ��id�ɣ�\n\n"+NOR);
  ob=new("/obj/login");
  input_to("get_id",1,me,ob);
  return ;
}
void get_id(string id,object me,object ob)
{
  if(file_size("/data/login/"+id[0..0]+"/"+id+".o")>0){
    	tell_object(me,"��������Ѿ����ˣ���һ���ɣ�\n\n");
    	input_to("get_id",1,me,ob);
    	return;}
    if(!check_legal_id(id)){
    	input_to("get_id",1,me,ob);
    	return;}
    ob->set("id",id);
    tell_object(me,"Ϊ��ĺ���ȡһ���������ְɣ�\n");
    input_to("get_name",1,me,ob);
}

void get_name(string name,object me,object ob)
{
  if(!check_legal_name(name)){
    input_to("get_name",1,me,ob);
    return;}
  ob->set("name",name);
  tell_object(me,"\n��ѡ���㺢�ӵ��Ա�����(Male) Ů��(Female)\n");
  input_to("get_gender",1,me,ob);
}
void get_gender(string arg,object me,object ob)
{
  if(arg==""){
  tell_object(me,"��ֻ��ѡ�����Ի�Ů��:����(Male) Ů��(Female)\n");
  input_to("get_gender",1,me,ob);return;}
  if(arg[0]=='f'||arg[0]=='F'){
  	ob->set("gender","Ů��");}
  else if(arg[0]=='M'||arg[0]=='m')
    ob->set("gender","����");
  else { 
  	tell_object(me,"��ֻ��ѡ�����Ի�Ů�ԣ�����(Male) Ů��(Female)\n");
  	input_to("get_gender",1,me,ob);
  	return;
  }
 tell_object(me,"\n���趨���ĺ��ӵ����룺");
 input_to("get_passwd",1,me,ob);
}
void get_passwd(string pass,object me,object ob)
{
  if(sizeof(pass)<5){
  	tell_object(me,"\n���볤��������λ��");
  	input_to("get_passwd",1,me,ob);
  	return;
  }
  ob->set("password", crypt(pass,0) );
  tell_object(me,"\n��������һ������:");
  input_to("confirm_pass",1,me,ob);
}

void confirm_pass(string pass,object me,object ob)
{
  string oldpass;object user;string id,oldid;
  oldpass=ob->query("password");
  if( crypt(pass, oldpass)!=oldpass ){
  	tell_object(me,"\n������������벻һ�£����������룺");
  	input_to("get_passwd",1,me,ob);
  	return;
  }
  ob->set("body", USER_OB);
  if(!objectp(user=make_body(ob))){
  	tell_object(me,HIR"�޷�������ȥ����ʹ��SOS�������ʦ��\n"NOR);
  	return;
  }
  
  tell_object(me,"\n��ѡ����ĺ��ӵ����ͣ�\n");
  tell_object(me,"\n(a)"HIR"�������͡�"NOR"��������24  ���ǣ�12  ���ԣ�12  ����12\n");
  tell_object(me,"(b)"HIY"�������͡�"NOR"��������12  ���ǣ�24  ���ԣ�12  ����12\n");
  tell_object(me,"(c)"WHT"���ǻ��͡�"NOR"��������12  ���ǣ�12  ���ԣ�24  ����12\n");
  tell_object(me,"(d)"HIC"�������͡�"NOR"��������12  ���ǣ�12  ���ԣ�12  ����24\n");
  tell_object(me,"(e)"HIG"��ƽ���͡�"NOR"��������15  ���ǣ�15  ���ԣ�15  ����15\n");
  tell_object(me,"\n���͵�ѡ��ͽ�������кܴ��ϵ������������������\n"+
	 "�����վ��ȥ��ѯ��\n"+
	 "��ѡ��ɣ�\n");
  input_to((:choose_gift:), me,user,ob);
  return;
}

private void choose_gift(string arg, object me,object user,object ob)
{
	if(arg!="a"&&arg!="b"&&arg!="c"&&arg!="d"&&arg!="e"){
	  tell_object(me,"\n��ֻ��ѡ��\n (a)"HIR"�������͡�"NOR"(b)"HIY"�������͡�"NOR"(c)"WHT"���ǻ��͡�"NOR"(d)"HIC"�������͡�"NOR"(e)"HIG"��ƽ���͡�"NOR"\n �е�һ�֡�\n");
	  tell_object(me,"����ѡ����һ�����ͣ�\n");
	  input_to((:choose_gift:), me,user,ob);
	  return;
	}
	if(arg=="a"){
	  user->set("str",24);
	  user->set("con",12);
	  user->set("int",12);
	  user->set("dex",12);
	  user->set("char_lev/char_type","str");
	}
	else
	if(arg=="b"){
	  user->set("str",12);
	  user->set("con",24);
	  user->set("int",12);
	  user->set("dex",12);
	  user->set("char_lev/char_type","con");
	}
	else
	if(arg=="c"){
	  user->set("str",12);
	  user->set("con",12);
	  user->set("int",24);
	  user->set("dex",12);
	  user->set("char_lev/char_type","int");
	}
	else
	if(arg=="d"){
	  user->set("str",12);
	  user->set("con",12);
	  user->set("int",12);
	  user->set("dex",24);
	  user->set("char_lev/char_type","dex");
	}
	else{
	  user->set("str",15);
	  user->set("con",15);
	  user->set("int",15);
	  user->set("dex",15);
	  user->set("char_lev/char_type","middle");
	}
	printf("\n��ȷ����(Yes/No)\n");
	input_to((:yes_no:), me,user,ob);
	return;
}

private void yes_no(string arg, object me,object user,object ob)
{
	int food,water;
	
	if(arg=="Yes"||arg=="yes"||arg=="Y"||arg=="y")
	  tell_object(me,"\n����ѡ����ϣ�\n");
	else
	if(arg=="No"||arg=="no"||arg=="N"||arg=="n"){
	  tell_object(me,"\n�ðɣ�������ѡ��\n");
	  tell_object(me,"\n(a)"HIR+"�������͡�"NOR"(b)"HIY"�������͡�"NOR"(c)"WHT"���ǻ��͡�"NOR"(d)"HIC"�������͡�"NOR"(e)"HIG"��ƽ���͡�"NOR"\n");
	  input_to((:choose_gift:), me,user,ob);
	  return;
	}
	else{
	  printf("\n��ȷ����(Yes/No)\n");
	  input_to((:yes_no:), me,user,ob);
	  return;
	}
  tell_object(me,HIY"\n��ĺ��������� 30 �����ԣ��������ɷ��䡣\n"NOR); 
  user->add("char_lev/points",30);
  
  user->set("birthday", time() );
  user->set("food", 1000);
  user->set("water", 1000);
  user->set("channels", ({ "chat","rumor","dt","banghui","party","sale"}));
  user->set_temp("link_ob", ob);
  user->set_encoding(me->query_encoding());
  user->set("password",ob->query("password"));
  user->set("body",ob->query("body"));
  user->set("gender",ob->query("gender"));
  user->set("title","��ͨ����");
  user->set("startroom","/d/newbie/door");
  user->set("pass_test",1);
  user->set("per",10+random(11)+random(11));
  user->set("kar",10+random(11)+random(11));
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  user->setup();
  
  message("vision",HIY"�����Ʒ��ơ�����˵��һ����"+HIG+user->query("name")+HIY+"��"+
          "��Ӣ�۵����ˣ�\n"NOR,users());
  
  user->save();
  ob->save();
  destruct(ob);
  destruct(user);
  tell_object(me,"\n\n��ĺ����Ѿ������ˣ������ʹ�ú��ӵ��˺Ž��е�¼��\n");
  return;
}

object make_body(object ob)
{
   string err;
   object user;
   int n;

        if(!ob->query("body")) {
     return 0;
        }
   user = new(ob->query("body"));
   if(!user) {
     write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
     write(err+"\n");
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

int check_legal_id(string id)
{
   int i;
   string *legalid;

   i = strlen(id);
   
   if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
     write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
     return 0;
   }
   while(i--)
     if( id[i]<'a' || id[i]>'z' ) {
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
   
   if( (strlen(name) < 2) || (strlen(name) > 8 ) ) {
     write("�Բ�������������ֱ����� 1 �� 4 �������֡�\n");
     return 0;
   }
   while(i--) {
     if( name[i]<=' ' ) {
        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
        return 0;
     }
     if( i%2==0 && !is_chinese(name[i..<0]) ) {
        write("�Բ��������á����ġ�ȡ���֡�\n");
        return 0;
     }
   }
   if( member_array(name, banned_name)!=-1 ) {
     write("�Բ����������ֻ���������˵����š�\n");
     return 0;
   }

   return 1;
}