// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");
        
        if(query_temp("no_receive_damage_"+type))
        return 1;
        
        if(query_temp("back_damage")&&objectp(who)){
	    who->receive_damage(type,
	    query_temp("back_damage")*damage/(query_temp("back_damage")+80));
	  return 1;    
	}
	
        
	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query(type) - damage;

	set(type, val);
	set_heart_beat(1);
		
	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");
        
        if(query_temp("no_receive_wound_"+type))
        return 1;
        
        if(query_temp("back_wound")&&objectp(who)){
	    who->receive_wound(type,
	    query_temp("back_wound")*damage/(query_temp("back_damage")+80));
	    return 1;    
	}
	
        
	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query("eff_" + type) - damage;

	set("eff_" + type, val);
	if( (int)query(type) > val ) set(type, val);
	if( who&&(who->query("family/family_name")=="������Ժ"||
	         who->query("family/family_name")=="�Ⱥ���ի"
	         )
	   &&!who->is_killing(query("id"))
	   &&living(this_object())
	   &&userp(this_object())
	   &&userp(who)
	   &&query("eff_" + type)<=0
	  )
	 COMBAT_D->pause_fight(who,this_object(),type);
	 
	set_heart_beat(1);
		
	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater,killer;
	
	
	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;
	

	if(objectp(killer=this_object()->query_temp("last_damage_from")))
		if(!this_object()->is_killing(killer->query("id"))&&!killer->is_killing(this_object()->query("id")))
		COMBAT_D->end_fight(killer,this_object());
	
	if(!this_object()) return;//�����жϣ���Ϊend_fight��������������
	
	if( ! this_object()->query("possessed"))
	this_object()->remove_all_enemy();

	message("system", HIR "\n�����ǰһ�ڣ�����ʲ��Ҳ��֪����....\n\n" NOR,
		this_object());
	COMBAT_D->announce(this_object(), "unconcious");
	this_object()->disable_player(" <���Բ���>");
	set("gin", 0);
	set("kee", 0);
	set("sen", 0);
	//set_temp("block_msg/all", 1);	

	call_out("revive", random(50 - (int) this_object()->query_con()) +40);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");
	this_object()->enable_player();
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
        if( (int) this_object()->query("gin") < 0 ) this_object()->set("gin",0);
        if( (int) this_object()->query("kee") < 0 ) this_object()->set("kee",0);
        if( (int) this_object()->query("sen") < 0 ) this_object()->set("sen",0);
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n�����������������֪��....\n\n" NOR,
		this_object());
	} //else
		//set_temp("block_msg/all", 0);    

}
void be_ghost(int flag)
{
	ghost = flag;
}
void die()
{
	object corpse, killer;
	int i;
	string str;

	if( !living(this_object()) ) revive(1);
	if( wizardp(this_object()) && query("env/immortal") ) return;
	
	// Clear all the conditions by death.
	this_object()->clear_condition();
        if(environment(this_object())->query("no_death")&&
           userp(this_object())&&!this_object()->query("pker"))
          this_object()->set("invalid_death",1);
    
    if( objectp(killer = query_temp("last_damage_from")) ) {
		if(killer->stop_kill(killer,this_object()))
			return;
	}
    
	COMBAT_D->announce(this_object(), "dead");
	if( objectp(killer = query_temp("last_damage_from")) ) {		
		set("last_damage_msg","��"+killer->query("name")+"("+killer->query("id")+")"+"ɱ��");
		COMBAT_D->killer_reward(killer, this_object());
	} else
	if(query_temp("last_damage_msg")){
	  if(userp(this_object())){
	     str=query_temp("last_damage_msg");
	     str=replace_string(str,NOR,HIM);
	   message("vision",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	   set("last_damage_msg",query_temp("last_damage_msg"));
	   delete_temp("last_damage_msg");
	    }
	  }
	else
	 {
	       if(userp(this_object())){
	       	str=query("name")+HIM+"Ī����������ˡ�";	       
		message("vision",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
		}
	  }
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	if( userp(this_object()) ) {
		set("gin", query("max_gin"));	set("eff_gin", query("max_gin"));
		set("kee", query("max_kee"));	set("eff_kee", query("max_kee"));
		set("sen", query("max_sen"));	set("eff_sen", query("max_sen"));
		ghost = 1;
		this_object()->save();
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	} else
		destruct(this_object());
}

void reincarnate()
{
        object rabbit,me=this_object();
        int flag;

        if( !living(me) )
        {
                me->enable_player();
                flag = 1;
        }
 
        if( flag )
                me->disable_player();

        ghost = 0;
        set("eff_gin", query("max_gin"));
        set("eff_kee", query("max_kee"));
	set("eff_sen", query("max_sen"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
        int update_flag, i,heal;
        mapping my;

if (environment())
    if (environment()->query("no_time")) return -1;
	update_flag = 0;


        my = query_entire_dbase();
        
        if(query_temp("no_heal_up")) return 30;
        
       // if(this_object())
       //  heal=this_object()->query_skill("busi-yin",1)/10+this_object()->query_skill("changsheng-jue",1)/10;

        if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
        if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }
        if((my["water"]<=0||my["food"]<=0)&&userp(this_object())) {
        	     tell_object(this_object(),YEL"��е�ʮ�ּ��ʣ��ж�������Щ�����ˡ�\n"NOR);
			return random(3)+30;}
	if((my["water"]<=30||my["food"]<=30)&&userp(this_object())) {
		   if(my["water"]<=my["food"])
        	     tell_object(this_object(),HIY"����������ѵ��촽��Ӧ�úȵ�ˮ�ˡ�\n"NOR);
        	   else
        	     tell_object(this_object(),HIY"ֻ�������ࡱһ������Ķ����Ѿ����ù������ˡ�\n"NOR);
			return random(3)+30;}
        if(my["kee"]<my["eff_kee"]){
			this_object()->receive_heal("kee",my["con"]/2+random(2)+heal);
			update_flag++;}
		if(my["gin"]<my["eff_gin"]){ 
			this_object()->receive_heal("gin",my["con"]/2+random(2)+heal);
			update_flag++;}
		if(my["sen"]<my["max_sen"]){ 
			this_object()->receive_heal("sen",my["con"]/3*2+random(2)+heal);
			}
		if(my["force"]<my["max_force"]){ 
			this_object()->add("force",my["con"]/3*2+5+random(2)+heal);
			}
		if(my["eff_kee"]<my["max_kee"]){ 
			this_object()->receive_curing("kee",my["con"]/3+random(2)+heal);
			update_flag++;}
		if(my["eff_gin"]<my["max_gin"]){ 
			this_object()->receive_curing("gin",my["con"]/3+random(2)+heal);
			update_flag++;}
		if(my["eff_sen"]<my["max_sen"]){ 
			this_object()->receive_curing("sen",my["con"]/3+random(2)+heal);
			update_flag++;}
		
                if(userp(this_object())&&this_object()->query("jiali")&&
                   this_object()->query("force")>this_object()->query("jiali")/10){
                    this_object()->add("force",-this_object()->query("jiali")/10);}
                if(userp(this_object())&&this_object()->query("jiali")&&
                    this_object()->query("force")<this_object()->query("jiali")/10){
                    this_object()->set("jiali",0);
                    this_object()->set("force",0);}
           if(this_object()->query_temp("sleep_interrupt"))
if(time()-this_object()->query_temp("sleep_interrupt")>3600*7&&this_object()->query("sen")>40){
           	tell_object(this_object(),CYN"\n�����ͷ����Щ�������ˣ��о���Щ���ˣ�����Ҹ��ط�˯һ���ˣ�\n"NOR);
           	this_object()->receive_damage("sen",20+random(20));}
           	
                    
        return update_flag;
}

