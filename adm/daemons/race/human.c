// human.c
//datang-shuanglong
// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
        ([      "action":               "$N��ȭ����$n��$l",
                "force":10,
                "dodge":10,
                "parry":10,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��$n��$lһץ",
                "force":10,
                "dodge":10,
                "parry":10,
                "damage_type":  "ץ��",
        ]),
        ([      "action":               "$N��$n��$l�ݺݵ�����һ��",
                "force":10,
                "dodge":10,
                "parry":10,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N����ȭͷ��$n��$l��ȥ",
                "force":10,
                "dodge":10,
                "parry":10,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
                "force":10,
                "dodge":10,
                "parry":10,
                "damage_type":  "����",
        ]),
});

void create()
{
        seteuid(getuid());
        set("unit", "λ");
        set("gender", "����");
        set("can_speak", 1);
        set("attitude", "peaceful");
        set("limbs", ({
                "����", "����", "�ʺ�", "ǰ��", "����", "���", "�Ҽ�", 
                "���", "�ұ�", "����", "С��", "����", "����", "ü��",
                "��"
        }));
}

void setup_human(object ob)
{
	mapping my;
	int i;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
	if(undefinedp(my["age"])) my["age"] = random(30) + 15;

	if(undefinedp(my["str"])) my["str"] = random(11) + 15;        
	if(undefinedp(my["int"])) my["int"] = random(11) + 15;
	if(undefinedp(my["per"])) my["per"] = random(11) + 15;
	if(undefinedp(my["con"])) my["con"] = random(11) + 15;
    if(undefinedp(my["kar"])) my["kar"] = random(15) + 15;
	if(undefinedp(my["dex"])){
    	if(!undefinedp(my["cor"])){
        	my["dex"]=my["cor"];
        	my["cor"]=0;
    	}
    	else my["dex"] = random(11) + 15;
	}  //this is a change DT1 TO DT2
           
 	 

	if(userp(ob) || undefinedp(my["max_gin"])){
		if(my["age"] <= 12) 
			my["max_gin"] = 100+(my["age"] - 10)*30;
   		else 
   		if(my["age"] <= 20) 
			my["max_gin"] = 160 + (my["age"] - 12) * 40;
   		else 
   		if(my["age"] <= 30) 
			my["max_gin"] = 480+ (my["age"] - 20) * 40;
		else 
		if(my["age"] <= 60) 
			my["max_gin"] = 880 + (my["age"] - 30) * 36;
		else 
			my["max_gin"] = 300+(my["age"] -60) *25;               
	}

	if(userp(ob) || undefinedp(my["max_sen"])){
		if(my["age"] <= 12) 
			my["max_sen"] =100;
		else 
		if(my["age"] <= 20) 
			my["max_sen"] = 100 + (my["age"] - 12) * 15;
		else 
		if(my["age"] <= 30) 
			my["max_sen"] = 220+ (my["age"] - 20) * 20;
		else 
		if(my["age"] <= 60) 
			my["max_sen"] = 420 + (my["age"] - 30) * 25;
		else  
			my["max_sen"] =300 + (my["age"] -60) * 25;
		my["max_sen"]+=my["max_sen_add"];
	}

	if(userp(ob) || undefinedp(my["max_kee"])){
		if(my["age"] <= 12) 
			my["max_kee"] = 100+(my["age"] - 10)*30;
		else 
		if(my["age"] <= 20) 
			my["max_kee"] = 160 + (my["age"] - 12) *55;
		else 
		if(my["age"]<=30)
			my["max_kee"] =600+(my["age"] - 20) *60;
		else 
		if(my["age"]<=60)
			my["max_kee"] =1200+(my["age"] - 30) *65;
		else  
			my["max_kee"] =500+(my["age"] - 60) *30;               
	}

	if(userp(ob) || undefinedp(my["max_apply_points"])){
    	int exp;
    	exp=ob->query("combat_exp");
    	for(i=0;i*i*i<exp*3;i++);
    		my["max_apply_points"] =i;                      
	}


	ob->set_default_object(__FILE__);
	if(!ob->query_weight()) 
		ob->set_weight(BASE_WEIGHT + (my["str"]) * 2000);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
