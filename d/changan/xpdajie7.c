
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
 "north":__DIR__"csdajie1",
  "west":__DIR__"dongshinankou2",
 "east":__DIR__"yanxingmen",
        ]));
  set("objects",([
  "/d/tujue/kang":1,
  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

