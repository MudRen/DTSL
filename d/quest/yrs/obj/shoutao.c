
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(HIW"����"NOR, ({ "shoutao"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ����ͨ�����ס�\n");
     set("material", "ë��");
     set("unit", "��");
     set("value",80);
     set("armor_prop/armor",2);
   }
   setup();
}
