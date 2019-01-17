#include <ansi.h>
inherit ROOM;

int damage_flag=0;

void create ()
{
  set ("short","潭底");
  set ("long", @LONG
潭水冰冷刺骨，光线不透，并有暗流急涌，潭底竟是如此凶险，稍
不留神被卷进暗涌，想必今生是无法出来了。这样伸手不见五指的环境
让人不舒服至极，黑暗中感觉到水流一阵阵涌动，似乎有大型的动物游
过，又凭添了一丝恐惧感。
LONG);
  
  set("exits",([
   "up":"/d/emeishan/shuitan",
   ]));
  
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_mo","mo");
	if(!damage_flag){
		remove_call_out("do_damage");
		call_out("do_damage",5);
		damage_flag=1;
	}
}

int do_mo(string arg)
{
	object me,ob;
	
	me=this_player();
		
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("你什么也没摸到！\n");
	message_vision("$N在水底胡乱地摸了起来。\n",me);
	me->start_busy(3);
		
	set("no_kaicai",time());
	
	if(random(100)<95){
	 message_vision("$N什么也没有摸到！\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang3");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"你负重过多了！\n");
	}
	message_vision("$N摸到了一块大小可以拿上去的冰冷冷的石头，返身向上游，\n"+
	               "脱离了这个凶险的地方。\n",me);
	me->move("/d/emeishan/shuitan");
	return 1;
}

void do_damage()
{
	object *ob;
	int i;
	
	ob=all_inventory(this_object());
	
	if(sizeof(ob)<=0){
		damage_flag=0;
		return;
	}
	
	for(i=0;i<sizeof(ob);i++){
	   if(living(ob[i])){
	    ob[i]->receive_damage("sen",800);
	    tell_object(ob[i],HIB"一阵冰冷的水流冲来，你打了个哆嗦！\n"NOR);
	   }
	   else
	    ob[i]->move("/d/emeishan/shuitan");
	}
	
    call_out("do_damage",5);
    
}