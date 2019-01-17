
#include <ansi.h>
inherit ROOM;
int do_roat(string arg);
void create ()
{
  set ("short",HIR"�׻���"NOR);
  set ("long", @LONG
�������μұ��İ׻��á���������ɭ�ϣ�ƽʱ����û���˵�
�����������������һ����Ƥ���Σ���Ƥ���ε��Ա���һ����
ɫ��С��ͷ���������ƺ�������תŤ����
LONG);

  set("exits", ([ 
 "down":"/d/lingnan/zhengting",
        ]));
  set("objects",([
     __DIR__"chair":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_roat","roat");
}
void noway(object ob)
{
  message_vision(MAG"ͻȻһȥ�������С��ͷ��ð����ֱ��$N��ȥ��\n"NOR,ob);
  ob->delete_temp("song_quest1");
  ob->delete_temp("song_quest2");
  ob->delete_temp("song_quest3");
  ob->delete_temp("song_quest_times");
  ob->unconcious();
  return;
}
int do_roat(string arg)
{
  object ob;int kar;
  ob=this_player();
  
  if(ob->query("super_force_sjb_no_roat")&&
     ob->query("family_lingwu")=="songjia"){
     message_vision("$N��ת��ͷ�����������ҡ�\n",ob);
     ob->move(__DIR__"lingnan");
     return 1;
  }
     
  if(!arg||
   (arg!="up"&&arg!="right"&&arg!="left"))
  return notify_fail("�������ת[roat]��ͷ up �� right �� left.\n");
  if(ob->query("pker"))
  return notify_fail("ͨ����������ʵ��ɣ�\n");
  if(ob->query("family_lingwu")!="songjia"){
  	noway(ob);return 1;}
  ob->add_temp("song_quest_times",1);
   if(ob->query_temp("song_quest_times")==1)
   ob->set_temp("song_quest1",arg);
   if(ob->query_temp("song_quest_times")==2)
   ob->set_temp("song_quest2",arg);
   if(ob->query_temp("song_quest_times")==3)
   ob->set_temp("song_quest3",arg);     
   tell_object(ob,"����ת��һ��С��ͷ��\n");
  if(ob->query_temp("song_quest_times")<3)
   return 1;
  kar=ob->query("kar");
  if(kar<=15){
    if(ob->query_temp("song_quest1")!="up"
       ||ob->query_temp("song_quest2")!="left"
       ||ob->query_temp("song_quest3")!="right"){
       noway(ob);return 1;}}
  else
  if(kar<=20){
    if(ob->query_temp("song_quest1")!="left"
       ||ob->query_temp("song_quest2")!="up"
       ||ob->query_temp("song_quest3")!="right"){
       noway(ob);return 1;}}
  else 
  if(kar<=25){
    if(ob->query_temp("song_quest1")!="right"
       ||ob->query_temp("song_quest2")!="left"
       ||ob->query_temp("song_quest3")!="up"){
       noway(ob);return 1;}}
  else
  if(kar<=30){
    if(ob->query_temp("song_quest1")!="left"
       ||ob->query_temp("song_quest2")!="right"
       ||ob->query_temp("song_quest3")!="up"){
       noway(ob);return 1;}   }
  ob->delete_temp("song_quest1");
  ob->delete_temp("song_quest2");
  ob->delete_temp("song_quest3");
  ob->delete_temp("song_quest_times");
  tell_object(ob,"ֻ����֨һ����Ƥ�������˿���������һ���ص���\n");
  ob->set("super_force_sjb_no_roat",1);
  set("exits/enter",__DIR__"lingnan");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
