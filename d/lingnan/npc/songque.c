
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <org.h>

string do_quest();
int do_action1();
int do_action2();

void create()
{
   int i;
   object *ob;
   set_name("��ȱ",({ "song que","song","que" }) );
   set("gender", "����" );
   set("nickname",HIG"�쵶"NOR);
   set("age", 52);
   set("long", "�������μұ��ı������˳ơ��쵶�������ĵ�����˵Ϊ���ֵ�һ��\n");
       
   set("combat_exp",8000000);
   set("str", 35);
   set("per", 25);
   
   set_skill("blade",500);
   set_skill("sword",500);
   set_skill("dijian-jue",500);
    set_skill("dodge",400);
    set_skill("parry",400);
    set_skill("force",400);
    set_skill("tiandao-bajue",500);
    set_skill("anxiang-fuying",400);
    set_skill("tiangang-sanjue",400);
    set_skill("poyu-quan",400);
    set_skill("cuff",400);
    set_skill("wangdao-jue",400);
    set_skill("literate",400);
    set("jiali",200);

    set("apply_points",2000);
    set("perform_quest/bajue",1);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform bajue") :),
        (: command("execute wangdao") :),
        (: command("exert zhanyi") :),
        (: command("exert ningxin") :),
    }));
  
    set("max_gin",5000);
    set("max_kee",6000);
    set("max_sen",6000);
    set("max_force",15000);
    set("force",15000);
   
   
   create_family("�μұ�",3,"����");
   set("shili",([
      "name":"songjia_b",
      "leader":"songjia_b",
      ]));
   set("shili_id","songque");
    set("npc_id","songque");
   
   set("inquiry",([
     "����һ��":(:do_quest:),
    // "����":(:do_action1:),
     "�쵶�˾�":(:do_action2:),
     ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   
   ob=children(__DIR__"obj/chanyidao");
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
   
   ob=children(__DIR__"obj/shuixian");
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
   
   ob=children(__DIR__"obj/tanlangtun");
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
     
   carry_object(__DIR__"obj/chanyidao")->wield();
   carry_object(__DIR__"obj/shuixian");
   carry_object(__DIR__"obj/tanlangtun");
   
  
}

void init()
{
   object ob;
   
   ob=previous_object();
   
   if(!ob->query("dtsl_quest_badao_help_ok")
     &&ob->query("combat_exp")>=800000
     &&ob->query("nickname")=="���"+NOR
     &&ob->query("PKS")>=10
     &&ob->query("deadtimes")<3
     &&!ob->query_temp("dtsl_quest_badao_help_ok")
     ){
     ob->set_temp("dtsl_quest_badao_help_ok",1);
     call_out("do_hit_ob",1,ob);
   }
   
}

void do_hit_ob(object ob)
{
  if(!ob)
   return;
  
  command("say �����������������μұ������ǻ�ò��ͷ���");
  
  kill_ob(ob);
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="�μұ�")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say ������������Ϊ̫���ˣ��Ҳ��������ĵ��ӣ�");
        return;
        }
	if(ob->query("office_number")<50){
        command("say ��Ĺ�����ô�ͣ��μұ��ɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query("deposit")<500000){
         command("say �����μұ�������һ�󷧣�������ô�������Ƶ����ҿɲ�Ҫ��");
         return;
        }
        if(ob->query("kill_same_party_flags")){
          command("heng");
          command("say ��������ɱ��ͬ�ŵ����Ҳ�ɱ����������������ɣ�");
          return;
        }
        if(ob->query("kill_good_party_flags")){
          command("heng");
          command("say ���μ���һ�������ɣ���ɱ�����ɵ��ӣ�����ô������Ϊͽ��");
          return;
        }
        /*
        if(!ob->query("char_lev/bai_songque_ok")){
          command("say ��û�о����ҵĿ��飬�Ҳ�������Ϊ���ӵģ�");
          return;
        }
        */
        ob->set("lingnan_menpai/lingnan_MKS",ob->query("MKS"));
        ob->set("lingnan_menpai/lingnan_PKS",ob->query("PKS"));
        ob->set("lingnan_menpai/lingnan_deadtimes",ob->query("deadtimes"));
        if(!ob->query("menpai/songjia3")){
          ob->set("menpai/songjia3",1);
	  
	}
	command("say ���ǳ���������ǰ�ˣ�ϣ���������μұ��ư����£�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song3");
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("�����μұ��ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ORG_D->is_leader("songque"))
	 return notify_fail("���Ѿ����Ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("������������μұ��������ϣ�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ�����μұ��������۰�һ����\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}
string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("tiangang-sanjue",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷�����[����һ��]����ºţ�\n";
  if(ob->query("family_lingwu")=="songjia")
   return "����������ǰ�ˣ����Ѿ�ͻ�ƾ����ˣ����ǿ�ȥ����ɣ�\n";
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_song",1);
  
  obj=new(__DIR__"q_songque");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "�ð��������Ϊ����һ���������ܷ�ͻ��������ϰ��������ľ���д�һ�°ɡ�\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_song"))
   return 1;
   message("vision",HIG"���μұ���:��ȱ���쳤Ц����"+killer->name()+HIG+"սʤ���ң��μұ����ں�������ˣ�\n"NOR,users());
   tell_object(killer,"��ȥ���μұ��İ׻��ã��������������ɵ�һ�����ܣ�\n"+
                      "�ܲ������򣬾Ϳ����Լ����컯�ˣ�\n");
   killer->set("family_lingwu","songjia");
   killer->set("title","����һ��");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_songjia"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
*/
int accept_gage(object me)
{
   message_vision("$N��$nЦ��:�ðɣ�ֻҪ���ܽ�ס�ҵ��������Ϳ��Խ����ҵ�ְλ�ˣ�\n",
    this_object(),me);
   
   add_temp("apply/damage",-900);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   COMBAT_D->do_attack(this_object(),me,this_object()->query_temp("weapon"),0,1);
   add_temp("apply/damage",900);
   if(living(me)){
   message_vision("$N��$nЦ���������ǳ���������ǰ�ˣ��Ժ��μұ��ͽ������ˣ�\n",
   this_object(),me);
   ORG_D->del_leader("songque");
   ORG_D->set_leader_log(me,this_object());
   
   me->set("shili/leader",this_object()->query("shili/leader"));
   CHANNEL_D->do_channel(this_object(), "rumor",
   me->name()+"��Ϊ���μұ��ı�����\n");}
   return 1;
}

int do_action1()
{
  object ob,book;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family"))
  if(ob->query("family/family_name")!="�μұ�"){
      command("say �˻��Ӻ�˵��\n");
      return 1;
  }
  if(ob->query("family"))
  if(ob->query("family/family_name")=="�μұ�")
  if((int)ob->query("family/generation",1)<=4){   
      command("say �˻��Ӻ�˵��\n");
      return 1;
  }
  if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say ������������Ϊ̫���ˣ�����ס�ҵĿ���ģ�");
        return 1;
  }
  if(present("bai_songque_linghui_book",ob)){
  	command("heng");
  	return 1;
  }
  if(ob->query("char_lev/bai_songque_ok")){
    command("say ��Ȼ���Ѿ���������еľ��ϣ��Ͱ���Ϊʦ�ɣ�");
    return 1;
  }
  if(ob->query("char_lev/bai_songque_fail")){
    command("say ���еľ����㶮���Ƕ����������ǲ������ҿ��㻹�����ˣ�");
    return 1;
  }
  book=new(__DIR__"obj/book");
  book->move(ob);
  msg="$N����$nһ"+book->query("unit")+book->query("name")+"��\n"+
      "��������ͽ�ϸ�����������(linghui)�����еľ��ϣ��Ҿ����㣡\n";
  message_vision(msg,this_object(),ob);
  return 1;
}

int do_action2()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->query("perform_quest/ditian")){
     command("say ���Ѿ�ѧϰ�˵ؽ����ľ��裬��û�о�������ѧ�쵶�ģ�");
     return 1;
   }
   if(ob->query("perform_quest/bajue")){
     command("say ���Ѿ�ѧϰ���쵶�˾��ľ��裬�Լ�ȥ��߰ɣ�");
     return 1;
   }
   if(ob->query_skill("tiandao-bajue",1)<190){
     command("say ����쵶�˾���Ϊ̫�ͣ����ڻ��޷�������еľ��裡");
     return 1;
   }
   if(ob->query("family/master_name")!=query("name")){
     command("say ��û������Ϊͽ�����������쵶�˾��ľ��裿");
     return 1;
   }
   if(present("perform_bajue_blade",ob)){
     command("say �����ϰ�ε��ɣ�");
     return 1;
   }
   ob->set_temp("perform_quest/bajue_action1",1);
   obj=new(__DIR__"obj/blade2");
   obj->move(ob);
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+obj->query("name")+"��\n");
   command("say Ҫ�����쵶���������������Ҫ���ǰε���������ϰһ�°ε��ļ����ɣ�");
   return 1;
}
