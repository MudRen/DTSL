
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
����������֣��������ӳ����ǵľ�ҫ�ţ��������������ƽ���ݹ�
�������������ڳ�������������������ֳ�������¥�Ĺ�������������
���Ƿ��Ÿ������Ǻպ�����������Է������Щ��¥�Ĺ����⣬���˴���
�������а�С̯���ձ�����黨�ģ���ը�͸⡢�������ģ����ַǳ��� 
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie2",
 "south":__DIR__"yadajie2",
 "east":__DIR__"fengyage",
 "west":__DIR__"shanglinyuan",
       ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

