
inherit ROOM;
#include <ansi.h>
int do_ask(string arg);
void create()
{
	set("short", HIG"问心石"NOR);
	set("long", @LONG
这里是问心石(shi) 。据说如果有什么心事，到这里来倾诉一番，
心中所想的事就会浮现于问心石之上。北边是一个凉亭，南边是一个大
院。
LONG);
	set("exits", ([
		"north":__DIR__"qingzhuting",
		"south":__DIR__"dayuan",
	]));
           set("objects",([
           __DIR__"npc/shanwanjing":1,
           ]));
	set("item_desc",([
		"shi":"这里东溟派的问心石\n",
		]));
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
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
	if(!arg||arg!="石")
		return notify_fail("你要问谁什么事?\n");
	tell_object(ob,HIR"只见问心石上慢慢浮现出一片红云\n"NOR);
	tell_object(ob,HIW"红云散尽，石头上显示出一个数字\n"NOR);
	tell_object(ob,"上面的字迹已经模糊不清了。\n");
	return 1;
}