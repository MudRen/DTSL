
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("������", ({ "shan zi","shan" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ�������ȣ����滭�ŵ��񽭺���������Ů�Ļ�����������ʦ�����Ļ���\n");
     set("wield_msg", "$N�ó�һ��$n��������,�������˼��¡�\n");
     set("unequip_msg", "$N�����е�$n���𣬷��뻳�С�\n");
   }
   init_blade(50,100,100);
   setup();
}
