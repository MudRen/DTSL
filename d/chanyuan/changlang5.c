
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĳ��ȡ���������Ժ���о����������߿��Ե���Ժ
�ĳ����������ﴫ��������ķ��㡣���������о�֮���������������
��ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"changlang4",
	  "southdown":__DIR__"songjingfang",
	  "westdown":__DIR__"xiaolu5",

       ]));

  
  set("valid_startroom", 1);
  setup();
 
}

