
inherit ROOM;
#include <ansi.h>
int do_ask(string arg);
void create()
{
	set("short", HIG"����ʯ"NOR);
	set("long", @LONG
����������ʯ(shi) ����˵�����ʲô���£�������������һ����
����������¾ͻḡ��������ʯ֮�ϡ�������һ����ͤ���ϱ���һ����
Ժ��
LONG);
	set("exits", ([
		"north":__DIR__"qingzhuting",
		"south":__DIR__"dayuan",
	]));
           set("objects",([
           __DIR__"npc/shanwanjing":1,
           ]));
	set("item_desc",([
		"shi":"���ﶫ���ɵ�����ʯ\n",
		]));
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
      
}
void init()
{
	add_action("do_ask",({"ask","wen"}));
}

int do_ask(string arg)
{
	object ob;
	ob=this_player();
	if(!arg||arg!="ʯ")
		return notify_fail("��Ҫ��˭ʲô��?\n");
	tell_object(ob,HIR"ֻ������ʯ���������ֳ�һƬ����\n"NOR);
	tell_object(ob,HIW"����ɢ����ʯͷ����ʾ��һ������\n"NOR);
	tell_object(ob,"������ּ��Ѿ�ģ�������ˡ�\n");
	return 1;
}