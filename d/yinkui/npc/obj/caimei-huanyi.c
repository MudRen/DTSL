
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIG"��"HIR"��"HIY"��"HIM"��"NOR, ({ "caimei huanyi","cloth","yi","yulong_cloth"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","���������ɵ�����֮�������Ȼ��¡�����˵���������á�\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor", 15);
     set("armor_prop/yulong_cloth", 1);
   }
   setup();
}
