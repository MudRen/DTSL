

inherit NPC;

void create()
{
        set_name("����",({ "monkey","hou" }) );
        set("gender", "����" );
		set("race","Ұ��");
        set("age", 13);
        set("long", "����һҰ���ӡ�\n");
        set("kee",200);
		set("gin",200);
		set("sen",200);
        set("limbs",({"ͷ","β��","צ��"}));
       
		set("apply/attack",5);
		set("apply/parry",5);
	set("shen_type", 1);
	set("shen", 3000);
       
        set("combat_exp", 120000);
        
		
		set("hand",({"zhua"}));
        set_skill("zhua",10);
		
	
	
        setup();

        
}

