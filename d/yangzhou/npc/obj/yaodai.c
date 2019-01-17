
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
   set_name(HIY"金莽腰带"NOR, ({ "jinmang yaodai","yaodai"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "蛇皮");
     set("long","据说这是用罕见的金色蟒蛇皮制成的腰带。\n");
     set("unit", "条");
     set("value",5000);
     set("armor_prop/armor",30);
     set("armor_prop/dodge",2);
   }
   setup();
}
