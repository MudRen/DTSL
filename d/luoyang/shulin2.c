
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����֡�������ľïʢ��ʹ���ֿ�������Щ�������㲻��
�ӿ��˽Ų���
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin1",
  "southwest":__DIR__"shashilu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

