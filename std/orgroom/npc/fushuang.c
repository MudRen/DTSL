// ����˫����

inherit NPC;

#include <ansi.h>

void create()
{
 
  set_name("��˪", ({"fu shuang", "fu", "shuang"}));
  set("gender", "Ů��");
  set("long","�����Ľ��ɵĸ�˪��\n");
  set("age", 24);
  set("str", 30);
  set("int", 30);
  set("per", 28);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",1000000);
 
  set_skill("literate", 200);
  set_skill("sword", 200);
  set_skill("force", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  
  set_skill("jiuxuan-dafa",200);
  set_skill("yijian-shu",200);
  set_skill("jiuzhuan-jianjue",200);
  set_skill("xingyun-dodge",200);
  set_skill("bafang-zhenfa",200);
 
  setup();
  
  carry_object("/d/yjp/npc/obj/sword")->wield();
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
   if(skill!="bafang-zhenfa") return 1;
   return 0;
 
}