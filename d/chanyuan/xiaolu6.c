
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����Ǿ�����Ժ��С·����������Ժ���о����������߿��Ե���Ժ
���䳡�����ﴫ��������ߺ�����������������о�֮���������������
��ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	 
	  "northeast":__DIR__"caodi4",
	  "west":__DIR__"songjingfang",
      ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

