
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIW"»¨¸ÚÑÒ"NOR, ({ "huagang yan","yan"}) );
   set_weight(5000);
   
   set("weapon",([
		 "damage":50+random(20),
		 "strong":90+random(50),
		 ]));
        
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "¿é");
     
   }
   setup();
}
