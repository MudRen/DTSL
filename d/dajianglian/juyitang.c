
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIG"������"NOR);
  set ("long", @LONG
�����Ǵ����ֶ�ľ����á����Ϸ�������һ�������ӣ����湤��
������д���������֣������á�����ׯ�����£��㲻���ŵ��˽Ų���
LONG);

  set("exits", ([ 
	  "east":__DIR__"shilu",
	     ]));
  set("objects",([
	  __DIR__"npc/mengzhu":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

