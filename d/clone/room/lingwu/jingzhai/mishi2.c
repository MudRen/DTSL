
#include <ansi.h>
inherit ROOM;

int do_push(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
����һ��Сɽ������Ȼ�������ѩ�أ�������ȴ��ů�紺��ֻ����
���ǽ�Ϲ�����öͭ�ƣ�д�š��ա�������������̰�������֡���֪��
��һ��ͭ�ƻ���ʲô���鷢����
LONG);

  set("exits", ([ 
 "east":__DIR__"mishi1",
        ]));
  set("no_fight",1);
  set("no_rideto",1);
set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_push","push");
}

void clear_exit()
{
  delete("exits");
  set("exits/east",__DIR__"mishi1");
  delete("no_push");
  return;
}

void clear_ob(object ob)
{
  ob->delete_temp("push_pai1");
  ob->delete_temp("push_pai2");
  ob->delete_temp("push_pai3");
  return;
}

void noway(object ob)
{
  tell_object(ob,"��ͻȻ�������ܾ�����ң��Ѿ��Ҳ�����ȥ��·�ˣ���\n");
   set("exits/west",__DIR__"mishi2");
   set("exits/east",__DIR__"mishi2");
   set("exits/south",__DIR__"mishi2");
   set("exits/north",__DIR__"mishi2");
   set("no_push",1);
   clear_ob(ob);
   call_out("clear_exit",30);
   return;
}

int do_push(string arg)
{
  object ob;
  int kar;
  ob=this_player();
  if(ob->query("family_lingwu")!="jingzhai"){
   noway(ob);
   return 1;}
  
  if(ob->query("super_force_chjz_no_push")&&
     ob->query("family_lingwu")=="jingzhai"){
  	message_vision("$N�ƿ�ͭ�ƣ����������ҡ�\n",ob);
  	ob->move(__DIR__"jingzhai");
        return 1;
  }
  
  if(!arg||(arg!="��"&&arg!="��"&&arg!="̰"))
  return notify_fail("��Ҫ���Ŀ����ӣ���\n");
  
  if(query("no_push"))
  return notify_fail("���﷽����ң��޷������ӣ�\n");
  
  message_vision("$N����һ��"+arg+"��!\n",ob);
  if(!ob->query_temp("push_pai1")){
   ob->set_temp("push_pai1",arg);
   return 1;}
  else
  if(!ob->query_temp("push_pai2")){
   ob->set_temp("push_pai2",arg);
   return 1;}
  else
  if(!ob->query_temp("push_pai3"))
   ob->set_temp("push_pai3",arg);
  kar=ob->query("kar");
  
  if(kar<=24){
   if(ob->query_temp("push_pai1")!="̰"||
      ob->query_temp("push_pai2")!="��"||
      ob->query_temp("push_pai3")!="��"){
      	noway(ob);return 1;}
  }
  else
  if(kar<=25){
   if(ob->query_temp("push_pai1")!="��"||
      ob->query_temp("push_pai2")!="��"||
      ob->query_temp("push_pai3")!="̰"){
      	noway(ob);return 1;}
  }
  else    	
  if(kar<=26){
   if(ob->query_temp("push_pai1")!="��"||
      ob->query_temp("push_pai2")!="̰"||
      ob->query_temp("push_pai3")!="��"){
      	noway(ob);return 1;}
  }
  else
  if(kar<=27){
   if(ob->query_temp("push_pai1")!="��"||
      ob->query_temp("push_pai2")!="̰"||
      ob->query_temp("push_pai3")!="��"){
      	noway(ob);return 1;}
  }
  else{
   if(ob->query_temp("push_pai1")!="̰"||
      ob->query_temp("push_pai2")!="��"||
      ob->query_temp("push_pai3")!="��"){
      	noway(ob);return 1;} 
  }
   clear_ob(ob);
   tell_object(ob,"ֻ����֨���У�ǽ��¶��һ�����ţ�\n");
   ob->set("super_force_chjz_no_push",1);
   set("exits/enter",__DIR__"jingzhai");
   call_out("clear_exit",5);
   return 1;
}   	
  
