// Combatd.c
//Written by Yanyan.
//For DaTangShuangLong
//Copyrights DaTangShuangLong.wiz
#pragma optimize

inherit F_DBASE;

#include <ansi.h>
#include <skill.h>
#include <org.h>
#include <weapon.h>
#include <combat.h>
#include <globals.h>


void fight(object me, object victim);
void end_fight(object killer,object victim);
void do_parry(object me,object victim,object weapon);

void create() 
{
	seteuid(getuid());
	set("channel_id", "ս������");

}


string *guard_msg = ({
	CYN "$N"+CYN+"ע����$n"+CYN+"���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N"+CYN+"������$n"+CYN+"��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N"+CYN+"�������ƶ��ţ���Ҫ�ҳ�$n"+CYN+"��������\n" NOR,
  CYN "$N"+CYN+"�۾�����ض���$n"+CYN+"��Ѱ����ѳ��л��ᡣ\n" NOR,
	CYN "$N"+CYN+"Ŀ��ת���ض���$n"+CYN+"�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N"+CYN+"�������ƶ��ţ��Ż����֡�\n" NOR,
});

string *beat_parry=({
	"$n��æ�Ŀ����㿪�˹���!\n",
	"$nѸ�ٵ��ܿ���׼����Ѱ�һ���!\n",
	"$n�ɿ�Ķ㿪��׼���ٴν���!\n",
});

string *beat_guard=({
	CYN"$N"+CYN+"��æ�Ŀ����㿪�˹���!\n"NOR,
	CYN"$N"+CYN+"һ��������׼����Ѱ�һ���!\n"NOR,
	CYN"$N"+CYN+"һ��������׼���ٴν���!\n"NOR,
});

string *catch_hunt_human_msg = ({
	HIW "$N"+HIW+"��$n"+HIW+"������������ۺ죬���̴���������\n" NOR,
	HIW "$N"+HIW+"����$n"+HIW+"��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N"+HIW+"��$n"+HIW+"һ���棬������˵�ʹ���������\n" NOR,
	HIW "$N"+HIW+"һ��Ƴ��$n"+HIW+"�����ߡ���һ�����˹�����\n" NOR,
	HIW "$N"+HIW+"һ����$n"+HIW+"�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N"+HIW+"�ȵ�����$n"+HIW+"�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N"+HIW+"�ȵ�����$n"+HIW+"�����У���\n" NOR,
});

string *catch_hunt_beast_msg = ({
	HIW "$Nŭ��һ�������˹�������$n��\n" NOR,
	HIW "$N����$n�����ɱ��$n��\n" NOR,
	HIW "$N���������ͺ�ͻȻ���𹥻�$n��\n" NOR,
});

string *catch_hunt_bird_msg = ({
	HIW "$N����$nһ��ŭ�����ɳ��˹�����\n" NOR,
	HIW "$Nŭ��������ͻȻ���𹥻�$n��\n" NOR,
	HIW "$Nһ����������Ȼ��$n���𹥻���\n" NOR,
});

