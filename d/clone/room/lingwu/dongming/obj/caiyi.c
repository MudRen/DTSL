
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"����"NOR, ({ "cai yi","cloth","yi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","����һ��ѩ����ѩ���·�.\n");
     set("unit", "��");
     set("value", 400);
     set("armor_prop/armor", 20);
   }
   setup();
}
