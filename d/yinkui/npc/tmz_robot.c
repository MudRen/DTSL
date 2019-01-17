
inherit NPC;

void create()
{
   set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );		
   set("long", "����һ��ľ�ˣ������÷ǳ����ɣ���ͬ����һ�㡣\n");     
   set("combat_exp",800000);
   set("tmz_robot",1);
   setup();

}

void fight_ob(object ob)
{
   message_vision("\nֻ����֨��֨������$N��$n������\n",this_object(),ob);
   return ::fight_ob(ob);
}

void die()
{
   set("eff_kee",query("max_kee"));
   set("kee",query("max_kee"));
   
   set("eff_gin",query("max_gin"));
   set("gin",query("max_gin"));
   
   set("eff_sen",query("max_sen"));
   set("sen",query("max_sen"));
   message_vision("\nֻ����֨��֨������$Nͣ��������\n",this_object());
   return;
}

void unconcious()
{
  set("eff_kee",query("max_kee"));
   set("kee",query("max_kee"));
   
   set("eff_gin",query("max_gin"));
   set("gin",query("max_gin"));
   
   set("eff_sen",query("max_sen"));
   set("sen",query("max_sen"));
   message_vision("\nֻ����֨��֨������$Nͣ��������\n",this_object());
   return;
}

void give_reward(object ob)
{
   int reward;
   
   reward=ob->query("potential");
   
   if(reward<=0){
     tell_object(ob,"���Ǳ�ܲ��㣬ʲôҲ���򲻵���\n");
     return;
   }
   reward=reward*ob->query_int();
   
   ob->improve_skill("tianmo-zhen",reward);
   tell_object(ob,"���ս����������һЩ��ħ��\n");
   ob->set("potential",0);
   return;
}

int surrender(object killer,object victim)
{
   set("eff_kee",query("max_kee"));
   set("kee",query("max_kee"));
   
   set("eff_gin",query("max_gin"));
   set("gin",query("max_gin"));
   
   set("eff_sen",query("max_sen"));
   set("sen",query("max_sen"));
   message_vision("\nֻ����֨��֨������$Nͣ��������\n",this_object());
   killer->add_temp("fight_tmz_robot",1);
   if(killer->query_temp("fight_tmz_robot")>=4){
     killer->delete_temp("fight_tmz_robot");
     give_reward(killer);
   }
   return 1;
}

int is_end_fight(object ob)
{
 
  return 1;
     
}
