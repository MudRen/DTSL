// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        object ob;int sum;string ob_name;
        string zhao_name;
        mapping skill;
        int my_skill, cost;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (where->query("sleep_room"))
                return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");

        if( me->is_fighting() )
                return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if(!arg||(sscanf(arg,"%s",ob_name)!=1&&
           sscanf(arg,"%s for %d",ob_name,sum)!=2))
        return notify_fail("��ʹ�� study|du <����> ��study|du <����> for <����>\n");
        if(sscanf(arg,"%s for %d",ob_name,sum)!=2) sum=1;
        if(sum>100)
        return notify_fail("���黹���������ɣ�\n");
        if(sum<=0)
        return notify_fail("ר�Ķ��飬��Ҫ���ҡ�\n");
        if(!objectp(ob = present(ob_name, me)) )
                return notify_fail("��Ҫ��ʲô��\n");
       if( !mapp(skill = ob->query("skill")) )
                return notify_fail("���޷�����������ѧ���κζ�����\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        if(me->query("gin")<10*sum)
			return notify_fail("��̫���ˣ���Ϣһ�°ɣ�\n");
        if (!random(5))
                message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()
                + "��\n", environment(me), me);

        if( (int)me->query("combat_exp") < skill["exp_required"])
                return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
               
        if( me->query_int() < skill["difficulty"])
              return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");
        notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
        
        if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

        cost = (skill["jing_cost"] + skill["jing_cost"] 
                * (skill["difficulty"] - (int)me->query("int"))/20)*sum;
        if (cost < 10) cost = 10*sum; // minimum cost
        if(me->query("gin")<cost) return notify_fail("��ľ��������ˣ�ЪЪ�ɣ�\n");
        if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
                return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ�û��ѧ���κζ�����\n");
        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
                return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

        if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

        my_skill = me->query_skill(skill["name"], 1);

        if( (int)me->query("gin") > cost ) {
                if(SKILL_D(skill["name"])->query_type()!="knowledge"
                &&SKILL_D(skill["name"])->query_type()!="literate"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        write("Ҳ����ȱ��ʵս���飬���"+ob->name()+"������˵�Ķ��������޷���ᡣ\n");
                } else {
                        write(sprintf("���ж��й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"])));
                        me->improve_skill(skill["name"], sum*((int)me->query_skill("literate", 1)/5+me->query_int()/4+1));
                }
        } else {
                cost = me->query("gin");
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

       if (cost < 1) cost = 1;
        me->receive_damage("gin", cost );

        return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study|du <��Ʒ����>�� study|du <��Ʒ����> for <����>

���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����

see also : learn
HELP
   );
   return 1;
}
