
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������λ�ڱ��Ʒ��£���ǰ�д��ʯ����ҺȪ��Ȫ��ʯ�£��峺��
�ȣ����겻�ԡ�һ����������������ٲ��䣬������Χ���ߴ�ʮ���ɡ�
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shiqiao",
 "westup":__DIR__"gelou",
 "southup":__DIR__"shanlu6",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

