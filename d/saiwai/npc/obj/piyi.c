
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"Ƥ��"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "��");
     set("value", 300);
     set("armor_prop/armor", 20);
   }
   setup();
}
