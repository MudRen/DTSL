
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ϴ��");
  set ("long", @LONG
���ǰ��ϴ�֣��ϱ����ӳ����ǵ���ƽ�ֺͽ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ��ϱ��ֵ����档����ʮ�����֣���
������������Ϣ��
LONG);

  set("exits", ([ 
 "north":__DIR__"asdajie2",
 "south":__DIR__"xpdajie4",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

