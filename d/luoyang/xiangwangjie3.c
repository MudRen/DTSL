
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
������������������֡��������ߣ��͵��������Ķ��š�����ս��
������Ȼ���������ķ��������кܶ��˴Ӷ���ӿ�룬�ٱ������ܵؼ��
�����������ˡ�ֻ���������������������������ڶ���
LONG);

  set("exits", ([ 
  
  "west":__DIR__"xiangwangjie2",
  "east":__DIR__"dongmen",
  "northeast":__DIR__"dongbianmen1",
  "north":__DIR__"qingshilu2",
  "south":__DIR__"matou",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
