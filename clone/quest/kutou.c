//
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIY"��ͷ"NOR, ({ "ku tou","ku"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","����һ����ͷ����˵���Ϻ���������Ƚ��ͣ���\n");
     set("unit", "��");
     set("value", 400000);
     set("armor_prop/armor",-500);
   }
   setup();
}
