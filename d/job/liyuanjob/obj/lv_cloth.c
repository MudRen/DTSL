
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIG"��ɫ����"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��Ư�������¡�\n");
     set("material", "cloth");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
