
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"С��"NOR);
	set("long", @LONG
��������С�������߾��Ǻ�̲�ˡ����Ĵ����˿����ƺ�Զ����һ��
�޴�Ľ����
LONG);
	set("exits", ([
		"southwest":__DIR__"xiaojing2",
		"northeast":__DIR__"haitan1",
		
	]));
	set("objects",([
          __DIR__"npc/shanggong":1,
          ]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

