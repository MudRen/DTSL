
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
�͹��֡��������ߣ���һƬ�Ʋ֡�
LONG);

  set("exits", ([
 "north":__DIR__"hgdajie1",
 "south":__DIR__"jiucang",
 "east":__DIR__"xishinankou1",
 "west":__DIR__"yanpingmen",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

