inherit ROOM;
#include <ansi.h>
string joke();
int do_search(string arg);
void create()
{
	set("short","�鷿");
	set("long", @LONG
�����ǰ��Ϸ��ӵ��鷿�����������������˺ܶ��顣�����뻹
��һ�������ӣ����滹��һ��ûд�����[zi]��
LONG);
        set("exits",([
          "out":__DIR__"tianjing",
          ]));
        set("objects",([
           __DIR__"npc/shilong":1,
           ]));
        set("item_desc",([
          "zi":(:joke:),
          ]));
        set("no_quit",1);
	setup();      
}
string joke()
{
  object ob;
  ob=this_player();
  return HIW+ob->name()+"�Ǵ���˫�������޳ܡ���û��ǰ;���ˣ���\n\n"NOR+
                        "                                     ���Ϸ�����\n";
}
void init()
{
  add_action("do_search","sou");
}
int do_search(string arg)
{
  object ob;
  object target,map;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step7"))
  return 0;
  if(!arg)
  return notify_fail("��Ҫ��ʲô��\n");
  if(arg!="corpse")
  return 0;
  if(!objectp(target=present(arg,environment(ob))))
  return 0;
  if(target->query("dead_id")!="shi long")
  return 0;
  if(sizeof(children(__DIR__"obj/map"))>1)
  return 0;
  message_vision("$N����������ʬ��������һ�ᣬͻȻ����һ����Ƥ��\n",ob);
  map=new(__DIR__"obj/map");
  map->move(ob);
  return 1;
}
