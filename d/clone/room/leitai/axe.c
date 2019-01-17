
#include <weapon.h>

inherit AXE;

void create()
{
   set_name("斧子", ({ "axe" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("leitai_weapon",1);
     set("material", "iron");
     set("long", "这是一柄斧子。\n");
     set("wield_msg", "$N拿出$n,晃了两晃。\n");
     set("unequip_msg", "$N收起$n站好。\n");
   }
   init_axe(40,300,300);
   setup();
}
