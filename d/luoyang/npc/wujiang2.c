
inherit "/std/guard.c";

void create()
{
   set_name("�佫",({ "wu jiang","jiang","wu" }) );
   set("gender", "����" );
   set("age", 30);
   set("long", "�����������ֵ��佫��������ʮ�����硣\n");
       
   set("combat_exp",2000000);
   set("guard","luoyang");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),270);
   
   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
  
}
