
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @long
�����Ǳ���֡�������һ�����������Ŀ�ջ[������ջ]����С����
������������к����������ˡ����������������ġ��������ַǷ�����
���߿��Ե�����������¥����Ժ���������������к�·�ߵ����ˡ�
long);

  set("exits", ([ 
      "west":__DIR__"luoyang-kezhan",  
      "south":__DIR__"tianjie",
      "north":__DIR__"beijie2",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

