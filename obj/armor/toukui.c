
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIG"ͷ��"NOR, ({ "tou kui","kui"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�����Ƶ�ͷ����\n");
     set("material", "��");
     set("unit", "��");
     set("value",100);
     set("armor_prop/armor",30);
   }
   setup();
}
