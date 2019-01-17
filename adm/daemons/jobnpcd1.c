#include <job_money.h>
#include <ansi.h>

string *names1 = ({
  WHT"��"NOR,"chen",
  WHT"��"NOR,"du",
  WHT"��"NOR,"li",
  WHT"��"NOR,"zhang",
  WHT"��"NOR,"wang",
  WHT"��"NOR,"he",
  WHT"ŷ"NOR,"ou",
  WHT"��"NOR,"zhou",
  WHT"��"NOR,"hu",
  WHT"��"NOR,"ma",
  WHT"��"NOR,"mai",
  WHT"ʷ"NOR,"shi",
  WHT"��"NOR,"liao",
  WHT"��"NOR,"lin",
  WHT"��"NOR,"bai",
  WHT"��"NOR,"cai",
  WHT"��"NOR,"jin",
  WHT"��"NOR,"chao",
  WHT"¬"NOR,"lu",
  WHT"��"NOR,"wu",
  WHT"��"NOR,"huang",
  WHT"��"NOR,"yan",
});

string *names2 = ({
  YEL"��"NOR,"feng",
  YEL"��"NOR,"fei",
  YEL"��"NOR,"liang",
  YEL"��"NOR,"hui",
  YEL"��"NOR,"rong",
  YEL"��"NOR,"yang",
  YEL"��"NOR,"kun",
  YEL"��"NOR,"wei",
  YEL"��"NOR,"yu",
  YEL"��"NOR,"zhou",
  YEL"��"NOR,"fa",
  YEL"��"NOR,"dong",
  YEL"Ȼ"NOR,"ran",
  YEL"ƽ"NOR,"ping",
  YEL"��"NOR,"ling",
  YEL"��"NOR,"jiang",
  YEL"��"NOR,"ren",
  YEL"Ƚ"NOR,"ran",
  YEL"ׯ"NOR,"zhuang",
  YEL"ҵ"NOR,"ye",
});

string *names3=({
"��","dai",
"ʷ","shi",
"��","ci",
"ż","ou",
"ʤ","sheng",
"ʢ","sheng",
"��","zi",
"��","xuan",
"Ц","xiao",
"��","jian",
"��","dao",
"ƽ","ping",
"Į","mo",
"��","yan",
"˪","shuang",
"��","xiang",
"��","hao",
"־","zhi"
});

string *name=({"��","ɽ","����","����"});
string *name1=({
"��","zhao",
"Ǯ","qian",
"��","sun",
"��","li",
"��","zhou",
"��","wu",
"֣","zheng",
"��","wang"
});

void add_killer_level(object killer,int damage,int armor,int dodge)
{
	killer->add_temp("apply/damage",damage);
	killer->add_temp("apply/armor",armor);
	killer->add_temp("apply/dodge",dodge);
}

//������������
int set_ygjob_killer(object killer,object ob)
{

	killer->set_name("��"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
	killer->set("combat_exp",ob->query("combat_exp")-400000);	
	if(ob->query("combat_exp")<150000)
		killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
  		killer->set_this_skills("middle");
	else{		
  		killer->set_this_skills("high");
  		add_killer_level(killer,50,100,150);
  		
  	}

	set_all_skill(killer,ob->query("max_pot")-160);
	copy_hp_item(ob,killer,"gin");
	copy_hp_item(ob,killer,"kee");
	copy_hp_item(ob,killer,"sen");
	copy_force(ob,killer);
	killer->set("last",time());
		
	killer->set("target_id",ob->query("id"));	
	killer->set("pfm_rate",90);
	
}

int set_cyjsjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "����" );	
	killer->set("age", 30+random(10));
	killer->set("long", "����һ����������˵���ո�͵�˱����顣\n");
	
	if(ob->query("combat_exp")<150000){
    	killer->set_this_skills("low");
    	killer->set("combat_exp",ob->query("combat_exp"));
    	copy_hp_item(ob,killer,"gin");
    	copy_hp_item(ob,killer,"kee");
    	copy_hp_item(ob,killer,"sen");
    	set_all_skill(killer,ob->query("max_pot")-180);
  }
   else
   if(ob->query("combat_exp")<500000){
    	killer->set_this_skills("middle");
    	killer->set("combat_exp",ob->query("combat_exp")-300000);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",3,2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	set_all_skill(killer,ob->query("max_pot")-170);
  }
  else
   if(ob->query("combat_exp")<1000000){
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")-500000);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",3,2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	set_all_skill(killer,ob->query("max_pot")-150);
    	killer->set("jiali",30);
    	add_killer_level(killer,50,100,150);
  }
   else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",3,2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	set_all_skill(killer,ob->query("max_pot")-145);
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
  }
                
   		copy_force(ob,killer);
   		killer->set("target_id",ob->query("id"));
   		killer->set("last",time()+600);	
   		killer->set("pfm_rate",90);
   		return 1;
	
}

