
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIG"ָ��"NOR, ({ "zhi huan","huan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "ö");
     set("no_give",1);
     set("no_get",1);
     set("no_sell",1);
     set("armor_prop/armor",5);
   }
   setup();
}
