
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIR"����"NOR);
  set ("long", @LONG
�����ǵص��ľ�ͷ�ˣ���վ�����������һ�½�ǡ����ҵ�����
����һ�������ӣ��������յ�ơ��Աߵ�ǽ�ϻ�����һ�ѵ�����֪����
˭��ס�����
LONG);

  set("exits", ([ 
 "out":__DIR__"didao3",
      ]));
      set("objects",([
      __DIR__"npc/shizhixuan":1,
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
