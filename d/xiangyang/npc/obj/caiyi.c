
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"����"NOR, ({ "cai yi","yi","cai"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","����һ���ǳ�Ư���Ĳ���.\n");
     set("unit", "��");
     set("value", 500);
     set("armor_prop/armor", 10);
   }
   setup();
}
