
inherit "/std/guard.c";

void create()
{
   set_name("ÊÌÎÀ",({ "shi wei","shiwei","wei" }) );
   set("gender", "ÄĞĞÔ" );
   set("age", 32);
   set("long", "ÕâÊÇÊØÎÀ»Ê¹¬µÄÊÌÎÀ¡£\n");
       
   set("combat_exp",800000);
   set("attitude", "peaceful");
   set("guard","xucheng");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
  
  
}
