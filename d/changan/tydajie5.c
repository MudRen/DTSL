
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ���ǰ��ϴ�֣�������
�����š�
LONG);

  set("exits", ([
 "north":__DIR__"jianfumen",
 "south":__DIR__"asdajie5",
 "east":__DIR__"tydajie6",
 "west":__DIR__"tydajie4",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

