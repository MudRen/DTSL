
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��԰"NOR);
  set ("long", @LONG
������һ����԰�������˱Ƕ�������ʱ����Ŀˬ����ϸһ��������
���಻�Ǻܶ࣬���ǵ���֮�࣬�����Գ�����ĳ������ա�
LONG);

  set("exits", ([ 

  "north":__DIR__"zhengdian",
  "south":__DIR__"suishilu1",
  "east":__DIR__"huiketing",
       ]));
  set("objects",([
	  "/d/job/cihangjob/qin":1,
	  ]));
set("outdoors","jingzhai");
  
  set("valid_startroom", 1);
  setup();
 
}

