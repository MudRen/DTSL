
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","�Ļ�ɽׯ");
	set("long", @LONG
�������Ļ�ɽׯ�� �����������������(tianyia)��С����
(yanzi) �򸾡�ֻ���������һ�ŷ��������ż������ӣ�������
����һ���ո���õĲ�ˮ������������̫ʦ�Ρ����Ϸ���ǽ����
����һ�ѽ���������š��������ĸ��֡�������һ�������
������һ��Ժ�ӣ�¥���������˷���Ϣ�����ҡ�
LONG);
    set("exits", ([
	        "up" : __DIR__"woshi",
	        "south":__DIR__"door",
	        "north":__DIR__"chufang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
