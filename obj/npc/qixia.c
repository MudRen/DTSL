
inherit JOBNPC;

#include <job_money.h>

void create()
{
        
        object *ob;
        int i;
        
        set_name("�糾��ʿ", ({"dao shi","dao","shi"}));
        set("gender", "����");
        set("age", 34);
        set("long","����һ���糾��ʿ����˵�����ܿ��Ƴ������Ķ�����\n");
        set("str", 30);
        set("int", 30);
        set("dex", 30);
        set("con", 30);
 
        set("max_kee",3000);
        set("max_gin",3000);
        set("max_sen",3000);
        set("force",3000);
	set("max_force",3000);
        set("combat_exp",800000);
       
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	set("chat_chance",40);
	set("chat_msg",({
	    (:random_move:),
	}));
	
	switch(random(3)){
		
	 case 0:set("combat_exp",100000);
	        set_this_skills("low");
	        set_all_skill(this_object(),100);
	        break;
	 case 1:set("combat_exp",800000);
	        set_this_skills("middle");
	        set_all_skill(this_object(),160);
	        break;
	 case 2:set("combat_exp",1000000);
	        set_this_skills("high");
	        set_all_skill(this_object(),200);
	}
	
        setup();
        
        ob=children(__DIR__"obj/bingposhenzhu");
        for(i=0;i<sizeof(ob);i++)
         if(objectp(ob[i])&&environment(ob[i])){
           if(userp(environment(ob[i])))
            tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"���������������ˣ�\n");
           else
            tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
           destruct(ob[i]);
         }
        
        ob=children(__DIR__"obj/huolongneidan");
        for(i=0;i<sizeof(ob);i++)
         if(objectp(ob[i])&&environment(ob[i])){
           if(userp(environment(ob[i])))
            tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"���������������ˣ�\n");
           else
            tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
            destruct(ob[i]);
         }
        
        switch(random(2)){
          
          case 0:carry_object(__DIR__"obj/bingposhenzhu");break;
          case 1:carry_object(__DIR__"obj/huolongneidan");break;
       }
       
		
}

