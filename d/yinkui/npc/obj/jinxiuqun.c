
#include <armor.h>

inherit CLOTH;

#include <ansi.h>

void create()
{
   set_name(HIY"金色绣裙"NOR, ({ "jinse xiuqun","xiuqun","cloth"}) );
   set_weight(1500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","这是一件金色绣裙，非常漂亮。\n");
     set("unit", "件");
     set("value", 60);
     set("armor_prop/armor", 8);
   }
   setup();
}
