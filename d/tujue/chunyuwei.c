
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("����ޱ",({ "chun yuwei","chun","yuwei" }) );
   set("gender", "Ů��" );		
   set("age",22);
   set("per",24);
   set("long", "�����Ǳ�����ͽ�ܡ�\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("literate",150);
  
   set_skill("yanyang-dafa",150);
   set_skill("canglang-jue",150);
   set_skill("youlong-shenfa",150);  
   set_skill("kuangsha-daofa",150);
  
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("ͻ��",5,"��ʿ");
   set("inquiry",([
     "����":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<=5)
	{   
	  command("say �˻��Ӻ�˵��");
	  return;
	}
	if(ob->query("tujue_jun")!="���Ǿ�"){
            command("say ��û�������ǽ��Ǿ����ҿɲ�Ҫ��������ͽ�ܣ�");
            return;
        }
        if(ob->query_skill("yanyang-dafa",1)<100){
            command("say �����������Ϊ̫���ˣ������������Ϊͽ��");
            return;
        }
        if(ob->query("office_number")<30){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(!ob->query("menpai/tujue2")){          
          ob->set("menpai/tujue2",1);
				}
	command("say ���ҪŬ��ѧϰ�书������Ϊͻ��һͳ��ԭ������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue2");
}

int do_action1()
{
  object ob;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="ͻ��"
    ){
    command("say ������˵Ц�ˣ�");
    return 1;
  }
  if(!ob->query("family")
    ){
    command("say �㻹������ͻ�ʵ��ӣ�������飿");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="���Ǿ�"){
      command("say ���Ȼ�Ѿ������˺��Ǿ����������ٽ����ҽ��Ǿ���");
      return 1;
  }
  if(ob->query("tujue_jun")=="���Ǿ�"){
      command("say ���Ѿ������ˡ�");
      return 1;
  }
 
  msg="$N��$n������ͻ�ʷ�Ϊ���Ǿ��ͽ��Ǿ����ӽ��������ҽ��Ǿ���սʿ�ˣ�\n\n";
 
  ob->set("tujue_jun","���Ǿ�");
  message_vision(msg,this_object(),ob);
  
  return 1;
}