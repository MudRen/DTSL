
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
�͹��֡�
LONG);

  set("exits", ([
 "north":__DIR__"qydajie1",
  "east":__DIR__"xpdajie6",
 "west":__DIR__"xpdajie4",
"south":__DIR__"qixiamen",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

