
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIY"��ѥ"NOR, ({ "guan xue","xue"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "leather");
	 set("long","���ǵ��ٵ���������ѥ��\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor", 10);
      set("armor_prop/dodge", 10);
   }
   setup();
}
