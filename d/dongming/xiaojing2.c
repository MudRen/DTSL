
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"С��"NOR);
	set("long", @LONG
��������С���������뺣�߲�Զ�ˡ��ϱ���һ����԰�����������
���󺣲��ε�������
LONG);
	set("exits", ([
		"south":__DIR__"huayuan1",
		"northeast":__DIR__"xiaojing1",
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

