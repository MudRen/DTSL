
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǳ�����֣��ϱ����ӳ����ǵĳ��ַ��������������ﲻ����ô
�������ˣ�����ʮ�����֣���������������Ϣ��������ǳ��������Ķ�
���ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshidongkou2",
 "south":__DIR__"xpdajie7",
 "east":__DIR__"xunbufang",
       ]));
  set("objects",([
 "/d/job/tujuejob/shijie":1,
	  ]));
	  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

