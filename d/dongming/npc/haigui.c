
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("海龟",({ "hai gui","gui"}) );
   set("race", "野兽" );
   set("long", "这是一只大海龟。\n");
   set("chat_chance",30);
   set("limbs",({"头","尾巴"}));
   set("verbs",({"bite"}));
   set("chat_msg",({
   "大海龟爬啊爬，好慢啊 .... ....\n",
   }));
       
   
   setup();
  
}

int accept_fight(object ob)
{
  return notify_fail("海龟连忙缩到了壳里！\n");
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  tell_object(ob,"海龟连忙缩到了壳里！\n");
  return;
}
