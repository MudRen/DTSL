//logindd.c for dt.
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

void create() 
{
   seteuid(getuid());
   set("channel_id", "ת������");
   set("id", "logind");
}
int do_zhuanshi(object me)
{
  object ob;
  if(me->query("age")<me->query("con")+60&&!wizardp(me))
  return notify_fail("������δ�������Ǻúû��Űɣ�\n");
  tell_object(me,"\n�ðɣ���������ת�������ID:\n\n");
  ob=new("/obj/login");
  input_to("get_id",1,me,ob);
  return 1;
}
void get_id(string id,object me,object ob)
{
  if(file_size("/data/login/"+id[0..0]+"/"+id+".o")>0){
    	tell_object(me,"��������Ѿ����ˣ���һ����:\n");
    	input_to("get_id",1,me,ob);
    	return;}
    if(!check_legal_id(id)){
    	input_to("get_id",1,ob,me,ob);
    	return;}
    ob->set("id",id);
    tell_object(me,"\n��������ת������������֣�\n\n");
    input_to("get_name",1,me,ob);
}

void get_name(string name,object me,object ob)
{
  if(!check_legal_name(name)){
    input_to("get_name",1,me,ob);
    return;}
  ob->set("name",name);
  tell_object(me,"��ѡ������Ա�\nGender:����(Male) Ů��(Female)>");
  input_to("get_gender",1,me,ob);
}
void get_gender(string arg,object me,object ob)
{
  if(arg==""){
  tell_object(me,"��ֻ��ѡ�����Ի�Ů�ԡ�\nGender:����(Male) Ů��(Female)>");
  input_to("get_gender",1,me,ob);return;}
  if(arg[0]=='f'||arg[0]=='F'){
  	ob->set("gender","Ů��");}
  else if(arg[0]=='M'||arg[0]=='m')
        ob->set("gender","����");
  else { 
  	tell_object(me,"��ֻ��ѡ�����Ի�Ů�ԡ�\nGender:����(Male) Ů��(Female)>");
  input_to("get_gender",1,me,ob);return;}
 tell_object(me,"���趨���롣\nPassword:>");
 input_to("get_passwd",1,me,ob);
}
void get_passwd(string pass,object me,object ob)
{
  if(sizeof(pass)<5){
  tell_object(me,"���볤��������λ��\nPassword:>");
  input_to("get_passwd",1,me,ob);return;}
  ob->set("password", crypt(pass,0) );
  tell_object(me,"��������һ�����롣\nPassword Again:>");
  input_to("confirm_pass",1,me,ob);
}

void confirm_pass(string pass,object me,object ob)
{
  string oldpass;object user;string id,oldid;
  oldpass=ob->query("password");
  if( crypt(pass, oldpass)!=oldpass ){
  tell_object(me,"������������벻�ԣ����������롣\nPassword:>");
  input_to("get_passwd",1,me,ob);return;}
  ob->set("body", USER_OB);
  if(!objectp(user=make_body(ob))){
  tell_object(this_player(),"�޷�������ȥ���뱨����ʦ��\n");
  return;}
  user->set("str",me->query("str")+1);
  user->set("int",me->query("int")+1);
  user->set("con",me->query("con")+1);
  user->set("cor",me->query("cor")+1);
  user->set("kar",me->query("kar")+1);
  user->set("per",me->query("per")+1);
  user->set_skill("literate",me->query_skill("literate",1)+5);
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
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  user->setup();
  user->save();
  ob->save();
  oldid=me->query("id");
  rm(DATA_DIR + "login/"+oldid[0..0]+"/"+oldid+__SAVE_EXTENSION__);
  rm(DATA_DIR + "user/"+oldid[0..0]+"/"+oldid+__SAVE_EXTENSION__);
  tell_object(me,"���ԭ�������Ѿ�ɾ������������ת��id���ߣ�\n");
  destruct(ob);
  destruct(user);
  destruct(me);
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