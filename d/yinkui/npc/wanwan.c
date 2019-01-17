
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_quest1();
int do_quest2();
int do_quest3();
int do_quest4();
int do_quest5();
int do_skjf_quest();

void create()
{
   int i;
   object *ob;
   set_name("����",({ "wan wan","wan"}) );
        set("gender", "Ů��" );
	set("nickname","��������");	
        set("age", 22);
   set("long", "���������ɵĊ�����δ�������ɵļ̳е��ӡ�\n");
       
   set("combat_exp",1800000);
   set("str", 25);
   set("dex",30);
   set("per", 29);
   
   set_skill("dagger",400);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",400);
   set_skill("cuff",400);
   set_skill("literate",400);
   
   set_skill("tianmo-jue",400);
   set_skill("tianmo-dafa",400);
   set_skill("tianmo-huanzong",400);
   set_skill("tianmo-zhan",400);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   set("perform_quest/lingxiao",1);
   create_family("������",4,"����");
   
   set("inquiry",([
       "��ħն":(:do_quest1:),
       "ʦ����":(:do_quest2:),
       "��ħ����ն":(:do_quest3:),
       "������":(:do_quest4:),
       "��ս":(:do_quest5:),
       "��а֮ս":(:do_skjf_quest:),
       ]));
       
   setup();
   
   ob=children(__DIR__"obj/dagger");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/dagger")->wield();
  
}
void attempt_apprentice(object ob)
{
	
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=4)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	if(ob->query("gender")=="����"){
	
	command("say �Ҳ����е��ӵģ����������Ͷ�뱾�ɣ�ȥ����ʿ��ɣ�\n");
	return;
        }
        
        
        if(ob->query_skill("tianmo-dafa",1)<150){
        command("say �����ħ����Ϊ������������ȥ��ϰһ���ٰ���Ϊʦ�ɣ�\n");
        return;
        }
     
        if(ob->query("office_number")<60){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query("bellicosity")<1000){
        command("say ���ɱ�������࣬��γ�Ϊ�����µ�ħ�ŵ��ӣ�\n");
        return;
        }
        if(ob->query_per()<30){
	 command("hmm1");
	 command("say ������Ӳ���Ư�����ҿɲ��������ĵ��ӣ�\n");
	 return;
	}
        
        if(!ob->query_temp("bai_wanwan")){
          ob->set_temp("bai_wanwan_step1",1);
          command("say ���������ҪһЩ���ϣ���֪��"+RANK_D->query_respect(ob)+
                 "�ܲ��ܰ���Ū����");
          return;
        }

        lev=ob->query_skill("cuff",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("dagger",lev);
        tell_object(ob,HIY"��ӻ���ȭ�������Ե��˻���ذ����\n"NOR);
               
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("bai_wanwan");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin_guan");
}

int accept_object(object ob,object obj)
{
    string msg;
    
    if(!ob->query_temp("bai_wanwan_step1"))
    return 0;
    if(obj->query("order")!=2)
    return 0;
    ob->add_temp("bai_wanwan_goods",1);
    if(ob->query_temp("bai_wanwan_goods")==1){
      msg="$N��$n΢΢һЦ��лл���ˣ�\n";
    }
    else
    if(ob->query_temp("bai_wanwan_goods")==2){
      msg="$Nչ�յ����鷳"+RANK_D->query_respect(ob)+"�ˡ�\n";      
    }
    else{
      msg="$N�������Ǹ�л��"+RANK_D->query_respect(ob)+"�ĵز���\n"+
          "�Ժ���ѧʲô�͵���ʦ���������ɡ�\n"; 
          ob->set_temp("bai_wanwan",1);
      ob->delete_temp("bai_wanwan_goods");
      ob->delete_temp("bai_wanwan_step1");
    }
    message_vision(msg,this_object(),ob);

    return 1;
}
    

int do_quest1()
{
   object ob;
   string msg;
   int flag;
   
   ob=this_player();
   
   if(ob->query("perform_quest/lingxiao")){
     command("say ���Ѿ��������ħն�ľ��ϣ��Ժ����߾Ϳ����Լ��ˣ�");
     return 1;
   }
   if(ob->query("perform_quest/wanhuan")){
     command("say ���Ѿ������ǧ��ͭ���ľ��ϣ��޷��������ħն�ľ����ˣ�");
     return 1;
   }
   if(ob->query("perform_quest/yulong")){
     command("say ���Ѿ��������ħ���ľ��ϣ��޷��������ħն�ľ����ˣ�");
     return 1;
   }
   if(ob->query_skill("tianmo-zhen",1)){
     command("say ��ѧ����ħ���޷���ѧϰ��ħն�ľ����ˣ�");
     return 1;
   }
   
   if(ob->query_skill("tianmo-zhan",1)<160){
      command("pat "+ob->query("id"));
      command("say ��ġ���ħն����Ϊ̫���ˣ����ڻ�����������еľ��ϣ�");
      return 1;
   }
   
   
   msg="$N����$nһ�ۣ�ͻȻ������Ц�����������������̽�����ô��ս���а����ӣ�\n";
   message_vision(msg,this_object(),ob); 
   
   flag=COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,2);
   
   if(!flag){
     msg="$N��$nŭ������Ȼ�㱾����ô��ǿ������������ʲô��\n";
     message_vision(msg,this_object(),ob); 
     return 1;
   }
   ob->set_temp("tianmz_quest1",1);
   command("whisper "+ob->query("id")+" "+"��ħն�ľ�����������У����Ҫ�����ˣ�");
   return 1;
}

