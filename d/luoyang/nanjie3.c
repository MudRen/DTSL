
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������������֡������������ţ����Կ������������������
�����������ķ�⡣������һ�������꣬�����ﴫ��ƹƹ���ҵ��ô��
����������
LONG);

  set("exits", ([ 
	  "north":__DIR__"nanjie2",
	  "west":__DIR__"bingqidian",
  	  "south":__DIR__"nanjie4",

         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

