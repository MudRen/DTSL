
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"�ٷ�"NOR, ({ "cloth"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","����һ�������ٱ������·���\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor",10);
   }
   setup();
}
