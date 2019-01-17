
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
string do_quest();
string move_room();
string do_skill_quest();
string do_skill_quest2();
string do_tmd_quest1();
string do_tmd_quest2();
int do_give();
int do_syxf_quest();

void create()
{
   int i;
   object *ob;
   set_name("ף����",({ "zhu yuyan","zhu","yu","yan" }) );
        set("gender", "Ů��" );
	set("nickname","����");
        set("age", 42);
   set("long", "���������ɵĽ���,�����书�����ֿ�����\n"+
               "һ�����ġ�����ħ�����Ƕ�������!\n");
       
    set("combat_exp",5000000);
   set("str", 25);
   set("dex",30);
   set("per", 28);
 
    set_skill("whip",450);
    set_skill("dodge",450);
    set_skill("parry",450);
    set_skill("force",500);
    set_skill("literate",500);
    set_skill("tianmo-jue",450);
    set_skill("tianmo-dafa",500);
    set_skill("tianmo-huanzong",450);
    set_skill("tianmo-dai",450);

    set("perform_quest/yulong",1);
    set("apply_points",1000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("exert huihun") :),
        (: command("exert jufen") :),
        (: command("perform yulong") :),
    }));

    set("max_gin",5000);
    set("max_sen",6000);
    set("max_kee",7000);
    set("max_force",11000);
    set("force",11000);
   create_family("������",3,"����");
   set("inquiry",([
	   "��������":(:do_quest:),
	   "����":(:move_room:),
	   "��ħ��":(:do_tmd_quest1:),
	   "����Ԧ��":(:do_tmd_quest2:),
	   "ˮ���䷨":(:do_syxf_quest:),
	   //"�·�":(:do_give:),
	  // "���Ľ���":(:do_skill_quest:),
	 //  "����":(:do_skill_quest2:),
	   ]));  
   set("perform_quest/yulong",1);//NPCӦ�ý�ô����⣬��Ȼperform������С��
   setup();
   
   ob=children(__DIR__"obj/jueqing-bian");
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
   carry_object(__DIR__"obj/jueqing-bian")->wield();
  
  
}
void attempt_apprentice(object ob)
{
	
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	if(ob->query("family/master_name")=="����"){
	command("heng "+ob->query("id"));
	command("say ��Ȼ���Ѿ����ˊ���Ϊʦ���Ͳ������ұ����ˣ�\n");
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
        if(ob->query("office_number")<50){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query("bellicosity")<1000){
        command("say ���ɱ�������࣬��γ�Ϊ�����µ�ħ�ŵ��ӣ�\n");
        return;
        }
        if(ob->query_per()<28){
	 command("hmm1");
	 command("say ������Ӳ���Ư�����ҿɲ��������ĵ��ӣ�\n");
	 return;
	}
        
        lev=ob->query_skill("cuff",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("whip",lev);
        tell_object(ob,HIY"��ӻ���ȭ�������Ե��˻����޷���\n"NOR);
                
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin3");
}

//force quest
string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("tianmo-dafa",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="yingui")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_zhu",1);
  
  obj=new(__DIR__"q_zhuyuyan");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "�ð��������Ϊ�������ߣ������ȴ�Ӯ���ľͷ�ˣ�\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu"))
   return 1;
   message_vision(HIR"$N���쳤Ц������ħ�����ں�������ˣ�\n"NOR,victim);
   message_vision(HIR"$NͻȻ��ɫһ�䣬��Ȼ�ܴ�ù��ң����ȥ�ҵ�����ѧϰ�ɣ�\n"NOR,victim); 
   killer->set("family_lingwu","yingui");
   killer->set("title","��������");
   killer->move("/d/clone/room/lingwu/yingui/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_zhu"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "���Ǹ�ͨ������������ʵ��ɣ�\n";
  if(ob->query("family_lingwu")!="yingui")
  return "����˵ʲô����һ��Ҳ������\n";
  ob->move("/d/clone/room/lingwu/yingui/mishi");
  return "��Ը����������ħ���ݺὭ����һͳ���֣�\n";
}


string do_skill_quest()
{
    object ob;
    
    ob=this_player();
    
    if(ob->query("class")!="yin3")
     return "��������Ľ������������޷�������еľ��ϵģ�\n";
     
    if(ob->query("bellicosity")<600000)
     return "�������ݶ��Ľ�����ƾ�����ڵ��������޷����յģ�\n";
    
    ob->set("dtsl_quest_sxjianfa_ok",1);
    
    return "��Ȼ���ĵ��㹻�ݶ��������㹻����ѧϰ�������Դ��Ľ����ˣ�\n";
}

