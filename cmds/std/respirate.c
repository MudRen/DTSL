#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

int finish(object me, string force_skill,int i);
int halt_respirate(object me);
string swap_msg(string arg);

int main(object me, string arg)
{
	int gin_cost, busy_time;string *force,force_skill;
	int i;string sub_force;
	seteuid(getuid());
   
	if(environment(me)->query("no_respirate")||environment(me)->query("sleep_room")||
			( environment(me)->query("no_fight")&&!environment(me)->query("can_exercise") )
			)
		return notify_fail("�����ֹ����������\n");
         
	if (me->is_busy() || me->query_temp("pending/respirating"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");
   
	force=me->query("force_skill");
	if(sizeof(force)==0)
		return notify_fail("�������ѧһ���ڹ�!\n");
	if(sizeof(force)>1){
		if( !arg||sscanf(arg, "%s %d",force_skill,gin_cost)!=2 )
			return notify_fail("���ж����ڹ�����ʹ�� respirate �ڹ����� ����.�� respirate changsheng-jue 10.\n");

		if(sizeof(force-({force_skill}))==sizeof(force))
			return notify_fail("��û��ѧϰ�����ڹ�!\n");
	}
	else{
		if(!arg||sscanf(arg,"%d",gin_cost)!=1)
			return notify_fail("��ʹ�� respirate ���֡�\n");
		force_skill=force[0];
	}

	if( gin_cost < 10 ) 
		return notify_fail("������Ҫ�� 10 �㡸��������������\n");

	if( (int)me->query("gin") < gin_cost )
		return notify_fail("�����ڵľ�̫���ˣ��޷�������Ϣ����ȫ������\n");
	if(me->query("kee")*100/me->query("max_kee")<50)
		return notify_fail("�����ڵ���Ѫ���㣬�޷�����������\n");
  
  	i=SKILL_D(force_skill)->query_respirate(me);

	if(me->query("combat_exp")>=3000000&&me->query("env/tuna_msg")){
		sub_force = me->query("env/tuna_msg");
		if( strlen(sub_force) > 40 )
			sub_force = "";
		else
			sub_force = swap_msg(sub_force);
	}
	else		
		sub_force=SKILL_D(force_skill)->sub_respirate(me);
	
	if(sub_force=="") 	
   		sub_force = "$N����������������һ����Ϣ��ʼ������������\n";
   		
	message_vision(sub_force,me);

	sub_force=replace_string(sub_force,"$N",me->name());
	sub_force=replace_string(sub_force,"\n","");
	me->set_temp("do_respirate",1);
	me->set_temp("apply/short",({sub_force}));
	me->set_temp("gin_cost",gin_cost);
	me->start_busy((:finish,me,force_skill,i:),(:halt_respirate:));
	return 1;
}

int finish(object me, string force_skill,int i)
{
	int force_gain;int gin_cost;
	gin_cost=me->query_temp("gin_cost");
	force_gain=10+(me->query_skill("force",1)/3+me->query_skill(force_skill,1)/2)/3;
	// me add force_gain sen one second
	if(force_gain>gin_cost) force_gain=gin_cost;
	if(force_gain>me->query("gin")) force_gain=me->query("gin");
	gin_cost=gin_cost-force_gain;
	me->receive_damage("gin",force_gain);
	me->add("sen",force_gain+force_gain*i/100);
	if(gin_cost<=0||me->query("gin")<=0||me->is_fighting()){
		tell_object(me, "��������ϣ���һ����������վ��������\n");
		me->delete_temp("apply/short");
		me->delete_temp("gin_cost");
		me->delete_temp("do_respirate");
		if( (int)me->query("sen") >=(int)me->query("max_sen") * 2) {
			if(me->query("max_sen")>=me->query("max_force")){    
				me->set("max_sen",me->query("max_sen"));
				me->set("eff_sen",me->query("max_sen"));
				me->set("sen",me->query("max_sen"));
				tell_object(me, "�㷢���������ͣ�����û����ߵ�����\n");
			}
			else{
				tell_object(me, "��ľ�����ǿ�ˣ�\n");
				me->add("max_sen_add", 1);
				me->add("max_sen", 1);
				me->add("eff_sen",1);
				me->set("sen", me->query("eff_sen"));
			}
		}
		me->start_busy(1);
		return 0;
	}
	me->set_temp("gin_cost",gin_cost);
	return 1;
}

int halt_respirate(object me)
{
    message_vision("$Nǿ�н���Ϣѹ�ص���֮�У�����վ��������\n",me);	
    
    if( (int)me->query("sen") >=(int)me->query("max_sen") * 2){
     me->set("eff_sen",me->query("max_sen"));
      me->set("sen",me->query("max_sen"));}
    
    me->delete_temp("apply/short");
   me->delete_temp("gin_cost");
   me->delete_temp("do_respirate");
   
   return 1;
}

string swap_msg(string arg)
{
	
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg += "\n"+NOR;
	return arg;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|tuna [<�ķѡ�����������Ԥ��ֵ 10>]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

��ο� help stats
HELP
        );
        return 1;
}
