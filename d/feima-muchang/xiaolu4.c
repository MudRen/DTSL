
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·������ͨ����ɽ��·�����Լ���û��ʲô�ˡ��кܶ�
��ǣ����Զ����ȥ��Զ�����Կ��������������м������������ĵ���
���������������
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu3",
	  "southwest":__DIR__"houshan",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

