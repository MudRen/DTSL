// attack.c
//new reset_action() by yanyan for DtSl.
#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>
#define MAX_OPPONENT    4

static object *enemy = ({});
static string *killer = ({});
int do_ride_none(object who);


// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
        if( !ob ) return sizeof(enemy) > 0;

        return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
        if( !id ) return sizeof(killer) > 0;

        return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
        if(!ob || ob==this_object()) return;
        
        if(stringp(ob->query("target_id"))&&ob->query("target_id")!=query("id")
          &&is_killing(ob->query("id")))
        return;
        if(arrayp(ob->query("target_id"))&&
	   member_array(query("id"),ob->query("target_id"))==-1
	  &&is_killing(ob->query("id")))
        return;
        set_heart_beat(1);

        if( member_array(ob, enemy)==-1 ) 
                enemy += ({ ob });
}

// This function starts killing between this_object() and ob


void kill_ob(object ob)
{
	object *guards;

	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });
        tell_object(ob, HIR"������" + this_object()->name() + "��ɱ���㣡\n" NOR);

 if ( ob == query_temp( "guardfor" ) )
    {
    	delete_temp("guardfor");
    	guards = ob->query_temp("guarded");
    	guards -= ({ this_object() });
    	ob->set_temp("guarded", guards);
    	tell_object(this_object(), HIY "��ֹͣ����" + ob->name() + "��\n" NOR);
    	tell_object(ob, HIY + this_object()->name() + "ֹͣ�����㡣\n" NOR);
    }

	if ( arrayp(guards = ob->query_temp("guarded")) )
    {
    	guards = filter_array(guards, (:
            	objectp($1)
            &&	living($1)
            &&    $1 != this_object()
            &&	present($1, environment())
            &&    !is_fighting($1)
            && !$1->query("pker")
            &&    $1->visible(this_object()) :));
        
        if(arrayp(guards)&&stringp(query("target_id")))
         guards = filter_array(guards, (:
          $1->query("id")==query("target_id") :));
        
        if(arrayp(guards)&&arrayp(query("target_id")))
         guards = filter_array(guards, (:
          member_array($1->query("id"),query("target_id"))!=-1 :));
          
    	if ( sizeof(guards) > 0 )
        {
            enemy += guards;
        	message("vision", HIR + ob->name() + "�ܵ���������ͦ�����ս�ţ�\n" NOR,
            	guards);
        	guards->kill_ob(this_object());
        }
    }
	fight_ob(ob);
  if( ob->query_temp("ridee"))
{
        do_ride_none( ob );
	fight_ob(ob);
  }
  fight_ob(ob);
}
int do_ride_none(object who)
{
   object ob;
   ob= who->query_temp("ridee");

   message_vision("$N��æ��$n������ӭս��\n", who, ob);
   ob->set_temp("no_return",0);
   ob->set_temp("rider",0);
   who->set_temp("ridee",0);          
   who->add_temp("apply/dodge",-who->query_temp("ride/dodge"));
   who->set_temp("ride/dodge",0);
   return 1;
}

