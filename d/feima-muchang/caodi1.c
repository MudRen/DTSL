
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ��ݵء��ϱ���һ��С��԰���кܶ���ǣ��������ȥ��
Զ�����Կ��������������м������������ĵ����������������������
���߾��Ƿ����������ڱ��ˡ�
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"door",
	  "southeast":__DIR__"huayuan1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

