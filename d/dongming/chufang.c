
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
�����Ƕ����ɵĳ������м�����ʦ��������æ�����������˵�����
����Ʈ����ı��У��㲻����Щ���ˡ��Աߵ������Ϸ���һЩ�׷���һ
Щˮ���м���������������������̻��ʵس��š�
LONG);
	set("exits", ([
	     
		"north":__DIR__"tingyuan",
		
	]));
	set("objects",([
		__DIR__"obj/mifan":3,
		"/d/clone/npc/chuzi":1,
		]));
	set("resource/water",1);
       
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

