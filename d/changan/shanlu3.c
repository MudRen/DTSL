
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·����·ͨ��������ɽ�����������Ҫ����ʯ������
���������ҡ��ݿܱ���֮�ء�̧ͷ��ȥ��Ρ�뻪ɽ��һ��ͭǽ��������
��μˮ֮����
LONG);

  set("exits", ([ 
"northup":__DIR__"shanlu4",
"southwest":__DIR__"tulu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

