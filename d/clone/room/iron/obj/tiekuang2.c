
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIY"ĞşÎäÑÒ"NOR, ({ "xuanwu yan","yan"}) );
   set_weight(5000);
   
   set("weapon",([
                "damage":70+random(15),
                "strong":50+random(50),
		 ]));
        
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "¿é");
     
   }
   setup();
}
