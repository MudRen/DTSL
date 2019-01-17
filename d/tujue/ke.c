
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   int i;
   object *ob;
   
   set_name("�ɴ�־",({ "ke dazhi","ke" }) );
   set("gender", "����" );		
   set("age", 30);
   set("combat_exp",6500000);

   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("blade",350);
   set_skill("literate",200);

   set_skill("yanyang-dafa",300);
   set_skill("canglang-jue",200);
   set_skill("kuangsha-daofa",350);
   set_skill("youlong-shenfa",300);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("force",8000);
   set("max_force",8000);
   
   set("inquiry",([
     "����":(:do_action1:),
     ]));
   
   create_family("ͻ��",3,"��ʿ");
    set("perform_quest/kuangsha",1);
   set("chat_chance_combat",80);
   set("chat_msg_combat",({
                (: command("perform kuangsha") :),
                (: command("execute xiao") :),
        }));
    set("apply_points",200);
   
   ob=children(__DIR__"obj/kuangsha-dao");
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
   setup();
  
   carry_object(__DIR__"obj/kuangsha-dao")->wield();  
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
            command("say ��û�������ǽ��Ǿ����ҿɲ�Ҫ��������ͽ�ܣ�");
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
        if(!ob->query_temp("bai_ke_ok")){
          command("say ��û�������飬����ô�����㣿");
          return;
        }
        ob->delete_temp("bai_ke_ok");
        
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
  object ob;
  
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
    command("say �㻹������ͻ�ʵ��ӣ���ν����ҵĿ��飿");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="���Ǿ�"){
      command("say ���Ȼ�Ѿ������˺��Ǿ�����������Ϊ�Ұ��£�");
      return 1;
  }
  if(ob->query_temp("bai_ke_ok")){
     command("say ���Ѿ����������ˡ�");
     return 1;
  }
  if(ob->query_temp("bai_ke")){
     command("say �㵽�׸Ҳ���ȥ��");
     return 1;
  }
  command("say ���ǻ����֧Ԯ�������Ԫ������֪����ı�����Σ�\n"+
          "������ܴ�Ӯ��߸�������Ҿ�����Ϊͽ��");
  ob->set_temp("bai_ke",1);
  return 1;
}
