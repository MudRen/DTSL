
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
�����Ǻ��������ľ�¥--����¥�����ں��ݵ��ο�һֱ�ܶ࣬����
��¥������ܺá����ھ�¥�ش��������ߣ�����ȡ��������¥������С
������æ����ͣ��
LONG);

  set("exits", ([ 
"south":__DIR__"xidajie1",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
 
  set("valid_startroom", 1);
  setup();
 
}

