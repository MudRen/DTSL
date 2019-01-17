// throwing.c

#include <ansi.h>;
inherit F_CLEAN_UP;
inherit F_COMMAND;
inherit F_DBASE;

int do_throw(object me, object ob, object victim);

private int throw_result(object me, object victim, object ob);

int main(object me, string arg)
{
        string what, who, skill; 
        object ob, victim;

        seteuid(geteuid(me));

        if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
                return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

        ob = present(what, me);
        if( !ob) return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("no_drop"))
                return notify_fail("������������뿪�㡣\n");
        if (ob->query("embedded"))
                return notify_fail("�����������ȡ��������\n");

        if (!(victim = present(who, environment(me))))
                return notify_fail("����û�����Ŀ�ꡣ\n");

        if (!victim)
                return notify_fail("���ﲢ�޴��ˣ�\n");

        if (!living(victim))
                return notify_fail("�ⲻ�ǻ��\n");

        if (victim->query("winner"))
                return notify_fail("���ɶ�"+victim->short()+"������\n");
        
        if(stringp(victim->query("target_id"))&&victim->query("target_id")!=me->query("id"))
	return notify_fail(victim->name()+"������������ս������\n");
	
	if(arrayp(victim->query("target_id"))&&
	   member_array(me->query("id"),victim->query("target_id"))==-1)
	   return notify_fail(victim->name()+"������������ս������\n");

        if (me->is_busy() )
                return notify_fail("��ǰһ��������û�����ꡣ\n");

        if (victim == me) 
                return notify_fail("�αض��һ�٣�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("����Ҫ����������ͻȻ���һ���������������һ������������׼����ʦ���˲�����\n");
        
        if(me->query("pker"))
	return notify_fail("ͨ����������ʵ�ش���ɣ�\n");
	
	if(userp(me) && userp(victim)&&me->query("age")<13)
	return notify_fail("��������ôС��������ʵһ�°ɣ�\n");
	
	if(userp(me) && userp(victim)&&me->query("combat_exp")<300000)
	return notify_fail("�㾭����ô�ͣ�������ʵһ�°ɣ�\n");
                
        if ( userp(me) && userp(victim) && victim->query("age") < 13 )
                return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
        if ( userp(me) && userp(victim) && victim->query("combat_exp") < 15000 )
                return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

        if( ob->query("weapon_prop") && me->is_exert() &&
            ob == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_exert()+"���޷��ӳ�"+ob->name()+"��\n");
        if( ob->query("weapon_prop") && me->is_perform() &&
            ob == me->query_temp("weapon"))
                 return notify_fail("������ʹ��"+me->query_perform()+"���޷��ӳ�"+ob->name()+"��\n");
                 
        return do_throw(me, ob, victim);
}

int do_throw(object me, object ob, object victim)
{
        string msg;

        if( !stringp(msg = ob->query("throw_msg"))&&!me->query_skill("throwing",1) )
             msg = "\n$N��һ���"+ob->name()+"��׼$n���˹�ȥ��\n";
        else
             msg="\n$Nʩչ�������ɰ�����ѧ����һ������"+ob->name()+"��׼$n���˹�ȥ��\n";
        message_vision(msg, me, victim);

        me->start_busy(1);

        throw_result(me, victim, ob);

        return 1;
}

