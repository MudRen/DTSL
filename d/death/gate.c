// gate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB "鬼门关" NOR);
	set("long", "这里就是阴间的鬼门关了。只见左右有很多鬼魂排队朝里面走
去。这里昏暗无光，阴森恐怖。\n");
	set("exits", ([
		"enter" : __DIR__"gateway",
	]) );
    set("no_fight", 1);
    set("no_quit",1);
	setup();
}
void init()
{
  object ob;
  ob=previous_object();
  if(!ob) return;
  call_out("run",5,ob);
}
void run(object ob)
{
  
   if( !ob || !present(ob) ) return;
   
  ob->set("gin",ob->query("max_gin"));
  ob->set("kee",ob->query("max_kee"));
  ob->set("sen",ob->query("max_sen"));
  ob->set("eff_gin",ob->query("eff_gin"));
  ob->set("eff_kee",ob->query("max_kee"));
  ob->set("eff_sen",ob->query("max_sen"));
  
    tell_object(ob, HIW"一股阴冷的浓雾突然出现，很快地包围了你。\n\n"NOR);
    tell_object(ob,HIB"突然一股巨大的力量把你拉了进去！\n"NOR);
    ob->move(__DIR__"gateway");
    return;
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "enter") 
	     return notify_fail(HIB"只见前面的鬼魂回过头，凄惨地叫道：到这里你还抢路吗！？\n"NOR);

	else return 1;
}
