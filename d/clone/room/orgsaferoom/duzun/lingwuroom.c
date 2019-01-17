
#include <ansi.h>
#include <org.h>

inherit "/std/lingwuroom";

void create ()
{
  set ("short","��ϰ��");
  set ("long", @LONG
�����Ƕ��𱤵���ϰ�ң����𱤵ĵ��Ӷ���������ϰһЩ��������
����ǳ�������ֻ���������Ѿ��м�������ϥ�������ĬĬ����ϰһ
Щ�����������ﻹ����һ������(pai)��
LONG);

  set("exits", ([ 
 "east":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
  set("shili/name","duzun_b");
  set("item_desc",([
     "pai":"�����ʹ���о�(yanjiu)���о��书��\n"+
           "      ʹ��checkskills ���鿴Ŀǰ�������Ļ����书��\n",
     ]));
  setup();
 
}

void init()
{
  ::init();
  add_action("do_yanjiu","yanjiu");
  add_action("do_skills","checkskills");
  
}

int do_yanjiu(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!arg)
   return notify_fail("��Ҫ�о�ʲô���ܣ�\n");
  if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
  
  return ORG_D->do_improve_skill(ob,this_object(),arg);
 
}

int do_skills()
{
  return ORG_D->check_skills(this_player(),this_object());
} 