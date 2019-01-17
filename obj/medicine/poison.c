
inherit ITEM;
#include <ansi.h>
int do_tu(string arg);
int do_xiadu();
int do_xishi(string arg);
void create()
{
        set_name("������ҩ", ({ "poison" }) );
        set_weight(10);
        set("medicine_class","poison");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
		set("long","����һö��ҩ��\n");
		
              	              
        }      
        setup();
}

void init()
{
   add_action("do_tu","tu");
   add_action("do_xiadu","xiadu");
   add_action("do_xishi","xishi");
}

int do_tu(string arg)
{
   object me,ob;
   
   me=this_player();
   if(!arg)
   return notify_fail("��Ҫ��ʲô������ͿĨ��"+query("name")+"����\n");
   if(!objectp(ob=present(arg,me)))
   return notify_fail("������û�����������\n");
   if(ob==this_object())
   return notify_fail("������û���ɣ���\n");
   if(ob->is_character())
   return notify_fail("�㿴������Ǹ�������Ϳ��ҩ�𣿣�\n");
   if(me->query("pker"))
   return notify_fail("ͨ����������ʵһ��ɣ�\n");
   if(ob->query("skill_type")&&!ob->query("poison_flag"))
   return notify_fail(ob->query("name")+"���ǿ���ͿĨ��ҩ��ı������޷�������ͿĨ��ҩ��\n");
   if(ob->query("skill_type")&&me->query("vocation")!="ɱ��")
   return notify_fail("ֻ��ɱ�����������Ϳ����\n");
   message_vision("$N��"+ob->query("name")+"ͿĨ��Щ"+query("name")+"��\n",
      me);
   ob->set("poison",query("heal_up"));
   destruct(this_object());
   return 1;
}

int do_xiadu()
{
   object ob;
   
   ob=this_player();
   if(ob->query("pker"))
   return notify_fail("ͨ����������ʵһ��ɣ�\n");
   message_vision("$N�ڵ�������Щ"+query("name")+"��\n",ob);
   environment(ob)->set("poison",query("heal_up"));
   destruct(this_object());
   return 1;
}

int do_xishi(string arg)
{
  object ob,corpse;
   
   ob=this_player();
  if(query("name")!="��ʬ��")
  return notify_fail("ֻ����ʬ�ۿ��Դ�ʬ������������\n");
  if(!arg)
  return notify_fail("��Ҫ��ʲô��������[��ʬ��]��\n");
  if(!objectp(corpse=present(arg,environment(ob))))
  return notify_fail("���Ա�û�����������\n");
  if(!corpse->is_corpse())
  return notify_fail("�Ǹ���������ʬ�壬����������\n");
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  if(ob->is_fighting())
  return notify_fail("���ȴ�������˵�ɣ�\n");
  if(ob->query("force")<ob->query_skill("poison",1))
  return notify_fail("���������������ʬ��\n");
  if(ob->query_skill("poison",1)<80)
  return notify_fail("��Ķ����������޷�������ʬ��\n");
  if(ob->query_skill("poison",1)>=ob->query_int()*10)
  return notify_fail("��Ķ����Ѿ�ѧ���˾�ͷ���޷��ټ�������ˣ�\n");
  message_vision("$N����ʬ��������ʬ��֮�ϣ����ư�����ʬ���ϡ�\n",ob);
  tell_object(ob,HIR"���ʬ���ϲ�����ȡ����֮�������ö�����Щ�����ˣ�\n"NOR);
  tell_object(environment(ob),"ֻ��ʬ�������ػ�����Ѫˮ��\n");
  ob->start_busy(random(2));
  ob->add("force",-ob->query_skill("poison",1));
  ob->improve_skill("poison",ob->query_int());
  add("use_times",1);
  destruct(corpse);
  if(query("use_times")>=ob->query_skill("poison",1)/10)
   destruct(this_object());
  return 1;
}