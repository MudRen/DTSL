inherit ROOM;
#include <ansi.h>
int do_whisper(string arg);
void create()
{
	set("short","ǰ��");
	set("long", @LONG
������ʯ�����ҵ�ǰ����ƽʱʯ���ǲ��ñ����߽��������ҵġ���
������ܰ�����ֻ��ɨ�ص������������ɨ������
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
  return notify_fail("ʯ���������㻹�ǲ�Ҫ��ȥ�ˣ�\n");
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
  return notify_fail("ʲô?\n");
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("ʲô?\n");
  if(base_name(target)!="/d/quest/csj/npc/yuwen-huaji")
    if(!userp(target))
  return notify_fail("ʲô?\n");
    else return notify_fail("ʲô?\n");
  if(text!="ʯ�������")
  return notify_fail(target->name()+"ʲô?\n");
  ob->set_temp("dtsl_quest_csj/step3",1);
  ob->delete_temp("dtsl_quest_csj/step2");
  message_vision(HIR"$Nһ���߿����ţ������ȵ���ʯ��������������\n\n"NOR,target);
  message_vision(YEL"ֻ��ž��һ����һ����Ӱ�ƴ������������������������ʧ�����ˣ�\n"NOR,ob);
  message_vision(HIR"$N������Х��ʯ���������������ӣ�˵�����н���������Ӱ��ȥ����\n\n"NOR,target);
  destruct(target);
  return 1;
}