
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("��Ѫ",({ "li xue","li","xue"}) );
   set("gender", "����" );
   set("age", 36);
   set("long", "����һ����ʿ��\n");
   set("combat_exp",1000000);
   set("str", 28);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("strike",200);
   set_skill("busi-yin",200);
   set_skill("blade",200);
   set_skill("literate",200);
   set_skill("tianyi-xuangong",200);
   set_skill("huanmo-shenfa",200);
   set_skill("zhehua-baishi",200);
   set_skill("baihua-zhang",200);
   set_skill("liaoyuan-tianshu",200);
   
   set("max_gin",4000);
   set("max_sen",4000);
   set("max_kee",4000);
   set("max_force",4000);
   set("force",4000);
   set("jiali",10);
 
    setup();
  
   carry_object("/d/changan/npc/obj/blade")->wield();
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
   if(skill!="liaoyuan-tianshu") return 1;
   return 0;
 
}