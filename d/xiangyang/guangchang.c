
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�㳡");
  set ("long", @LONG
�����������������ˡ���Ȼ��һ�ǵ����ģ���ȴ˿��û�����ֵľ�
���Ե���Щ���塣ֻ��һ��С�̷���������������߹�������С����
װ�˺ܶ�����ȴһ����û������ȥ��Զ�����Կ�����������������
������������ǽ���·���ߵ�̯��ײ��������䡣
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie1",
 "west":__DIR__"xidajie3",
 "north":__DIR__"beidajie1",
 "south":__DIR__"nandajie1",
        ]));
       set("objects",([
      "/u/kouzhong/walker":1,
     ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

