//Edit By Subzero
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", YEL "����" NOR);
        set("long", @LONG
�����������������������Ժ����������ص㡣�����������һ
�Ų輸���ͼ������ӣ�����������һ���������������Ů�ӡ�
LONG);

        set("valid_startroom", 1);
        set("exits", ([
        "east" : "/d/luoyang/nanjie4",
        "west" : "/d/luoyang/ygrestroom2",
        ]));
  		set("objects",([
     		"/d/clone/npc/chuzi":1,
    		 ]));
		set("resource/water",1);
        setup();
}
