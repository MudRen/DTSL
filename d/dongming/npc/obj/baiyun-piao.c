
#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
   set_name(WHT"����Ʈ"NOR, ({ "baiyun piao","piao","baiyun","whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("rumor",1);
     set("material", "���˿");
     set("long", "����һ��Ʈ�������ɽ��˿�Ƴɣ������ޱȡ�\n");
     set("wield_msg", "$N����ؽ�$n�������ϣ����˼��Ρ�\n");
     set("unequip_msg", "$N����ؽ�$n�����˸첲�ϡ�\n");
   }
   init_whip(98,200,200);
   setup();
}
