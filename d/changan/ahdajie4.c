
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǰ�����֣��ϱ����ӳ����ǵİ����źͷ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ������ֵĶ��档����ʮ�����֣���
������������Ϣ��������һ�����ڡ�������Ե���ʳǵ�˳���š�
LONG);

  set("exits", ([ 
 "north":__DIR__"ahdajie5",
 "south":__DIR__"gmdajie5",
 "west":__DIR__"hnhuangfu",
 "east":"/d/cahc/shunyimen",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

