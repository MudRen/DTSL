
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("����",({ "liao shan","liao","shan"}));
   set("gender", "����" );
   set("age", 40);
   set("long", "����һλ��Ŀ���ƵĴ�ʦ��\n");
   set("class","bonze"); 
   set("combat_exp",1500000);
  
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("staff",200);
   set_skill("cuff",200);
   set_skill("finger",200);
   set_skill("strike",200);
   
   set_skill("tiangang-quan",200);
   set_skill("fumo-zhangfa",200);
   set_skill("dujie-zhi",200);
   set_skill("rulai-shenzhang",200);
   set_skill("lianhua-step",200);
   
   set_skill("literate",200);
   set_skill("chanzong-fofa",210);
   set_skill("wuxiang-shengong",200);
   set_skill("bikouchan",200);
   set_skill("war-heal",200);
 
   set("max_gin",3000);
   set("max_sen",3000);
   set("max_kee",3000);
   set("max_force",3000);
   set("force",3000);
   
   create_family("������Ժ",3,"��ʦ");
  
   setup();
  
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
   if(skill!="war-heal") return 1;
   return 0;
 
}