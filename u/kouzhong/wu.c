
#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��Сé�ݡ�������ʰ���������롣������һ��С��԰������
��һ����դ����é�ݵİ��費�Ǻܶ࣬���˼��������Ӻ�һ����û��ʲ
ô�ˡ�é��������һ��С���ӣ����������������д�š�����С������
���֡�
LONG);


	set("exits", ([
		"north" :__DIR__"youlin2",
		"south":__DIR__"youlin3",
		"west":"/d/quest/bawangdao/xiaojing",
		"east":__DIR__"youlin1",
	]));
	set("objects",([
       "/d/chengdu/npc/shiqingxuan":1,
	   ]));
       
      setup();
}

