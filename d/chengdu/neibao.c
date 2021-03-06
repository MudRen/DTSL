
#include <ansi.h>
inherit ROOM;

int do_yell();
void create ()
{
  set ("short","内堡");
  set ("long", @LONG
这里是独尊堡的内堡了。有几个弟子在忙来忙去。独尊堡在成都有
很大的势力，所以这里的检查也是非常严格。如果想出独尊堡，你可以
高声呼喝(yell)守门的独尊堡弟子。
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"zhaobi",
	
         ]));
  set("objects",([
	  __DIR__"npc/dizi2":1,
	  ]));
  set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
	add_action("do_yell","yell");
}

int do_yell()
{
    int beipan;object me;object where;
    
	me=this_player();
	where=environment(me);
    if(where->query("can_go")||query("exits/out")) return notify_fail("吊桥已经放下来了!\n");
	call_out("do_bridge",5,where);
	message_vision("守卫冲着$N大声道:"+RANK_D->query_respect(me)+",等一下,我这就放下吊桥!\n",me);
	tell_object(where,"只听隆隆声音,吊桥正缓慢的放下来了.\n");
	return 1;
}

void do_bridge(object where)
{
    object bridge;
	bridge=load_object(__DIR__"duzunbao");
	tell_object(where,"只听哐当一声,吊桥已经放下来了!\n");
	tell_object(bridge,"只听哐当一声,吊桥已经放下来了!\n");
	where->set("exits/out",__DIR__"duzunbao");
	where->set("can_go",1);
	bridge->set("exits/enter",__DIR__"neibao");
	remove_call_out("do_bridge");
	call_out("do_close",5,where,bridge);
	return;
}

void do_close(object where,object bridge)
{
	tell_object(where,"只听隆隆声音,吊桥被拉上去了.\n");
	tell_object(bridge,"只听隆隆声音,吊桥被拉上去了.\n");
	where->delete("exits/out");
	where->delete("can_go");
	bridge->delete("exits/enter");
	remove_call_out("do_close");
	return;
}
