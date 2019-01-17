
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","空灵峰");
  set ("long", @LONG
空灵峰在北峰横翠崖西的一个平台上。古时自横翠崖西登台途中架
有吊桥，桥板曳起，即成天堑。台上原凿有连体石洞，面积很大，后依
洞筑庙，自成道院。其处环境幽雅，花木掩映，堪称天然仙境，古代名
人隐士多来这里修身养性。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yuquanyuan",
 "westdown":__DIR__"baichixia",
 "eastup":__DIR__"woniutai",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
