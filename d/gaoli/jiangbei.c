// /d/gaoli/xuanwumen
// Room in ����
#include <ansi.h>
inherit ROOM;

#define FROM __DIR__"jiangbei"
#define	TO	__DIR__"jiangnan"
#define SHIPDIR __DIR__"duchuan2"

#include "/std/shiproom.c";


void create()

{
set("short", "Ѽ�̽�����");

	set("long", @LONG
������Ѽ�̽��ı�����������˴����£��Ϳ��Ե������ˡ������
�˱Ƚ϶࣬����ͣ���ż���С������Զ������С��Ҫ���������������
�д���(yell boat)���˴���
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : "/d/yangzhoubei/tulu",
		               
	]));
       setup();
	
}
