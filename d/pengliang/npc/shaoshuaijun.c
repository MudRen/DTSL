
inherit "/std/guard.c";

void create()
{
   set_name("��˧��",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "������������˧����\n");
   set("guard","pengliang");   
   set("combat_exp",800000);
   set("attitude", "peaceful");
   
   set_this_skills("middle");
   set_all_skill(this_object(),160);
   
   setup();
   
}

