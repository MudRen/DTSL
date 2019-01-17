
// chard.c

#include <race.h>
#include <skill.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
	string race;int pot,max_pot;
	mapping my;

	if( !stringp(race = ob->query("race")) ) {
		race = "����";
		ob->set("race", "����");
	}
     
	switch(race) {
		case "������":
		case "����":
        	HUMAN_RACE->setup_human(ob);
        	break;
		case "��ħ":
        	MONSTER_RACE->setup_monster(ob);
        	break;
     	case "Ұ��":
	 	case "����":
        	BEAST_RACE->setup_beast(ob);
        	break;
     	default:
        	error("Chard: undefined race " + race + ".\n");
	}
   
	my = ob->query_entire_dbase();

	if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
	if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
	if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

	if(undefinedp(my["eff_gin"])) my["eff_gin"] = my["max_gin"];
	if(undefinedp(my["eff_kee"])) my["eff_kee"] = my["max_kee"];
	if(undefinedp(my["eff_sen"]) ) my["eff_sen"] =my["max_sen"];
	//if(my["max_sen"]<my["eff_sen"]) my["max_sen"]=my["eff_sen"];

	if(my["max_sen"]>100)
		my["max_gin"]+=my["max_sen"]/4;
	if(my["max_force"] > 0) 
		my["max_kee"] += my["max_force"] / 2;
		
	if(ob->query_skill("qingxin-force",1)>0)
		my["max_kee"] += ob->query_skill("qingxin-force",1)/2;
	else
	if(ob->query_skill("wuxiang-shengong",1)>0)
		my["max_kee"] += ob->query_skill("wuxiang-shengong",1)/2;
	else
	if(ob->query_skill("flower-force",1)>0)
		my["max_kee"] += ob->query_skill("flower-force",1)/2;
	else
	if(ob->query_skill("tianmo-dafa",1)>0)
		my["max_kee"] += ob->query_skill("tianmo-dafa",1)/2;
	else
	if(ob->query_skill("yanyang-dafa",1)>0)
		my["max_kee"] += ob->query_skill("yanyang-dafa",1)/2;
	else
	if(ob->query_skill("bihai-force",1)>0)
		my["max_kee"] += ob->query_skill("bihai-force",1)/2;
	else
	if(ob->query_skill("jiuxuan-dafa",1)>0)
		my["max_kee"] += ob->query_skill("jiuxuan-dafa",1)/2;
	else
	if(ob->query_skill("tiangang-sanjue",1)>0)
		my["max_kee"] += ob->query_skill("tiangang-sanjue",1)/2;

	if(!userp(ob)){
		my["eff_gin"]=my["max_gin"];
		my["gin"]=my["max_gin"];
		my["eff_sen"]=my["max_sen"];
		my["sen"]=my["max_sen"];
		my["eff_kee"]=my["max_kee"];
		my["kee"]=my["max_kee"];
	}

	//if( !ob->query_max_encumbrance() )
	ob->set_max_encumbrance(ob->query_str()*10000 +
                    (int)ob->query_skill("unarmed",1)*200);
  
	if(my["potential"]>my["max_pot"]) my["potential"]=my["max_pot"];
  
	ob->reset_action(ob->query_temp("weapon"));
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		if(objectp(killer))
			inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}

	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name() + "��ʬ��", ({ "corpse" }) );
	corpse->set("dead_id",victim->query("id"));
	if(objectp(killer))
		corpse->set("killed_by",killer->query("id"));
	
	if(victim->query("long"))
		corpse->set("long", victim->query("long")
			+ "Ȼ����" + gender_pronoun(victim->query("gender")) 
			+ "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
	else
		corpse->set("long", victim->short(1)+"\n"
			+ "Ȼ����" + gender_pronoun(victim->query("gender")) 
			+ "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set("combat_exp",victim->query("combat_exp"));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	if(userp(victim))
		corpse->set("player_corpse",1);
	corpse->move(environment(victim));
   
   // Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ){
		inv = all_inventory(victim);
		if(objectp(killer))
			inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if(!inv[i]->query("save_box"))			
				inv[i]->move(corpse);
		}
	}

	return corpse;
}
