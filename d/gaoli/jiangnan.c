// /d/gaoli/xuanwumen
// Room in ����
#include <ansi.h>
inherit ROOM;

#define FROM __DIR__"jiangnan"
#define	TO	__DIR__"jiangbei"
#define SHIPDIR __DIR__"duchuan2"

#include "/std/shiproom.c";

void create()

{
set("short", "Ѽ�̽��ϰ�");

	set("long", @LONG
������Ѽ�̽����ϰ���������˴����ϣ��Ϳ��Ե���ԭ�ı����ˡ�
����ͣ���ż���С������Զ������С��Ҫ��������������Խд���(yell 
boat)���˴���
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"milin1",
		               
	]));
       setup();
	
}