string do_skill_quest2()
{
   object ob;
    
    ob=this_player();
    
   if(ob->query("class")!="yin3")
     return "��������İ����ַ��������£���ѧϰһ�������������������ɣ�\n";
   
   ob->set("dtsl_quest_throw_ok",1);
   
   return "�ðɣ������ھͽ��˰����ַ��������㣡\n";
}

string do_tmd_quest1()
{
    object ob;
    string msg;
    
    ob=this_player();
    
    if(ob->query_skill("tianmo-dai",1)<160)
    return "���������޷������ħ�������������ģ�\n";
    
    if(ob->query("perform_quest/yulong"))
    return "���Ѿ��������ħ���ľ�ѧ����ûʲô�ɽ̵��ˡ�\n";
    if(ob->query("perform_quest/wanhuan"))
     return "���Ѿ������ǧ��ͭ���ľ��ϣ��޷��������ħ���ľ����ˣ�";
    if(ob->query("perform_quest/lingxiao"))
       return "���Ѿ��������ħն�ľ��ϣ��޷��������ħ���ľ����ˣ�";
    if(ob->query_skill("tianmo-zhen",1))
       return "��ѧ����ħ���޷���ѧϰ��ħ���ľ����ˣ�\n";
    
    ob->set_temp("tmd_quest_action1",1);
    
    msg="��ħ������һ�С�����Ԧ�����������Ƿ���\n"+
        "���Ǳ�����������������о��ϵ���ȴ���Ǻܶࡣ\n";
    return msg;
}

string do_tmd_quest2()
{
    object ob;
    string msg;
    
    ob=this_player();
    
    if(is_fighting())
       return "û�����Һ��˴���������Ȼ������ɣ�\n";
    
    if(!ob->query_temp("tmd_quest_action1"))
    return "���������Ĺ������ѵ��볢��һ����\n";
    
    ob->delete_temp("tmd_quest_action1");
    msg="$N��$n΢΢һЦ���ðɣ���Ȼ�������˾��ƣ����Ҿ����ָ����㣡\n";
    message_vision(msg,this_object(),ob);
    fight_ob(ob);
    remove_call_out("do_action2");
    call_out("do_action2",2,ob);
    return "���ҪС���ˣ�\n";
}

void do_action2(object ob)
{
   if(!ob) return;
   if(!living(ob)) return;
   if(ob->is_ghost()) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!this_object()->is_fighting(ob)){
    tell_object(ob,query("name")+"������Ц����û�뵽�㵨�����С�������᱾�ž�����\n");
    return;
   }
   set("apply_points",316);//��������
   command("perform yulong");
   call_out("do_action3",2,ob);
   return;
}

void do_action3(object ob)
{
   string msg;
   
   if(!ob) return;
   if(!living(ob)) return;
   if(ob->is_ghost()) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!this_object()->is_fighting(ob)){
    tell_object(ob,query("name")+"������Ц����û�뵽�㵨�����С�������᱾�ž�����\n");
    return;
   }
   remove_enemy(ob);
   ob->remove_enemy(this_object());
   
   msg="$N��$n΢΢һЦ���ã�������Ĺ��򻹲���\n"+
       "��ô������ᵽ���еľ�������\n";
   msg +="\n$n��ͷ˼����һ�ᣬͻȻ��Ц��������$Nһ�Ϲ�����лʦ��ָ�㣡\n";
   message_vision(msg,this_object(),ob);
   ob->set("perform_quest/yulong",1);
   ob->save();
   return;
}

int do_give()
{
   object ob,obj;
   
   ob=this_player();
   
   if(present("yulong_cloth",ob)){
     command("say ���Ѿ��С����Ȼ��¡��ˣ�����ô̰���ˣ�");
     return 1;
   }
   obj=new(__DIR__"obj/caimei-huanyi");
   obj->move(ob);
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
              obj->query("name")+"��\n");
   command("pat "+ob->query("id"));
   return 1;
}

int do_syxf_quest()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/yanyu_action1")){
     command("say ���䷨����Ů��������ȷʵ��������");
     return 1;
   }
   command("say �ã��Ҿ����㿴����β��������䷨�ľ��裡");
   
   msg="\n$N��˫�䳯����������ǵ��˽�ǰ��˫��ͻȻ�ɾ���������������Ტ����\n"+
       "��ͬ��������˫��һ�㣡$nֻ��������û����·���ӣ����ڱ�$N��˫��������\n"+
       "�ؿںͶ�ͷ�ϣ�\n\n";
   msg+="$N����һЦ��������Ů���ĵ��ӣ��Ҳ�ɱ�㡣\n\n";
   message_vision(msg,this_object(),ob);
   ob->set("perform_quest/yanyu",1);
   ob->delete_temp("perform_quest/yanyu_action1");
   ob->unconcious();
   return 1;
}
