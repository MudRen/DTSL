#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_search(string arg);
void create()
{
   set_name(HIR"��ɱ��"NOR, ({ "paper"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�ż�ɱ��������(search)�����ҷ��ˡ�\n");
     set("material", "��ֽ");
     set("unit", "��");
     set("value", 0);
     set("no_sell",1);
     set("no_steal",1);
     set("no_drop",1);
     set("no_give",1);
  }
   setup();
}

void init()
{
   add_action("do_search","search");
}

int do_search(string arg)
{
  object ob,killer;int flag;
  
  ob=this_player();
  if(!arg||arg!="����ʤ")
  return notify_fail("��Ҫ�Ѳ�ʲô�ˣ�\n");
  if(!ob->query_temp("shang_kill_pantu"))
  return notify_fail("��û���ʸ�����ɱ����ʤ��\n");
  if(ob->query_temp("shang_kill_pantu/where")!=base_name(environment(ob)))
  return notify_fail("�������һ�ᣬ��������ʤ���������\n");
  if(query("no_search"))
  return notify_fail("���ͣ����ͣ�\n");
  set("no_search",1);
  killer=new(__DIR__"killer");
  killer->set("combat_exp",ob->query("combat_exp"));
  if("/cmds/usr/hp.c"->get_pot(killer));
  copy_hp_item(ob,killer,"kee");
  copy_hp_item(ob,killer,"gin");
  copy_hp_item(ob,killer,"sen");
  killer->set("max_force",ob->query("max_force"));
  killer->set("force",ob->query("max_force"));
  set_all_skill(killer,ob->query("max_pot")-100);
  killer->set("target_id",ob->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIW"$NͻȻ����Ծ������$n�ȵ�����Ȼ���㷢�֣�ֻ��ɱ������ˣ�\n"NOR,
                 killer,ob);
  killer->kill_ob(ob);
  message_vision("$N˳���ӵ���"+query("name")+"��Ŀ��ת���ض���$n���ж���\n",
                 ob,killer);
  destruct(this_object());
   return 1;
}