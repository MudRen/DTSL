inherit ITEM;
#include <job_money.h>
#include <ansi.h>

int do_find(string arg);

void create()
{
	set_name("��ͼ",({"map"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ŵ�ͼ��\n");
		set("unit", "��");
		set("no_save",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);
	 }
}
void init()
{
  add_action("do_find","soucha");
}
int do_find(string arg)
{
  object ob;string here;
  object killer;
  ob=this_player();
  
  if(query("target_name"))
   if(!arg||arg!=query("target_name"))
    return notify_fail("��Ҫ�Ѳ�˭����\n");
  
  here=base_name(environment(ob));
  if(here!=query("place"))
  return notify_fail("�����ŵ�ͼ���˿�������Ŀ���û�ĵط������Ǵ˴���\n");
  
  killer=new(query("target_npc"));
 killer->set("combat_exp",ob->query("combat_exp")*query("exp_lev"));
 
 set_all_skill(killer,ob->query("max_pot")-query("skill_lev"));
 copy_hp_item(ob,killer,"gin",query("hp_lev"));
 copy_hp_item(ob,killer,"kee",query("hp_lev"));
 copy_hp_item(ob,killer,"sen",query("hp_lev"));
 copy_force(ob,killer,query("force_lev"));
 
 killer->set("reward_exp",query("reward_exp"));
 killer->set("reward_pot",query("reward_pot"));
 
  killer->set("target_id",ob->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->set("last",time());
  killer->move(environment(ob));
  ob->start_busy(1);
  message_vision(query("kill_msg"),killer,ob);
  killer->kill_ob(ob);
  ob->add_temp_array("job_temp_killer",killer);
  message_vision("\n$N��һ�ţ���ͼ�����˵��ϣ�\n",ob);
  destruct(this_object());
  return 1;
}
