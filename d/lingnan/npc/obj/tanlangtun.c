//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIY"̰����"NOR, ({ "tanlang tun","tanlang","dao" }) );
   set_weight(80000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 100000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", HIY"�˵���ʷ��Զ���ഫ����ĩս���е�������������֪���Ǻ��˺�ʱ����\n"+
                    "���ɣ�Ψһ��֪�ģ����Ǵ˵����ʽ����������죬�ش�һ����ʮ���\n"+
                    "������������ƣ����޷��У�����ע���ڼҸ��ֵ������󣬵�����Ȼ��\n"+
                    "��һ�����У�һ�㱦���಻����֮���⡣\n"NOR);
     set("wield_msg", HIR"$N"+HIR+"̽��һ�����ʣ������һ����$n"+HIR+"�������㷢��������\n"+
                         "�������������������͸������յ����γ���ȫ�޷ֱ𣬿�����Χ������ֱð������\n"NOR);
     set("unequip_msg",HIB"$N"+HIB+"������ץ��$n"+HIB+"�����һ�����ε�����ǣ���㣬\n�������������յĵ����С�\n"NOR);
   }
   init_blade(130,200,200);
   setup();
}
