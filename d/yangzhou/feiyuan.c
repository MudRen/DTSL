
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ��������԰�ӣ������Ѿ��þ�û���������ˡ������Ӳݴ�
��������һ����ɭ�ĸо�����˵���ﾭ���ֹ���ͨ���ռ�����������
�����Ҳ����������ʿ�ӱܳ�ҵĺô����ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie3",
       ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_zuan","zuan");
  
}

int do_zuan()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_csj_action1"))
  return 0;
  
  message_vision("$N�����˿�����һ����ש�����˽�ȥ��\n",ob);
  ob->move("/d/quest/csj/migong1");
  
  return 1;
}