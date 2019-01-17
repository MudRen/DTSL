
#include <room.h>

inherit ROOM;
string do_look1();
string do_look2();
int do_nothing(string arg);
void create()
{
	set("short", "密室");
	set("long", @LONG
这是一个密室。上面是一个坟地。这里没有阳光，只有上面洞中漏
下的丝丝光线。墙壁上有一行字,旁边还有一幅石刻的画。
LONG);


	set("exits", ([
		"out" :__DIR__"fendi",
		"west":__DIR__"mishi2",
	]));
	set("item_desc",([
	 "字":(:do_look1:),
	 "画":(:do_look2:),
	 "liuyan":"换日大法的学习方法改了。自己琢磨吧！\n",
	 ]));
	 set("no_channel","你还是专心练功吧！\n");
  	setup();
}

string do_look1()
{
 return "此洞一生只能进来一次，好好珍惜吧！\n";
}
string do_look2()
{
  object me,here,*ob;string *fs;int i,j;
   me=this_player();
   fs=me->query("force_skill");
   if(sizeof(fs)>0)
   if(sizeof(fs)>1||(fs&&fs[0]!="huanri-dafa"))
   return "你看了半天，发现什么也看不懂。\n";
  if(me->query("sen")<me->query_skill("huanri-dafa",1)/2)
   return "你精神太差了！\n";
   if(me->is_busy())
   return "你正忙着呢！\n";
   here=load_object(__DIR__"mishi");
   ob=all_inventory(here);j=0;
   for(i=0;i<sizeof(ob);i++){
     if(interactive(ob[i])) j++;}
   if(j>1) return "这里人太多了，你无法静下心来学习！\n";
   if(me->query_skill("huanri-dafa",1)>=100)
   return "你觉得画中的图象十分疏浅，继续看已经没有什么提高了。\n";
   me->receive_damage("sen",me->query_skill("huanri-dafa",1)/2?me->query_skill("huanri-dafa",1)/2:1);
    me->improve_skill("huanri-dafa",me->query_int()/10+me->query_skill("huanri-dafa",1)/5);
   me->start_busy(1);
   return "你看着画中图象，觉得[换日大法]的修为有了一定的提高。\n";
}

