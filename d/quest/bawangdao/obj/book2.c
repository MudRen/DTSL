
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name("����ɽ�־�", ({ "yueshan shoujuan","book","shoujuan"}));
   set_weight(100);
   set("unit", "��");
   set("long","����һ����ɽ���µ���ѧ�־�\n");
   set("no_give",1);
   
}

string long()
{
   string msg;
   
   if(query("no_use"))
   return query("long");
   
   msg="$N����"+query("name")+"���ص���ѧ�ؼ����ƺ�����������һЩ������\n";
   message_vision(msg,this_player());
   this_player()->set_temp("dtsl_quest_jzzy_action1",1);
   set("no_use",1);
   return query("long");
}