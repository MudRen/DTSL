
inherit NPC;
#define TIME_TICK1 time()*60
#include "ansi.h"
string do_quest1();
string do_quest2();
string do_quest3();
int do_answer(string arg);
string do_find1();
string do_find2();
string do_find3();
string do_find4();
#include "target.c"
void create()
{
   set_name("������",({ "zhuge dewei","zhuge"}) );
        set("gender","����");
        set("title","������");
        set("age", 32);
        set("max_kee",1000);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_force",1500);
        set("force",1500);
        set("combat_exp",300000);
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("force",140);
        set_skill("tieshan-gong",140);
        set_skill("blade",140);
        set_skill("yirong-shu",200);
        set("inquiry",([
           "������":(:do_quest1:),
           "������":(:do_quest2:),
           "���":(:do_quest3:),
           "������":"�����ҵĺ��ֵܣ������Ѿ��ܾò����ˡ�\n",
           "�޶�":"�����ҵĺ��ֵܣ���ϧ����̫��ϧ�ˣ�\n",
           "ʮ����״":"�ҵ�Ȼ֪���ˣ��������ø����㣡\n",
           "��Ƥ":(:do_find1:),
           "����":(:do_find2:),
           "ʯ��":(:do_find3:),
           "���":(:do_find4:),
           ]));
    setup();
   carry_object(__DIR__"obj/tieshan")->wield();
  
}
int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
       
        if(!ob->query("dtsl_quest_yrs_ok"))
         return 0;
        if(ob->query("combat_exp")<500000)
        return notify_fail("�㹦����ô�ͣ��ҿɲ��ܴ�������������\n");
        ob->set("dtsl_quest_yrs_all_ok",1);
        return 1;
}

int prevent_learn(object ob,string skill)
{
	if(skill!="yirong-shu")
		return 1;
	return 0;	
}

void init()
{
  add_action("do_answer","answer");
}
string do_quest1()
{
  object ob;
  ob=this_player();
  ob->set_temp("dtsl_quest_yrs/step1",1);
  return "�Һ�ϲ�������ӣ����ܲ����ٸ���Ūһ���أ�\n";
}
string do_quest2()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_yrs/step2"))
  return "�ҵ��������������ײ����˵ġ�\n";
  ob->delete_temp("dtsl_quest_yrs/step2");
  ob->set_temp("dtsl_quest_yrs/step3",1);
  return "������»��ң������޵�����ѧ�����������ʲô���أ�\n";
}
string do_quest3()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_yrs/step3"))
  return "���������Ļ��ϣ�����ᱻ�����ɱ���ģ�\n";
  ob->delete_temp("dtsl_quest_yrs/step3");
  ob->set_temp("dtsl_quest_yrs/step4",1);
  return "��ô˵��Ҳ��ͬ�ҵĹ۵��ˣ���֪������ʮ����״��\n";
}

int do_answer(string arg)
{
   object ob;
   string str1,str2;
   
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_yrs/step4"))
   return 0;
   if(!arg)
   return notify_fail("�����������㣺�㵽���ܲ���˵��������\n");
   if(arg!=
   "һ�s���������ף������Ͼ�ɫ���Ľ�����¥̨���ݳ��˷ѣ��������˰��"+
   "ѹե���գ���Ѳ�����£����쳤�ǣ�������������������䣬�˾�ֱ�ɣ�"+
   "ɱֱʿ���Ż�¸�ɷ磬������Ұ��С����λ��ʮ�Զ����š�")
   return notify_fail("������ҡҡͷ����˵�Ĳ��԰���\n");
   str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)])
  return notify_fail(query("name")+"̾�˿���������Ȼ˵�ò������վ������Գ�Ϊ�ҵ�֪������\n");
   ob->delete_temp("dtsl_quest_yrs/step4");
   ob->set("dtsl_quest_yrs_ok",1);
   message_vision("$N����һЦ����˵��̫���ˣ�������������ҵ�֪���ˣ�\n",this_object());
   return 1;
}

string do_find1()
{
  object ob;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "��֣���Ҫ��Ƥ��ʲô���أ�\n";
  ob->set_temp("yrs_find/skin",1);
  return "��˵�Ž��ϳ����мҺڵ꣬��ȥ�������ѿ��ɣ�\n";
}

string do_find2()
{
  object ob;
  
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "��֣���Ҫ������ʲô���أ�\n";
  ob->set_temp("yrs_find/pencil",1);
  return "��˵���������̸���λ��ʦ����ȥ���￴���ɣ�\n";
}

string do_find3()
{
  object ob;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "��֣���Ҫʯ����ʲô���أ�\n";
  return "ʯ��������Ҳû�У���ȥ�����һ���ɣ�\n";
}

string do_find4()
{
  object ob;
  ob=this_player();
   if(!ob->query("dtsl_quest_yrs_ok"))
  return "��֣���Ҫ�����ʲô���أ�\n";
  ob->set_temp("yrs_find/mianfen",1);
  return "��˵�Ž��м��ӻ��̲���������ۣ���ȥ���Ұɣ�\n";
}

int accept_object(object who,object ob)
{
  
  string name;
  
  if(!who->query_temp("dtsl_quest_yrs/step1"))
  return 0;
  
  name=ob->query("name");
  name=replace_string(name,NOR,"");
  if(name!="����")
  return 0;
  if(ob->query("skill_type")!="blade")
  return 0;
  tell_object(who,YEL"�������Ǻ�һЦ���ã�����лл���ˣ�\n"NOR);
  who->delete_temp("dtsl_quest_yrs/step1");
  who->set_temp("dtsl_quest_yrs/step2",1);
  return 1;
}