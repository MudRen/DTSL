// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

int sort_skill(string skill1,string skill2);

string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	BLU "�Կ��ž�" NOR,
	BLU "ƽƽ����" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "����ͨͨ" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	HIB "�������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "�������" NOR,
	CYN "���д��" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "��������" NOR,
	HIC "��������" NOR,
	HIC "¯����" NOR,
	HIC "�����޵�" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIR "������" NOR,
	HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	BLU "�Կ��ž�" NOR,
	BLU "ƽƽ����" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "����ͨͨ" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	HIB "�������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "�������" NOR,
	CYN "���д��" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "��������" NOR,
	HIC "��������" NOR,
	HIC "¯����" NOR,
	HIC "�����޵�" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIR "������" NOR,
	HIW "��ɲ�" NOR
});

string skill_level(object,string,string, int);

int main(object me, string arg)
{
	object ob, *list, couple_ob;
	mapping skl, lrn;
	string *sname, *mapped,target;
	string msg;
	int i, marry_flag;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}
	target = (string) me->query("marry");	
	if(stringp(target)) couple_ob = find_player(target);
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public") )
		return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: sort_skill :) );
		
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	msg="";
	for(i=0; i<sizeof(skl); i++) {
	     if(me->query("env/skill_list")){
		msg+=sprintf("%s%s%-40s" NOR " - %-10s %3d/%3d%s\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1))&&SKILL_D(sname[i])->query_type()!="knowledge"
			&&SKILL_D(sname[i])->query_type()!="literate"
			 ? HIM : "",
			SKILL_D(sname[i])->query_type()=="base"?"��":"  ",
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(ob,sname[i],SKILL_D(sname[i])->query_type(), skl[sname[i]]),
			( skl[sname[i]]+(sname[i]!="dodge"?ob->query_temp("apply/"+sname[i]):
			 ob->query_temp("apply/dodge_skill")) )<0?0: 
			 ( skl[sname[i]]+(sname[i]!="dodge"?ob->query_temp("apply/"+sname[i]):
			 ob->query_temp("apply/dodge_skill")) ), 
			(int)lrn[sname[i]]*100/((skl[sname[i]]+1) * (skl[sname[i]]+1)),
			"%",
		);
	      }
	      else{	
	        msg+=sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1))&&SKILL_D(sname[i])->query_type()!="knowledge"
			&&SKILL_D(sname[i])->query_type()!="literate"
			 ? HIM : "",
			SKILL_D(sname[i])->query_type()=="base"?"��":"  ",
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(ob,sname[i],SKILL_D(sname[i])->query_type(), skl[sname[i]]),
			( skl[sname[i]]+(sname[i]!="dodge"?ob->query_temp("apply/"+sname[i]):
			 ob->query_temp("apply/dodge_skill")) )<0?0: 
			 ( skl[sname[i]]+(sname[i]!="dodge"?ob->query_temp("apply/"+sname[i]):
			 ob->query_temp("apply/dodge_skill")) ), 
			(int)lrn[sname[i]],
		);
	      }	
	}
	me->start_more(msg);
	write("\n");
	return 1;
}

string skill_level(object ob,string skill_name,string type, int level)
{
	int grade;

	grade = level / 20;
	
	if(stringp(SKILL_D(skill_name)->query_level_msg(ob,level)))
	 return SKILL_D(skill_name)->query_level_msg(ob,level);

	switch(type) {
		case "knowledge":
		case "literate":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

mapping base_skill=([
"force":100,
"force_skill":95,
"dodge":90,
"dodge_skill":88,
"cuff":85,
"cuff_skill":83,
"blade":80,
"blade_skill":78,
"sword":75,
"sword_skill":73,
"strike":71,
"staff":70,
"staff_skill":69,
"strike":68,
"strike_skill":67,
"finger":65,
"finger_skill":63,
"leg":60,
"leg_skill":58,
"hammer":55,
"hammer_skill":53,
"spear":50,
"spear_skill":48,
"whip":45,
"whip_skill":43,
"parry":40,
"unarmed":37,
"knowledge":35,
"literate":30,
]);

int sort_skill(string skill1,string skill2)
{
   string s1,s2;
   
   s1=SKILL_D(skill1)->query_type();
   if(!s1) s1=skill1;
   else
   if(s1=="base") s1=skill1;
   
   if(stringp(SKILL_D(skill1)->query_base()))
    s1=SKILL_D(skill1)->query_base()+"_skill";
  
   
   
   s2=SKILL_D(skill2)->query_type();
   if(!s2) s1=skill1;
   else
   if(s2=="base") s2=skill2;
   
   if(stringp(SKILL_D(skill2)->query_base()))
    s2=SKILL_D(skill2)->query_base()+"_skill";
      
   if(base_skill[s1]&&base_skill[s2]&&
      base_skill[s1]>base_skill[s2])
   return -1;
   return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
