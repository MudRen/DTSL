
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIG"Ƥñ"NOR, ({ "cap"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ����ͻ�ʳ�����Ƥñ��\n");
     set("material", "��Ƥ");
     set("unit", "��");
     set("value",80);
     set("armor_prop/armor",20);
   }
   setup();
}
