
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����������������ţ�������Ҳ������ǡ���ǽ��վ�ż���ʿ����
����ؿ��Ž��������ˡ�
LONG);

  set("exits", ([ 
      "southwest":__DIR__"qinglongjie",
      "east":__DIR__"beimen",
  ]));
  set("objects",([
      __DIR__"npc/bing":2,
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 }

