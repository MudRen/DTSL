
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��԰"NOR);
	set("long", @LONG
�����Ǹ���԰���������˲��ٵ��ʻ����������кܶ�����ӡ��Ա�
��������һ��ʯ��������д�ţ��춹һ�������飬����ãã����
LONG);
	set("exits", ([
	     
		"south" :__DIR__"shilu2",
		"north":__DIR__"shilu1",
		
		
	]));
	set("objects",([
		__DIR__"npc/shanxia":1,
	]));
     set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

