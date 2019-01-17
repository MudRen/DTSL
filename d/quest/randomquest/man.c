
inherit NPC;

#include <elite.h>

string *name1=({"����","����","Ѳ��","��ؤ","С�к�","����","��������",
"����","����"});
string *name2=({"che fu","yi ren","xun bu","qi gai","boy","xia ke","man",
"shu sheng","shang ren"});



void create()
{
   int i;
   i=random(sizeof(name1));
   
   
   
   set_name(name1[i],({name2[i]}) );
        set("gender", "����" );
        set("age",10+random(20));
   set("long","����һ���Ĵ����˵�"+name()+"��\n");     
   set("combat_exp",5000);
   set("str", 20);
   set("chat_chance",90);
   set("chat_msg",({
   	(:random_move:),
   	}));
  
   setup();
   
  switch(random(5)){
   case 0:
   carry_object(__DIR__"book1");
   break;
   case 1:
   carry_object(__DIR__"book2");
   break;
   case 2:
   carry_object(__DIR__"book3");
   break;
   case 3:
   carry_object(__DIR__"book4");
   case 4:
   carry_object(__DIR__"book5");
   break;
   default:break;}
  if(random(100)>98)
   carry_object(__DIR__"danyao");
  
 
}

void recover(object who)
{
   int max;
   
   set("combat_exp",who->query("combat_exp")+500000);
   
   set("max_kee",who->query("max_kee"));
   set("eff_kee",who->query("max_kee"));
   set("kee",who->query("max_kee"));
   
   set("max_gin",who->query("max_gin"));
   set("eff_gin",who->query("max_gin"));
   set("gin",who->query("max_gin"));
   
   set("max_sen",who->query("max_sen"));
   set("eff_sen",who->query("max_sen"));
   set("sen",who->query("max_sen"));
   
   set("max_force",who->query("max_force"));
   set("force",who->query("max_force"));
   
   max=who->query("max_pot")-100;
   
   set_skill("dodge",max);
   set_skill("parry",max);
   set_skill("finger",max);
   set_skill("liuyun",max);
   set_skill("strike",max);
   set_skill("leg",max);
   
   set_skill("fengxue-leg",max);
   set_skill("dujie-zhi",max);
   set_skill("jiutian-huanzhang",max);
   
   set_skill("force",max);
   return;
}

int chat()
{
   object weapon;
   string type,skill_name;
   int skill_number,skill_damage;
   string *skills;
   
   weapon=query_temp("weapon");
        if(weapon)
          type=weapon->query("skill_type");
        else type="hand";
        
        skills=query(type);
        if(sizeof(skills)>0&&(random(100)>75||
         query("eff_kee")*100/query("max_kee")<50)){
            skill_name=skills[random(sizeof(skills))];
            skill_number=1+random(4);
            if(query("eff_kee")*100/query("max_kee")<50)
               skill_damage=0;
            else
             if(query("eff_kee")*100/query("max_kee")<60)
               skill_damage=3;
            else
             if(query("eff_kee")*100/query("max_kee")<70)
               skill_damage=5;
            else
             if(query("eff_kee")*100/query("max_kee")<80)
               skill_damage=7;
            else
             if(query("eff_kee")*100/query("max_kee")<90)
               skill_damage=9;
            else skill_damage=10;
            command("apply "+skill_name+" "+skill_number+" "+skill_damage);}
        
        return ::chat();
}

int accept_fight(object who)
{
   recover(who);
   
   return ::accept_fight(who);
}

void kill_ob(object who)
{
   recover(who);
   return ::kill_ob(who);
}

void die()
{
   
   object elite_ob,ob;
   int ei,exp;
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   
   exp=ob->query("combat_exp");
   
   if(exp>=2000000&&
        random(3000+exp/100000)>3000){
        	
         if(random(10000+exp/100000)>10000){
         	
            if(random(20000+exp/100000)>20000){
            	ei=random(sizeof(elite));
            	elite_ob=new("/d/clone/obj/elite/elite/"+elite[ei]);
            	elite_ob->move(this_object());}
            else{
                ei=random(sizeof(unique));
                elite_ob=new("/d/clone/obj/elite/unique/"+unique[ei]);
                elite_ob->move(this_object());}}
         else{
                ei=random(sizeof(normal));
                elite_ob=new("/d/clone/obj/elite/normal/"+normal[ei]);
                elite_ob->move(this_object());}}
                
    return ::die();
}