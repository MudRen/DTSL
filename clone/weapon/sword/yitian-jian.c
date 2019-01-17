// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"���콣"NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 9);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/parry", 8);
                set("treasure",1);
                set("wield_neili", 1300);
                set("wield_maxneili", 1700);
                set("wield_str", 28);
                set("wield_msg", HIY"$N��ৡ���һ��������콣���˸�������������â���£������Ƿɡ�\n$N���ɵô��ĵ�����һ�����ƺ�����\n"NOR);
                set("long", "����һ���ĳ������ĹŽ��������Ͻ�˿���š����졯����׭�ġ�\n����������������һ����������δ���ʣ��ѿɼ��䲻����\n");                
                set("unwield_msg", HIY "���콣����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);                
        }
        init_sword(180);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "huifeng-jian" ||
            me->query_skill("huifeng-jian", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return WHT "���콣Я�Ŵ̹Ƿ���������ʣ�$nֻ��ȫ��������һ˿˿���Ž���ӿ����\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n , me);
                victim->receive_damage("jing", n/2 , me);
                victim->receive_wound("jing", n / 2, me);
                 victim->receive_wound("neili", n , me);

                return     WHT "���콣�д�������������������Ϯ��$n,$nֻ������������������Լ��ľ�����\n" NOR;


        }
        return damage_bonus;
}
