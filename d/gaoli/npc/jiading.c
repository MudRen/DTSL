// ����˫����
 
// jiading.c

inherit NPC;

void create()
{
  set_name("�Ҷ�", ({"jia ding", "jia","ding"}));
  set("long","һ����ͨ�ļҶ���\n");
  set("gender", "����");
  set("age", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("combat_exp",60000);
  set("max_kee", 400);
   //set("max_mana", 200);
   set("max_sen", 400);
   set("max_force", 200);
   set("force", 200);
   set("force_factor", 10);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  setup();
  //carry_object("/d/shanhaiguan/obj/cloth")->wear();
}


