
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIB"����"NOR, ({ "han tie","tie"}) );
   set_weight(5000);
   
   set("weapon",([
                "damage":80+random(10),
                "strong":80+random(40),
		 ]));
        
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "��");
     
   }
   setup();
}
