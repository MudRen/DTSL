
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
   set_name(HIC"����"NOR, ({ "botao"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�����ס�\n");
     set("material", "ë��");
     set("unit", "��");
     set("value",20);
     set("armor_prop/armor",3);
   }
   setup();
}
