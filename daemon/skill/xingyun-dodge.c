//���ƾŲ���

#include <ansi.h>
inherit SKILL;
string *dir=({"Ǭ","��","��","��","��","��","ب","��"});
string *num=({"����","����","û��ô"});
string *do1=({"����","�ƻ�"});
string *do2=({"�㿪","����","�ܿ�"});

mapping action = ([
         "action" : "$n���α任�޳����������Σ���"+YEL"[Ǭ]"NOR+"λ�ε���"+YEL"[��]"NOR"λ��������$n�Ĺ�����"
]);


mapping query_action(object me)
{
     int i,j;
     i=random(8);
     j=random(8-i);
     action["action"]="$n���α任�޳���"+num[random(sizeof(num))]+
	do1[random(sizeof(do1))]+",��"+YEL+dir[i]+NOR+"λ�ε���"+
	YEL+dir[j]+NOR+"λ��"+do2[random(sizeof(do2))]+"��$N�Ľ�����\n";
	return action;
}


int valid_learn(object me)
{
    
	   return 1;
}



int practice_skill(object me)
{
     
	
	return 1;
}

string query_type()
{
	return "dodge";
}
string query_base()
{
	return "dodge";
}

string *query_perform()
{
   return ({"nitian"});
}

int query_dodge(object me)
{
	return 50;
}