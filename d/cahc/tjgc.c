

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̫���㳡");
  set ("long", @LONG
̫���㳡��λ��̫����ǰ��ľ޴�Ĺ㳡��ȫ���ɺ�����ʯ�̳ɣ�
���ش�ʱ�̣������������������ٹ١���Զ��̫�����ʳ��ĵ����
�����У�����������ǧ�������Ŵ��ƻʳ�Ȩ���ļ��塣
LONG);

  set("exits", ([ 
 "north":__DIR__"taijimen",
 "south":__DIR__"chengtianmen",
        ]));
 
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

