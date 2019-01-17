// tune.c

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

void full_me(object me)
{
		int jin, qi,shen, neili, shiwu, yinshui;
		
		jin = me->query("max_gin");
        qi =me->query("max_kee");
        shen = me->query("max_sen");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        
        me->set("eff_sen", shen);
        me->set("sen", shen);
        
        me->set("eff_kee", qi);
        me->set("kee", qi);
        
        me->set("eff_gin", jin);
        me->set("gin", jin);
       
        me->set("force", neili*2);
        me->set("food", shiwu);
        me->set("water", yinshui);
write(HIY"�����������������ѽ�����һظ��������ɣ�����\n"NOR);
tell_object(me,HIW"��ͻȻ��һ������Χ������ȫ���������������\n"NOR);

}

int main(object me, string arg)
{
	int value;
	string type,msg,t_name;
	object target;
	
	mapping skills;
	string *skillname;
	int i;
	
	object obj;
	
	if(!arg)
		return help(me);
	
	if(arg == "fullme"){
		full_me(me);
		return 1;
	}
	if(arg == "��ְҵ"){
		me->delete("vocation");
		me->delete("vocation_fenzhi");
		tell_object(me,"���ְҵȥ���ˣ�\n");
		return 1;
	}
	if(arg == "��ʯ"){
		obj = new("/cmds/std/misc/tiekuang");
		obj->set_status(me);
		obj->move(me);
		tell_object(me,"��Ū����һ���ʯ��\n");
		return 1;
	}
	if(arg == "ҩ��"){
		obj = new("/cmds/std/misc/medicine");
		obj->set_status(me);
		obj->move(me);
		tell_object(me,"��Ū����һ��ҩ�ģ�\n");
		return 1;
	}
	if(arg == "����"){
		me->add("age_modify",86400);
		me->set("age",me->query("age")+1);
		me->update_age();
		tell_object(me,"������������� 1 ��\n");
		return 1;
	}
	
	if(sscanf(arg,"copynpc %s %s",t_name,type)==2){
		target = present(t_name,environment(me));
		if(!target)
			return notify_fail("����û������ˡ�\n");
		msg = "";
		switch(type){
			case "shuxing":
				me->set("combat_exp",target->query("combat_exp"));	
				msg += "�趨���� "+target->query("combat_exp")+"\n";
			
				me->set("max_kee",target->query("max_kee"));
				me->set("eff_kee",target->query("eff_kee"));
				me->set("kee",target->query("kee"));
				msg += "�趨��Ѫ "+target->query("kee")+"\n";
				
				me->set("max_gin",target->query("max_gin"));
				me->set("eff_gin",target->query("eff_gin"));
				me->set("gin",target->query("gin"));
				msg += "�趨��Ѫ "+target->query("gin")+"\n";
				
				me->set("max_sen",target->query("max_sen"));
				me->set("eff_sen",target->query("eff_sen"));
				me->set("add_sen",target->query("add_sen"));
				me->set("sen",target->query("sen"));
				msg += "�趨���� "+target->query("sen")+"\n";
				
				me->set("max_force",target->query("max_force"));
				me->set("force",target->query("force"));
				msg += "�趨���� "+target->query("force")+"\n";
				break;
			case "skills":
				skills = target->query_skills();
				if(!mapp(skills))
					return notify_fail(target->name()+"�����κμ��ܣ�\n");
				skillname = keys(skills);
	
				for(i=0;i<sizeof(skillname);i++)
					me->set_skill(skillname[i],target->query_skill(skillname[i],1));
				msg += "���ܸ�����ϣ�\n";
				break;
			default:
				return help(me);
		}	
		tell_object(me,msg);
		return 1;	
		
	}
	
	if(sscanf(arg,"%s %d",type,value)!=2)
		return help(me);
	if(value<=0)
		return notify_fail("��ֵ����С����\n");
	
	msg = "";
	switch(type){
		case "exp":
			me->set("combat_exp",value);	
			msg += "�趨���� "+value+"\n";
			break;
		case "qi":
			me->set("max_kee",value);
			me->set("eff_kee",value);
			me->set("kee",value);
			msg += "�趨��Ѫ "+value+"\n";
			break;
		case "jing":
			me->set("max_gin",value);
			me->set("eff_gin",value);
			me->set("gin",value);
			msg += "�趨��Ѫ "+value+"\n";
			break;
		case "shen":
			me->set("max_sen",value);
			me->set("eff_sen",value);
			me->set("add_sen",value);
			me->set("sen",value);
			msg += "�趨���� "+value+"\n";
			break;
		case "neili":
			me->set("max_force",value);
			me->set("force",value);
			msg += "�趨���� "+value+"\n";
			break;
		case "gongji":
			me->set("office_number",value);
			msg += "�趨����"+value+"\n";
			break;
		case "shaqi":
			me->set("bellicosity",value);
			msg += "�趨ɱ��"+value+"\n";
			break;
		case "bili":
			me->set("str",value);
			msg += "�趨����"+value+"\n";
			break;
		case "shenfa":
			me->set("dex",value);
			msg += "�趨��"+value+"\n";
			break;
		case "gengu":
			me->set("con",value);
			msg += "�趨����"+value+"\n";
			break;
		case "wuxing":
			me->set("int",value);
			msg += "�趨����"+value+"\n";
			break;
		case "��ò":
			me->set("per",value);
			msg += "�趨��ò"+value+"\n";
			break;
		case "allskill":
			skills = me->query_skills();
			if(!mapp(skills))
				return notify_fail("�㲻���κμ��ܣ�\n");
			skillname = keys(skills);
	
			for(i=0;i<sizeof(skillname);i++)
				me->set_skill(skillname[i],value);
			msg += "�趨���м���Ϊ"+value+"\n";
			break;
		case "fangqiskill":
			skills = me->query_skills();
			if(!mapp(skills))
				return notify_fail("�㲻���κμ��ܣ�\n");
			skillname = keys(skills);
	
			for(i=0;i<sizeof(skillname);i++)
				if(skills[skillname[i]]<=value)
					me->delete_skill(skillname[i]);
				else	
					me->set_skill(skillname[i],skills[skillname[i]]-value);
			msg += "�������м���"+value+"��\n";
			break;
		default:
			if(file_size(SKILL_D(type)+".c") < 0)
				return notify_fail("û������书��\n");
			me->set_skill(type,value);
			msg += "�趨 "+type+"  "+value+"��\n";
	}
	tell_object(me,msg);
	return 1;
		
}

int help(object me)
{
	write(@HELP
����ʹ�� testcmd ���� ��ֵ

testcmd exp 100000
testcmd qi  1000
testcmd jing 1000
testcmd shen 1000
testcmd neili 1000
testcmd shaqi 1000

testcmd ���� ������ testcmd strike 100

�ر�ģ�
testcmd fullme ��ָ���������ʳ���ˮ
testcmd gongji 100 �趨���� 100 ��
testcmd allskill 100 �趨�����书 100 ��
testcmd fangqiskill 100 ���������书 100 ��,
                        �����С��100���ģ���ֱ��
                        ȫ��������

testcmd copynpc NPC���� shuxing ����NPC��hp���ԡ�
testcmd copynpc NPC���� skills  ����NPC�ļ��ܡ�

testcmd ��ְҵ ��ȥ��ְҵ
testcmd ��ʯ   ���õ�һ����ʯ
testcmd ҩ��   ���õ�һ��ҩ�� 
testcmd ����   ����������� 1 ��
testcmd ��ò 30 ����òΪ 30  

testcmd bili(gengu,wuxing,shenfa) ��ֵ���趨������ֵ  

HELP
	);
	return 1;
}

