
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·�������Ѿ�û��ʲô�����ˡ�������һ���񷿣�����
�����������ľͷ����������������Ժ���䳡�����ȵ�������ʱ������
���������о�֮��������������ƴ�ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
      "northeast":__DIR__"chaifang",
	  "west":__DIR__"wuchang",
      ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

