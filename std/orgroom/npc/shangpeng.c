
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("����",({ "shang peng","shang","peng" }) );
   set("gender", "����" );
   set("age", 42);
   set("long", "���Ƕ����ɵĵ��ӡ�\n");
       
   set("combat_exp",1000000);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("hammer",200);
  
   set_skill("dongming-xinfa",200);
   set_skill("bihai-force",200);
   set_skill("leiting-chuifa",200);
   set_skill("nishang-piaoming",200);
   set_skill("literate",200);
   set_skill("junxie-xue",200);
   
   set("max_gin",3000);
   set("max_sen",3000);
   set("max_kee",3000);
   set("force",3000);
   set("max_force",3000);
   create_family("������",3,"����");
      
   setup();
   carry_object("/d/dongming/npc/obj/hammer")->wield();
  
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
   if(skill!="junxie-xue") return 1;
   return 0;
 
}