int set_yunyanjob_killer(object killer,object ob)
{
	if(ob->query("combat_exp")<300000){
		killer->set_this_skills("low");
  		killer->set("combat_exp",ob->query("combat_exp")-200000);
  		set_all_skill(killer,ob->query("max_pot")-160);
  		copy_hp_item(ob,killer,"kee");
  		copy_hp_item(ob,killer,"sen");
  		copy_hp_item(ob,killer,"gin");
	}
	else
	if(ob->query("combat_exp")<300000){
		killer->set_this_skills("middle");
  		killer->set("combat_exp",ob->query("combat_exp")-200000);
  		set_all_skill(killer,ob->query("max_pot")-180);
  		copy_hp_item(ob,killer,"kee");
  		copy_hp_item(ob,killer,"sen");
  		copy_hp_item(ob,killer,"gin");
	}
	else{
		killer->set_this_skills("high");
  		killer->set("combat_exp",ob->query("combat_exp")-400000);
  		set_all_skill(killer,ob->query("max_pot")-180);
  		copy_hp_item(ob,killer,"kee");
  		copy_hp_item(ob,killer,"sen");
  		copy_hp_item(ob,killer,"gin");
	}
	copy_force(ob,killer);
	killer->set("last",time());
	killer->set("target_id",ob->query("id"));
	killer->set("pfm_rate",95);
	return 1;
	
}

int set_xiangjob_killer(object killer,object ob)
{
	killer->set("last",time());
	killer->set("target_id",ob->query("id"));
  
	killer->set("combat_exp",ob->query("combat_exp")-200000);
	if(ob->query("combat_exp")<150000)
		killer->set_this_skills("low");
   	else
	if(ob->query("combat_exp")<80000){		
		killer->set_this_skills("middle");
		copy_hp_item(ob,killer,"gin",3,2);
		copy_hp_item(ob,killer,"kee",3,2);
		copy_hp_item(ob,killer,"sen",3,2);
	}
	else{
		killer->set_this_skills("high");
		copy_hp_item(ob,killer,"gin",3,2);
		copy_hp_item(ob,killer,"kee",3,2);
		copy_hp_item(ob,killer,"sen",3,2);
		add_killer_level(killer,50,100,150);
	}
	set_all_skill(killer,ob->query("max_pot")-150);
	
  	killer->set("pfm_rate",90);
	copy_force(ob,killer);
	
	return 1;
	
}

int set_sjbptjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "����" );
        
	killer->set("age", 30+random(10));
	killer->set("long", "�����μұ�����ͽ��\n");
	
	killer->set("combat_exp",ob->query("combat_exp")-300000);
	if(ob->query("combat_exp")<150000)
    	killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
		killer->set_this_skills("middle");
	else
	    killer->set_this_skills("high");
	set_all_skill(killer,ob->query("max_pot")-200);
   
	copy_hp_item(ob,killer,"gin");
	copy_hp_item(ob,killer,"kee");
	copy_hp_item(ob,killer,"sen");
   
	killer->set("max_force",ob->query("max_force"));
	killer->set("force",ob->query("max_force"));
	killer->set("target_id",ob->query("id"));
	killer->set("last",time()+600);
	
	return 1;
	
}

int set_timejob_killer(object killer,object ob)
{
	killer->set("combat_exp",ob->query("combat_exp")-400000);
	if(ob->query("combat_exp")<150000)
    	killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
    	killer->set_this_skills("middle");
	else
    	killer->set_this_skills("high");
	set_all_skill(killer,ob->query("max_pot")-120);
   
	copy_hp_item(ob,killer,"gin",3,2);
	copy_hp_item(ob,killer,"kee",3,2);
	copy_hp_item(ob,killer,"sen",3,2);
   
	copy_force(ob,killer);
   
	killer->set("target_id",ob->query("id"));
   
	killer->set("last",time());
	killer->set("pfm_rate",85);
	return 1;
}

