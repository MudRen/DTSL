
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("�λ�",({ "song hui","song","hui" }) );
   set("gender", "����" );
 
   set("age", 48);
   set("long", "�����μұ��ĵ��ӡ�\n");
       
   set("combat_exp",1000000);
   set("str", 28);
   set("per", 25);
   
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   
   set_skill("dijian-jue",200);   
   set_skill("anxiang-fuying",200);
   set_skill("tiangang-sanjue",200);
   set_skill("wangdao-jue",200);
   set_skill("literate",200);
   set_skill("zhencha-shu",200);
  
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   create_family("�μұ�",3,"����");
  
   setup();
   carry_object("/d/lingnan/npc/obj/changjian")->wield();
  
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
   if(skill!="zhencha-shu") return 1;
   return 0;
 
}