string *winner_msg = ({
	CYN "\n$N"+CYN+"΢΢һЦ��˵���������ˣ�\n\n" NOR,
	CYN "\n$N"+CYN+"˫��һ����Ц��˵�������ã�\n\n" NOR,
    CYN "\n$N"+CYN+"Ц������ɽ���ģ���ˮ�������ʹ˰������?\n\n" NOR,   
	CYN "\n$N"+CYN+"ʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	
});
string *winner_animal_msg = ({
	CYN "\n$N����һ�ԣ��������$n���ӣ�\n\n" NOR,
	CYN "\n$N���ؿ���������Ȼ�������ɵض���$n��\n\n" NOR,
	CYN "\n$N���˼���������ʱ�����ٳ������\n\n" NOR
});
string damage_msg(int damage, string type)
{
	string str;
	if( damage <= 0 ) return "�����$nû������κ��˺���\n";

	switch( type ) {
		case "����":
		case "����":
		case "����":
			if( damage < 10 ) return "$N���ֻ������ػ���$n��$l����Ƥ�⡣\n";
			if( damage < 50 ) return "$N�����$n�����ϻ���һ��ϸ����Ѫ�ۡ�\n";
			if( damage < 100 ) return "������͡���һ����$N��$n���ϻ���һ���˿ڣ�\n";
			if( damage < 200 ) return "������͡���һ����$N��$n���ϻ���һ��Ѫ���ܵ��˿ڣ�\n";
			if( damage < 320 ) return "������͡���һ����$N��$n���ϻ���һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
			return "���ֻ����$nһ���Һ�������$n$l�ϻ���һ������ǵĿ����˿ڣ���\n";
		case "����":
			if( damage < 10 ) return "���ֻ������ش���$n$l����Ƥ�⡣\n";
			if( damage < 50 ) return "�����$n��$l�̳�һ�����ڡ�\n";
			if( damage < 100 ) return "������ۡ���һ��������$n$l����\n";
			if( damage < 200 ) return "������ۡ���һ���̽�$n��$l��ʹ$n�������������˼�����\n";
			if( damage < 320 ) return "��������͡���һ�����̽���$n��$l��������Ѫ�漴���˳�����\n";
			return "���ֻ����$nһ���Һ�������$n��$l�Դ���������Ѫ�������أ���\n";
		case "����":
			if( damage < 20 ) return "���ֻ�����������$n��$l�����Ĳ�Ӭ��΢���˵㡣\n";
			if( damage < 40 ) return "�����$n��$l���һ�����ࡣ\n";
			if( damage < 80 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
			if( damage < 100 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
			if( damage < 170 ) return "������项��һ����$n����������\n";
			if( damage < 240 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
			if( damage < 320 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
			if( damage < 450 ) return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
			return "ֻ����$nһ���ҽУ���������������ߵķ���һ�����˳�ȥ����\n";
		case "����":
			if( damage < 20 ) return "���ֻ�ǰ�$n������˰벽����������\n";
			if( damage < 60 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
			if( damage < 100 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
			if( damage < 170 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
			if( damage < 240 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
			if( damage < 320 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
			if( damage < 450 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
			return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		case "����":                
			if( damage < 100 ) return "���$n�ܵ�$N�ľ���һ���ƺ�һ����\n";
			if( damage < 150 ) return "���$n��$N�Ծ���һ�𣬡��١���һ������������\n";
			if( damage < 230 ) return "���$n��$N�Ծ���һ��$l�����ܵ�һ���ش�����������������\n";
			if( damage < 340 ) return "���$N�ľ���һ�����$n�����˺ü�������һ��ˤ����\n";
			if( damage < 450 ) return "���$n��$N�ľ������ȫ����Ѫ������������Ѫ���������\n";
			return "���$n��$N�ľ��������ǰһ�ڣ��������ѣ�����ƾ�շ��˳�ȥ����\n";
		case "����":
			if( damage < 15 ) return "���ֻ������ػ�����$n��$l��\n";
			if( damage < 50 ) return "�����$n��$l���һ��ϸ����Ѫӡ��\n";
			if( damage < 150 ) return "�����ž����һ����$n��$l��Ƥ���������γ�һ���������˿ڣ�\n";
			if( damage < 250 ) return "ֻ��$n��������һ���³�һ����Ѫ��ԭ��$n$l�Ĺ�ͷ�Ѿ����ľ������ѣ�\n";
			if( damage < 350 ) return "������š��ǡ���һ�����ѽ�$n$l���Ĺ�ͷӲ�����س�ϣ��ϹǴ�����ð�˳�����\n";
			return "���$nһ���Һ����Ѵ�$n��$l��˺����һ��ƬѪ���ܵ�Ƥ�⣬��Ѫ�������أ���\n";
		case "����":
		case "����":
			if( damage < 20 ) return "���ֻ���������ײ����$nһ�£�û�����ʲô�˺���\n";
			if( damage < 80 ) return "���ֻ��$n��$l�ҳ�һ�����졣\n";
			if( damage < 160 ) return "�����ž����һ��������$n��$l����ʱ����һ���ϸߣ�\n";
			if( damage < 320 ) return "������صû���$n��$l�����$n�������������ۡ����³�һ�����Ѫ��\n";
			if( damage < 450 ) return "���ֻ�������𡹵�һ�����죬����$n$l����$n��һ�����ݰ���ɳ�ȥ��\n";
			return "���һ�´���$n��$l�������������У�$n��ɢ�˼��Ƶ�̱����ȥ����\n";
		case "ץ��":
			if( damage < 20 ) return "���ֻ����$n$l������ι���û��ʲô�˺���\n";
			if( damage < 40 ) return "���$n������ü��$l���²��Ѿ���������һ��ǳǳ��Ѫ�ۡ�\n";
			if( damage < 80 ) return "���������$n$l��һ��Ƥ�⣬�۵�$n�����ۡ��ֽ���������\n";
			if( damage < 120 ) return "�����ৡ���һ����$n��$l�϶�ʱ��ץ�����Ѫ�ۣ���Ѫ���˳�����\n";
			if( damage < 220 ) return "���$n�۵ô��һ����$l�ϱ�ץ���˼��������Ѫ������Ѫֱ����\n";
			if( damage < 330 ) return "���ֻ����$nһ���Һ���$N����צ����$n$l���̳������Ѫ��ģ���Ŀ�����\n";
			if( damage < 440 ) return "�����������һ���ҽУ�$n��$l��$Nץ����һ��ƬƤ�⣬��Ѫ������أ���\n";
			return "���$nһ����ҵ�˻�У�$l������Ƥ���⳶��һ��飬¶���˰�ɭɭ�Ĺ�ͷ����\n";
               case "ˤ��":
			if( damage < 20 ) return "���$n���²��ȣ��ڵ��ϲ����˵��Ƥ��\n";
			if( damage < 80 ) return "�����ž����һ����$n�ڵ���ˤ�˸�ƨ�⡣\n";
			if( damage < 160 ) return "���$nһ��С�ģ���$N����ˤ���ڵأ�\n";
			if( damage < 300 ) return "���$n��һ��ˤ���ڵأ����۵ء�һ�������һ�����Ѫ��\n";
            if( damage < 420 ) return "�����$N��һ��ˤ�ڵ��ϣ�$l���Ĺ�ͷ�����꡹һ�����ˣ�\n";
			return "���ֻ����$nһ���Һ�����$Nˤ��Ѫ���ɣ��Ҳ��̶ã���\n";
		case "����":
			if(damage<20) return "$Nֻ�ǹ�����$n$l����һ��Ƥ��\n";
			if(damage<40) return "ֻ���͵�һ����$n��$l���Ѿ�����Ѫֱ����\n";
			if(damage<80) return "ֻ��$nһ���ҽУ�$N�Ѿ��Ѿ�������$n$l����¶���˰�ɭɭ�Ĺ�ͷ��\n";
			if(damage<160) return "$N������$n��$l����$n�ҽ�һ��������������ȥ��\n";
			if(damage<300) return "$n��$l������Ѫ����ע���������Ѫ��һ�㣡\n";
			if(damage<420) return "$n��$l�����������꡹һ�����Ѿ���$N�����ˣ�\n";
			return "ֻ��$nһ���ҽУ�����������ߵķ��ݣ���������Ѫ����Զ����ȥ��\n";
		default:
			if( !type ) type = "�˺�";
			str =  "�����$n��ɷǳ����µ�����";
			if( damage < 270 ) str = "�����$n��ɼ������ص�";
			if( damage < 210 ) str = "�����$n���ʮ�����ص�";
			if( damage < 160 ) str = "�����$n����൱���ص�";
			if( damage < 120 ) str = "�����$n�����Ϊ���ص�";
			if( damage < 80 ) str = "�����$n���һ������";
			if( damage < 50 ) str = "�����$n���һ��";
			if( damage < 30 ) str = "�����$n�����΢��";
			if( damage < 10 ) str =  "�����$nֻ����ǿ���һ����΢";
			return str + type + "��\n";
	}
}

string report_status(object ob,int damage)
{
	if(ob->query_temp("no_report"))
		return "";
    
	if(damage>=80) 
    	return "($n"+HIY+"���������˼����ˣ������ƺ��������¡�"+NOR+")\n";
	else 
	if(damage>=60) 
		return "($n"+HIY+"���˲��ᣬ������״������̫�á�"+NOR+")\n";
	else 
	if(damage>=40) 
		return "($n"+HIR+"��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ"+NOR+")\n";
	else 
	if(damage>=30) 
		return "($n"+HIR+"�Ѿ��˺����ۣ���������֧���Ų�����ȥ��"+NOR+")\n";
	else 
	if(damage>=20)
		return "($n"+HIR+"���������˹��أ�ֻ�»�������Σ�ա�"+NOR+")\n";
	else 
	if(damage>=10) 
		return "($n"+RED+"����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϣ�"+NOR+")\n";
	else 
    	return "($n"+RED+"���˹��أ��Ѿ�������в�����ʱ�����ܶ�����"+NOR+")\n";
}
void report_sen(object ob,int sen)
{
	if(ob->query_temp("no_report"))
    	return;
	
	if(sen>=50){
		message_vision("\n($N"+CYN+"�Ѿ��������꣬������״������̫�á�"NOR")\n",ob);
		return;
	}
	else if(sen>=40){
		message_vision("\n($N"+CYN+"�������Ѿ��ƺ�ʮ��ƣ����Ӧ����Ϣһ���ˡ�"+NOR+")\n",ob);
		return;
	}
	else if(sen>=30){
		message_vision("\n($N"+CYN+"�Ѿ��۵�ͷ���ۻ����е�ҡҡ�λ��ˣ�"+NOR+")\n",ob);
		return;
	}
	else if(sen>=20){
		message_vision("\n($N"+CYN+"�Ѿ�û��ʲô�����ˣ����Ͼ�Ҫ�赹�ˣ�"NOR")\n",ob);
		return;
	}
	else{
		message_vision("\n($N"+CYN+"�Ѿ��ֽŷ�����Ҫ���ڵ����ˣ�"+NOR+")\n",ob);
		return;
	}
}

int status(object ob,int wound)
{
	
	if(wound)
		return (int)ob->query("eff_kee",1)*100/(int)ob->query("max_kee",1);
	else
		return ob->query("kee")*100/ob->query("max_kee",1);		

}
int sen_status(object ob)
{

	if(((int)ob->query("sen",1)*100)/(int)ob->query("max_sen",1)>100)
		return 100;
	return ((int)ob->query("sen",1)*100)/(int)ob->query("max_sen",1);
}

void announce(object ob, string event)
{
	switch(event) {
		case "dead":
			message_vision("\n$N��ž����һ�����ڵ��ϣ������ų鶯�˼��¾����ˡ�\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N��־�Ժ�������һ�����ȣ����ڵ��ϻ��˹�ȥ��\n\n", ob);
			break;
		case "revive":
		        if(ob->query("blind") || ob->query("race") != "����")
			     message_vision("\n$N����һ����Ť���˼��£������˹�����\n\n", ob);
			else if(ob->query("mute"))
			     message_vision("\n$N���������˹����������۾�վ����ҡ��ҡͷ��\n\n", ob);
			else message_vision("\n$N���Ӷ��˶������������˼��������ѹ�����\n\n", ob);
			break;
	}
}

string eff_status_msg(int ratio)
{
   if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
   if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
   if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
   if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
   if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
   if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
   if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧���Ų�����ȥ��" NOR;
   if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
   if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
   if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
   return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

varargs int skill_power(object ob, string skill, int usage)
{
	return 1;
}

int get_exp_inflict(object attack,object defense)
{
	return (attack->query("combat_exp")-defense->query("combat_exp"))*5/30000;
}

//���㹥���߽�����ɵ��˺���
int get_damage(object me,object victim,object weapon,mapping action,mapping apply_action,string skill_name)
{
	int damage,skill_level,base_skill_level;
	int damage_factor;
	string base_skill;
	int w_damage,w_min_damage,w_max_damage;
	int w_strong;
	int str_factor;
   
	damage=0;
	skill_level=0;
	base_skill_level=0;
   
   //�б�����û�б���ʱ�ĸ����˺���
   
	if(weapon&&weapon->query("max_strong")){
		w_strong=weapon->query("strong");
		if(w_strong<0) w_strong=0;         
		w_min_damage=me->query_temp("apply/min_damage")+me->query_temp("apply/enhance_min_damage")+
                me->query_temp("apply/double_damage");
		w_max_damage=me->query_temp("apply/damage")+me->query_temp("apply/enhance_max_damage")+
                me->query_temp("apply/double_damage");
		if(w_min_damage>w_max_damage) 
			w_min_damage=w_max_damage;
       
		if(weapon->query("save_flag")&&userp(me))
			damage=w_min_damage+random(w_max_damage-w_min_damage);
		else
			damage=w_max_damage;
          
		damage=damage-damage*(weapon->query("max_strong")-w_strong)/weapon->query("max_strong");
     
		if(userp(me)&&weapon->query("save_flag")&&
				weapon->query("user")!=me->query("id"))
			damage=damage/5;
		else
			damage +=weapon->query("user_skill")/10;
	}   
	else 
		damage=me->query_temp("apply/damage");
   //the end {�б�����û�б���ʱ�ĸ����˺�}
   
   //����(jiali)��ɵ��˺�������ʱЧ�����б���ʱЧ���ã�
   //��Ϊ�����и����˺���
	if(me->query("jiali",1)&&me->query("force",1)>me->query("jiali",1)){
		me->add("force",-(int)me->query("jiali",1));
		if(!weapon)
			damage +=(int)me->query("jiali",1)*5/3;
		else
			damage +=me->query("jiali")/2;
	}
   //the end {����(jiali)��ɵ��˺�}
      
  // the end {������ɵ��˺�}
	if(stringp(skill_name)
			&&intp(SKILL_D(skill_name)->skill_damage(me,victim)))
		damage +=SKILL_D(skill_name)->skill_damage(me,victim);
   
   
   //�����ܵĵȼ����뵽 �˺��С�
   // �������㣬��Ȼʹ�˺�����ֵ�Ӵ󣬵���Ե�
   //����һ���� parry ����Ҳ����˼��㣬���Բ������ܴ�
   // �����˺�=���⼼��+��������/2
	if(stringp(skill_name)){
		if(weapon) 
			skill_level=(int)me->query_skill(skill_name,1);
		else
			skill_level=(int)me->query_skill(skill_name,1)*3/2;
      
		if(stringp(base_skill=SKILL_D(skill_name)->query_base())){
			if(base_skill!="base"){
				base_skill_level=(int)me->query_skill(base_skill,1);
				damage +=(skill_level+base_skill_level/2);
			}
		}
    	else
    		damage +=(skill_level);		    
	}
   
   str_factor = me->query_str();
   damage = damage+(damage/4)*str_factor/20;
   
   return damage+damage*damage_factor/40;
}

//���㹥���ߵĹ�������Ҳ�������ݶȣ������ͷ����ߵ�
//������Ƚϣ����Ƿ��ܻ��жԷ���
int get_attack(object me,object victim,mapping action,mapping apply_action)
{
	int me_attack;
	int dex_factor;
	string *me_dodges,me_dodge;
   
   //���Ƿ��и������ݡ���ѥ�ӻ������书���á�
	if(me->query_temp("apply/dodge"))
		me_attack=me->query_temp("apply/dodge");
	else 
		me_attack=0;
      
   //���Ṧ�ȼ����뵽�����У�
   //��Ч�ȼ�������+����/2�����ѧ�����������������Ṧ��
   //�����ѡһ����
	me_dodges=me->query("dodge");
	if(sizeof(me_dodges)>0){
		me_dodge=me_dodges[random(sizeof(me_dodges))];
		me_attack=me_attack+(int)me->query_skill(me_dodge,1);
		me_attack = me_attack+SKILL_D(me_dodge)->query_dodge(me);
	}
	me_attack=me_attack+(int)me->query_skill("dodge",1)/2;
     
	if(me_attack>=0){
		//�����������>0�������������ӡ�
		dex_factor=me->query_dex(); 
		me_attack=me_attack+(me_attack/4)*dex_factor/15;
	}
	else 
		me_attack=random(me->query_dex());
   
	if(me->is_busy())
		me_attack = me_attack-me_attack/3;
      
	if(me_attack<0) 
		me_attack=0;
	return me_attack;
}

int get_parry(object victim)
{
	int victim_parry,defence_factor,armor;  
  
	victim_parry=0;
    
	//�����и��Ӳ��֡�����׻������ڹ���
	armor=victim->query_temp("apply/armor")+victim->query_temp("apply/parry");
//	if(armor>1000) armor=1000;
 
	victim_parry=victim_parry+armor;
  
	//�������ո��������ӡ�
	defence_factor=victim->query_con();
   
  
	//�������ϻ����мܵĵȼ���
	victim_parry +=victim->query_skill("parry",1)*3/2;
	if(!victim->query_temp("weapon"))
		victim_parry=victim_parry+victim_parry/3;
	else
		victim_parry=victim_parry+victim_parry/5;
  
	//�������æ��״̬���������٣�
	victim_parry=victim_parry+(victim_parry/4)*defence_factor/10;
  
	if(victim->is_busy()) victim_parry=victim_parry-victim_parry/3;
  
	if(victim_parry>0)
		return victim_parry;
	else 
		return 1;
}

varargs int do_perform_attack(int damage,int reduce_dex,string msg,
						object me,object target,object weapon,mapping apply_action,int quick,
            			string damage_type)
{
	int flag;
	
	me->add_temp("apply/damage",damage);
	me->add_temp("apply/dodge",reduce_dex);
	if(msg!="")
    	me->set_temp("action_msg",msg);
    flag = COMBAT_D->do_attack(me,target,weapon,apply_action,2,damage_type);
    me->add_temp("apply/damage",-damage);
    me->add_temp("apply/dodge",-reduce_dex);
    me->delete_temp("action_msg");	
    
    return flag;
	
}
   
varargs int do_attack(object me,object victim,object weapon,mapping apply_action,int quick,
            string damage_type)
{
	mapping action,dodge_action;
	string skill_name;
	int em,wound;
	int ap,me_status,me_sen;
	int pp,vp,victim_sen,victim_status;
	string report_damage,get_damage_type;
	string *limb,l,combat_msg;
	string *dodges,victim_dodge;
	int damage;int exp_inflict;
	int hit_victim,parry_flag;
	int reward_p=90;
	
	int skill_damage;
	int me_exp,victim_exp;
	
	if(!me||!victim) 
		return 0;
	
	me_exp = me->query("combat_exp");
	victim_exp = victim->query("combat_exp");
	wound=0;
	hit_victim=0;//�˱��������ж��Ƿ���е��ˣ���Ϊ������ֵ��
	parry_flag=0;//�˱��������ж��Ƿ��мܡ�
	combat_msg="";
	victim_sen=-1;
	victim_status=-1;
	limb=victim->query("limbs");
	l=limb[random(sizeof(limb))];
	
	if(me->query_temp("apply_pause_fight")>0){		
		message_vision(CYN"\n$N"+CYN+"ʩչ�������������Ϣ���ң���æ��ס�Ż���\n"NOR, me);		
		return 0;
	}
	
	if (userp(victim) && living(victim)&&victim->query("age")>12
	&& 3*me_exp >= 2*victim_exp){
    	victim->receive_damage("sen", 2+random(2));
		if (victim->query("sen") * 100 / victim->query("eff_sen") < 20)
			tell_object(victim, HIR "\n����������������ˣ�\n" NOR);
    }
        
	if(me->query("force_quest/csj_ok")){
    	if(me->query("force_quest/csj1")&&victim->query("apply_points")>0&&
              !present("huolong neidan",victim)){            
        	skill_damage=me->query_skill("changsheng-jue",1)/8;
            
            if(present("bingpo shenzhu",victim))
            	skill_damage/=2;
            if(victim->query_skill("huanri-dafa",1)>=me->query_skill("changsheng-jue",1))
            	skill_damage/=2;
            
			if(skill_damage>0){
            	victim->add("apply_points",-skill_damage);
            	if(victim->query("apply_points")<0)
            	victim->set("apply_points",0);
			}
		}
		if(me->query("force_quest/csj2")&&victim->query("force")>0
             &&!present("bingpo shenzhu",victim)){
            skill_damage=me->query_skill("changsheng-jue",1)/8;
            
            if(present("huolong neidan",victim))
            	skill_damage/=2;
            if(victim->query_skill("huanri-dafa",1)>=me->query_skill("changsheng-jue",1))
            	skill_damage/=2;
            
			if(skill_damage>0){
				victim->add("force",-skill_damage);
            	if(victim->query("force")<0)
            	victim->set("force",0);
			}
		}
	}
	//choose actions.

	if(!me->query("actionp")){//if you have perform or exert action.
		skill_name=me->reset_action(weapon);//new reset_action() at /feature/attack.c by yanyan.
		action=me->query("actions");
	}
	else{
		action=me->query("actionp");
		skill_name=action["skill_name"];
	}
	if(me->query_temp("action_msg"))
		combat_msg=me->query_temp("action_msg");//�����action_msg��������ս������Ϊ�˱�����
	else
		combat_msg=action["action"];
	if(weapon)
		combat_msg = replace_string(combat_msg, "$w", weapon->query("name"));
   
	combat_msg = replace_string(combat_msg, "$l", l);
   
	combat_msg ="\n"+combat_msg+"\n";
	//me_attack now.
	ap=get_attack(me,victim,action,apply_action);   
	//vdodge now.
	vp=get_attack(victim,me,0,0);
	dodges=victim->query("dodge");
	if(sizeof(dodges)>0)
		victim_dodge=dodges[random(sizeof(dodges))];
   
	//if(me_attack>vdodge)   //hit victim or not!
	if(!living(victim)||random(ap+vp)>vp*2/3||vp*3<ap){
		//only attack-dodge>10 you can must hit the victim!
		// damage now.or since your attack is high,the victim maybe dodge.
		damage=get_damage(me,victim,weapon,action,apply_action,skill_name);
		//parry now.
		pp=get_parry(victim);
   
		exp_inflict=get_exp_inflict(me,victim);
		damage = damage+(exp_inflict);
   
		if(damage<0)
			damage = 0;
		//if victim can parry:	    
		if((damage>pp&&(damage-pp)>(random(20)))
      			||!living(victim)||random(damage+pp)>pp||damage>2*pp){
	     	
			hit_victim=1;//���е��ˡ�
	     	
			if(damage<pp){
				if(!damage_type)
					victim->receive_damage("kee",damage/4,me);
				else
					victim->receive_damage(damage_type,damage/4,me);
			}
			else{
				if(!damage_type)
					victim->receive_damage("kee",(damage-pp*2/3),me);
				else
					victim->receive_damage(damage_type,(damage-pp*2/3),me);
			}
			//���жԷ����������顣
			if(victim->query("reward_p"))
				reward_p=victim->query("reward_p");
			if(me_exp>=victim_exp){
				if(me_exp-victim_exp>100000){
					if(random(100)>reward_p+20){ //����ͱ��Լ��� 100K���� fight ,�õ����١�
						me->add("combat_exp",victim->query("reward_exp")/3+random(1));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/3+random(1));
						//me->add("potential",victim->query("reward_pot")+random(3));
					}
				}
				else{
					if(random(100)>reward_p){//����ȶԷ��߲��࣬��õ��ļ��ʴ�Щ
						me->add("combat_exp",victim->query("reward_exp")/2+random(1));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/2+random(1));
					//me->add("potential",victim->query("reward_pot")+random(3));
					}
				}
			}
			else{
				if(victim_exp-me_exp>100000){
					if(random(100)>reward_p+20){
						me->add("combat_exp",victim->query("reward_exp")+random(3));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")+random(1));
						//me->add("potential",victim->query("reward_pot")+random(8));
					}
				}
                else{
					if(random(100)>reward_p){
						me->add("combat_exp",victim->query("reward_exp")+random(3));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/3+random(1));
						//me->add("potential",victim->query("reward_pot")+random(10));
					}
				}
			}
      
			//�����У��õ�Ǳ��
			if(random(100)>reward_p){
				victim->add("potential",me->query("reward_pot")+random(2));
				if(victim->query("potential")>victim->query("max_pot")*5)
					victim->set("potential",victim->query("max_pot")*5);
			}
      
			//�˺����޵�������
			//1) �˺�+�м� �������>�м�+���׵������
			//2) �˺��������>����
			//3) ��������������
			if(random(damage+pp)>pp+random(victim->query_temp("apply/armor"))
						&&random(damage)>victim->query_temp("apply/armor")
						&&random(ap+vp)>vp){
      	     
				damage = damage-pp;
         
				//��� ap �� vp С�ܶ࣬���������������жԷ���
				//���Դ�ʱ�Է��������˺�Ӧ�ý��ͣ�Ϊԭ���� 1/3
				if((ap-vp)<random(100))	        	
					damage=damage/3;
				if(damage<0){
					if(!damage_type)
						victim->receive_wound("kee",10,me);
					else
						victim->receive_wound(damage_type,10,me);
				}
				else{
					if(!damage_type)
						victim->receive_wound("kee",damage,me);
					else
						victim->receive_wound(damage_type,damage,me);
				}
      
				wound=1;//report status.
			}
		   
			if(apply_action)
				get_damage_type=apply_action["damage_type"];
			else
				get_damage_type=action["damage_type"];
			if(victim->query_temp("back_damage")||victim->query_temp("back_wound")){
				combat_msg+="$n�������壬$N�����Լ��Ĺ���������\n\n";
				message_vision(combat_msg,me,victim);
				combat_msg=damage_msg(damage,get_damage_type);
				combat_msg=replace_string(combat_msg, "$l", l);		   
				victim_status=status(me,wound);	  
				combat_msg +=report_status(me,victim_status);          
				message_vision(combat_msg,victim,me);
			}
			else{
				combat_msg+=damage_msg(damage,get_damage_type);
				combat_msg=replace_string(combat_msg, "$l", l);	
				victim_status=status(victim,wound);	  
				combat_msg +=report_status(victim,victim_status);          
				message_vision(combat_msg,me,victim);
			}	   
			if(random(50)>25)
				victim->add("potential",random(3));
		   
			if(random(me->query("max_pot"))>100&&random(50)>25)
				me->improve_skill(skill_name,random(10));
	  
			if(weapon){
				//1)ֻ�� me �� victim ��������ʱ�Ż�ʹ���������˺���
				//2)me ��ɱ��� victim ��ɱ���ܶࡣ	
				if(random(10)>7
						&&me_exp-victim_exp<300000
						&&me_exp-victim_exp>-300000
						&&random(me->query("apply_points"))>random(victim->query("apply_points")))
					weapon->improve(1+random(1));
				if(weapon->query("poison"))
					if(!victim->query_condition("quest_poison"))
						victim->apply_condition("quest_poison",weapon->query("poison"));
			}
			if(!apply_action)
				if(functionp(action["post_action"]))
					evaluate(action["post_action"],me,victim,weapon,damage);
	  
			if(me&&victim)// hit_ob
				SKILL_D(skill_name)->hit_ob(me,victim);			
			
			if(me&&victim&&weapon)//weapon hit_ob.
				weapon->hit_ob(me,victim);
			if(me&&victim)
				me->hit_ob(me,victim);
	  
		}//the end of{ if victim can parry}.
		else{  
			//victim �ܵ��������˺����������мܣ�
			if(!damage_type)
				victim->receive_damage("kee",random(5),me);
			else
				victim->receive_damage(damage_type,random(5),me);
			message_vision(combat_msg,me,victim);
			do_parry(me,victim,weapon);
	   		parry_flag=1;
	  	}
	}//the end of {if victim can dodge}.  
	else{   
		if(victim_dodge){  
			//����������Ṧ������ vp �� ap ��ܶ࣬������Ṧ����
			//�������мܡ�
			if(random(ap)<random(vp)&&living(victim)){ 	 	
				dodge_action=SKILL_D(victim_dodge)->query_action(victim);
				combat_msg +=dodge_action["action"]+"\n";
				message_vision(combat_msg,me,victim);
				if(functionp(dodge_action["skill_dodge"]))
				evaluate(dodge_action["skill_dodge"],me,victim);
			}
			else{ 
				//����Ƕ��ֻ����������
				if((string)victim->query("race")!="����"&&living(victim)){	     	
					combat_msg +=beat_parry[random(sizeof(beat_parry))];
					message_vision(combat_msg,me,victim);
				}
				else{
					message_vision(combat_msg,me,victim);
					do_parry(me,victim,weapon);	     
					parry_flag=1;
				}
			}		  
		}
		else//��� vp �� ap ��ܶ࣬��ʹ����ͨ�Ṧ�������������мܡ�
		if(random(ap)<random(vp)&&living(victim)){       	  
			dodge_action=SKILL_D("dodge")->query_action(victim);
			combat_msg +=dodge_action["action"]+"\n";
			message_vision(combat_msg,me,victim);
		}
		else{   
			if((string)victim->query("race")!="����"&&living(victim)){
				combat_msg +=beat_parry[random(sizeof(beat_parry))];
				message_vision(combat_msg,me,victim);
			}
			else{
				message_vision(combat_msg,me,victim); 		    
				do_parry(me,victim,weapon); 
				parry_flag=1;
			}
	   
		}
	}//the end of{victim can dodge or parry}
	victim_sen=sen_status(victim);
  
	if(!victim->query("env/wimpy")){
		if(((victim_sen>=0&&victim_sen<=50)
				||(victim_status>=0&&victim_status<=50))
				&&!me->is_killing(victim->query("id"))
				&&!victim->is_killing(me->query("id"))){
			end_fight(me,victim);
			return hit_victim;
		} 
	}
	else{
		if(((victim_sen>=0&&victim_sen<=victim->query("env/wimpy"))
				||(victim_status>=0&&victim_status<=victim->query("env/wimpy")))
				&&!me->is_killing(victim->query("id"))
				&&!victim->is_killing(me->query("id"))){
			end_fight(me,victim);
			return hit_victim;
		} 
	}
  
	if((victim->query_temp("guarding"))
			&&parry_flag&&!victim->is_busy()
			&&!victim->query_temp("apply_pause_fight")){     
		victim->delete_temp("guarding");
		if( random(me->query("dex")) < 5 ) {
			message_vision("$Nһ�����У���ʧɫ������¶����������\n", me);
			do_attack(victim, me, victim->query_temp("weapon"),0, TYPE_QUICK);
		} 
		else{
			message_vision("$Nһ��$n����ʧ�󣬶�ʱ�û�����������\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"),0, TYPE_QUICK);
		}
	}
    
    return hit_victim;//����ֵ���Ƿ���е��ˡ�
}

void do_parry(object me,object victim,object weapon)
{  
	object vweapon;
	vweapon=victim->query_temp("weapon");
	"/adm/daemons/parryd.c"->do_parry(me,victim,weapon,vweapon);
}

void fight(object me, object victim)
{
	object weapon = me->query_temp("weapon");
        
	me->set_temp("last_damage_from",victim);
	victim->set_temp("last_damage_from",me);
                
	if( !living(me) || me->query("env/yield")||
		me->query_temp("no_eff_combat")) return;	

	if (!me->is_killing(victim->query("id"))
			&& member_array(me, victim->query_enemy()) > 4) 
	return;
	
	if(userp(me)
			&&userp(victim)
			&&(me->query("apply_points")-victim->query("apply_points"))/100>0
			&&random(10)>5){
		victim->start_busy((me->query("apply_points")-victim->query("apply_points"))/100);
		message_vision(CYN"\n$n"+CYN+"��$N"+CYN+"�������ȣ����α�óٻ��ˣ�\n"NOR,me,victim);
	}

// If victim is busy or unconcious, me start to attack!
	if( victim->is_busy() || !living(victim)||victim->query_temp("apply_pause_fight") ) {
		me->delete_temp("guarding", 0);
		if( !victim->is_fighting(me) ) 
			victim->fight_ob(me);
						
	    if(objectp(weapon=me->query_temp("weapon"))) 
	    	do_attack(me,victim,weapon,0,TYPE_QUICK);
		else   
			do_attack(me,victim,0,0,TYPE_QUICK);		
	
        // Else, see if we are brave enough to make an aggressive action.
	}
	else 
	if( me->query_temp("guarding")||me->query_temp("combat")
			|| random( (int)victim->query_dex()*2) < (int)me->query_dex()) {
		me->delete_temp("guarding");
		if( !victim->is_fighting(me) )
			victim->fight_ob(me);  
					
		if(objectp(weapon=me->query_temp("weapon"))) 
			do_attack(me,victim,weapon,0,TYPE_QUICK);
		else   
			do_attack(me,victim,0,0,TYPE_QUICK);
		// Else, we just start guarding.
	} 
	else{
		me->set_temp("guarding", 1);
		if(me->query("race")=="����")
			message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		else
			message_vision( beat_guard[random(sizeof(beat_guard))], me, victim);
			
	}

}
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 1, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if(     me->is_fighting(obj)                            // Are we busy fighting?
	||      !living(me)                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	shen = -me->query("shen");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if( wizardp(me) || !userp(me) || (int)me->query("neili") > (random(shen) + shen)/20 ) return;

	if( shen/2 > random((int)me->query("combat_exp"))
	&&      !wizardp(obj) ) {
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɣ�\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We found our hatred! Charge!
	if (environment(me)==environment(obj)) {
		switch(me->query("race")) {
			case "����":
			case "Ұ��":
				message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
				break;
			case "����":
				message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);
				break;
			default:
				message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
		}
		me->kill_ob(obj);
	} else if (me->query("race")=="����" && random(4) == 2) {
		tell_object(me, HIW "�����Զ��"+obj->name()+"�ı�Ӱ�е����´α����ҿ����㣡\n" NOR);
		tell_room(environment(me), HIW+me->name()+"����Զ��"+obj->name()+"�ı�Ӱ�е����´α����ҿ����㣡\n" NOR, ({me}));
		tell_object(obj, HIW+me->name()+"��Զ������е����´α����ҿ����㣡\n" NOR);
		tell_room(environment(obj), HIW+me->name()+"��Զ����"+obj->name()+"�е����´α����ҿ����㣡\n" NOR, ({obj}));
	}
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We found our vendetta opponent! Charge!
	message_vision(HIW "$N��$n�ȵ���"+RANK_D->query_rude(obj)+"�����ҶԱ��ŵ����¶��֣������ɣ�\n" NOR, me, obj);
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

void pause_fight(object killer,object victim,string type)
{
    message_vision(HIY"\n$N"+HIY+"һʱ���������˶�$n"+HIY+"�Ĺ�����\n"NOR,killer,victim);
    victim->set("eff_" + type,0);
    victim->set(type,-10);
    killer->remove_killer(victim);
    victim->remove_killer(killer);
}
	  

void end_fight(object killer,object victim)  //Fight over!
{ 
	string shili;
		
	if((string)killer->query("race")=="����"||!killer->query("race"))
		message_vision(winner_msg[random(sizeof(winner_msg))],killer);
	else 
	if((string)killer->query("race")!="����")
		message_vision(winner_animal_msg[random(sizeof(winner_animal_msg))],killer,victim);
	killer->delete_temp("last_damage_from");
	victim->delete_temp("last_damage_from");
	
	if(victim->is_end_fight(killer)||
			killer->is_end_fight(victim))
		killer->remove_enemy(victim);
	else
		killer->remove_all_enemy();
       
	if(!killer||!victim) return;	
       
	if(victim->is_end_fight(killer)||
			killer->is_end_fight(victim))
		victim->remove_enemy(killer);
	else
		victim->remove_all_enemy();
	
	if(!killer||!victim) return;
	
	if(killer->query_temp("gage")==victim&&
			victim->query_temp("gage")==killer&&
			victim->query("shili/leader")){
		killer->set("shili/leader",victim->query("shili/leader"));
		victim->delete("shili/leader");
		shili=killer->query("shili/leader");
		if(shili=="lifa_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��������֮λ��", killer->name()));
		else 
		if(shili=="songjia_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s����μұ�����֮λ��", killer->name()));
		else
		if(shili=="duzun_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��ö��𱤱���֮λ��", killer->name()));
		else
		if(shili=="dajiang_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��ô�������֮λ��", killer->name()));
		else
		if(shili=="haisha_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��ú�ɱ�����֮λ��", killer->name()));
		else
		if(shili=="feima_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��÷�����֮λ��", killer->name()));
        if(!userp(victim))
			ORG_D->del_leader(victim->query("shili_id"));
        ORG_D->set_leader_log(killer,victim);
        killer->delete_temp("gage");
        victim->delete_temp("gage");						
		victim->save();
	}
	if(environment(killer)->query("end_fight"))
		environment(killer)->end_fight(killer,victim);
	killer->end_fight(killer,victim);
	victim->surrender(killer,victim);
       
	return;
	 
}

void killer_reward(object killer, object victim)
{
		
	if(userp(killer)){//���ɱ���������
		if(!environment(killer)->query("no_death")&&
				killer->is_killing(victim->query("id"))){
			if(userp(victim))
				killer->add("PKS",1);  		          
			else
				killer->add("MKS",1);
		}
		if(victim->query("guard")){//���ɱ�˹ٱ�
			killer->set("killer",victim->query("guard"));
			killer->set("killer_time",time());
		}
		if(killer->query("vocation")=="ɱ��"){
			if(userp(victim)){
				killer->add("bellicosity",10);
				killer->add("vocation_score",(victim->query("famous")+100)/1000);
			}
			else
				killer->add("bellicosity",2);		 
		}
		else{
			if(userp(victim))
				killer->add("bellicosity",5);
			else
				killer->add("bellicosity",1);
		}
		//�ж��Ƿ񽫱��ͨ������
		if(userp(killer)
	           &&userp(victim)
	           &&killer->is_killing(victim->query("id"))
	           &&!environment(killer)->query("no_death")
	           &&!environment(killer)->is_city_war_room()
	           &&victim->query("age")>12
	           &&!victim->query("pker")){
	         //ͨ�����趨��  
	         //killer->set("pk_target_id",victim->query("id"));
                 //killer->set("pk_target_id_time",time());
                 //killer->add("TIME_PKS",1);
                 //killer->set("TIME_PKS_TIME",time());
		 	killer->add("pker",1);
		 	killer->set("pker_time",time());
		 	//if(!killer->query_condition("pker_msg"))
		 	//	killer->apply_condition("pker_msg",1);		  
            ORG_D->org_lose(victim);//���Ĵ����ܵ���ʧ��
            //������μұ����ӣ�
			if(killer->query("family/family_name")=="�μұ�"){
				if(victim->query("family/family_name")=="�μұ�"){
					killer->add("kill_same_party_flags/times",1);
					killer->add("kill_same_party_flags/killers",10);                    
					if(!killer->query_condition("kill_same_party"))
						killer->apply_condition("kill_same_party",10);
				}
				if(victim->query("family/family_name")=="������Ժ"||
                       victim->query("family/family_name")=="������"||
                       victim->query("family/family_name")=="�Ⱥ���ի"||
                       victim->query("family/family_name")=="�Ľ���")
					victim->add("kill_good_party_flags",1);
                    
			}
		}              	           
	}//the end of {if the killer is player}

    //�����ɱ������ң�
	if(userp(victim)){   	
		if(killer->query("race")=="����"){
			if(!killer->is_killing(victim->query("id"))
					&&!victim->is_killing(killer->query("id")))
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%sʧ��ɱ���ˡ�", victim->name(), killer->name()));
			else 
			if(!killer->is_killing(victim->query("id"))
					&&victim->is_killing(killer->query("id")))
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%s��������ɱ���ˡ�", victim->name(), killer->name()));
			else
			if((int)victim->query("beipan",1)>=3)
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("��ͽ%s��%sɱ���ˡ�", victim->name(), killer->name()));
			else
			if(victim->query("vocation")=="ɱ��")
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("ְҵɱ��%s��%sɱ���ˡ�", victim->name(), killer->name()));
			else 
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%sɱ���ˡ�", victim->name(), killer->name()));
		}//the end of {if the killer is human}
		else{
			if(killer->query("race")=="����")
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%s�����ˡ�", victim->name(), killer->name()));
			else
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��%sɱ���ˡ�", victim->name(), killer->name()));
		}
         
		//ͨ������ɱ��
		if(userp(victim)&&victim->query("pker")
				&&!environment(victim)->query("no_death")){
			CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("ͨ����%s��%s�͵������ˡ�", victim->name(), killer->name()));
	    	if(userp(killer)||killer->is_defence_guard()){
				if(killer->is_defence_guard()){
					victim->set("pker_lose",victim->query("pker")-1);
					victim->set("zuolao",victim->query("pker"));
					victim->set("zuolao_time",time());
				}
				else{
					victim->set("pker_lose",victim->query("pker"));
					killer->set_temp("rank/class","�����е�");
				}
				victim->delete("pker");
			}
			
		}
	 
		//�������Ч�����ص㣬�򽵵�ɱ����
		if(!environment(victim)->query("no_death")){
			victim->set("bellicosity",0);
			//victim->add("office_number",-victim->query("office_number")/100);
			victim->save();//���浵��
		}
         
         
	}//the end of {if the victim is player}
    
	victim->delete_temp("last_damage_from");
	killer->delete_temp("last_damage_from");
	killer->remove_killer(victim);
	victim->remove_all_killer(killer);
                         
	if(environment(killer)->query("killer_reward"))
		environment(killer)->killer_reward(killer,victim);
  	killer->kill_object(killer,victim);   
	if(killer&&userp(killer))
		killer->save();
	if(victim&&userp(victim))
		victim->save();//���浵��
   //the end of function { killer_reward}
}
