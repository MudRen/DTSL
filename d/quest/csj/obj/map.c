
#include <ansi.h>
inherit ITEM;
int do_look(string arg);
void create()
{
        set_name(YEL"��Ƥ��" NOR, ({ "yangpi juan","juan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	        set("material", "��Ƥ");
                set("no_drop",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_steal",1);
        }
        setup();
}
void init()
{
  add_action("do_look","kan");
}
int do_look(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="��Ƥ��")
  return notify_fail("��Ҫ��ʲô��\n");
  if(!ob->query_temp("dtsl_quest_csj/step7"))
  return 0;
  if(!ob->query_temp("dtsl_quest_csj/check_time"))
  ob->set_temp("dtsl_quest_csj/check_time",time());
  if(time()-ob->query_temp("dtsl_quest_csj/check_time")
     <3600*(31-ob->query("kar"))||
     time()-ob->query_temp("dtsl_quest_csj/check_time")
     >3600*(31-ob->query("kar"))+30){
   tell_object(ob,"�㿴������д�ţ�\n"+
     "����ۼ�������ĺ�������,�ټ������̻�ʤ��,\n"+
     "���Խ����ĺ��Ͷ�Ҫ��������,����ʾ�Լ���Ӣ�۱�ɫ��\n");
   return 1;}
  tell_object(ob,"������һ��ɽ����ƽʱ����û���������\n"+
                 "ɽ���������������ƣ��羰��������ʱ����\n"+
                 "���������е�������\n");
  ob->delete_temp("dtsl_quest_csj/step7");
  ob->set_temp("dtsl_quest_csj/step8",1);
  return 1;
}

