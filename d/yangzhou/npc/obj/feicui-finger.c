
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIG"Ù‰¥‰÷∏ª∑"NOR, ({ "feicui zhihuan","zhihuan"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ù‰¥‰");
     set("unit", "√∂");
     set("value",2000);
     set("armor_prop/armor",15);
     set("armor_prop/dodge",8);
   }
   setup();
}
