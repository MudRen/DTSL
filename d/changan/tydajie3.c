
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ���ϱ�ͨ��Ĵ���ǰ�����֣�������
�����š�
LONG);

  set("exits", ([
 "north":__DIR__"fanglinmen",
 "south":__DIR__"ahdajie5",
 "east":__DIR__"tydajie4",
 "west":__DIR__"tydajie2",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

