
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
������������ĺ�ɽ�����Ｘ��û���ˣ���������ġ��кܶ���ǣ
����Զ����ȥ��Զ�����Կ��������������м������������ĵ�������
�����������
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu4",
    ]));
 
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

