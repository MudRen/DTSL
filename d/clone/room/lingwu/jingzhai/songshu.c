
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);

void create ()
{
  set ("short","����");
  set ("long", @LONG
����һ�����������±ߵ��������±���������Ԩ������Ʈ�������
��ߡ�̧ͷ��ȥ�������Ƕ��͵����£���������ͷ��һ��紵��������
���˼��Σ�������ƬƬ��ѩ����ϸ��ȥ���Ա��ƺ�����һ��Сɽ����
LONG);

  set("exits", ([ 
 "enter":__DIR__"mishi1",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="up")
  return notify_fail("��Ҫ������������\n");
  message_vision("$N�������£�������ȥ��\n",ob);
  ob->move(__DIR__"wolong4");
  return 1;
}
