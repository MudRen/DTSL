
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @long
�������ƿ�󣬳��˶������������й��⣬���������Ƿ��ٵ���
ҵ���������������������˷���ɵľ�ס������������Ҫ��ס���ֹ���
��Ա�ʹ��̼֣����巻�����������ӣ�ʲô�˶��С�
long);

  set("exits", ([      
      "northeast":__DIR__"beimen1",
      "south":__DIR__"qinglongjie3",
  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();
}

