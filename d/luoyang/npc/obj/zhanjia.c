
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIG"ս��"NOR, ({ "zhan jia","zhan","jia","armor"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("long","����һ��ʿ���Ǿ�������ս�ס�\n");
     set("unit", "��");
     set("value",2000);
     set("armor_prop/armor",30);
     set("armor_prop/dodge",-2);
   }
   setup();
}
