
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��Ժ"NOR);
	set("long", @LONG
������һ����Ժ�������Ƕ���ƽʱ��Ϣ����ĵط����ܶ��������
��̸��˵�ء��ϱ߾��Ƕ���������ˣ��Ƕ����ɵ���������ס�ĵط���
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"baiyuanshi",
		"south":__DIR__"qingzhugong",
		
	]));
   set("objects",([
	   __DIR__"npc/shangkuitai":1,
	   ]));
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

