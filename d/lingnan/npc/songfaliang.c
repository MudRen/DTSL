
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <job_money.h>

int do_action1();

void create()
{
   set_name("�η���",({ "song faliang","song","faliang" }) );
   set("gender", "����" );
   set("age", 28);
   set("long", "�������μұ����η����������μұ�����һ���еĸ��֡�\n");
       
   set("combat_exp", 600000);
   
   set_skill("blade",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   
   set_skill("tiandao-bajue",150);   
   set_skill("literate",150);
   set_skill("anxiang-fuying",150);
   set_skill("tiangang-sanjue",150);
   set_skill("wangdao-jue",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   
   set("inquiry",([
     "����":(:do_action1:),
     ]));
   
   create_family("�μұ�",5,"����");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/blade")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="�μұ�")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<100){
        command("say ������������Ϊ̫���ˣ��Ҳ��������ĵ��ӣ�");
        return;
        }
	if(ob->query("office_number")<30){
        command("say ��Ĺ�����ô�ͣ��μұ��ɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query("deposit")<100000){
         command("say �����μұ�������һ�󷧣�������ô�������Ƶ����ҿɲ�Ҫ��");
         return;
        }
        if(!ob->query_temp("bai_songfaliang/action2",1)){
          command("say ��û�����ҵĿ��飬�����֪����ĵ�����");
          return;
        }
        
        lev=ob->query_skill("cuff",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("blade",lev);
        tell_object(ob,HIY"��ӻ���ȭ�������Ե��˻���������\n"NOR);

	command("say ���Ҫ�ú���ϰ���գ��μұ�����˥�Ϳ������ˣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song2");
}

string *dirs=({
"/d/huashan","/d/emeishan","/d/taishan",
});

int do_action1()
{
  object ob,target;
  
  ob=this_player();
  
  if(ob->query("family"))
  if(ob->query("family/family_name")!="�μұ�"){
      command("say �˻��Ӻ�˵��\n");
      return 1;
  }
  if(ob->query("family"))
  if(ob->query("family/family_name")=="�μұ�")
  if((int)ob->query("family/generation",1)<=6){   
      command("say �˻��Ӻ�˵��\n");
      return 1;
  }
  if(ob->query_temp("bai_songfaliang/action1")){
    command("say �㵽����û�е���ȥ��");
    return 1;
  }
  if(ob->query_temp("bai_songfaliang/action2")){
    command("say ��Ȼ����ô�е������Ͱ���Ϊʦ�ɣ�");
    return 1;
  }
  ob->set_temp("bai_songfaliang/action1",1);
  target=new(__DIR__"tigger");
  if(!target->set_status(ob)){
  	command("say ���һ�£������뿼��ʲô��Ŀ��");
  	return 1;
  }
  ob->add_temp_array("job_temp_killer",target);
  
  if(!random_place(target,dirs)){
  	command("say ���һ�£������뿼��ʲô��Ŀ��");
  	return 1;
  }
  if(!environment(target)){
  	command("say ���һ�£������뿼��ʲô��Ŀ��");
  	return 1;
  }
  command("say �ðɣ��ҾͿ�����ĵ���������Σ�\n"+
          "��˵��"+MISC_D->find_place(environment(target))+"��һֻ"+target->name()+"��\n"+
          "��ȥ����ɱ���ɣ�");
  return 1;
}
  