//�������·�
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"����"NOR, ({ "cai yi","cloth","yi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","����һ����ʰ�쵵��·�,������.\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor", 10);
   }
   setup();
}
