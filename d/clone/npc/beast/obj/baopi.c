
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIR"��Ƥ"NOR, ({ "bao pi","pi"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("value",400);
     set("armor_prop/armor",15);
   }
   setup();
}
