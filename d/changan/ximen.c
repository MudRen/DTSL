
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���ǳ����ǵ�����--����ţ�����վ�ż����ٱ����ڼ����������
���ա�������������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϡ�һ����ֱ����ʯ��
��������������졣�����ǽ��⣬����ġ����εġ���·�ĸ�ɫ����
���ܴҴҡ�
LONG);

  set("exits", ([ 
   "north":__DIR__"xiaolu1",
   "south":__DIR__"xiaolu2",
   "east":__DIR__"gmdajie7",
   "west":__DIR__"guandao1",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

