
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玉泉院");
  set ("long", @LONG
玉泉院得名，源于玉泉。相传院内泉水原为山顶镇岳宫玉井潜流，
此水潜至张超谷牛羊石下，始涌出地表，聚而为泉。“微有酒香”，“
可去沉疴”，故名玉泉。此处为登临华山的必由之路。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shanlu1",
 "southup":__DIR__"konglingfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
