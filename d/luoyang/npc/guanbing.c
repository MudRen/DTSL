inherit "/std/guard.c";

void create()
{
   set_name("¹Ù±ø",({ "bing" }) );
   set("gender", "ÄĞĞÔ" );
   set("age", 32);
   set("long", "ÕâÊÇÊØÎÀÂåÑô»Ê¹¬µÄ¹Ù±ø¡£\n");
       
   set("combat_exp",800000);
   set("guard","luoyang");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
   
}