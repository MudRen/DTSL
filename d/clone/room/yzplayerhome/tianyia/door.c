
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","ׯ��");
	set("long", @LONG
��ת��һ��ï�ܵĻ���, ��Ȼ��, ֻ��һ����������, С��
�����ׯԺ�����ڲ����Ļ����С�ׯ�Ŵ����Ϻ�Ȼд�š��Ļ�ɽ
ׯ���ĸ���������Ĵ��֡�
LONG);
    set("exits", ([
	        "east" : "/d/clone/room/yzplayerhome/nandajie4",
	        "north":__DIR__"shanzhuang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
