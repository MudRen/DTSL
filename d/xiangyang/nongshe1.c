
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
 "west":__DIR__"nongtian1",
       ]));
   set("objects",([
      __DIR__"npc/nongfu":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