private int throw_result(object me, object victim, object ob)
{
        string *limbs, str, dodge_skill, result,*dodges;
        int ap, dp;mapping action;
        int damage;
        object ob2;
        
        damage=0;
        ap = me->query_str()*me->query_int();
        dp = victim->query_cor()*victim->query_int();
        ap *= me->query("combat_exp")/1000;
        
        dp *= victim->query("combat_exp")/1000;
        ap = random(ap);
        ap +=me->query_skill("throwing",1)/2;
        
        damage=me->query_skill("throwing",1);
        
        victim->add_temp("offenders/"+me->query("id"), 1);

        if ( ap > dp/2){
                limbs = victim->query("limbs");
victim->receive_wound("kee", damage+me->query_str()*damage/30, me);
 victim->receive_damage("kee",(ob->query_weight()/500)+me->query_str()+damage, me);
                
                if(ob->query("throwing")){
                     message_vision(CYN"���ֻ��$N"+CYN+"һ���ҽУ�"+ob->name()+CYN+"��Ȼ����$N"+CYN+"��"+limbs[random(sizeof(limbs))]+"�ϡ�\n"NOR, victim);
                              if(ob->query_amount()>1){
                                 ob->set_amount(ob->query_amount()-1);
                                 ob->set("victim", victim->query("id"));
                                 ob2=new(base_name(ob));
                                 if ((int)ob2->query_amount()>1)
                                 ob2->set_amount(1);
                                 ob2->move(victim);}
                               else{
                                  ob->set("victim", victim->query("id"));
                                  ob->move(victim);}
                                // if(stringp(ob->query("poison"))) victim->apply_condition(ob->query("poison"), ob->query("damage")*2);
                                 victim->receive_wound("kee", me->query_str()*ob->query("weapon_prop/damage"), me);
                                 victim->kill_ob(me);
                }
                else {  
                     message_vision(CYN"$N⧲�������$n"+CYN+"������$N��"+limbs[random(sizeof(limbs))]+"�ϡ�\n"NOR, victim, ob);
                     if(ob->query_amount()>1){
                                 ob->set_amount(ob->query_amount()-1);
                                 ob->set("victim", victim->query("id"));
                                 ob2=new(base_name(ob));
                                 if ((int)ob2->query_amount()>1)
                                 ob2->set_amount(1);
                                 ob2->move(environment(me));}
                               else{
                                  ob->set("victim", victim->query("id"));
                                  ob->move(environment(me));}
                     if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                     else{
                        victim->fight_ob(me);
                        call_out("do_respond", 1, victim, me);
                        }
                }
                me->start_busy(random(3));                

result = COMBAT_D->eff_status_msg((int)victim->query("kee") * 100/(int)victim->query("max_kee"));
        message_vision("($N"+result+")\n", victim);
        }

        else if ( ap < dp/7 && ob->query_weight() < 7000 
                && victim->query("race") == "����"){
                message_vision(CYN"����$N�����ֿ죬����һ�࣬��$n"+CYN+"����ؽ������\n\n"NOR, victim, ob);
                me->start_busy(random(3));
                if(ob->query_amount()>1){
                                 ob->set_amount(ob->query_amount()-1);
                                 ob->set("victim", victim->query("id"));
                                 ob2=new(base_name(ob));
                                 if ((int)ob2->query_amount()>1)
                                 ob2->set_amount(1);
                                 ob2->move(victim);}
                               else{
                                  ob->set("victim", victim->query("id"));
                                  ob->move(victim);}
                if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                else
                call_out("e_mote", 1, victim, me);      
        }

        else {

                dodges=victim->query("dodge");
			    if(sizeof(dodges)==0) dodge_skill = "dodge";
				else dodge_skill=dodges[random(sizeof(dodges))];
                action = SKILL_D(dodge_skill)->query_action(victim);
				str=action["action"];
                message_vision(str+"\n", me, victim);
                me->start_busy(random(3));
                if(ob->query_amount()>1){
                                 ob->set_amount(ob->query_amount()-1);
                                 ob->set("victim", victim->query("id"));
                                 ob2=new(base_name(ob));
                                 if ((int)ob2->query_amount()>1)
                                 ob2->set_amount(1);
                                 ob2->move(environment(me));}
                               else{
                                  ob->set("victim", victim->query("id"));
                                  ob->move(environment(me));}
                
                if (!userp(victim) && victim->query_temp("offenders/"+me->query("id")) > 1)
                        victim->kill_ob(me);
                else
                call_out("do_respond", 1, victim, me);
        }

        return 1;
}


void e_mote(object victim, object me)
{
        int i;
        string *emote = ({
        "sneer", "callname", "consider", "killair", "grin",
        "nonsense", "walkby", "cut", "chicken", "kick", });

        if (!me || environment(me) != environment(victim))
        return;

        i = random(sizeof(emote));

        EMOTE_D->do_emote(victim, emote[i], me->query("id"));
}
        
void do_respond(object victim, object me)
{
        string att; 

        if (!me || !victim || environment(me) != environment(victim))
        return;

        att = victim->query("attitude");

        if (victim->query("shen") < 0)
                return victim->kill_ob(me);

        if (att == "friendly" && victim->query("race") == "����")
                return e_mote(victim, me);
        
        if (att == "heroism" || att == "aggressive")
                return victim->kill_ob(me);     

        if (att == "peaceful" && random(5)== 1) 
                return victim->kill_ob(me);

        else if(victim->query("race") == "����")
        EMOTE_D->do_emote(victim, "brag", me->query("id"));

        return victim->fight_ob(me);    
}

