
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ϴ��");
  set ("long", @LONG
���ǰ��ϴ�֣��ϱ����ӳ����ǵ���ƽ�ֺͽ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ��ϱ��ֵ����档����ʮ�����֣���
������������Ϣ��������һ�������ĸ��ڡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"gmdajie4",
 "south":__DIR__"asdajie2",
 "west":__DIR__"yinfu",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

