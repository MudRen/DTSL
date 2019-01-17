
#include <ansi.h>
#include <org.h>

inherit ROOM;

void create ()
{
  set ("short","万啸堂");
  set ("long", @LONG
这里是飞马牧场的万啸堂，这里平时都重兵把守。里面进去是飞马
牧场英雄们休息、练习武功的地方。只听里面不断传出练武的声音，没
有护卫的许可，你不是不能进去的。
LONG);

  set("exits", ([ 
 "enter":__DIR__"huayuan",
 "west":"/d/feima-muchang/qingshilu5",
      ]));
  set("objects",([
   "/d/clone/room/orgsaferoom/npc/huwei":2,
   ]));
  set("valid_startroom", 1);
  set("shili/name","feima_b");
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(present("orgsafe_guard",environment(ob))
    &&dir=="enter"
    &&!ORG_D->if_friend_org(ob,this_object())
    &&ob->query("shili/name")!=query("shili/name"))
  return notify_fail("护卫一下拦住你：你不是本势力人员，还是不要进去的好！\n");
  
  return 1;
  
}
  