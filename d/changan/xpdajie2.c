
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ���");
  set ("long", @LONG
��������ƽ����ϣ�������ֺ�᳤���Ƕ��������������ţ�����
��ƽ�ţ��ǳ����ǵ����ɵ�֮һ�������������ֵģ��ϱ�ͨ��Ĵ����
������֡�
LONG);

  set("exits", ([
 "north":__DIR__"yadajie1",
 "east":__DIR__"xpdajie3",
 "westup":__DIR__"xpqiao",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

