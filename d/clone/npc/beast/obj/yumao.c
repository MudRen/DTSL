
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIY"��ë"NOR, ({ "yu mao","mao"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��ë");
     set("unit", "��");
     set("armor_prop/armor",1);
   }
   setup();
}
