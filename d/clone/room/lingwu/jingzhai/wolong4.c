
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);

void create ()
{
  set ("short","������");
  set ("long", @LONG
��������������ϵķ����£�����������׵���Ԩ������������
�������ϡ��ͱ��վ�����ͬ�õ��п�һ��⻬�������Ǹ���ƺ����Ŀ��
ȥ��Ⱥ��Ρ��ľ��۾����۵ס�
LONG);

  set("exits", ([ 
 "west":__DIR__"wolong3",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="down")
  return notify_fail("��Ҫ������������\n");
  if(ob->query("pker"))
  return notify_fail("ͨ����������ʵ��ɣ�\n");
  message_vision("$N˫��һ��أ���������������ȥ����\n",ob);
  ob->move(__DIR__"songshu");
  return 1;
}
