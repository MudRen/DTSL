
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��ʯ·"NOR);
	set("long", @LONG
��������ʯ·��������������ķ�ש��ǰ����һ����԰����������
����һ�����䡣
LONG);
	set("exits", ([
	     
		"south" :__DIR__"huayuan",
		"north":__DIR__"shijie3",
		"east":__DIR__"xiangfang",
		"west":__DIR__"muwu1",
		
	]));

 set("objects",([ "/d/job/dmshouzhang/zhangfang":1,]));
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

