
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵĴ��š����Ⱥ���ľ��������һ��ʯ�̵�ʨ�ӣ���
���Ϻ������Ҷ�����������д�ɵ�ʯ������ĸ����֡��кܶ�ʯ������
������������룬�Ե÷ǳ����֡�
LONG
);


	set("exits", ([
		"north" :__DIR__"zoulang1",
                "southeast":"/d/yangzhou/xidajie2",
	]));
	set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    __DIR__"npc/shifu2":1,
	    "/d/quest/csj/npc/shilong":1,
	    ]));
       set("outdoors", "����");
	setup();
}

int valid_leave(object ob,string dir)
{
   if(ob->query("combat_exp")>=20000&&dir=="north")
     return notify_fail("������Ӻ����������书��ô�ߣ��ѵ������߹�ô��\n");
   return ::valid_leave(ob,dir);
}