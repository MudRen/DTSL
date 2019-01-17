
#include <weapon.h>

inherit STAFF;

void create()
{
   set_name("钢杖", ({ "staff" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("leitai_weapon",1);
     set("material", "iron");
     set("long", "这是一柄钢杖。\n");
     set("wield_msg", "$N拿出$n,握在手中掂了掂。\n");
     set("unequip_msg", "$N收起$n站好。\n");
   }
   init_staff(35,300,300);
   setup();
}
