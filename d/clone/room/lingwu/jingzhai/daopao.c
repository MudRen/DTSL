
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"����"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","����һ����ͨ�ĵ��ۡ�\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor", 20);
   }
   setup();
}
