// xuantiejian ������

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"������"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(35000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("unique", 1);                
                set("rigidity", 10);
                set("sharpness", 9);
                set("material", "steel");
                set("weapon_prop/parry", 10);
                set("treasure",1);
                set("wield_neili", 1200);
                set("wield_maxneili", 1500);
                set("wield_str", 35);
                set("wield_msg", HIB"$N�˵�һ���ӱ������������������������ˣ���Բ֮�ں�Ȼ������������ɱ��֡�\n"NOR);
                set("long", "�˽����߳ߣ����������������������ޱȣ��޷����У�ȴɱ��ɭȻ��ʵ�����µ�һ�����\n");                
                set("unwield_msg", HIB "$N����������ؼ��ɱ���ټ���\n" NOR);               
        }
        init_sword(200);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "xuantie-jianfa" ||
            me->query_skill("xuantie-jianfa", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return HIB "��������ͻȻ����һ�ɾ���,$nֻ�����ؿ�һ�ƣ��������᲻������\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n , me);
                victim->receive_damage("jing", n/5 , me);
                victim->receive_wound("jing", n / 5, me);
                 victim->receive_wound("neili", n *2, me);

                return BLU"����������һ�������ľ��磬ֻ�����һ�����죬$n������ߵķ���һ����˳�ȥ��\n" NOR;


        }
        return damage_bonus;
}

