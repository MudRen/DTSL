
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǿ�����Ժ�������������һ��ͭ������������������
��һ������¯��ȼ�ŵ�̴��ľ���ͳ������������������������ڣ�����
������������������Ⱦ�����������ա�
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie2",
	  "eastup":__DIR__"shijie3",
  
         ]));
  set("objects",([
    __DIR__"npc/buchen":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}
