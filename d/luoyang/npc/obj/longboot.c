
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIG"��ͲƤѥ"NOR, ({ "pixue"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ƥ");
     set("long","����һ˫��ͻ�ʽ�������Ƥѥ��\n");
     set("unit", "˫");
     set("value",1500);
     set("armor_prop/dodge",15);
   }
   setup();
}
