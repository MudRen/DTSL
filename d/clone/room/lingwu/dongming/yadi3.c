
#include <ansi.h>
inherit ROOM;
int do_pa(string arg);
void create ()
{
  set ("short",HIB"��ɽ��"NOR);
  set ("long", @LONG
������ɽ�µİ�ɽ�������������ķ����ƺ�����[up]����
[left],��[right].
LONG);
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
 
}
void init()
{
   add_action("do_pa","climb");
}

void noway(object ob)
{
        ob->receive_wound("kee",2);
  	ob->move(__DIR__"yadi");
  	tell_object(ob,"����һ�����ҽ�һ�������ͱ��ϵ���������\n");
  	tell_object(ob,"��о�˫�ȷ��飬һ��Ҳ�߲����ˣ�����Ҫ��Ϣһ���ˣ�\n");
  	ob->delete_temp("climb_trace1");
  	ob->delete_temp("climb_trace2");
  	ob->delete_temp("climb_trace3");
  	ob->start_busy(180);
  	return;
}
int do_pa(string arg)
{
  object ob;int kar;
  ob=this_player();
  if(!arg||
  (arg!="up"&&arg!="left"&&arg!="right"))
  return notify_fail("��ֻ������[up]����[left],��[right]����\n");
  ob->set_temp("climb_trace3",arg);
  if(ob->is_busy())
  return notify_fail("����æ���ء�\n");
  message_vision(YEL"$N���������µı�Ե��������ȥ��\n"NOR,ob);
  kar=ob->query("kar");
  if(kar<=15){
    if(ob->query_temp("climb_trace1")!="left"||
       ob->query_temp("climb_trace2")!="right"||
       ob->query_temp("climb_trace3")!="up"){
       	noway(ob);return 1;}}
  else
  if(kar<=20){
    if(ob->query_temp("climb_trace1")!="up"||
       ob->query_temp("climb_trace2")!="left"||
       ob->query_temp("climb_trace3")!="right"){
       	noway(ob);return 1;}}
  else
  if(kar<=25){
    if(ob->query_temp("climb_trace1")!="right"||
       ob->query_temp("climb_trace2")!="left"||
       ob->query_temp("climb_trace3")!="up"){
       	noway(ob);return 1;}}
  else
  if(kar<=30){
    if(ob->query_temp("climb_trace1")!="up"||
       ob->query_temp("climb_trace2")!="right"||
       ob->query_temp("climb_trace3")!="left"){
       	noway(ob);return 1;}}
  if(ob->query("family_lingwu")=="dongming")
   ob->set("no_check_jump",1);
  ob->move(__DIR__"shanya");
  return 1;
}
