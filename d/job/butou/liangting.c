
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create ()
{
  set ("short","凉亭");
  set ("long", @LONG
这里是座凉亭，供游客休息之用。你来到这里，清风迎面而
来，不觉精神一振。向西边望去，西湖秀丽的风光尽收眼底，只
见湖面荷花绿叶在微风中微微晃动，不时有小舟从中穿过，南方
女子悦耳的歌声更是让人心醉。
LONG);

  set("exits", ([ 
"south":"/d/hangzhou/xidajie2",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

