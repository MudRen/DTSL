
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(HIB"��ӥצ��"NOR, ({ "tiezhua shou","shou"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("long","����һ��������ʿ���õ���צ�֡�\n");
     set("unit", "��");
     set("value",2000);
     set("armor_prop/armor",20);
     set("armor_prop/damage",6);
   }
   setup();
}
