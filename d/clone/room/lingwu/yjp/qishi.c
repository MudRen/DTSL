inherit ROOM;
#include <ansi.h>
int do_ci(string arg);
void create()
{
	set("short",HIB"����"NOR);
	set("long", @LONG
�����Ľ��ɵ����ҡ��������￴���ҳ��ܶ࣬�Ѿ��ܾ�û��
���������ˡ��Աߵ�ǽ�Ϲ���һ�����ף������Ѿ��ǲо��ˣ�ֻ
�ǻ�û�����꣬��֪��������λǰ�������µ��塣�������ܴ���
�ס�qipu�����ҳ�ʲô��������
LONG);
  set("item_desc",([
   "qipu":"���������ϵ�����,���������𽣷���,����ס���ý�����Щ�ڰ�����\n",
   ]));
	setup();      
}
void init()
{
  add_action("do_ci","ci");
}
void clear(object ob)
{
  ob->delete_temp("ci_times");
  ob->delete_temp("yjp_quest1");
  ob->delete_temp("yjp_quest2");
  ob->delete_temp("yjp_quest3");
  return;
}
void noway(object ob)
{
  clear(ob);
  message_vision(MAG"ֻ��ž��һ��,�����Ϸ���һö����,�������,�����ҵ����ͷ��!\n"NOR,ob);
  ob->unconcious();
  return;
}
int do_ci(string arg)
{
  object ob,weapon;
  ob=this_player();
  
  if(!arg||
  (arg!="����"&&arg!="����"))
  return notify_fail("�����ʲô?\n");
  if(!ob->query_temp("weapon"))
   return notify_fail("���������ץ������!!\n");
  weapon=ob->query_temp("weapon");
  if(weapon->query("skill_type")!="sword")
  return notify_fail("�㷢��"+weapon->name()+"����������ô�!\n");
  
  if(ob->query("super_force_yjp_no_ci")&&
     ob->query("family_lingwu")=="yjp"){
     message_vision("$Nһ�����ӣ����̿���һ�������˹�����$N������������ң�\n",ob);
     ob->move(__DIR__"yjp");
     return 1;
  }
  
  ob->add_temp("ci_times",1);
  if(!ob->query_temp("yjp_quest1"))
  ob->set_temp("yjp_quest1",arg);
  else if(!ob->query_temp("yjp_quest2"))
  ob->set_temp("yjp_quest2",arg);
  else if(!ob->query_temp("yjp_quest3"))
  ob->set_temp("yjp_quest3",arg);
  message_vision(YEL"$N��"+arg+"����һ��!\n"NOR,ob);
  if(ob->query_temp("ci_times")<3)
  return 1;
  if(ob->query_int()<=35){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest3")!="����"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=40){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest3")!="����"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=45){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest3")!="����"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=50){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest3")!="����"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=55){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest1")!="����"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=60){
    if(ob->query_temp("yjp_quest1")!="����"||
       ob->query_temp("yjp_quest2")!="����"||
       ob->query_temp("yjp_quest3")!="����"){
       	noway(ob);return 1;}}
  clear(ob);
  message_vision(YEL"$Nֻ�����̿���һ��,���˹���,����¶����һ������!\n"NOR,ob);
  ob->set("super_force_yjp_no_ci",1);
  set("exits/enter",__DIR__"yjp");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
