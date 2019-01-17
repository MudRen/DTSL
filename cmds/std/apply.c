// apply.c
//written by yanyan.
//2000.11.
//for datang-shuanglong.
//last Update By Yanyan@dt 2003.9.9

inherit F_CLEAN_UP;

#include <ansi.h>

string swap_skill(string type)
{
	switch(type){
		case "damage":return HIR"�˺�"NOR;
		case "dodge" :return HIM"����"NOR;
	    case "parry" :return WHT"�м�"NOR;
	}
}

int main(object me, string arg)
{
	string skill;
	int action,factor;
	string flag;
	mapping apply_action;
	object weapon;
	string type;
	int old_damage,old_dodge,old_parry;		
	
	if(!arg)
		return notify_fail("��ʹ�� apply damage �� apply parry �� apply dodge ��\n");
	if(arg=="none")
	{
				
	  	me->delete("prepare");
		tell_object(me,"�������ս���в�ָ��ʹ������!\n");
		return 1;
	}
	if(me->query_temp("combat"))
		return notify_fail("\n�����ھ�ȫ��ʹ�þ�����\n");
	if(sscanf(arg,"%s %s",skill,flag)==2
	  &&flag=="y")
	{
	  if(!me->query_skill(skill))
	  return notify_fail("��û�������书��\n");
	  if(SKILL_D(skill)->query_type()=="knowledge"||
	     SKILL_D(skill)->query_type()=="literate"||
	     SKILL_D(skill)->query_type()=="dodge"||
	     SKILL_D(skill)->query_type()=="force_skill"||
	     SKILL_D(skill)->query_type()=="base")
	  return notify_fail("�����书��������ս���еģ�\n");
	  me->set("prepare/"+SKILL_D(skill)->query_type(),skill);
	  tell_object(me,"������Ժ�ս����ֻʹ��"+to_chinese(skill)+"��\n");
	  return 1;
	}
	
	if( sscanf(arg, "%s",type)!=1)
                return notify_fail("ָ���ʽ��apply ����\n");
    
    	if(type!="damage"&&type!="dodge"&&type!="parry")
      		return notify_fail("����ֻ���� �˺�(damage)������(dodge)���м�(parry)����֮һ��\n");
      	
	me->set_temp("combat",1);
	apply_action=me->query("actions");
	tell_object(me,"\n��������"+chinese_number(apply_action["apply_factor"])+"��"+swap_skill(type)+"��Ч����\n");
	skill=me->reset_action(me->query_temp("weapon"));
	
	factor = apply_action["apply_factor"]*me->query_skill(skill,1)/10;
	
	old_damage = me->query_temp("apply/damage");
	old_dodge  = me->query_temp("apply/dodge");
	old_parry  = me->query_temp("apply/armor");
	if(type == "damage"){
		me->add_temp("apply/damage",factor);
		me->add_temp("apply/dodge",-factor/2);
		me->add_temp("apply/armor",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"�ĳ���ͻȻ����������\n"NOR,me);
	}
	else
	if(type == "dodge"){
		me->add_temp("apply/dodge",factor);
		me->add_temp("apply/damage",-factor/2);
		me->add_temp("apply/armor",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"����ͻȻ������������\n"NOR,me);
	}
	else{
		me->add_temp("apply/armor",factor);
		me->add_temp("apply/damage",-factor/2);
		me->add_temp("apply/dodge",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"�ս��Ż�����©˿��������\n"NOR,me);	
	}
	
	call_out("remove_factor",10,me,apply_action["apply_factor"],old_damage,old_dodge,old_parry);
	return 1;
	
}

void remove_factor(object me,int factor,int old_damage,int old_dodge,int old_parry)
{
	if(!me)
		return;
	
	me->delete_temp("combat");
	if(me->is_fighting())
		message_vision(CYN"\n$N"+NOR+CYN+"�����˿�����˫��ʮ�ֽ��������˼�����\n"NOR,me);
	else
		message_vision(CYN"\n$N"+NOR+CYN+"�����˿�������Ϣ�������ڵ��\n"NOR,me);
	
	me->set_temp("apply/damage",old_damage);
	me->set_temp("apply/dodge",old_dodge);
	me->set_temp("apply/armor",old_parry);
	
	me->set_temp("apply_pause_fight",random(factor/2));
	
}

int help (object me)
{
        write(@HELP
        
apply ��������

	�������ͷ�Ϊ �˺�(damage)���м�(parry)��������(dodge)��
���磺
	yong damage
	��ô�㽫����������ս���е��˺�������ͬʱ�������Ӧ�Ľ�����
�ܺ����ݡ�ͬ��������������мܣ���ô�˺������ݻή�ͣ�����������
�ݣ���ô�˺����мܻή�͡�
    ������������ֵ�Ǹ�������ʹ�õ��书���ѡ��ģ�ÿһ���书������
������������ͬ�������� action ����鿴��
�磺action tianmo-jianfa������action����ֻ�ܲ鿴����ѧ���书��
�磺 action tianmo-jianfa
����tianmo-jianfa ������������������������������������������������
����һ��       ����Ӱ������             ������2                 ��
���ڶ���       ����ħ���衹             ������3                 ��
��������       ����ӰԲ�衹             ������4                 ��
��������       ����ħ��Ӱ��             ������5                 ��
������������������������������������������������������������������

    ע�⣺������ļ��ܶ�ߣ�����Ч��ֻ����� 10 ���ӡ���ȫ��ʩ
չ��Ϻ󣬻������ʩչ��������������ͣ�����غϵ�ս���������ζ
����������˹�������ǿ�ĵ����У���ô�ڽ���ʱ������п����ڽ���
���ļ����غ���ֻ�ܴ��ڷ��ص�״̬�ˡ���Ϊ������ģ������������
�ã�Ҳ���ܲ�������ͣ��ʱ��

HELP
        );
        return 1;
}