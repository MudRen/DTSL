
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��");
	set("long", @LONG
������һ�Ҵ󴬡�����Φ����Ʈ����һ����죬���滭�Ŷ����ɵ�
��־������޴󣬿��������������һ�������ˡ����Ƕ����ɵĴ���ÿ
�궫���ɶ�����ԭ����������ֻ������������ʿ���ڳ�������ȥ��
LONG);
	set("exits", ([
		"east":__DIR__"gangkou2",
		"enter":__DIR__"chuancang",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

