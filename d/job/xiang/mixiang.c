
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
int do_mi(string arg);
void create()
{
   set_name(YEL"����"NOR,({ "mixiang" }));    
   set("long", "����һ���˷��ӳ��õ�����,���������Ե�[mi]�Է���\n");       
  set("unit","��");
  set("no_get",1);
  set("no_give",1);
  set("no_drop",1);
   setup();
  
}
void init()
{
  add_action("do_mi","mi");
}

string *msg=({
"$N����$n��Ц���������ײ����������㵹ù����",
"$N���һ�������ҵ�������Ҳ�������ǻ�ˣ���",
"$N���˿���ĭ����$n��������ү�Һ���ƴ�ˣ���",
"$Nһߣ�첲��������쵰�����²�����ר���������ĵĹ�����ȥ���ɣ���\n"
});

int do_mi(string arg)
{
  object ob,target,*guard;
  int i;
  
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ�Ե�˭��\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("����û������ˣ�\n");
  if(target->query("target")!=ob)
  return notify_fail("�ⲻ����Ҫ�Ե���Ŀ�꣡\n");
  
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  
  if(!living(target))
  return notify_fail("�Է�����������״̬������Ҫ�����㡣\n");
  
  guard=all_inventory(environment(ob));
  
  for(i=0;i<sizeof(guard);i++){
  
    if(guard[i]->query_leader()==target)
     return notify_fail(guard[i]->name()+"������һ�ۣ���ͣס���ֽţ�\n");
  }
  
  message_vision(YEL"$N�������㣬��$n���˹�ȥ��\n"NOR,ob,target);
  message_vision(RED"$N���Ӳ��˼�����ҡ����һ�£�\n"NOR,target);
  target->unconcious();

  return 1;
}
