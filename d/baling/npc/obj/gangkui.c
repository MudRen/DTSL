
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIB"�ֿ�"NOR, ({ "gangkui"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",1500);
     set("armor_prop/armor",10);
     set("armor_prop/dodge",-1);
   }
   setup();
}
