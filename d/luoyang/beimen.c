
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����������ı��š���Ϊ�����ĳ��У�ƽʱ�кܶ����������ǡ���
�����������ţ��м���ȫ����װ�Ĺٱ���վ��������ſڵĹٱ�����
�������ܵؼ�����������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"beijie3",
  "east":__DIR__"beimen2",
  "west":__DIR__"beimen1",
  "north":__DIR__"tulu1",
         ]));
 set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

