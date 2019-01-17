// learn.c
//datang-shuanglong
#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
       string skill, teacher, skill_name,skill_type,*st;
        object ob;int i,flag;int sum;
        int master_skill, my_skill, gin_cost;
        flag=0;
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
        if(!arg||(sscanf(arg,"%s %s for %d",teacher,skill,sum)!=3&&
        sscanf(arg, "%s %s", teacher, skill)!=2))
        return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����>\n�� learn|xue <ĳ��> <����> for ����.\n");
        
        if(sscanf(arg, "%s %s for %d", teacher, skill,sum)!=3)
           sum=1;
        else if(skill=="literate") return notify_fail("ѧ�Ļ�����һ��һ�����ɣ�\n");
        if(stringp(sum))
        return notify_fail("ѧϰ�Ĵ���������������\n");
if(sum<=0) sum=1;
        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");
        
        if( !(ob = present(teacher, environment(me))) || !ob->is_character() || ob->query("race") != "����")
                return notify_fail("��Ҫ��˭��̣�\n");
        
        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

        if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) ) {
			return  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
              
        }

		if( !master_skill = ob->query_skill(skill, 1) )
			return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
			return 0;

		my_skill = me->query_skill(skill, 1);
		if( my_skill >= master_skill )
			return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
		
        if(my_skill>=400&&skill!="literate"&&skill!="chanzong-fofa"&&skill!="wuwang-jing")
		return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ�\n");

		notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
		if( !SKILL_D(skill)->valid_learn(me) ) return 0;

		gin_cost = sum*150 / (int)me->query_int();
		if(gin_cost<=0)
		 gin_cost=1+random(2);
                if(me->query("gin")<gin_cost)
                return notify_fail("��û����ô��ľ���ѧϰ��\n");
		if( !my_skill ) {
                gin_cost *= 2;
                //me->set_skill(skill,0);

        }

		if( (int)me->query("potential") < sum )
			return notify_fail("���Ǳ�ܲ������ˣ�û�а취�ٳɳ��ˡ�\n");

		write("����" + ob->name()
                + "����йء�" + to_chinese(skill) + "�������ʡ�\n");

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

        tell_object(ob, me->name()
                + "��������йء�" + to_chinese(skill) + "�������ʡ�\n");

        if (random(10) > 9) tell_room(environment(me),
                me->name() + "������" + ob->name() + "������⡣\n",
                ({ me, ob }));

		if( (int)me->query("gin") >= gin_cost ) {
			if( SKILL_D(skill)->query_type()!="knowledge"&&
			    SKILL_D(skill)->query_type()!="literate"
			&&      my_skill>=((int)me->query("max_pot")-100) ) {
                write("Ҳ����ȱ��ʵս���飬���"+ob->name()+"�Ļش������޷���ᡣ\n");
			} else {
				if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                    write(sprintf("������%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", ob->name(),
                        skill_name));
				else
                    write("������"+ob->name()+"��ָ�����ƺ���Щ�ĵá�\n");
				me->add("potential", -sum);
				me->improve_skill(skill,
					sum*(my_skill /20 + me->query_int()/3 + random(me->query_int()*1/ 5)+
					  me->query_skill("jiuxuan-dafa",1)/30));
			}
		} else {
			gin_cost = me->query("gin");
			write("�����̫���ˣ����ʲôҲû��ѧ����\n");
		}
                me->delete_temp("mark/literate");
		me->receive_damage("gin", gin_cost );

		return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : learn|xue <ĳ��> <����>�� learn|xue <ĳ��> <����> for <����>

���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������ָ�� : apprentice, practice, skills, study
HELP
        );
        return 1;
}
