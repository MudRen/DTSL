
#include <ansi.h>
inherit ROOM;

int do_shangxian(string arg);
int do_ketou();

void create ()
{
  set ("short",WHT"普渡堂"NOR);
  set ("long", @LONG
这是净念禅院的普渡堂，堂前悬挂着一个横幅，上面写着：“苦海
无边，回头是岸”。许多犯了过错的人都来这里求佛祖开脱赎罪。有几
个僧人正在旁边念着经书，似乎在超脱着人们的罪恶。
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"zhulin",
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_shangxian","shangxiang");
   add_action("do_ketou","ketou");
}

int do_shangxian(string arg)
{
   object ob,obj;
   string name,msg;
   
   ob=this_player();
   
   
   if(!arg||sscanf(arg,"with %s",name)!=1)
   return notify_fail("你用什么上香？(shangxiang with xxx)\n");
   
   if(!objectp(obj=present(name,ob)))
   return notify_fail("你身上没有这个东西。\n");
   if(!obj->query("jinxiang_goods"))
   return notify_fail("这个东西不能上香。\n");
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   
   
   msg="\n$N点燃了香烛，恭恭敬敬地插到了香炉中。\n\n";
   message_vision(msg,ob);
   ob->add_temp("jinxiang_times",5);
   ob->start_busy(1);
   destruct(obj);
   return 1;
}

int do_ketou()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   
   if(!ob->query_temp("jinxiang_times"))
   return notify_fail("你去买点香烛再来磕头吧！\n");
   
   ob->add_temp("jinxiang_times",-1);
   msg="\n$N双手合十，低声念道：阿弥陀佛，望佛祖能超脱我的罪恶。\n";
   message_vision(msg,ob);
   ob->add("bellicosity",-10);
   if(ob->query("bellicosity")<=0)
   ob->set("bellicosity",0);
   ob->receive_damage("sen",200);
   ob->start_busy(2);
   return 1;
}
