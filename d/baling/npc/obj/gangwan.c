
#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
   set_name(HIG"����"NOR, ({ "gangwan"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",1000);
     set("armor_prop/armor",8);
     //set("armor_prop/dodge",-1);
   }
   setup();
}
