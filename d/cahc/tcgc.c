
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��㳡");
  set ("long", @LONG
��������ߵ�ǰ��һ���㳡�����������˴�������軨���м�һ 
��������ֱͨ��ߵ�������վ��һ��������������׾����Ե� 
�����ׯ�����¡�

LONG);

  set("exits", ([ 
 "northup":__DIR__"tiancedian",
 "southup":__DIR__"chengqingdian",
 "east":"/d/clone/room/orgsaferoom/lifa/baihutang",
 "west":__DIR__"woshi",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

