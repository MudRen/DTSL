
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĺ��š������߿��Ե������ǽ���Сɽ�������˺�
�٣�ƽʱ����û��ʲô�������
LONG);

  set("exits", ([ 
	 
	  "west":__DIR__"shilu5",
	  "east":"/d/xingyang/shanlu3",
  
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

