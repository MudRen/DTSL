
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ƕ������ϴ��ţ����ĵ�ʱ��̫�������ڴ˾�ס�����������
����������ɱ������ݳ����󣬶����ͳ���̫����ɵ�ס�����в�
�ٴ�����������İ�������ǰ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xiandemen",
 "south":__DIR__"hggc3",
        ]));
  set("objects",([
          "/d/changan/npc/shiwei":2,
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