int set_gaolijob_killer(object killer,object ob)
{
	if(ob->query("combat_exp")<200000){
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	killer->set_this_skills("low");
    	set_all_skill(killer,ob->query("max_pot")-170);
    	copy_hp_item(ob,killer,"gin");
    	copy_hp_item(ob,killer,"kee");
    	copy_hp_item(ob,killer,"sen");
    	killer->set("max_force",ob->query("max_force"));
   }
   else
   if(ob->query("combat_exp")<500000){
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	killer->set_this_skills("middle");
    	set_all_skill(killer,ob->query("max_pot")-180);
    	copy_hp_item(ob,killer,"gin");
    	copy_hp_item(ob,killer,"kee");
    	copy_hp_item(ob,killer,"sen");
    	killer->set("max_force",ob->query("max_force"));
    	
   }
   else
   if(ob->query("combat_exp")<1000000){
    	killer->set("combat_exp",ob->query("combat_exp")-500000);
    	killer->set_this_skills("high");
    	set_all_skill(killer,ob->query("max_pot")-150);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	killer->set("max_force",ob->query("max_force"));
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
   }
   else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	set_all_skill(killer,ob->query("max_pot")-145);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	killer->set("max_force",ob->query("max_force"));
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
   }
      
   killer->set("force",ob->query("max_force"));
   killer->set("target_id",ob->query("id"));
   killer->set("last",time()+600);
   
   killer->set("long",killer->query("long")+"��˵�����ٸ��Ѿ���"+ob->name()+"��ɱ���ˡ�\n");
   killer->set("pfm_rate",90);
   return 1;
}

int set_dmszjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "����" );
        
	killer->set("age", 30+random(10));
	killer->set("nickname","����");
	killer->set("long", "����һ���ܹ��ڱ�����Ļ�����\n");
	
	if(ob->query("combat_exp")<500000){
		killer->set_this_skills("middle");	
		killer->set("combat_exp",ob->query("combat_exp")-400000);
		set_all_skill(killer,ob->query("max_pot")-170);
     	copy_hp_item(ob,killer,"gin");
     	copy_hp_item(ob,killer,"kee");
     	copy_hp_item(ob,killer,"sen");
   }
   else
   if(ob->query("combat_exp")<1000000){
     	killer->set_this_skills("high");	
     	killer->set("combat_exp",ob->query("combat_exp")-400000);
     	set_all_skill(killer,ob->query("max_pot")-160);
     	copy_hp_item(ob,killer,"gin",3,2);
     	copy_hp_item(ob,killer,"kee",3,2);
     	copy_hp_item(ob,killer,"sen",3,2);
     	killer->set("jiali",10);
     	add_killer_level(killer,50,100,150);
   }
   else{
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	killer->set_this_skills("high");
    	set_all_skill(killer,ob->query("max_pot")-145);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	killer->set("jiali",10);
        add_killer_level(killer,50,100,150);	
   }
  
	killer->set("max_pot",ob->query("max_pot"));
  
	killer->copy_force(ob,this_object()); 
	killer->set("target_id",ob->query("id"));
	killer->set_temp("apply/armor",10+random(10));
	killer->set("last",time());
	killer->set("pfm_rate",85);
	return 1;
	
}

