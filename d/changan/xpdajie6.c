
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
���ɴ�֡�
LONG);

  set("exits", ([
 "north":__DIR__"wxdajie1",
  "east":__DIR__"dongshinankou1",
 "west":__DIR__"xpdajie5",
        ]));
  set("objects",([
    "/d/tujue/mutiexiong":1,
    ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

