
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIG"����"NOR, ({ "dunpai"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",1500);
     set("armor_prop/armor",15);
     set("armor_prop/dodge",-1);
   }
   setup();
}
