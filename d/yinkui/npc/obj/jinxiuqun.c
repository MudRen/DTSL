
#include <armor.h>

inherit CLOTH;

#include <ansi.h>

void create()
{
   set_name(HIY"��ɫ��ȹ"NOR, ({ "jinse xiuqun","xiuqun","cloth"}) );
   set_weight(1500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","����һ����ɫ��ȹ���ǳ�Ư����\n");
     set("unit", "��");
     set("value", 60);
     set("armor_prop/armor", 8);
   }
   setup();
}
