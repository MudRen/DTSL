
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ʯ·��������Ժ�Ľ����������������߸��ǣ�ɫ
�����£�ȴ��֪�������ں������ڴ�ɨ������������ˡ����������е�
��ȸ��ɫ��Ϊҫ�ۡ�
LONG);

  set("exits", ([ 
	  "out":__DIR__"miaodoor",
	  "east":__DIR__"shilu2",
  
         ]));
  set("objects",([
	  __DIR__"npc/budian":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

