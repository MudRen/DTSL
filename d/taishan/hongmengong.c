
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ź�");
  set ("long", @LONG
������̩ɽ�ĺ��Ź����ߵ�����㲻����Щƣ���ˡ�������ȥ��
���кܶ��ɽ·Ҫ�ߣ�̩ɽ�Ķ��廹��ң���ɼ���
LONG);

  set("exits", ([ 

   "westup":__DIR__"shanlu3",
   "down":__DIR__"shanlu2",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();

}