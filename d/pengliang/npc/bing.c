
inherit "/std/guard.c";

void create()
{
   set_name("�ٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����������˧���Ĺٱ���\n");
   set("guard","pengliang");   
   set("combat_exp",800000);
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),160);
   
   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
   
}

