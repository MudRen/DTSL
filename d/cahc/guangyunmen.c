
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������Ҵͥ�����ϴ��ţ����ĵ�ʱ������ڴ˾�ס�������߻�����
�������䣬߱����λ����������ݳ�����Ҵͥ���ͳ����������ڳ���
�ľӴ�����߸����������棬�в��ٴ�����������İ�������ǰ��
LONG);

  set("exits", ([ 
 "north":__DIR__"chengqingmen",
 "south":__DIR__"hggc1",
        ]));

  set("objects",([
          "/d/changan/npc/shiwei":2,
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

