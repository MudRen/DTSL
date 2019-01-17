// bamboo_stick.c �����
// by shang 97/6
// modified by explorer, 9/11/97

#include <ansi.h>
#include <weapon.h>

inherit STICK;

string* skills = ({
        "stick",
        "bangjue",
});

void create()
{
        int i;

        i = 0;
        if (random(10) > 6) i = 1;

        set_name(HIG "�����" NOR, ({"yuzhu bang", "bang", "stick"}));
        set_weight(10000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIG + "һ������������Ө,ͨ����̵����,,���ŵ�������� ��\n" NOR);
                set("value", 1000);
                set("material", "bamboo");
                set("treasure", 1);
                set("unique", 1);
                set("weapon_prop/parry", 4);
                set("rigidity", 10);
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 24);
                set("wield_msg", "$N���һ�����������������ץ�����С�\n");
                set("unwield_msg", "$N�����е������Ȳ�����С�\n");
                set("skill", ([
                     "name": skills[i],
                     "exp_required": 50000,
                     "difficulty": 24,
                     "max_skill": 100,
                ]) );
        }
        init_stick(150);
        setup();
}       

void init()
{
        if( this_player() == environment() )
                add_action("do_study", "study");
}

int do_study(string arg)
{
        int damage;

        object me = this_player();

        if ( arg != "bang" && arg != "stick" )
            return notify_fail("��Ҫѧʲô��\n");

        if ((int)me->query_skill("literate", 1) < 30 )
            return notify_fail("���ѧʶ��û�������ϵĿھ���\n");

        if ((int)me->query_skill("bangjue",1) > 120)
            return notify_fail("���Ѿ����ܴӰ���ѧ���κζ����ˡ�\n");

        if ((int)me->query_skill("stick", 1) < 60 )
            return notify_fail("��Ļ�������̫��, ����᲻�˰�����\n");

        damage = 2400 / (int)me->query("int");
        me->receive_damage("jing", damage);
        me->receive_damage("jingli", damage);
        me->improve_skill("bangjue", me->query("int"));
        message_vision("$N���Ű��ϵ��ּ�, ��˼���ѡ�\n", me);
        return 0;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("stick") != "dagou-bang" ||
            me->query_skill("dagou-bang", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->add_condition("no_exert", 2 + random(3));
                return HIG "$nֻ���á�����Ѫ����һ��,�������������,����һ˿�����᲻������\n"NOR;



        case 1:
                n = me->query_skill("stick");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n / 3, me);
                victim->receive_damage("jing", n , me);
                victim->receive_wound("jing", n , me);
                 victim->receive_wound("neili", n * 2, me);

                return     HIY "$N���һ��,�����������ͷ����,$n���ܲ���,����һ������������ǡ�\n" NOR;
     
       case 2:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("stick") / 200 + 2);
                return HIG "$N���������Խ��Խ��,ָ��������$nֻ�����ۻ�����,һʱ֮�侹��֪���Ӧ����\n"NOR;



        }
        return damage_bonus;
}
