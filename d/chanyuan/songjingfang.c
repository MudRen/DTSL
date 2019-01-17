
#include <ansi.h>
inherit ROOM;

string do_look();
void create ()
{
  set ("short","诵经房");
  set ("long", @LONG
这里是净念禅院的诵经房。平时禅师都是在这里诵经。这里经常诵
声阵阵。只听禅师们诵经的声音，就知道他们都是武林高手。墙上挂着
一幅画，上面是两个和尚在用渡劫指比试武艺，有几个僧人在认真地看
着这幅画。
LONG);

  set("exits", ([ 
	  "northup":__DIR__"changlang5",
	  "east":__DIR__"xiaolu6",
      ]));
  set("item_desc",([
     "hua":(:do_look:),
     "画":(:do_look:),
     ]));
  set("objects",([
     __DIR__"npc/butan":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}
string do_look()
{
	object me;
	me=this_player();
   
	if(me->query("sen")<20)
		return "你精神太差了！\n";
	if(me->query_skill("finger",1)>=101)
		return "你的基本指法很高了，这些画已经没什么用了！\n";
	if(me->is_busy())
		return "你正忙着呢！\n";
	me->improve_skill("finger",me->query_int()/2+30+random(5));
	me->add("sen",-20);
	return "你看着画中的人物，觉得指法的修为有了提高。\n";
}
   
