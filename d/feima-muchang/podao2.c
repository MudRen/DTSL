
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���µ�");
  set ("long", @LONG
�����Ǹ������µ��������Ѿ��Ƿ����������Ɽ�ˡ������˽���
�����������кܶ���ǣ��������ȥ��Զ�����Կ��������������м���
���������ĵ������������������
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaolu1",
	  "southeast":__DIR__"podao1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

