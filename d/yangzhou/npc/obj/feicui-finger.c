
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIG"���ָ��"NOR, ({ "feicui zhihuan","zhihuan"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "���");
     set("unit", "ö");
     set("value",2000);
     set("armor_prop/armor",15);
     set("armor_prop/dodge",8);
   }
   setup();
}
