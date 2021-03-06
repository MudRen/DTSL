// learn.c
//datang-shuanglong
#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"象是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
       string skill, teacher, skill_name,skill_type,*st;
        object ob;int i,flag;int sum;
        int master_skill, my_skill, gin_cost;
        flag=0;
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(!arg||(sscanf(arg,"%s %s for %d",teacher,skill,sum)!=3&&
        sscanf(arg, "%s %s", teacher, skill)!=2))
        return notify_fail("指令格式：learn|xue <某人> <技能>\n或 learn|xue <某人> <技能> for 次数.\n");
        
        if(sscanf(arg, "%s %s for %d", teacher, skill,sum)!=3)
           sum=1;
        else if(skill=="literate") return notify_fail("学文化还是一次一次来吧！\n");
        if(stringp(sum))
        return notify_fail("学习的次数必须是整数！\n");
if(sum<=0) sum=1;
        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");
        
        if( !(ob = present(teacher, environment(me))) || !ob->is_character() || ob->query("race") != "人类")
                return notify_fail("你要向谁求教？\n");
        
        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

        if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) ) {
			return  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
              
        }

		if( !master_skill = ob->query_skill(skill, 1) )
			return notify_fail("这项技能你恐怕必须找别人学了。\n");

        notify_fail(ob->name() + "不愿意教你这项技能。\n");
        if( ob->prevent_learn(me, skill) )
			return 0;

		my_skill = me->query_skill(skill, 1);
		if( my_skill >= master_skill )
			return notify_fail("这项技能你的程度已经不输你师父了。\n");
		
        if(my_skill>=400&&skill!="literate"&&skill!="chanzong-fofa"&&skill!="wuwang-jing")
		return notify_fail("学就只能学到这里了，剩下的要靠你自己领悟了。\n");

		notify_fail("依你目前的能力，没有办法学习这种技能。\n");
		if( !SKILL_D(skill)->valid_learn(me) ) return 0;

		gin_cost = sum*150 / (int)me->query_int();
		if(gin_cost<=0)
		 gin_cost=1+random(2);
                if(me->query("gin")<gin_cost)
                return notify_fail("你没有这么多的精来学习！\n");
		if( !my_skill ) {
                gin_cost *= 2;
                //me->set_skill(skill,0);

        }

		if( (int)me->query("potential") < sum )
			return notify_fail("你的潜能不够用了，没有办法再成长了。\n");

		write("你向" + ob->name()
                + "请教有关「" + to_chinese(skill) + "」的疑问。\n");

        if( ob->query("env/no_teach") )
                return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

        tell_object(ob, me->name()
                + "向你请教有关「" + to_chinese(skill) + "」的疑问。\n");

        if (random(10) > 9) tell_room(environment(me),
                me->name() + "正在向" + ob->name() + "请教问题。\n",
                ({ me, ob }));

		if( (int)me->query("gin") >= gin_cost ) {
			if( SKILL_D(skill)->query_type()!="knowledge"&&
			    SKILL_D(skill)->query_type()!="literate"
			&&      my_skill>=((int)me->query("max_pot")-100) ) {
                write("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
			} else {
				if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                    write(sprintf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(),
                        skill_name));
				else
                    write("你听了"+ob->name()+"的指导，似乎有些心得。\n");
				me->add("potential", -sum);
				me->improve_skill(skill,
					sum*(my_skill /20 + me->query_int()/3 + random(me->query_int()*1/ 5)+
					  me->query_skill("jiuxuan-dafa",1)/30));
			}
		} else {
			gin_cost = me->query("gin");
			write("你今天太累了，结果什么也没有学到。\n");
		}
                me->delete_temp("mark/literate");
		me->receive_damage("gin", gin_cost );

		return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : learn|xue <某人> <技能>或 learn|xue <某人> <技能> for <次数>

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

其他相关指令 : apprentice, practice, skills, study
HELP
        );
        return 1;
}
