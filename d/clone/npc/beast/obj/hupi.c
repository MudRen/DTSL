
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(YEL"ª¢∆§"NOR, ({ "hu pi","pi"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "ª¢∆§");
     set("unit", "’≈");
     set("value",300);
     set("armor_prop/armor",10);
   }
   setup();
}
