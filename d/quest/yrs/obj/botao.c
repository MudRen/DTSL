
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
   set_name(HIC"脖套"NOR, ({ "botao"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个脖套。\n");
     set("material", "毛线");
     set("unit", "个");
     set("value",20);
     set("armor_prop/armor",3);
   }
   setup();
}
