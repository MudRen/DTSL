inherit ITEM;
#include <job_money.h>
#include <ansi.h>
int do_find();
void create()
{
	set_name("��ͼ",({"map"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�Ÿ������е�ƽ��ֲ�ͼ.\n");
		set("unit", "��");
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);
	 }
}
void init()
{
  add_action("do_find","soucha");
}
int do_find()
{
  object ob;string here;
  object killer;
  ob=this_player();
  if(!ob->query_temp("gaoli_kill_job"))
  return notify_fail("�㿴�˿���ͼ��û����ʲô����Ķ�����\n");
  here=base_name(environment(ob));
  if(here!=query("here"))
  return notify_fail("�����ŵ�ͼ���˿������ֵ�����û�ĵط������Ǵ˴���\n");
  if(ob->query_temp("have_killer"))
  return notify_fail("���ͣ�����!!!\n");
  killer=new(__DIR__"killer");
 killer->set("combat_exp",ob->query("combat_exp"));
 if("/cmds/usr/hp.c"->get_pot(killer));
 set_all_skill(killer,killer->query("max_pot")-130);
 copy_hp_item(ob,killer,"gin");
 copy_hp_item(ob,killer,"kee");
 copy_hp_item(ob,killer,"sen");
 killer->set("max_force",ob->query("max_force"));
 killer->set("force",ob->query("max_force"));
 if(ob->query("combat_exp")>=500000)
 killer->improve_level();
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("shili");
  killer->set_name("����",({"killer"}));
  killer->set("target_id",ob->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  ob->start_busy(1);
  ob->set_temp("have_killer",1);
  message_vision(HIR"$NͻȻ�����������$n��Ц������Ȼ���㷢�֣�Ҳֻ��ƴ���ˣ���\n"NOR,killer,ob);
  killer->kill_ob(ob);
  message_vision("\n$N��һ�ţ���ͼ�����˵��ϣ�\n",ob);
  destruct(this_object());
  return 1;
}
