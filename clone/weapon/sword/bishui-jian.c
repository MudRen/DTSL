// ITEM: /d/huashan/npc/obj/bishuijian.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( HIG "��ˮ��" NOR, ({ "bishui jian", "jian", "sword" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", GRN "���Ǳ��ֱ����������������������͸���̹⣬��������ޱȡ�\n" NOR);
                set("value", 1500);
                set("rigidity", 3);
                set("sharpness", 3);
                set("weapon_prop/parry", 2);
                set("material", "steel");
                set("unique", 1);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);
                set("wield_msg", GRN "ֻ�����ˡ���һ�����̹���֣�$N���������$n"+ GRN "����ˢ����һ�����ñ�ֱ��\n" NOR);
                set("unwield_msg", GRN "ֻ���̹�һ���������ǰһ����$N�����е�$n"+ GRN "�������䡣\n" NOR);
        }
        init_sword(80);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "huashan-jianfa" ||
            me->query_skill("huashan-jianfa", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return HIG "��ˮ�����������̹⣬��˿˿ϸ������$n��\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n , me);
                victim->receive_damage("jing", n/2 , me);
                victim->receive_wound("jing", n / 2, me);
                 victim->receive_wound("neili", n , me);

                return     HIG "��ˮ�������һ����â������㹥��$n���Ŵ��Ĵ�Ѩ��\n" NOR;


        }
        return damage_bonus;
}