void clean_up_enemy()
{
        if( sizeof(enemy) > 0 ) {
                for(int i=0; i<sizeof(enemy); i++) {
                        if( !objectp(enemy[i])
                        ||      environment(enemy[i])!=environment()
                        ||      (!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
                                enemy[i] = 0;
                }
                enemy -= ({ 0 });
        }
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
        int which;

        if( !sizeof(enemy) ) return 0;

        which = random(MAX_OPPONENT);

        return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
        if( is_killing(ob->query("id")) ) return 0;

        enemy -= ({ ob });
        return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
        if( is_killing(ob->query("id")) ) {
                killer -= ({ ob->query("id") });
                remove_enemy(ob);
                return 1;
        }

        return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
        for(int i=0; i<sizeof(enemy); i++) {
                // We ask our enemy to stop fight, but not nessessary to confirm
                // if the fight is succeffully stopped, bcz the fight will start
                // again if our enemy keeping call COMBAT_D->fight() on us.
                if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
                enemy[i] = 0;;
        }

        enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
        killer = ({});
        enemy -= ({ 0 });

        for(int i=0; i<sizeof(enemy); i++)
                if( enemy[i]->remove_killer(this_object()) )
                        enemy[i] = 0;;

        enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
string reset_action(object weapon)
{
	string w,weapon_type,*respond_skill,skill_name;
	int i;
	if(weapon)          
   {   
       w=(string)weapon->query("name");
	   weapon_type=(string)weapon->query("skill_type");
	   if(query("prepare/"+weapon_type))
	     {skill_name=query("prepare/"+weapon_type);
	      set("actions",SKILL_D(skill_name)->query_action(this_object(),weapon));
	      }
       else{
	   respond_skill=query(weapon_type);
	   if(respond_skill)                                 
	   {
		   i=random(sizeof(respond_skill));
	       
	       if(query_skill(respond_skill[i],1))
		   {
			   set("actions",SKILL_D(respond_skill[i])->query_action(this_object(),weapon));
			   skill_name=respond_skill[i];
	       }
		   
	   }
	   else
	   {
          set("actions",WEAPON_D->query_action(weapon));
		  skill_name=weapon_type;
		
	   }
	 }                                                       
    }
   else                                                      
   {
	   
	   if(query("prepare/hand"))
	   {skill_name=query("prepare/hand");
	   set("actions",SKILL_D(skill_name)->query_action(this_object()));
	   }
	  else{
	   respond_skill=query("hand");           
	   if(respond_skill)                                     
	   {
		   i=random(sizeof(respond_skill));
		   if(query_skill(respond_skill[i],1))          
		   {
			   set("actions",SKILL_D(respond_skill[i])->query_action(this_object()));
			   skill_name=respond_skill[i];
		   }
		   	
	   }
	      else                                           
		  {
set("actions",query("default_actions"));
			  skill_name="unarmed";
		  }
            }
   }
   return skill_name;
}
// This is called in heart_beat() to perform attack action.
//change by cbra from private to public for v22pre11
//private int attack()
public int attack()
{
        object opponent;

        clean_up_enemy();

        opponent = select_opponent();
        if( objectp(opponent) ) {
                set_temp("last_opponent", opponent);
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
        object ob;
        string vendetta_mark;

        // We check these conditions here prior to handle auto fights. Although
        // most of these conditions are checked again in COMBAT_D's auto_fight()
        // function, these check reduces lots of possible failure in the call_out
        // launched by auto_fight() and saves some overhead.
        if(     is_fighting()
        ||      !living(this_object())
        ||      !(ob = this_player()) 
        ||      environment(ob)!=environment()
        ||      !living(ob)
        ||      ob->query("linkdead")
        ||      environment(ob)->query("no_fight") )
                return;

        // Now start check the auto fight cases.
        if(userp(ob) && is_killing(ob->query("id"))) 
        {
                COMBAT_D->auto_fight(this_object(), ob, "hatred");
                return;
        } else if((int)query("GARRISON") && (int)ob->query("PK_MURDER")) {
                COMBAT_D->auto_fight(this_object(), ob, "catch");
                return;
        } else if(stringp(vendetta_mark = query("vendetta_mark"))
        && ob->query("vendetta/" + vendetta_mark) ) {
                COMBAT_D->auto_fight(this_object(), ob, "vendetta");
                return;
        } else if(userp(ob) && (string)query("attitude")=="aggressive") {
                COMBAT_D->auto_fight(this_object(), ob, "aggressive");
                return;
        } /*else if(random((int)query("bellicosity") / 40) > (int)query("cor")&&
                  query("couple/couple_id")!=ob->query("id")) {
                COMBAT_D->auto_fight(this_object(), ob, "berserk");*/
                return;
        //}
}
