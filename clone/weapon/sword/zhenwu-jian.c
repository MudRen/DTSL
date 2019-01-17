// zhenwu-jian.c ���佣
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"���佣"NOR, ({"zhenwu jian", "sword", "zhenwu"}));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѻ������۵ĹŽ�,��������Ļ������ƺ�������Щ����,�����Ͼ�Ȼ���м���ȱ�ڡ�\n");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 5);
                set("material", "blacksteel");
                set("weapon_prop/parry", 4);
                set("treasure",1);       
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("wield_msg",HIW"\nֻ����ৡ���һ����$N�������һ�Ѻ�������ı����������䵱ɽ��ɽ֮�������佣����\n"NOR);
                set("unwield_msg",HIW"$N�����е����佣��ؽ��ʡ�\n"NOR);
        }
        init_sword(120);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "taiji-jian" ||
            me->query_skill("taiji-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 2);
                return HIC "$N" HIC "��ǰһ�������е�" NOR + HIY "���佣" NOR
                       + HIC "�û�������ԲȦ����$n" HIC "��ȥ������ϸ��֮����"
                       "$n" HIC "���һ\n������֪��εֵ���ֻ���������ˣ�\n" NOR;


        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n / 2, me);
                victim->receive_damage("jing", n/5 , me);
                victim->receive_wound("jing", n / 5, me);
                 victim->receive_wound("neili", n / 3 , me);

                return             HIY "$N" HIY "ͻȻ�����ȵ�����аħ�������"
                                   "�����������������佣" HIY "����һ����$n"
                                   HIY "��ʱ�����ۻ����ң�\n" NOR;

        }
        return damage_bonus;
}

