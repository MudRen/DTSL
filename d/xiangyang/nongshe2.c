
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ũ��");
  set ("long", @LONG
������һ�����������ɵ�С�ݣ����ڳ���һ�Ŵ���һ����������û
��ʲô�����ˡ���������һ������
LONG);

  set("exits", ([ 
 "east":__DIR__"nongtian1",
       ]));
  set("objects",([
      __DIR__"npc/nongfu":2,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

