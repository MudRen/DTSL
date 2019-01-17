
inherit NPC;

#include <ansi.h>

mapping *manclass=({
 ([
   "name":"����",
   "id":({"fu qin","fu","qin"}),
   "gender":"����",
   "age":60,
   "gender_id":"��",
 ]),
 ([
   "name":"ĸ��",
   "id":({"mu qin","mu","qin"}),
   "gender":"Ů��",
   "age":60,
   "gender_id":"��",
 ]),
 ([
   "name":"���",
   "id":({"ge ge","ge"}),
   "gender":"����",
   "age":20,
   "gender_id":"��",
 ]),
 ([
   "name":"����",
   "id":({"mei mei","mei"}),
   "gender":"Ů��",
   "age":9,
   "gender_id":"��",
 ]),

});
void create()
{
   mapping getname;
   
   getname=manclass[random(sizeof(manclass))];
   
   set_name(getname["name"],getname["id"]);
   set("gender", getname["gender"]);		
   set("age",getname["age"]);
   set("gender_id",getname["gender_id"]);     
   set("combat_exp",1000);
  
   setup();
 
}

void die()
{
    object killer;
    
    killer=query_temp("last_damage_from");
    if(!killer) return ::die();
    if(killer->query("id")!=query("target_id"))
    return ::die();
    
    message_vision(HIR"\n$N˫��ð��Ѫһ�����ˮ����˲������ָֻ���ᣬֻ�������һ����\n"NOR,
    killer);
    killer->set("class","yin1");
    tell_object(killer,HIR"\n���Ϊ���������˼����ӣ�\n"NOR);
    
    killer->set_temp("bai_yingui/step4",1);
    killer->delete_temp("bai_yingui/step3");
    
    return ::die();
}