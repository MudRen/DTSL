
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������������֡�������һ�ұ����̣������ﴫ����ƹƹ����
���ô�����������һ��С�Եֻ꣬����С�������ſ�������к�������
�Ŀ��ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie3",
 "west":__DIR__"xidajie1",
 "north":__DIR__"bingqipu",
 "south":__DIR__"xiaochidian",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

