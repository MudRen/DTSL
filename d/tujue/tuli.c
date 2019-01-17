
inherit F_MASTER;
inherit NPC;

#include <ansi.h>


int do_action1();

void create()
{
   set_name("ͻ��",({ "tu li","tu","li" }) );
   set("gender", "����" );		
   set("age",48);
   set("nickname","�����");
   set("long", "�����ǡ�����硱ͻ���������ֶ֮���书��ǿ��\n");       
   set("combat_exp",2500000);
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("spear",350);
   set_skill("literate",200);
  
   set_skill("yanyang-dafa",300);
   set_skill("canglang-jue",200);
   set_skill("youlong-shenfa",300);  
   set_skill("fuying-spear",350);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("force",8000);
   set("max_force",8000);
   create_family("ͻ��",3,"�ɺ�");
    set("perform_quest/fengsha",1);
    set("perform_quest/fengyu",1);
   set("chat_chance_combat",80);
   set("chat_msg_combat",({
                (: command("perform fengyu") :),
                (: command("perform fengsha") :),
                (: command("execute xiao") :),
        }));
    set("apply_points",200);
   set("inquiry",([
     "����":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/fuying-spear")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<=3)
	{   
	  command("say �˻��Ӻ�˵��");
	  return;
	}
	if(ob->query("tujue_jun")!="���Ǿ�"){
            command("say ��û�������Ǻ��Ǿ����ҿɲ�Ҫ��������ͽ�ܣ�");
            return;
        }
        if(ob->query_skill("yanyang-dafa",1)<150){
            command("say �����������Ϊ̫���ˣ������������Ϊͽ��");
            return;
        }
        if(ob->query("office_number")<40){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(!ob->query_temp("husong_badai_ok")){
          command("say ����֤�����ʵ�����ҿ�����");
          return;
        }
                
	command("say ���ҪŬ��ѧϰ�书������Ϊͻ��һͳ��ԭ������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue3");
}

int do_action1()
{
  object ob,target;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="ͻ��"
    ){
    command("say ������˵Ц�ˣ�");
    return 1;
  }
  if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<=4)
	{   
	  command("say �˻��Ӻ�˵��");
	  return 1;
	}
  if(!ob->query("family")
    ){
    command("say �㻹������ͻ�ʵ��ӣ���λ��Ͱ������");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="���Ǿ�"){
      command("say ���Ȼ�Ѿ������˽��Ǿ�����������Ϊ�Ұ��£�");
      return 1;
  }
  if(ob->query_temp("husong_badai")){
      command("say �㵽�׸Ҳ��һ��ͣ�");
      return 1;
  }
  if(ob->query_temp("husong_badai_ok")){
      command("say �㻤�Ͱ��������֤�����ʵ�����ҿ�������Ϊͽ�ˣ�");
      return 1;
  }
  
  target=new(__DIR__"badai");
  target->set_status(ob);
  target->move(environment(ob));
  
  msg="$N��$n��������ҰѰ�������͵������������Űɣ�·��С���ҵĳ�У�\n\n";
 
  ob->add_temp_array("job_temp_killer",target);
  ob->set_temp("husong_badai",1);
  message_vision(msg,this_object(),ob);
  call_out("killer_come",15,ob);
  return 1;
}

void killer_come(object ob)
{
  object killer;
  
  if(!ob) return;
  if(ob->is_ghost()) return;
  
  killer=new(__DIR__"killer");
  killer->set_status(ob);
  
  tell_object(ob,HIB"��ͻȻ�е�һ����紵����\n\n"NOR);
  
  killer->move(environment(ob));
  
  killer->kill_ob(ob);
  
  return;
}
