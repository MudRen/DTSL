
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(YEL"²ÝÐ¬"NOR, ({ "cao xie","xie"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","ÕâÊÇÒ»Ë«²ÝÐ¬¡£\n");
     set("material", "²Ý");
     set("unit", "Ë«");
     set("value",80);
     set("armor_prop/dodge",20);
   }
   setup();
}
