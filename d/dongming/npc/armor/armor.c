
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIB"ս��"NOR, ({ "armor"}) );
   set_weight(7000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("unit", "��");
     set("no_give",1);
     set("no_get",1);
     set("no_sell",1);
     set("armor_prop/armor",25);
   }
   setup();
}
