
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
���ǰ�����֣��ϱ����ӳ����ǵİ����źͷ����š��������ǳ���
���ϱ�����Ҫ��֣������ʳǾ��ڰ������ֵĶ��档����ʮ�����֣���
������������Ϣ��
LONG);

  set("exits", ([ 
 "north":__DIR__"gmdajie5",
 "south":__DIR__"ahdajie2",
 "east":__DIR__"jiangjunfu",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

