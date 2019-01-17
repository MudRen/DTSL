#include <ansi.h>
inherit ROOM;
int do_post(string arg);
void create ()
{
  set ("short",HIR"大唐双龙法庭"NOR);
  set ("long", @LONG
这里是大唐双龙的法庭，是巫师审判玩家的地方。如果某个玩家蓄
意在大唐双龙捣乱或有意对大唐双龙发展造成影响，巫师可以在这里对
他进行审判。在审判结束后，你可以使用 xuangao「宣告」来发布审判
结果。
LONG);

  set("exits", ([ 
  "west":__DIR__"wizroom",
        ]));
  set("valid_startroom", 1);
  set("no_quit",1);
  set("no_shout","法庭不准大声喧哗！！\n");
  set("no_look_msg","这里不准四处张望！\n");
  set("no_suicide","犯了错误可以改正，没必要自杀吧？！\n");
  set("no_fight",1);
  set("no_channel","犯了法还敢这里乱说话吗？\n");
  set("no_tell","犯了法还敢这里乱说话吗？\n");
  setup();
}
int valid_leave(object ob,string dir)
{
  if(!wizardp(ob))
  return notify_fail("你犯了了错误，还是不要动的好！\n");
  return ::valid_leave(ob,dir);
}
void init()
{
  add_action("do_post","xuangao");
}
int do_post(string arg)
{
  object ob;
  ob=this_player();
  if(!arg){
   if(!wizardp(ob))
     return notify_fail("什么？\n");
   else return notify_fail("你要发布什么消息？\n");}
 if(!wizardp(ob))
 return notify_fail("什么？\n");
 message("vision",HIR+"【法  庭】:"+arg+"\n"+NOR,users());
 return 1;
}
  
