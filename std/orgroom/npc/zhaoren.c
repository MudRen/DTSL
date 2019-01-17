
inherit NPC;

#include <ansi.h>

void create()
{
   
   set_name("ÕÔÈÌ",({ "zhao ren","zhao","ren" }) );
   set("gender", "ÄÐÐÔ" );		
   set("age", 30);
   set("combat_exp",1000000);

   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("blade",200);
   set_skill("literate",200);

   set_skill("yanyang-dafa",200);
   set_skill("canglang-jue",200);
   set_skill("kuangsha-daofa",200);
   set_skill("youlong-shenfa",200);
   set_skill("qianjun-shu",200);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   create_family("Í»ØÊ",3,"ÎäÊ¿");
   
   setup();
  
   carry_object("/d/tujue/obj/blade")->wield();  
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
   if(skill!="qianjun-shu") return 1;
   return 0;
 
}