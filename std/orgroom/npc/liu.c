
#include <ansi.h>

inherit NPC;

void create()
{
	
   set_name("����",({ "liu shang","liu" }) );
   set("gender", "Ů��" );
   set("age", 23);
   set("long", "���ǴȺ���ի�����ѡ�\n");
       
   set("combat_exp",1000000);
   set("int", 30);
   set("per", 30);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("max_force",3000);
   set("force",3000);
   set_skill("sword",200);
   set_skill("parry",200);
   set_skill("dodge",200);
   set_skill("finger",200);
   set_skill("literate",200);
   set_skill("force",200);
   set_skill("sekong-jianfa",200);
   set_skill("xiuluo-zhi",200);
   set_skill("wuwang-jing",210);
   set_skill("qingxin-force",200);
   set_skill("lingyun-shenfa",200);
   set_skill("dadao-qishu",200);
  
   create_family("�Ⱥ���ի",4,"����");
  
   setup();
  
   carry_object("/d/jingzhai/npc/obj/changjian")->wield();
  
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
   if(skill!="dadao-qishu") return 1;
   return 0;
 
}