
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"����"NOR, ({ "pifeng"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("no_give",1);
     set("no_get",1);
     set("no_sell",1);
     set("armor_prop/armor",20);
   }
   setup();
}
