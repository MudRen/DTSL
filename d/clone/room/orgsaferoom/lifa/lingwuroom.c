
#include <ansi.h>
#include <org.h>

inherit "/std/lingwuroom";

void create ()
{
  set ("short","修习室");
  set ("long", @LONG
这里是天策府的修习室，天策府的弟子都在这里修习一些基本功夫。
这里非常安静，只见屋子里已经有几个人盘膝做在那里，默默地修习一
些基本功夫。这里还挂着一个牌子(pai)。
LONG);

  set("exits", ([ 
 "south":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
  set("shili/name","lifa_b");
  set("item_desc",([
     "pai":"你可以使用研究(yanjiu)来研究武功。\n"+
           "      使用checkskills 来查看目前本势力的基本武功。\n",
     ]));
  setup();
 
}

void init()
{
  ::init();
  add_action("do_yanjiu","yanjiu");
  add_action("do_skills","checkskills");
  
}

int do_yanjiu(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!arg)
   return notify_fail("你要研究什么技能？\n");
  if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
  
  return ORG_D->do_improve_skill(ob,this_object(),arg);
 
}

int do_skills()
{
  return ORG_D->check_skills(this_player(),this_object());
} 