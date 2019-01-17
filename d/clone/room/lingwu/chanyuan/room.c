inherit ROOM;
#include <ansi.h>
int do_open();
int do_push(string arg);
void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����������й���һ�������ǰ��һ�����ӣ���
���Ѿ������˺ܶ�ҳ�����ߵ�ǽ���Ϻ������Щ�֣������Ѿ�
ģ�������ˣ����������һ��С�ף��ƺ����Էš�insert����ȥ
ʲô������
LONG);

  set("exits", ([ 
 "out":__DIR__"shanlu2",
        ]));
 set("valid_startroom", 1);
  setup();
}
void init()
{
  add_action("do_open","unlock");
  add_action("do_push","insert");
}
void noway(object ob)
{
  message_vision(YEL"ֻ�������ꡱһ����Կ�׶�Ϊ���أ�\n"NOR,ob);
  set("lock",1);
   return;
}

int do_open()
{
  object ob,key;
  int str,jiali;
  ob=this_player();
  if(!ob->query_temp("can_move_in"))
  return notify_fail("�����˼��£������Ÿ����Ʋ�����\n");
  str=ob->query("str");
  jiali=ob->query("jiali");
  if(str<=15){
    if(jiali*10/ob->query_skill("force",1)!=10){
      noway(ob);return 1;}}
  else
  if(str<=20){
    if(jiali*10/ob->query_skill("force",1)!=7){
      noway(ob);return 1;}}
  else
  if(str<=25){
    if(jiali*10/ob->query_skill("force",1)!=4){
      noway(ob);return 1;}}
  else
  if(str<=30){
    if(jiali*10/ob->query_skill("force",1)!=1){
      noway(ob);return 1;}}
  message_vision("$N��Կ����ת�˼��£�ֻ������һ�����Ա�¶����һ��С���š�\n",ob);
  ob->set("super_force_cy_no_open",1);
  set("exits/enter",__DIR__"chanyuan");
  ob->delete_temp("can_move_in");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
int do_push(string arg)
{
  object ob,key;
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ���ȥʲô������\n");
  if(!objectp(key=present(arg,ob)))
  return notify_fail("������û�����������\n");
  if(!key->query("unique"))
  return notify_fail("�㷢��Կ�׸����岻��ȥ��\n");
  
  if(ob->query("family_lingwu")=="chanyuan"&&
     ob->query("super_force_cy_no_open")){
   destruct(key);
   message_vision("$N��Կ�״����ţ�Ȼ�����˽�ȥ��\n",ob);
   ob->move(__DIR__"chanyuan");
   return 1;
  }
     
  if(query("lock"))
  return notify_fail("�㷢�������и��۶ϵ�Կ�ף����е�Կ�׸����岻��ȥ��\n");  
  ob->set_temp("can_move_in",1);
  message_vision("$N��Կ�ײ����Կ�׿ס�\n",ob);
  destruct(key);
  return 1;
}

void reset()
{
  delete("lock");
  return ::reset();
}
