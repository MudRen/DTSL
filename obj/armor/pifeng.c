
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"��Ƥ����"NOR, ({ "pi feng"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ����Ƥ���硣\n");
     set("material", "��Ƥ");
     set("unit", "��");
     set("value", 400);
     set("armor_prop/armor",40);
   }
   setup();
}
