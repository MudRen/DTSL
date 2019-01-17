
inherit NPC;

#include <ansi.h>

mapping *manclass=({
 ([
   "name":"父亲",
   "id":({"fu qin","fu","qin"}),
   "gender":"男性",
   "age":60,
   "gender_id":"他",
 ]),
 ([
   "name":"母亲",
   "id":({"mu qin","mu","qin"}),
   "gender":"女性",
   "age":60,
   "gender_id":"她",
 ]),
 ([
   "name":"哥哥",
   "id":({"ge ge","ge"}),
   "gender":"男性",
   "age":20,
   "gender_id":"他",
 ]),
 ([
   "name":"妹妹",
   "id":({"mei mei","mei"}),
   "gender":"女性",
   "age":9,
   "gender_id":"她",
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
    
    message_vision(HIR"\n$N双眼冒出血一般的泪水，但瞬间表情又恢复冷酷，只是冷哼了一声！\n"NOR,
    killer);
    killer->set("class","yin1");
    tell_object(killer,HIR"\n你成为了阴癸派人级弟子！\n"NOR);
    
    killer->set_temp("bai_yingui/step4",1);
    killer->delete_temp("bai_yingui/step3");
    
    return ::die();
}