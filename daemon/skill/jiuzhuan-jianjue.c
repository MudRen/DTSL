//��ת����jiuzhuan-jianjue
//�м�-->�ռ��书��


inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N������ָ��һʽ���ޱ���ľ��������ֱ��$n��$l��",
    "apply_factor": 2,
    "name" : "�ޱ���ľ", 
    "damage_type":"����",
  ]),
 ([ "action":"$N̤ǰ�����������ʵ������ʹһʽ���ǳڵ�����ֱ��$n��$l��",
    "apply_factor": 3,
    "name" : "�ǳڵ���",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ�С����ɻ��������ⶶ����佣�����ֱ����$n���������Ҷ���",
    "apply_factor": 4,
    "name" : "���ɻ�",
    "damage_type":"����",
  ]),
  ([ "action":"$N�����ڣ�����ָ��$n��������һ�С�����ǧ��������ɨ$n��$l��",
    "apply_factor": 5,
    "name" : "����ǧ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ�С��ϵ紩�ơ��������й���ƽ��$n��$l��",
    "apply_factor": 6,
    "name" : "�ϵ紩��",
    "damage_type":"����",
  ]),
  ([ "action":"$N��Цһ�����ὣб����һ�С��׺���ա����������$n��$l��",
    "apply_factor": 7,
    "name" : "�׺����",
    "damage_type":"����",
  ]),
  ([ "action":"$Nʹ��������Ϯ�¡���$w��һ������������һ�ɺ�������$n��$l��",
    "apply_factor": 8,
    "name" : "����Ϯ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N�ڿն���ͻȻʹ��һ�С�������ɫ����������Ϣ�ؼ���$n�ı�����ȥ��",
    "apply_factor": 9,
    "name" : "������ɫ",
    "damage_type":"����",
  ]),
  ([ "action":"$N����ǰ��������б����һ�С����ɷ��١�������Ӱ����ֱк��������ס$n�Ϸ���",
    "apply_factor": 10,
    "name" : "���ɷ���",
    "damage_type":"����",
  ]),

});   


string *parry_weapon=({

"$N���񲻶�������$w���Ǻ��ȴ�����ȷ����Ѿ���ס��$n��$v��\n",
"$NͻȻ��$w�������֮�������������е�һ�ӣ���$n���ò�����$v��\n",
"$N�����е�$w����һ��Ȧ�ӣ�Ȼ�󷴴���Բ�Ĵ����ǳ�׼ȷ�ظ���$n��$v��\n",
"$N��$w���𲻶�����$v����Լ���$n������ض��ȱ�$w�̵���$n����֮�£�ֻ�ó���$v��\n"

});

string *parry_hand=({

"$Nˢˢˢ�������Ѿ�����Ϊ�أ�ȴ�и�$nһ����·��$n��æ��Ψһ��·���˳�ȥ��\n",
"$N΢΢һЦ������$w��Ȼ��ס����������$n�������Զ����������̣�$n��æ���к��ˣ�\n",
"$N������㣬�ƺ���$n�Ľ��´�ȥ������ʽ���ϣ��Ѿ�����$n���Ŵ�ȥ��$nһ������æ�������С�\n",
"$N�Ľ�����΢֮����ÿһ�ж��Ƿ������ܣ���$n���ò����к��ˣ�\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}




mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon=me->query_temp("weapon")))
	return notify_fail("�����޽������ѧϰ��ת������\n");
	if(weapon->query("skill_type")!="sword")
	return notify_fail("�����޽������ѧϰ��ת������\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
   return ({"xingchen","liuxing"});
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/jue"))
  return 200;
  return 100;
}


object offensive_target(object me)
{
	int sz;
	object *enemy,target;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ){
	  target=enemy[random(sz)];
	  return target;
	}
	else return 0;
}

int form_array(object me)
{
   object *t,*m,target;
   int i,flag=0,fight_flag=0;
   string skill_name;
   
   t=me->query_team();
   t=t-({0});
   if(sizeof(t)<2) return notify_fail("Ҫʩչ�����־��������������ˣ�\n");
   
   if(time()-me->query_temp("form_busy")<10)
   return notify_fail("���������㣬�޷�ʩչ���־���\n");
   
   for(i=0;i<sizeof(t);i++)
    if(objectp(t[i])){
     if(environment(t[i])!=environment(me))
      return notify_fail("���˲�����վ��һ��\n");
     if(t[i]->query_skill("jiuzhuan-jianjue",1)<160)
      return notify_fail(t[i]->name()+"��ת������Ϊ̫���ˣ�\n");
     skill_name=t[i]->reset_action(t[i]->query_temp("weapon"));
     if(skill_name!="jiuzhuan-jianjue")
     return notify_fail(t[i]->name()+"û��ʹ�þ�ת������\n");
    }
   target=offensive_target(me);
   if(!target)
   return notify_fail("��û��ս����Ŀ�꣡\n");
   m=target->query_team();
   if(!arrayp(m)) return notify_fail("�Է�û����ӣ�û�б�Ҫʹ���󷨣�\n");
   m=m-({0});
   
   message_vision(HIG"$N"+HIG+"һ����Х��ֻ�������־����Ѿ�ʩչ������\n"NOR,me);
   if(me->is_killing(target->query("id")))
    fight_flag=1;
   
   for(i=0;i<sizeof(t);i++){
      if(!t[i]->is_fighting(target)){
        if(fight_flag) {t[i]->kill_ob(target);target->kill_ob(t[i]);}
        else {t[i]->fight_ob(target);target->fight_ob(t[i]);}
      }
      t[i]->set_temp("form_busy",time());
      flag+=COMBAT_D->do_attack(t[i],target,t[i]->query_temp("weapon"),0,2);
   }
   if(flag>=2){
     message_vision("\n�ڡ����־��󡹵ĳ��֮�£�$N�Ķ����Ѿ�ɢ�ң�\n",target);
     m=target->query_team();
     m=m-({0});
     for(i=0;i<sizeof(m);i++)
      if(objectp(m[i])){
        m[i]->dismiss_team();
        m[i]->delete_temp("team_mark");
      }
   }
   
   return 1;
}