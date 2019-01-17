
inherit NPC;

void create()
{
        set_name("��ͷ", ({"bu tou","bu","tou"}));
        set("gender", "����");
        set("age", 34);
        set("long","���������ǵĲ�ͷ,�⼸�������Ǻ�æ.\n");
        set("str", 26);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 300); 
        set("max_kee", 300);
        set("gin", 300);
        set("max_gin", 300);
        set("sen",300);
        set("max_sen",300);
		set("force",300);
		set("max_force",300);
        set("combat_exp",90000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
		set_skill("cuff",70);
		set_skill("force",70);
		
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/damage", 40);
		set("chat_chance",10);
		set("chat_msg",({
			(:random_move:),
		}));
       setup();
        carry_object(__DIR__"obj/cloth")->wear();
		
}

void init()
{
	object *ob,here,me;
	int i;
	me=this_object();
	here=environment(me);
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query("PKS")>=6)
			call_out("kill_pker",1,me,ob[i]);
	}
}

void kill_pker(object me,object pker)
{
	if(!objectp(me)||!objectp(pker)) {remove_call_out("kill_pker");return;}
	message_vision("\n$N��$n������:��ɱ�����̫����!\n",me,pker);
	me->set_leader(pker);
	me->kill_ob(pker);
	remove_call_out("kill_pker");
}