
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
����������֣��������ӳ����ǵľ�ҫ�ţ��������������ƽ���ݹ�
�������������ڳ�������������������ֳ�������¥�Ĺ�������������
���������Ĺݣ������Ǻպ������������ѡ����˴����������а�С̯����
������黨�ģ���ը�͸⡢�������ģ����ַǳ���
LONG);

  set("exits", ([ 
 "north":__DIR__"yadajie3",
 "south":__DIR__"gmdajie6",
 "east":__DIR__"liufuduguan",
 "west":__DIR__"mingtangwo",
       ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

