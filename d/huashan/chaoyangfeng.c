
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�������ֳƶ��塣�嶥�����������ɣ�Ũ����գ������ǳ����ġ�
���������ּ䴩�У���������������ɡ��ǣ������������Σ�������
ӽ���پ��Ŀ���������Ȼ���⡣������һ�������ĸ���ͷ��ɣ�����̨
���ڵķ�ͷ������Ů��������ʯ¥��Ӷ�����̨ƫ�ϣ��������򣬸�
��ǧ�
LONG);

  set("exits", ([ 
 "westdown":__DIR__"shanlu5",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
