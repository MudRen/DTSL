//Edit By Subzero
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR"����ì"NOR,({ "potian mao", "mao", "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000000);
                set("material", "steel");
                set("rumor", 1);
                set("no_sell", 1);
                set("super", 4);
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", -5);
                set("wield_maxforce", 800);
                set("wield_str", 23);
                set("long", HIR"��ì�˹��С�ì������ƽ��֮��ɾ��ִ�����ɣ�����ʮ����Ӳ������
��������������ì����������ƣ���������֮�ơ�\n");
                set("wield_msg", WHT"$N"+WHT+"���쳤Х����չ����֮�������ִӱ�����$n"+WHT+"�����һƬìӰ���������ơ�\n"NOR);
                set("unwield_msg", HIY "$N"+HIY+"��ì������У��漴Ծ���ڿ���̽��ץס$n"+HIY+"����غ󱳱��ң�������ء�\n" NOR);                
        }
   init_spear(120,180,180);
        setup();
}