int do_quest2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("tianmz_quest1")){
     command("sigh");
     command("say ʦ�������书��ǿ����Ҳδ������ʤ������");
     return 1;
   }
   ob->delete_temp("tianmz_quest1");
   ob->set_temp("tianmz_quest2",1);
   command("say �Ҹոմ��Ĵ�����������������һ�ܣ�");
   message_vision("$N����һЦ��\n",this_object());
   return 1;
}

int do_quest3()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("tianmz_quest2")){
     command("say ������ħն�ľ�ѧ����δ���������ˣ�");
     return 1;
   }
   ob->delete_temp("tianmz_quest2");
   ob->set_temp("tianmz_quest3",1);
   msg="$N��$nŶ��һ����������������ʦ������ã��������档˵������һЦ��\n"+
       "�����뵽��ʲô�����¡�\n"; 

   message_vision(msg,this_object(),ob);
   return 1;
}

int surrender(object killer,object victim)
{
     string msg;
         
     if(killer->query_temp("tianmz_quest5")){
     	msg="$Nǿ�����ݣ����������ħն�����Ѿ�����ˣ����ǹ���������һ��... ...\n"+
     	    "����ȥ$N��Щ���£�$n�������Ǿ��������գ��������������ݣ�������Ѫ������\n"+
     	    "����ѩ���������ѩ��ȹ�³���ľ��󣬽������ĵ�������������������\n";
     	message_vision(msg,this_object(),killer);
     	killer->set("perform_quest/lingxiao",1);
     	killer->save();
     	killer->delete_temp("tianmz_quest5");
     	return 1;
     }

     
     if(!killer->query_temp("tianmz_quest3"))
     return 1;
     command("heng");
     return 1;
}

int end_fight(object killer,object victim)
{
   string msg;
   
   if(!victim->query_temp("tianmz_quest3"))
   return 1;
   
   msg="$N��$n˵������������ô��һ��Ƥ��ʩչ����ն������ħ����ն�ķ��������ķ���\n"+
       "������������б��У�ɱ�б������ϴ�����ƭ��ġ�\n";
   message_vision(msg,killer,victim);
   victim->delete_temp("tianmz_quest3");
   victim->set_temp("tianmz_quest4",1);
   return 1;
}

int do_quest4()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("tianmz_quest4")){
     command("say �Һܾ�û�������ˣ��˼Һ���������");
     return 1;
   }
   ob->delete_temp("tianmz_quest4");
   ob->set_temp("tianmz_quest5",1);
   
   msg="$N̾��һ���������Ѿ�ʮ��û�м������ˣ���֪������������ڿɺã�\n";
   message_vision(msg,this_object(),ob);
   return 1;
}

int do_quest5()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("tianmz_quest5")){
     command("say ��򲻹��ҵģ��ò�����ս�ˣ�");
     return 1;
   }
   fight_ob(ob);
   return 1;
}

int do_skjf_quest()
{
   object ob,target,*guards;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/kong_action3")){
     command("say ƾ��Ҳ��������а֮ս���㻹���Զ�أ�");
     return 1;
   }
   guards=ob->query_temp("guarded");
   if(!arrayp(guards)){
    command("say �����Լ�Ҳ��սʤ�ң������ܵģ�");
    return 1;
   }
   if(guards)
   guards=guards-({0});
   if(sizeof(guards)>1){
     command("say ������ô����֣���ʲô����");
     return 1;
   }
   target=guards[random(sizeof(guards))];
   if(!objectp(target)||environment(target)!=environment(ob)){
     command("say �����Լ�Ҳ��սʤ�ң������ܵģ�");
     return 1;
   }
   if(target->query("combat_exp")<1000000){
     command("say ��İ����书̫���˰ɣ�");
     return 1;
   }
   if(target->query("famous")<2000){
     command("say ��İ���ûʲô����������һ���ɣ�");
     return 1;
   }
   if(target->query("gender")=="Ů��"){
     command("say �㻹�Ҹ��а������ɣ�");
     return 1;
   }
   if(environment(ob)->query("no_death")){
     command("say ����ط���ս�������ʰɣ�");
     return 1;
   }
   
   msg="\n$NЦ�����ðɣ���Ȼ��ζ�Թ��Ҫ�˽ᣬ�ǾͿ�ʼ�ɣ�\n"+
       "$NͻȻ��$n����������\n"+
       target->name()+"����һԾ��������$n��ǰ��\n"+
       "$N��ħ����һ����"+target->name()+"�޷��������Ѿ����������أ�\n";
   message_vision(msg,this_object(),ob);
   target->die();
   
   "/cmds/std/go.c"->do_flee(ob);
   
   msg="\n$NͻȻ������������Ĵ�Կա�����Ʈ��ĵ�������\n";
   message_vision(msg,ob);
   ob->delete_temp("perform_quest/kong_action3");
   ob->set("perform_quest/kong",1);
   
   return 1;
}
