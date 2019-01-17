///u/jpei/thd/obj/biyuxiao.c ������
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(GRN"������"NOR,({"biyu xiao","xiao"}));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","֧");
                set("value",2000);
                set("material","gem");
                set("unique", 1);
                set("treasure", 1);       
                set("rigidity", 6);
                set("weapon_prop/parry", 3);
                set("wield_neili", 500);
                set("wield_maxneili", 1000);
                set("long","����һ֧ͨ�徧Ө���ü�Ϊ������"GRN"����"NOR"��������������ʮ�־�Զ��\n");
                set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
                set("unwield_msg","$Nһ����Х����$n������䡣\n");
        }
        init_sword(90);
        setup();
}
int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 200){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("force") != "bihai-chaosheng" ||
            me->query_skill("bihai-chaosheng", 1) < 100)
                return damage_bonus / 2;

        switch (random(5))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return HIM "ͻȻ��һ�Ρ��̺�����������������$N" HIW "��������$n" HIW
                       "��ʱֻ����̫��Ѩ������ʹ��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n / 2, me);
                victim->receive_wound("qi", n / 5, me);
                victim->receive_damage("jing", n, me);
                victim->receive_wound("jing", n / 2, me);
                 victim->receive_wound("neili", n , me);

                return HIW "$N" HIW "������������ʽ����������������$n" HIW
                       "��ʱֻ����Ѫ��ӿ������֮����\n" NOR;
        }
        return damage_bonus;
}

