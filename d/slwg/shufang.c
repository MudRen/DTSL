
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�鷿");
	set("long", @LONG
������ʯ�����鷿�����ﲢ�ŷ���������ܣ������кܶ���ѧ����
���鼮�����ӵ��м����һ�Ŵ����ӣ���������ķ��ı��������ұߵ�
ǽ���ϻ�����һ�ڱ�����
LONG
);


	set("exits", ([
		"southwest" :__DIR__"jiashan",
                
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}
