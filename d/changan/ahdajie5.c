
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǰ�����֣��ϱ����ӳ����ǵİ����źͷ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ������ֵĶ��档����ʮ�����֣���
������������Ϣ��������һ������ݡ�������Ե���ʳǵİ����š�
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie3",
 "south":__DIR__"ahdajie4",
 "west":__DIR__"waibinguan",
 "east":"/d/cahc/anfumen",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

