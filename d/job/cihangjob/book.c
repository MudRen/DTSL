#include <ansi.h>
inherit ITEM;
mapping name=([
"���ľ�":"qingxinjue","������":"banruojing","������":"fahuajing",
"��վ�":"jingangjing","������":"wuliangjing","���ƾ�":"pushanjing",
"�����ྭ":"dawuxiangjing","С���ྭ":"xiaowuxiangjing",
"������":"jingchanjing",
]);
int do_chao(string arg);
void create()
{
   string *na;int i;
   na=keys(name);
   i=random(sizeof(na));
   
   set_name(na[i], ({name[na[i]]}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("unit", "��");
     set("value", 0);
     set("no_drop",1);
     set("no_get",1);
   }
   setup();
}
int is_get_of(object pa,object ob)
{
  return notify_fail("����������������\n");
}

void init()
{
  add_action("do_chao","chao");
}

int do_chao(string arg)
{
  object me,ob;
  me=this_player();
  if(!arg)
  return notify_fail("��Ҫ��ʲô���飿\n");
  ob=present(arg,me);
  if(!ob)
  return notify_fail("������û�����������\n");
  if(ob!=this_object())
  return notify_fail("���������ô���������鰡��\n");
  if(me->query("gin")<me->query_skill("wuwang-jing",1)/5+me->query_int()/4)
  return notify_fail("�㷢�־���ʮ��ƣ�ͣ��޷���������ȥ��\n");
  if(me->query_temp("cihang-job-ok"))
  return notify_fail("���Ѿ���������ˣ�\n");
  if(me->query_temp("cihang-job")!=base_name(environment(me)))
  return notify_fail("���ߴ�ط��ˣ�\n");
  message_vision("$N���������һ˿�����ؽ����鳭��ֽ�ϡ�\n",me);
  me->receive_damage("gin",me->query_skill("wuwang-jing",1)/5+me->query_int()/4);
  me->add_temp("cihang-job-times",1);
  if(me->query_temp("cihang-job-times")>random(3)+8){
  message_vision(YEL"$N�����˿��������ڳ�����һ���֣����Ի�ȥ�������������ˣ�\n"NOR,me);
  me->set_temp("cihang-job-ok",1);
  this_object()->set_temp("cihang-job-ok",1);
  return 1;}
  me->start_busy(2);
  return 1;
}