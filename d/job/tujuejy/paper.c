
inherit ITEM;
#include <ansi.h>
#include <job_money.h>

int do_action(string arg);

void create()
{
   set_name(HIW"����"NOR,({ "juan zhou","juan","zhou" }));    
   set("long", "����ͻ����������̽��Ӧ�ľ��ᡣ\n");       
  set("unit","��");
  set("no_get",1);
  set("no_give",1);
  set("no_drop",1);
   setup();
  
}
void init()
{
  add_action("do_action","jieying");
}

string *msg=({
"$N����$n��Ц���������ײ����������㵹ù����",
"$N���һ����ͻ�ʵ��߹����������ɱ���ˣ���",
"$N���˿���ĭ����$n�������������̽������������ɣ���",
});

int do_action(string arg)
{
  object ob,target;
  string pass,name;
  
  ob=this_player();
  
  if(!arg||sscanf(arg,"%s with %s",pass,name)!=2)
  return notify_fail("��Ҫ��ʲô���ź�˭��Ӧ��\n");
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("����û������ˣ�\n");
  if(target->query("target")!=ob)
  return notify_fail("�ⲻ����Ҫ��Ӧ��Ŀ�꣡\n");
  
  if(target->query("pass_ok"))
  return notify_fail(target->name()+"�������������Ѿ��Թ��ˣ�����һض���ɣ�\n");
  
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  
  if(!living(target))
  return notify_fail("���ȰѶԷ�Ū�Ѱɣ�\n");
  
  if(pass!=query("pass")){
  
  tell_object(ob,"\n�㳯"+target->name()+"����˵����"+HIY+pass+NOR"��\n");
  tell_object(ob,"\n"+target->name()+"���ɻ�ؿ����㡣\n");
  ob->start_busy(3);//��ֹ������
  return 1;}
  
  tell_object(ob,"\n�㳯"+target->name()+"����˵����"+HIY+pass+NOR"��\n");
  tell_object(ob,"\n"+target->name()+"����˵����ԭ�����Լ��ˣ�\n");
  message("vision",ob->name()+"��"+target->name()+"����˵�˼��仰��\n",
        environment(ob),ob);
  
  target->set("pass_ok",1);
  
  target->set_leader(ob);
  tell_object(ob,"\n"+target->name()+"����������һ���ж���\n");
  
  call_out("killer_come",30+random(10),ob,target);
  return 1;
}

void killer_come(object ob,object target)
{
   object killer;
   
   if(!ob||!target)
    return;
   
   killer=new(__DIR__"killer");
   killer->set_status(ob);
   
   tell_object(ob,BLU"\nͻȻһ��ɱ����"+target->name()+"Ϯȥ����\n\n"NOR);
   killer->move(environment(target));
   message_vision("\n"+msg[random(sizeof(msg))]+"\n\n",killer,target);
   
   copy_hp_item(ob,target,"kee",3/2);
   ob->add_temp_array("job_temp_killer",killer);
   killer->kill_ob(target);
   return;
}
   
   