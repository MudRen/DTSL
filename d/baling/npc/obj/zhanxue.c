
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIC"սѥ"NOR, ({ "boot"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ƥ��");
     set("unit", "˫");
     set("value",300);
     set("armor_prop/armor",1);
     set("armor_prop/dodge",6);
   }
   setup();
}
