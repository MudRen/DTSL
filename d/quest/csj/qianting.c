inherit ROOM;
#include <ansi.h>
int do_whisper(string arg);
void create()
{
	set("short","前厅");
	set("long", @LONG
这里是石龙卧室的前厅。平时石龙是不让别人走进他的卧室的。所
以这里很安静。只有扫地的仆人在那里打扫卫生。
LONG);
       set("exits",([
         "enter":__DIR__"qianting",
         "south":"/d/slwg/neitang",
         ]));
	setup();      
}
int valid_leave(object ob,string dir)
{
  if(dir=="enter")
  return notify_fail("石龙的卧室你还是不要进去了！\n");
  return ::valid_leave(ob,dir);
}
void init()
{
  add_action("do_whisper","gaosu");
}

int do_whisper(string arg)
{
  object ob;
  object target;
  string name,text;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step2"))
  return 0;
  if(!arg||sscanf(arg,"%s %s",name,text)!=2)
  return notify_fail("什么?\n");
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("什么?\n");
  if(base_name(target)!="/d/quest/csj/npc/yuwen-huaji")
    if(!userp(target))
  return notify_fail("什么?\n");
    else return notify_fail("什么?\n");
  if(text!="石龙在里边")
  return notify_fail(target->name()+"什么?\n");
  ob->set_temp("dtsl_quest_csj/step3",1);
  ob->delete_temp("dtsl_quest_csj/step2");
  message_vision(HIR"$N一脚踹开房门，高声喝道：石龙出来送死！！\n\n"NOR,target);
  message_vision(YEL"只听啪地一声，一个人影破窗而出，从你的身旁闪过，消失不见了！\n"NOR,ob);
  message_vision(HIR"$N纵声长啸：石龙，看你往哪里逃！说完身行紧随那条黑影而去！！\n\n"NOR,target);
  destruct(target);
  return 1;
}