
inherit "/std/guard.c";

void create()
{
   set_name("¹Ù±ø",({ "bing" }) );
   set("gender", "ÄĞĞÔ" );
   set("age", 32);
   set("long", "ÕâÊÇÊØÎÀÀÖÊÙµÄ¹Ù±ø¡£\n");
       
   set("combat_exp",800000);
   set("attitude", "peaceful");
   set("guard","pengliang");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
   
}

