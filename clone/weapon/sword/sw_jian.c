// sw_jian.c ���ƹŽ�
// by Looklove 2000/8/25 for a quest

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"���ƹŽ�"NOR,({ "songwen jian", "songwen gujian", "jian","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("rigidity", 1);
                set("weapon_prop/parry", 1);
                set("weapon_prop/sword", 1);
                set("no_drop","ʦ�����Ľ���������㶪����\n");
                set("no_give","ʦ���Ľ������ˣ����²��ðɣ�\n");
                set("wield_msg", HIC"$N�������һ��$n�����˸�������\n"NOR);
                set("unwield_msg", HIC"$N��ɫ�����ؽ�$nб�������䡣\n"NOR);
        }
        init_sword(20);
        setup();
}

