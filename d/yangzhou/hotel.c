
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIB"�м��ջ"NOR);
	set("long", @LONG
������һ����ͨ�Ŀ�ջ������������һ��������ң�����д���м�
��ջ�ĸ����֡���ǰ������������Ѿ����飬��΢���в�ס��ҡ���š�
��ջ�����Ѿ����飬ֻʣ������ľͷ�����������������ӡ�����Ҳ
�Ѿ����飬���ҵ�ɢ���ڵ��ϡ���ջ�Ĵ����Ѿ��ƾɣ���΢��Ĵ�����
�ζ��š�һ����紵�����㲻�����˸���ս����ֻ��ѻ���Ƶؽ��Ŵ���
ͷ�Ϸɹ���
LONG);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"xiaolou",
	]));
	
	set("objects",([
		__DIR__"npc/hotel_xiaoer":1,
	]));
	

	set("no_exert",1);
	setup();
	replace_program(ROOM);
}
