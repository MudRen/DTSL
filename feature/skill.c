#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;


mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
string type;
        if(!find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if(!mapp(skills) ) skills = ([ skill: val ]);
        else skills[skill] = val;
type=SKILL_D(skill)->query_type();
if(type&&type!="base"&&type!="knowledge")
this_object()->add_array(type,skill);
}

int delete_skill(string skill)
{
        string type;
        type=SKILL_D(skill)->query_type();
        if(type&&type!="base"&&type!="knowledge")
        this_object()->reduce_array(type,skill);
        if(mapp(skills)) {
                map_delete(skills, skill);
                if(mapp(learned)) {
                        map_delete(learned, skill);
                        return undefinedp(learned[skill]);
                }
                return undefinedp(skills[skill]);
        }
        return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_prepare) ) {
                map_delete(skill_prepare, skill);
                return;
        }

        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;

        if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
        else skill_prepare[skill] = mapped_to;
}
string query_skill_prepared(string skill)
{
        if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
                return skill_prepare[skill];
        return 0;
}


varargs void map_skill(string skill, string mapped_to)
{
        if(!mapped_to && mapp(skill_map)) {
                map_delete(skill_map, skill);
                return;
        }

        if(!find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )

                error("F_SKILL: No such skill (" + skill + ")\n");

        if(!mapp(skills) || undefinedp(skills[mapped_to]))
                return;
                
        if(!mapp(skill_map)) skill_map = ([ skill: mapped_to ]);
        else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
        if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
                return skill_map[skill];
        return 0;
}

varargs int query_skill(string skill, int raw)
{
        if( !raw ) {
                int s, lvl;
                string sname;
                
                s = query_temp("apply/" + skill);
                if( mapp(skills) ) {
                        s += skills[skill] / 2;
                        if( mapp(skill_map) ) {
                                sname = skill_map[skill];
                                lvl = skills[sname];
                                if (lvl) {
                                        lvl = SKILL_D(sname)->skill_rank(lvl);
                                        s += lvl;
                                } else {
                                        s += skills[skill_map[skill]];
                                }
                        }
                }
                return s;
        }
        if( mapp(skills) && !undefinedp(skills[skill]) ) 
        return skills[skill];
        //modify by yanyan.
        return 0;
}

mapping query_skill_map()
{
        return skill_map;
}

mapping query_skill_prepare()
{
        return skill_prepare;
}


int skill_death_penalty()
{
        string *sk;
        int i;

        if( wizardp(this_object()) || !mapp(skills) ) return 0;

        sk = keys(skills);
        if( !mapp(learned) )
                for(i = 0; i<sizeof(sk); i++) {
                        skills[sk[i]]--;
                        if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
                }
        else
                for(i = 0; i<sizeof(sk); i++) {
                        if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
                                learned[sk[i]]-=(skills[sk[i]]+1) * (skills[sk[i]]+1) / 2;
                        else {
                                skills[sk[i]]--;
                                if( skills[sk[i]]<0 ) 
                                	map_delete(skills, sk[i]);
                                else
                                	learned[sk[i]]=(skills[sk[i]]+1) * (skills[sk[i]]+1) / 2;
                        }
                }
        skill_map = 0;
        return 1;
}
varargs int query_skill_eff_lvl(string skill)
{
        int level;
if(mapp(skills)){
level = (int) (SKILL_D(skill)->effective_level())  ;
// for baisc skills where effecitive_level() undefined
if( level == 0) level = 5;
return skills[skill] * level /10;
}
return 0;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
        int intel;

        if(!find_object(SKILL_D(skill))
        && file_size(SKILL_D(skill)+".c") < 0)
                error("F_SKILL: No such skill (" + skill + ")\n");
        if(!weak_mode || !userp(this_object())) 
        {
                if(!mapp(skills)) skills = ([]);
                if(undefinedp(skills[skill])) skills[skill] = 0;
if(!query_skill(skill,1))
this_object()->set_skill(skill,1);
        }

        // Give learning penalty to those learning too much skills.
        intel = query("int");
        if(sizeof(learned) > intel)
                amount /= sizeof(learned) - intel;

        if(!amount) amount = 1;

        if(!mapp(learned)) learned = ([ skill : amount ]);
        else (int)learned[skill] += amount;

        if((!weak_mode || !userp(this_object()))
        && learned[skill] > (skills[skill] + 1) * (skills[skill] + 1)) 
        {
if(skills[skill]>=query("max_pot")-100&&SKILL_D(skill)->query_type()!="knowledge"&&
   SKILL_D(skill)->query_type()!="literate")
{tell_object(this_object(),"����ȱ��ʵս���飬��ļ����޷���һ������ˡ�\n");
 learned[skill]=(skills[skill] + 1) * (skills[skill] + 1);}
else
if(SKILL_D(skill)->query_type()=="knowledge"&&query_skill("literate",1)<300&&
   query_skill(skill,1)>query_skill("literate",1)+50){
  learned[skill]=(skills[skill] + 1) * (skills[skill] + 1);
   tell_object(this_object(),"����Ļ�ˮƽ�����ߣ��޷��ټ������������ˣ�\n");}
else
{
                skills[skill]++;
                learned[skill] = 0;
                tell_object(this_object(), HIC "��ġ�" 
                        + to_chinese(skill) + "�������ˣ�\n" NOR);
SKILL_D(skill)->skill_improved(this_object());}
        }
}

varargs int query_eff_skill_level(string skill) 
{
        
        string sname;
        int lvl;

        if(mapp(skills))
        {
                lvl = skills[skill];
                if(lvl) 
                {
                        lvl = SKILL_D(skill)->skill_rank(lvl);
                        if(!lvl) lvl = skills[skill] / 2;
                        if(lvl < 1) lvl = 1;
                        return lvl;
                }
        }
        return 0;
}

void check_valid_parry_skill(string skill_type)
{
        string parry_skill;
        mapping map;

        //map = query_skill_map();
        if(!skill_map) return;
        if (!skill_map["parry"]) {
            if(skill_type == "throwing") {
                if(parry_skill = skill_map["unarmed"])
                map_skill("parry",parry_skill);
            } 
            return;
        } 
        parry_skill = skill_map["parry"];
        if(skill_type == "unarmed") {
            if (parry_skill == "star-move")
                return ;
            else if (parry_skill && SKILL_D(parry_skill)->valid_enable("unarmed"))
                return ;
            else if(parry_skill = skill_map["unarmed"]) {
                map_skill("parry",parry_skill);
                return ;
            } else {
                map_delete(skill_map, "parry");
                return ;
            }
        } else {
            if (parry_skill && SKILL_D(parry_skill)->valid_enable(skill_type))
                return ;
            else if (parry_skill && SKILL_D(parry_skill)->valid_enable("unarmed"))
                return ;
            else if(parry_skill = skill_map[skill_type]) {
                map_skill("parry",parry_skill);
                return ;
            }
            else if(parry_skill = skill_map["unarmed"]) {
                map_skill("parry",parry_skill);
                return ;
            } else {
                map_delete(skill_map, "parry");
                return ;
            }
        }

}

int party_reward_skill(string skill,int lev)
{
  
  lev=query_skill(skill,1)+lev;
  
  if(lev>query("max_pot")-100)
   lev=query("max_pot")-100;
  
  set_skill(skill,lev);
  
  return 1;

}

int reward_family_point()
{
if(!query("reward_family_point")){
	add("char_lev/points",4);
	set("reward_family_point",1);
	tell_object(this_object(),"\n��õ��� 4 �����Խ�����\n\n");
}	
return 1;
}

