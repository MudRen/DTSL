
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIB"����"NOR, ({ "hu dun","hu","dun","shield"}) );
   set_weight(1500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("long","����һ�滤�ܣ��������һЩ����ģ���Ļ���\n");
     set("unit", "��");
     set("value",2000);
     set("armor_prop/armor",29);
     set("armor_prop/dodge",-1);
   }
   setup();
}
