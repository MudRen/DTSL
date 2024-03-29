// /clone/npc/party_npc.c
// Created by lane@SJ

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("门派弟子", ({ "menpai dizi", "dizi", "npc" }));
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("str", 10+random(20));
	set("int", 10+random(20));
	set("con", 10+random(20));
	set("dex", 10+random(20));
	set("no_get","这人对你而言太重了。");
	set("no_bark",1);
	set("no_ansuan",1);

	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 20);
	set("combat_exp", 500000);

	set_skill("literate", 200);
	set_skill("strike", 300);
	set_skill("cuff", 300);
	set_skill("hand", 300);
	set_skill("dodge", 300);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("hammer", 300);
	set_skill("stick", 300);
	// set_skill("club", 300);
	set_skill("staff", 300);
	set_skill("whip", 300);
	set_skill("dagger", 300);
	set_temp("apply/armor", 60);

	setup();
        carry_object("/clone/armor/shuikao")->wear();
}

void die()
{
	object me;
	me = query("master_user/user");

	if( me ) me->delete_temp("zhaoji_npc");

	if( !me || environment(me) != environment(this_object()) )
		message_vision("$N突然向后一跃，匆匆忙忙的离开了。\n", this_object());

	if( !living(me) ) {
		message_vision("$N大叫一声：“不好”，背起$n夺路而逃。\n", this_object(), me);
		me->move("/d/xiangyang/damen");
		if( me->query("eff_qi") < 1 ) me->set("eff_qi",1);
	} else 	if( !me->is_fighting() || !this_object()->is_fighting() )
		message_vision("$N对$n鞠了个躬道：“代掌门，卑侄还要要事在身，先行告退了！”\n说完便匆匆忙忙的离开了。\n", this_object(), me);

	destruct(this_object());
}

void unconcious(){ die(); }

void set_master_player(object ob)
{
	object weapon;
        mapping hp_status, skill_status, map_status, prepare_status;
	string fam;
        string *sname, *mname, *pname;
	int i;

	fam = ob->query("family/family_name");

// copy misc

	set("family/family_name", fam);
	set("master_user/user", ob);
	set("age", ob->query("age")*2/3);
	set("gender", ob->query("gender"));

	if( fam == "大轮寺" ) {
		set_name("雪山弟子", ({ "xueshan dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "longxiang" :),
 			(: exert_function, "shield" :),
		}));
	}
	if( fam == "峨嵋派" ) {
		set_name("峨嵋女弟子", ({ "emei dizi", "dizi" }) );
		set("gender", "女性");
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "fengyun" :),
 			(: exert_function, "riyue" :),
 			(: exert_function, "tiandi" :),
 			(: exert_function, "wuwo" :),
 			(: exert_function, "yinyang" :),
 			(: exert_function, "youming" :),
 			(: exert_function, "zhixin" :),
		}));
	}
	if( fam == "姑苏慕容" ) {
		set_name("慕容门人", ({ "murong menren", "menren" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "shenyuan" :),
		}));
	}
	if( fam == "古墓派" ) {
		set_name("古墓弟子", ({ "gumu dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "xinjing" :),
		}));
	}
	if( fam == "华山派" ) {
		set_name("华山弟子", ({ "huashan dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "zixia" :),
		}));
	}
	if( fam == "明教" ) {
		set_name("明教教众", ({ "mingjiao jiaozhong", "jiaozhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "jiuyang" :),
		}));
	}
	if( fam == "少林派" ) {
		set_name("少林弟子", ({ "shaolin dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "jingang" :),
		}));
	}
	if( fam == "神龙教" ) {
		set_name("神龙教弟子", ({ "shenlong dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "wudi" :),
 			(: exert_function, "shexin" :),
		}));
	}
	if( fam == "桃花岛" ) {
		set_name("桃花岛门人", ({ "taohuadao menren", "menren" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "qimen" :),
 			(: exert_function, "maze" :),
		}));
	}
	if( fam == "天龙寺" ) {
		set_name("天龙寺弟子", ({ "tianlong dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "ku" :),
 			(: exert_function, "rong" :),
 			(: exert_function, "kong" :),
 			(: exert_function, "xinjing" :),
		}));
	}
	if( fam == "铁掌帮" ) {
		set_name("铁掌帮众", ({ "tiezhang bangzhong", "bangzhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "juli" :),
		}));
	}
	if( fam == "武当派" ) {
		set_name("武当派弟子", ({ "wudang dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "taiji" :),
 			(: exert_function, "yinyun" :),
		}));
	}
	if( fam == "星宿派" ) {
		set_name("星宿弟子", ({ "xingxiu dizi", "dizi" }) );
 		set("chat_chance_combat", 40);
 		set("chat_msg_combat", ({
 			(: exert_function, "huadu" :),
 			(: exert_function, "huagong" :),
 			(: exert_function, "huajing" :),
 			(: exert_function, "judu" :),
		}));
	}
	if( fam == "丐帮" ) {
		set_name("丐帮帮众", ({ "gaibang bangzhong", "bangzhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "huntian" :),
 			(: exert_function, "shentong" :),
		}));
	}
	if( fam == "嵩山派" ) {
		set_name("嵩山弟子", ({ "songshan dizi", "dizi" }) );
 		set("chat_chance_combat", 80);
 		set("chat_msg_combat", ({
 			(: exert_function, "hanbing" :),
 			(: exert_function, "huti" :),
 			(: exert_function, "juhan" :),
		}));
	}
	if( fam == "昆仑派" ) {
		set_name("昆仑弟子", ({ "kunlun dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "riyue" :),
 			(: exert_function, "taxue" :),
		}));
	}

