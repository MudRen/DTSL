
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIG"����"NOR, ({ "armor"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�����ף��������ܱ��ء�\n");
     set("material", "����");
     set("unit", "��");
     set("value", 600);
     set("armor_prop/armor",80);
     set("armor_prop/dodge",-2);
   }
   setup();
}
