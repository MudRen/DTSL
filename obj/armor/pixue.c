
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIG"Ƥѥ"NOR, ({ "pi xue","xue"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ˫ͻ��������Ƥѥ��\n");
     set("material", "��Ƥ");
     set("unit", "˫");
     set("value",100);
     set("armor_prop/dodge",30);
   }
   setup();
}
