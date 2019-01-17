// ���ս�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIR "���ս�" NOR, ({ "guanri jian", "guanri", "jian" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("long", HIR "���ս���˵�ڹ��շ�ʮ�����ɣ���â�������֮���գ�����ħ���֡�\n" NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 23);
                set("wield_msg", HIR "$N���ְν�һת��һ�ֺ������ӽ��������𣬽�����˸ҫ�ۡ�\n" NOR);
                set("unwield_msg", HIR "ֻ��$N��ָ΢��������û�ڽ���֮�С�\n" NOR);
        }
        init_sword(95);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "songshan-jian" ||
            me->query_skill("songshan-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return HIR "���ս��û���һ�����ʺ�����$n,$nֻ���ֽ��������Զ�����\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n /3 , me);
                victim->receive_damage("jing", n/5 , me);
                victim->receive_wound("jing", n / 5, me);
                 victim->receive_wound("neili", n *2, me);

                return HIY"���ս��û���һ��ҫ�۽�â����Χ�����з������ڵ����죡$n����һ�����ܵ����\n" NOR;


        }
        return damage_bonus;
}
