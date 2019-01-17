
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("������",({ "dun yugu","dun" }) );
   set("gender", "����" );
   set("age", 42);
   
   set("long", "�����Ǳ����ĵܵܣ����ͻ�ʴ󺹵����Σ�\n");
       
   set("combat_exp",1000000);
 
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("whip",200);
   set_skill("literate",200);
  
   set_skill("yanyang-dafa",200);
   set_skill("canglang-jue",200);
   set_skill("youlong-shenfa",200);
   set_skill("feiwo-whip",200);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   create_family("ͻ��",3,"��ʿ");
   set("inquiry",([
    "����":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
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
        if(!ob->query_temp("bai_dun_ok")){
          command("say ��û�������飬����ô�����㣿");
          return;
        }
        ob->delete_temp("bai_dun_ok");
     
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
  if(ob->query_temp("bai_dun_ok")){
     command("say ���Ѿ����������ˡ�");
     return 1;
  }
  
  ob->set_temp("bai_dun",1);
  command("say ������һֻСӥ�����ܲ��ܸ�����һ����");
  
  return 1;
}

int accept_object(object ob,object obj)
{
   if(!ob->query_temp("bai_dun"))
    return 0;
   if(!obj->query("bai_dun_quest_obj2"))
   return 0;
   
   ob->delete_temp("bai_dun");
   ob->set_temp("bai_dun_ok",1);
   command("say лл���ˣ�");
   return 1;
}