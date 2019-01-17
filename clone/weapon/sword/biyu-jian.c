#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG "����" NOR, ({ "biyu jian", "sword", "jian" }) );
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("treasure",1);
		set("rigidity", 4);
		set("sharpness", 6);
		set("unique", 1);
		set("weapon_prop/parry", 2);
		set("wield_neili", 500);
		set("wield_maxneili", 900);
		set("wield_str", 23);
		set("material", "jade");
		set("long", "���ǰ�ǰ�������������������͸������֮�⣬��������ޱȡ�\n");
		set("wield_msg", HIC "ֻ�������ˡ���һ�����̹����֣�$N��������µ�$n" HIC "���ñ�ֱ��\n" NOR);
		set("unwield_msg", HIC "$n" HIC "����һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
	}
	init_sword(80);
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "murong-jianfa" ||
            me->query_skill("murong-jianfa", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->add_condition("no_exert", 2 + random(3));
                return HIG "���񽣷���һ����������,$nֻ���ý�����������,��ʱ�����ڿյ�����,�ǳ����ܡ�\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n / 2, me);
                victim->receive_wound("qi", n / 3, me);
                victim->receive_damage("jing", n/10 , me);
                victim->receive_wound("jing", n / 10, me);
                 victim->receive_wound("neili", n , me);

                return     HIG "���񽣼����һ����â������㹥��$n���Ŵ��Ĵ�Ѩ��\n" NOR;


        }
        return damage_bonus;
}

