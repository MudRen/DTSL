
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����Է");
  set ("long", @LONG
����Է�������ֶԳƶ������壬��չ������ɢ����԰�е�Ϊ���ģ�
���߾���ز��ø�ʽ��������ʮ������������ǽ��������̨ͤ��������
������£����ܺ϶ȡ�����������Ԫ����ס���������ǹ�������������
�롣
LONG);

  set("exits", ([ 
 "north":__DIR__"waixuanmen",
 "south":__DIR__"qingshilu2",
 "east":__DIR__"wudedian",
 "west":__DIR__"yiyuxuan",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

