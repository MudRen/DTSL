inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIB"ɽ��"NOR);
	set("long", @LONG
������һ��ɽ����ƽʱ����û���������ɽ���������������ƣ�
�羰��������ʱ�������������е�������
LONG);
        set("exits",([
          "out":"/d/hengshan/yuyang",
          ]));
        setup();      
}

void init()
{
  
  add_action("do_lingwu","lingwu");
}

int do_lingwu(string arg)
{
  object ob;
  string str1,str2;
  
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ����ʲô�ڹ���\n");
  if(arg!="changsheng-jue")
  return notify_fail("���ﲻ�����������ڹ���\n");
  
  if(ob->query_skill("changsheng-jue",1)<150)
  return notify_fail("��ĳ�������Ϊ̫�ͣ�\n");
  
  if(ob->query("force_quest/csj_fail"))
   return notify_fail("�㷢�ָ����޷���ᵽ�����������ľ��裡\n");
     
  if(ob->query("force_quest/csj_ok"))
  return notify_fail("���Ѿ�����������������ˡ�\n");
  
  if(!ob->query("force_quest/no_check_csj"))
   if(ob->query("force_quest/csj_PKS")!=ob->query("PKS")
   ||ob->query("force_quest/csj_deadtimes")!=ob->query("deadtimes")
    ){
      ob->set("force_quest/csj_fail",1);
      tell_object(ob,"�㷢�ָ����޷���ᵽ�����������ľ��裡\n");
      return 1;
   }
  
  if(random(ob->query_kar())<26){
   tell_object(ob,RED"������һ����Ѫ��������ʱ���޷���᳤�����ľ��裡\n"NOR);
   ob->set_skill("changsheng-jue",10);
   ob->set("force_quest/no_check_csj",1);
   ob->add("force_quest/csj_fail_times",1);
   if(ob->query("force_quest/csj_fail_times")>=2){
   	ob->set("force_quest/csj_fail",1);
    tell_object(ob,"\n�㷢�ָ����޷���ᵽ�����������ľ��裡\n");		   
   }
   return 1;
  }
  
  
  ob->set("force_quest/csj_ok",1);
  tell_object(ob,"\n��ͻȻ���һ�֣���ᵽ�˳������ľ���֮����\n");
  return 1;
}
