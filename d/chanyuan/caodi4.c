
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����Ǿ�����Ժ��С·�������Ǹ���԰����������Ժ�����䳡�ˣ�
�����ﲻʱ����������ߺ�ȵ����������������о�֮���������������
��ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"caiyuan",
	  "east":__DIR__"wuchang",
	  "southwest":__DIR__"xiaolu6",
      ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

