
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"��ɫɮ��"NOR, ({ "cloth"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor",10);
   }
   setup();
}