// copy skills

        if( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        set_skill(sname[i], skill_status[sname[i]]);
                }
        }

        command("jifa all");

// copy skill maps

        if( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        map_skill(mname[i], map_status[mname[i]]);
                }
        }


// copy skill prepares

        if( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

// copy hp

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);

        set("max_qi",    hp_status["max_qi"]);
        set("eff_qi",    hp_status["max_qi"]);
        set("qi",        hp_status["max_qi"]);
        set("max_jing",  hp_status["max_jing"]);
        set("eff_jing",  hp_status["max_jing"]);
        set("jing",      hp_status["max_jing"]);
        set("max_neili", hp_status["max_neili"]);
        set("eff_jingli", hp_status["max_jingli"]);
        set("max_jingli", hp_status["max_jingli"]);
        set("jingli",     hp_status["max_jingli"]);
        set("neili",     hp_status["max_neili"]);
        set("jiali",     ob->query_skill("force")/5);
        if( query("jiali") > 200 ) set("jiali", 200 );
        set("combat_exp",hp_status["combat_exp"]);

// copy weapon

	if( objectp(weapon = ob->query_temp("weapon")) ) {

		if( weapon->query("skill_type") == "sword" )
			carry_object("/clone/weapon/changjian")->wield();
		if( weapon->query("skill_type") == "blade" )
			carry_object("/clone/weapon/blade")->wield();
		if( weapon->query("skill_type") == "axe" )
			carry_object("/clone/weapon/axe")->wield();
		if( weapon->query("skill_type") == "brush" )
			carry_object("/clone/weapon/brush")->wield();
		if( weapon->query("skill_type") == "club" )
			carry_object("/clone/weapon/club")->wield();
		if( weapon->query("skill_type") == "dagger" )
			carry_object("/clone/weapon/dagger")->wield();
		if( weapon->query("skill_type") == "hammer" )
			carry_object("/clone/weapon/hammer")->wield();
		if( weapon->query("skill_type") == "hook" )
			carry_object("/clone/weapon/hook")->wield();
		if( weapon->query("skill_type") == "spear" )
			carry_object("/clone/weapon/spear")->wield();
		if( weapon->query("skill_type") == "staff" )
			carry_object("/clone/weapon/staff")->wield();
		if( weapon->query("skill_type") == "stick" )
			carry_object("/clone/weapon/stick")->wield();
		if( weapon->query("skill_type") == "whip" )
			carry_object("/clone/weapon/whip")->wield();
		if( weapon->query("skill_type") == "throwing" )
			carry_object("/clone/weapon/feihuangshi")->wield();
	}

}

void heart_beat()
{
	int i;
	object me;
	object *ob;

	me = query("master_user/user");
	if (!objectp(me))
	{
		return;
	}

	if(!me->is_fighting()
	 || !living(me)  || environment(me) != environment(this_object()) ) {
		die();
		return;
	}

	ob = all_inventory(environment(me));

	for( i=0; i<sizeof(ob); i++ ) {
		if( !living(ob[i]) || ob[i] == me ) continue;
		if( userp(ob[i]) ) continue;
		if( !ob[i]->is_fighting(me) ) {
			ob[i]->remove_killer(this_object());
			remove_killer(ob[i]);
		} else {
			ob[i]->kill_ob(this_object());
			fight_ob(ob[i]);
		}
	}

	if( !is_fighting() ) {
		die();
		return;
	}
	::heart_beat();
}
