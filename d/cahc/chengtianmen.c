
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","承天门");
  set ("long", @LONG
承天门总高九丈八尺，平面矩形。基部为汉白玉石须弥座，城台辟
门洞五座，上建城楼。楼建于汉白玉基座上，面阔五间，进深一间，四
周围廊，环以汉白玉石栏杆。楼前、后檐明间与左、右次间开门，菱花
隔扇门。东西两山设双扇板门，通城墙及左、右马道。四面门前各出踏
跺。楼为重檐庑殿顶，下层单翘重昂五踩斗栱上层单翘重昂七踩斗栱，
梁枋间饰墨线大点金旋子彩画。上檐悬蓝底鎏金铜字满汉文“ 承天门 ”  
华带匾。顶覆黄色琉璃瓦。楼内顶部为金莲水草天花，地面铺墁金砖。
穿过承天门，就到了太极宫了。
LONG);

  set("exits", ([ 
 "north":__DIR__"tjgc",
 "south":__DIR__"hggc2",
        ]));

  set("objects",([
          "/d/changan/npc/shiwei":2,
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

