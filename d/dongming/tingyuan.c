
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ͥԺ"NOR);
	set("long", @LONG
������ͥԺ�������Ƕ����ɵ�����Ϣ�ĵط��������Ǹ������⡣��
�����һ������¯���Ա���һ��������(pai)��
LONG);
	set("exits", ([
	     
		"south":__DIR__"chufang",
		"north":__DIR__"zhulin2",
		"east":__DIR__"sleep_room",
		"west":__DIR__"bingqiku",
		
	]));
set("objects",([
	__DIR__"npc/dizi2":1,
 "/d/clone/obj/tielu/tielu":1,
	]));
        set("item_desc",([
     "pai":"������Ҫ��¯�����������õ��[fire]\n"+
           "Ȼ����Ҫ��ұ���Ķ����ŵ�¯���У�[put],ֻ���Էſ�ʯ��������\n"+
           "Ȼ�����Ҫ����������[la ����],��ʼ����\n"+
           "����������ˣ����Կ�¯[kailu]ȡ���õ�����\n"+
           "�����Ĺ����У��ǳ�������������Ѫ��Ҫע����\n",
           ]));
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

int valid_leave(object me,string dir)
{
	if(dir=="west"&&
		me->query("family/family_name")!="������"
		&&present("nan dizi",environment(me)))
	return notify_fail("�е�����ס���㣺�Ǳ������ﲻ�ý�������⣡\n");
	return ::valid_leave(me,dir);
}
