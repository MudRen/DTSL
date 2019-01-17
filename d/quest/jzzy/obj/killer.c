
inherit NPC;
void create()
{
       set_name("����ɱ��", ({ "killer"}) );
       set("gender", "����" );
       set("age",40);
       set("long","����һ������ɱ�֡�\n");
       set("combat_exp", 12500);
       set_skill("finger",100);
       set_skill("strike",100);
       set_skill("force",100);
       set_skill("parry",100);
       set_skill("dodge",100);
       
       set_skill("dujie-zhi",100);
       set_skill("xiuluo-zhi",100);
       set_skill("youyue-zhangfa",100);
       set_skill("nishang-piaoming",100);
       set_skill("tiangang-sanjue",100);
       set("chance_combat",50);
       set("chat_msg_combat",({
       	(:apply_action,"dujie-zhi",3,"damage":),
       	(:apply_action,"xiuluo-zhi",3,"parry":),       	
       	(:apply_action,"dujie-zhi",4,"dodge":),
       	(:apply_action,"xiuluo-zhi",2,"damage":),
       	}));
       setup();
 
}

void die()
{
  object ob;
  ob=query_temp("last_damage_from");
  if(!ob) return ::die();
  if(!ob->query_temp("dtsl_quest_jzzy/step3"))
  return ::die();
  ob->set_temp("dtsl_quest_jzzy/step4",1);
  ob->delete_temp("dtsl_quest_jzzy/step3");
  return ::die();
}