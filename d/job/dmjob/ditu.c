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
		set("long", "����һ������ɽƽ��ֲ�ͼ.\n");
		set("unit", "��");
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
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
  object killer,killer2;
  object thing;
  
  ob=this_player();
  if(!ob->query_temp("dm_job_find"))
  return notify_fail("���ŵ�ͼ������˵ûʲô�ô���\n");
  here=base_name(environment(ob));
  if(here!=ob->query_temp("dm_job_find_where"))
  return notify_fail("�����ŵ�ͼ���˿������ֵ����������ڴ˴�����\n");
  if(ob->query_temp("have_killer"))
  return notify_fail("���ͣ�����!!!\n");
  killer=new(__DIR__"killer");
 killer->set("combat_exp",ob->query("combat_exp"));
 set_all_skill(killer,ob->query("max_pot")-120);
 copy_hp_item(ob,killer,"gin");
 copy_hp_item(ob,killer,"kee");
 copy_hp_item(ob,killer,"sen");
 killer->set("max_force",ob->query("max_force"));
 killer->set("force",ob->query("max_force"));
 if(ob->query("combat_exp")>=500000){
 killer2=new(__DIR__"killer");
 killer2->set("combat_exp",ob->query("combat_exp"));
 set_all_skill(killer2,ob->query("max_pot")-100);
 copy_hp_item(ob,killer2,"gin");
 copy_hp_item(ob,killer2,"kee");
 copy_hp_item(ob,killer2,"sen");
 killer2->set("max_force",ob->query("max_force"));
 killer2->set("force",ob->query("max_force"));
 killer->improve_level();
 killer2->improve_level();}
  killer->set("target_id",ob->query("id"));
  killer->move(environment(ob));
  if(objectp(killer2)){
  killer2->set("target_id",ob->query("id"));
  killer2->move(environment(ob));}
  ob->set_temp("have_killer",1);
  thing=new("/d/job/funjob/thing");
  thing->set("dm_find_job",1);
  thing->set("no_give",0);
  thing->set("no_sell",0);
  thing->set("no_drop",0);
  thing->set("no_get",0);
  thing->set("baowu",0);
  thing->set("owner",ob);
  thing->move(killer);
  message_vision(HIR"\n$NͻȻ�����������$n"+HIR+"��Ц������Ȼ���㷢�֣�Ҳֻ��ƴ���ˣ���\n\n"NOR,killer,ob);
  killer->kill_ob(ob);
  if(objectp(killer2))
  killer2->kill_ob(ob);
  call_out("drop_map",1,ob);
  return 1;
}

void drop_map(object ob)
{
  message_vision("$Nһ����ң����е�$n�����˵��ϡ�\n",ob,this_object());
  destruct(this_object());
  return;
}