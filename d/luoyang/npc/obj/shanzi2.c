
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("����", ({ "shan zi","shan"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "iron");
     set("no_give",1);
     set("save_flag",1);
     set("save_box",1);
     set("long", "����һ��ֽ���ӡ�\n");
     set("wield_msg", "$N�ó�һ��$n��������,�������˼��¡�\n");
     set("unequip_msg", "$N�����е�$n���𣬷��뻳�С�\n");
   }
   init_blade(15,90,90);
   setup();
}

