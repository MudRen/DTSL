
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǰ�����֣��ϱ����ӳ����ǵİ����źͷ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ������ֵĶ��档����ʮ�����֣���
������������Ϣ��
LONG);

  set("exits", ([ 
 "north":__DIR__"ahdajie3",
 "south":__DIR__"ahdajie1",
       ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

