
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(HIG"ս��"NOR, ({ "zhanpao"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ����ʿ����ʱ����ս�ۡ�\n");
     set("material", "����");
     set("unit", "��");
     set("value",200);
     set("armor_prop/armor",30);
   }
   setup();
}
