
inherit NPC;

#include <ansi.h>


void create()
{
   
   
   set_name("����",({ "lei ling","lei","ling" }) );
   set("gender", "����" );
	
   set("age",46);
   set("long", "���������ɵĵ��ӡ�\n");
       
   set("combat_exp",1000000);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("strike",200);
   set_skill("qianbian-tongxiao",200);
   set_skill("sword",200);
   set_skill("literate",200);
   set_skill("tianmo-dafa",200);
   set_skill("tianmo-jue",200);
   set_skill("tianmo-huanzong",200);
   set_skill("wuxing-qishu",200);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
  
   create_family("������",3,"����");
  
   setup();
   
   carry_object("/d/yinkui/npc/obj/changjian")->wield();
  
}

int is_apprentice_of(object ob)
{
	
	return 1;
}

int recognize_apprentice(object ob)
{
        return 1;
        
}

int prevent_learn(object ob,string skill)
{
   if(skill!="wuxing-qishu") return 1;
   return 0;
 
}