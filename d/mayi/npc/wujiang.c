
inherit "/std/guard.c";

void create()
{
   set_name("�佫",({ "wu jiang","jiang","wu" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "�����������ص��佫��������ʮ�����硣\n");
       
   set("combat_exp",800000);
   set("guard","mayi");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
  
}
