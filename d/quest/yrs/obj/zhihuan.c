
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIY"ָ��"NOR, ({ "zhihuan"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��ָ����\n");
     set("material", "��");
     set("unit", "��");
     set("value",30);
     set("armor_prop/armor",1);
   }
   setup();
}
