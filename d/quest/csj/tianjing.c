inherit ROOM;
#include <ansi.h>
int do_kick(string arg);
int do_insert(string arg);

void create()
{
	set("short",HIG"�쾮"NOR);
	set("long", @LONG
������������Ժ�ĺ�Ժ��ǰԺ������ѧ�����ʵĶ��������Ա���һ
��С�ݣ����Źصĺܽ��ܡ�
LONG);
        set("exits",([
          "south":"/d/yangzhou/shuyuan",
          ]));
	setup();      
}
void init()
{
  add_action("do_kick","kick");
  add_action("do_insert","insert");
} 

int do_kick(string arg)
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step5"))
  return 0;
  if(!arg||arg!="door")
  return notify_fail("��Ҫ��ʲô��\n");
  message_vision(HIR"$N���ŷ�������һ�ţ�ֻ����������һ��������Ӧ��������\n"NOR,ob);
  ob->delete_temp("dtsl_quest_csj/step5");
  ob->set_temp("dtsl_quest_csj/step6",1);
  set("exits/enter",__DIR__"shufang");
  call_out("del_exit",5);
  return 1;
}


int do_insert(string arg)
{
  object ob;
  object obj;
  ob=this_player();
  if( !objectp(obj = present("yaoshi", ob)) )
      return notify_fail("ʲô?\n");
  message_vision(HIR"$N��Կ�ײ�����ۡ�\n"NOR,ob);
  return 1;
}

void del_exit()
{
  delete("exits/enter");
  return;
}
   
  
