
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIG"����"NOR, ({ "shield"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ������Ļ��ܡ�\n");
     set("material", "��");
     set("unit", "��");
     set("value",200);
     set("armor_prop/armor",30);
   }
   setup();
}
