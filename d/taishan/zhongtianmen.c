
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������̩ɽ�������š���������ʵ�̩ɽ��·�̾��Ѿ�����һ��
�ˡ�����̩ɽ�Ķ��壬һ�ɺ�׳�����Ʋ�����Ȼ������
LONG);

  set("exits", ([ 

   "northup":__DIR__"yunbuqiao",
   "westdown":__DIR__"hutiange",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