int set_tjjyjob_killer(object killer,object ob)
{
	int i;
   
   	i=random(sizeof(name1));
   
   	if(i%2!=0)
   		i++;
   	if(i==sizeof(name1))
   		i=i-2;
   	killer->set_name(name1[i]+"����",({name1[i+1]+" "+"xiake",name1[i+1]}) );
   	
   	if(ob->query("combat_exp")<150000){
    	killer->set_this_skills("low");
    	killer->set("combat_exp",ob->query("combat_exp")-100000);
    	set_all_skill(killer,ob->query("max_pot")-180);
    	copy_hp_item(ob,killer,"gin");
    	copy_hp_item(ob,killer,"kee");
    	copy_hp_item(ob,killer,"sen");
    	copy_force(ob,killer);
   	}
   	else
   	if(ob->query("combat_exp")<500000){
    	killer->set_this_skills("middle");
    	killer->set("combat_exp",ob->query("combat_exp")-400000);
    	set_all_skill(killer,ob->query("max_pot")-170);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",1);
    	copy_hp_item(ob,killer,"sen",3,2);
    	copy_force(ob,killer);
    	
   	}
   	else
   	if(ob->query("combat_exp")<1000000){
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")-500000);
    	set_all_skill(killer,ob->query("max_pot")-160);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",3,2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	copy_force(ob,killer);
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
   	}
   	else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")-500000);
    	set_all_skill(killer,ob->query("max_pot")-150);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	copy_force(ob,killer,3/2);
    	killer->set("jiali",10);    	
    	add_killer_level(killer,50,100,150);
  	}
      
   	killer->set("target_id",ob->query("id"));
   	killer->set("last",time());
   	killer->set("pfm_rate",75);
   	return 1;
	
}

int set_butoujob_killer(object killer,object ob)
{
	int i,j,k,flag;
	int exp;
   
   	flag=0;
   
   	if(random(10)<6){
    	i=random(sizeof(names1));
    	if(i%2!=0)
     		i++;
    	if(i==sizeof(names1))
     		i=i-2;
    	j=random(sizeof(names2));
    	if(j%2!=0)
     		j++;
    	if(j==sizeof(names2))
     		j -=2;
   	}
   	else{
     	i=random(sizeof(names1));
    	if(i%2!=0)
     		i++;
    	if(i==sizeof(names1))
     		i -=2;
    	j=random(sizeof(names2));
    	if(j%2!=0)
     		j++;
    	if(j==sizeof(names2))
     		j -=2;
   	 	k=random(sizeof(names3));
    	if(k%2!=0)
     		k++;
    	if(k==sizeof(names3))
     		k -=2;
    	flag=1;
	}
    
   	if(!flag)
   		killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
   	else
   		killer->set_name(names1[i]+names2[j]+names3[k],({names1[i+1]+" "+names2[j+1]+" "+names3[k+1],
         	names1[i+1],names2[j+1],names3[k+1]}) );
	

    
    exp=random(3000000);
    
    killer->set("combat_exp",exp-400000);
    "/cmds/usr/hp.c"->get_pot(killer);
    
    if(exp<100000)
     	killer->set_this_skills("lowe");
    else
    if(exp<600000)
     	killer->set_this_skills("middle");
    else
     	killer->set_this_skills("high");
    
    set_all_skill(killer,killer->query("max_pot")-140);
    
    killer->set("max_kee",killer->query("combat_exp")/1000+200);
    killer->set("eff_kee",killer->query("combat_exp")/1000+200);
    killer->set("kee",killer->query("combat_exp")/1000+200);
    
    killer->set("max_gin",killer->query("combat_exp")/1000+200);
    killer->set("eff_gin",killer->query("combat_exp")/1000+200);
    killer->set("gin",killer->query("combat_exp")/1000+200);
    
    killer->set("max_sen",killer->query("combat_exp")/1000+200);
    killer->set("eff_sen",killer->query("combat_exp")/1000+200);
    killer->set("sen",killer->query("combat_exp")/1000+200);
    
    killer->set("max_force",killer->query("combat_exp")/1000+1000);
    killer->set("force",killer->query("combat_exp")/1000+1000);
    killer->set("pfm_rate",80);
    return 1;
	
}

int set_bsyquest_killer(object killer,object ob,int lev)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "����" );
        
	killer->set("age", 30+random(10));
	killer->set("long", "����һ��ɱ�֡�\n");
	
    killer->set("combat_exp",ob->query("combat_exp")-200000);
    killer->set_this_skills("high");
    set_all_skill(killer,ob->query("max_pot")-160);
    copy_hp_item(ob,killer,"gin",3/2);
    copy_hp_item(ob,killer,"kee",2);
    copy_hp_item(ob,killer,"sen",3/2);
    killer->set("jiali",10);
    
	killer->copy_force(ob,this_object()); 
	killer->set("target_id",ob->query("id"));
	killer->set_temp("apply/armor",10+random(10));
	
	return 1;
	
}