
#include <armor.h>
//#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("սѥ", ({ "zhan xue","xue"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ƥ");
     set("long","����һ˫սѥ��\n");
     set("unit", "˫");
     set("value",80);
     set("armor_prop/armor",5);
  }
   setup();
}
