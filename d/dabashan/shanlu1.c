
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·���ϱ��Ǹ�ɽ����������һ����ʯ�ĵط�����С����
������ţ����ⲻС�ĵ�����ȥ��
LONG);

  set("exits", ([ 

   "southdown":__DIR__"shanji1",
   "north":__DIR__"shanya",
   "northeast":"/d/job/yishengjob/shenshan",
   "northwest":__DIR__"caishichang",
//   "northwest":__DIR__"qiaobi",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

