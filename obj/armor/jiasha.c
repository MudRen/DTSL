
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"����"NOR, ({ "jia sha","jia","sha"}) );
   set_weight(700);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��ɮ�˴������ġ�\n");
     set("material", "˿��");
     set("unit", "��");
     set("value", 100);
     set("armor_prop/armor",20);
     set("armor_prop/dodge",10);
   }
   setup();
}
