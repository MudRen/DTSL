
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIB"������������"NOR, ({ "book" }));
   set_weight(300);
   set("unit", "��");
   set("long","���Ƕ����ɵ��书�ؼ���������������\n");
  
 
}


int is_get_of(object me,object ob)
{
   if(me->query("family/family_name")!="������"||
      query("owner_ob")!=me)
   return notify_fail("��������Ȿ�飡\n");
   return 1;
}

string long()
{
   object ob;
   
   ob=this_player();
   
   if(environment(this_object())!=ob
    ||ob->query("perform_quest/pili")
    ||ob->query("perform_quest/duomeng")
    ||ob->query("perform_quest/yanyu")
    ||query("owner_ob")!=ob
     )
   return query("long");
   tell_object(ob,"�㿴�����ϵ���ʽ���������������������ľ���֮����\n");
   ob->set("perform_quest/pili",1);
   return "";
}