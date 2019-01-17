
inherit ROOM;
#include <ansi.h>

int do_move(string arg);

void create()	
{
	set("short", "����");
	set("long", @LONG
�����Ǳ��������ֵ����ҡ������ɨ�ĸɸɾ�����һ����Ⱦ����ǰ
���������ţ��Ա߷���һ��ľ��muyu����������һ����ϯ���ڴ�ͷ����
�ż����𾭡�
LONG);
    set("exits", ([
	        "out" : "/d/changan/wulousi",
	]));
   set("item_desc",([
      "muyu":"����һ����ͨľ�㣬������Ե����Щĥ���ˡ�\n",
      ])); 
 	  setup();
	
}

void init()
{
  add_action("do_move","move");
}

void clear(object ob)
{
  ob->delete_temp("move_muyu_times");
  ob->delete_temp("move_muyu_dir1");
  ob->delete_temp("move_muyu_dir2");
  ob->delete_temp("move_muyu_dir3");
  return;
}

int do_move(string arg)
{
  object ob;
  int kar;
  string dir;
  int times;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("��ҪŲ��ʲô��\n");
  
  if(sscanf(arg,"ľ�� %s",dir)!=1||
  (dir!="right"&&dir!="left"&&dir!="up"))
  return notify_fail("����԰�ľ��Ų�� ��[right],��[left],��[up].\n");
  kar=ob->query("kar");
  ob->add_temp("move_muyu_times",1);
  times=ob->query_temp("move_muyu_times");
  
  if(!ob->query_temp("move_muyu_dir1"))
    ob->set_temp("move_muyu_dir1",dir);
  else
  if(!ob->query_temp("move_muyu_dir2"))
    ob->set_temp("move_muyu_dir2",dir);
  else
  if(!ob->query_temp("move_muyu_dir3"))
    ob->set_temp("move_muyu_dir3",dir);
    
  if(times<3)
  return notify_fail("���ľ����Ų��һ��\n");
  
  if(kar<=15){
    
    if(ob->query_temp("move_muyu_dir1")!="right"||
       ob->query_temp("move_muyu_dir2")!="right"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("�㷢��ûʲô�仯��\n");}}
  else
  if(kar<=20){
    
    if(ob->query_temp("move_muyu_dir1")!="up"||
       ob->query_temp("move_muyu_dir2")!="right"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("�㷢��ûʲô�仯��\n");}}
  else
  if(kar<=25){
    
    if(ob->query_temp("move_muyu_dir1")!="left"||
       ob->query_temp("move_muyu_dir2")!="up"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("�㷢��ûʲô�仯��\n");}}
  else
  if(kar<=30){
    
    if(ob->query_temp("move_muyu_dir1")!="up"||
       ob->query_temp("move_muyu_dir2")!="left"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("�㷢��ûʲô�仯��\n");}}
     
  tell_object(ob,"ֻ����֨һ����ľ���±�¶��һ����������\n");
  set("exits/down",__DIR__"mishi");
  call_out("del_enter",5);
  return 1;
}

void del_enter()
{
  delete("exits/down");
  return;
}
