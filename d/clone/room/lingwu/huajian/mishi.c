
#include <ansi.h>
inherit ROOM;
int do_push(string arg);
void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
������һ�����ң��������Ѿ��ܾ�û���������ˡ��������
һ�����ӣ������и����ƾɵ���ױ̨���Աߵ�ǽ�Ϲ�������ͭ��
��jing������ϸ��ȥ����������м�����ӡ��
LONG);
 set("item_desc",([
 "jing":"��������ͭ�����ֱ�Ϊ�졢�����̡��ϡ��ף�\n"+
        "���滨�ƽ�����֪����[push]һ�»���ô��\n",
 ]));
 set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_push","push");
}
void clear(object ob)
{
  ob->delete_temp("push_jing");
  ob->delete_temp("huajian_quest1");
  ob->delete_temp("huajian_quest2");
  ob->delete_temp("huajian_quest3");
  return;
}
void noway(object ob)
{
  clear(ob);
  message_vision(HIR"ͻȻ$N�Ľ���һ���ذ��Ѿ���������$N���˽�ȥ��\n"NOR,ob);
  ob->move(__DIR__"downroom");
  return;
}
int do_push(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="��ͭ��"&&
   arg!="��ͭ��"&&
   arg!="��ͭ��"&&
   arg!="��ͭ��"&&
   arg!="��ͭ��"))
  return notify_fail("��Ҫ��ʲô��\n");
  message_vision(YEL"$N���ֳ�"+arg+"�������˹�ȥ��\n"NOR,ob);
  
  if(ob->query("super_force_huajian_nocheck")){
  	tell_object(ob,YEL"ֻ����֨��֨������ǽ��¶����һ�����ţ�\n����æ���˽�ȥ��\n"NOR);
  	ob->move(__DIR__"huajian");
  	return 1;
  }	
  
  ob->add_temp("push_jing",1);
  if(!ob->query_temp("huajian_quest1"))
  ob->set_temp("huajian_quest1",arg);
  else if(!ob->query_temp("huajian_quest2"))
  ob->set_temp("huajian_quest2",arg);
  else if(!ob->query_temp("huajian_quest3"))
  ob->set_temp("huajian_quest3",arg);
  if(ob->query_temp("push_jing")<3)
  return 1;
  if(ob->query("per")==26)
    if(ob->query_temp("huajian_quest1")!="��ͭ��"||
       ob->query_temp("huajian_quest2")!="��ͭ��"||
       ob->query_temp("huajian_quest3")!="��ͭ��"){
       	noway(ob);return 1;}
  if(ob->query("per")==27)
    if(ob->query_temp("huajian_quest1")!="��ͭ��"||
       ob->query_temp("huajian_quest2")!="��ͭ��"||
       ob->query_temp("huajian_quest3")!="��ͭ��"){
       	noway(ob);return 1;}
  if(ob->query("per")==28)
    if(ob->query_temp("huajian_quest1")!="��ͭ��"||
       ob->query_temp("huajian_quest2")!="��ͭ��"||
       ob->query_temp("huajian_quest3")!="��ͭ��"){
       	noway(ob);return 1;}
  if(ob->query("per")==29)
    if(ob->query_temp("huajian_quest1")!="��ͭ��"||
       ob->query_temp("huajian_quest2")!="��ͭ��"||
       ob->query_temp("huajian_quest3")!="��ͭ��"){
       	noway(ob);return 1;}
  if(ob->query("per")==30)
    if(ob->query_temp("huajian_quest1")!="��ͭ��"||
       ob->query_temp("huajian_quest2")!="��ͭ��"||
       ob->query_temp("huajian_quest3")!="��ͭ��"){
       	noway(ob);return 1;}
  clear(ob);
  tell_object(ob,YEL"ֻ����֨��֨������ǽ��¶����һ�����ţ�\n"NOR);
  ob->set("super_force_huajian_nocheck",1);
  set("exits/enter",__DIR__"huajian");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
