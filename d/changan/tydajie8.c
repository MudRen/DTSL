
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨԶ���");
  set ("long", @LONG
������ͨԶ����ϣ�������ֺ�᳤���Ƕ���������ͨ���ţ�����
��Զ�ţ��ǳ����ǵ����ɵ�֮һ�����澲���ĵġ��ϱ�ͨ��Ĵ���ǳ�
����֡��������ͨ���š�
LONG);

  set("exits", ([
 "south":__DIR__"csdajie3",
 "east":__DIR__"tonghuamen",
 "west":__DIR__"tydajie7",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

