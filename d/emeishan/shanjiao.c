
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ƕ�üɽ��ɽ���¡���������Կ�����üɽ��������ɫ������
�кܶ����ˣ�����Ϊ��һ�ö�üɽ�ķ�⡣
LONG);

  set("exits", ([ 
 "northup":__DIR__"xiaojing1",
 "westup":__DIR__"shanlu1",
 "eastdown":__DIR__"shanlu4",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

