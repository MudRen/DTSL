
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("�߲���",({ "bian bufu","bian","bu","fu" }) );
   set("gender", "����" );
   set("nickname","ħ��");
   set("age", 42);
   set("long", "���������ɵĸ���֮һ�������书������ף������\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("strike",150);
   set_skill("jiutian-huanzhang",150);
   set_skill("moxin-lianhuan",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jue",150);
   set_skill("tianmo-huanzong",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   setup();
  
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�÷�ɣ�\n");
	return;
        }
        if(ob->query_skill("tianmo-dafa",1)<100){
        command("say �����ħ����Ϊ������������ȥ��ϰһ���ٰ���Ϊʦ�ɣ�\n");
        return;
        }
        
        if(ob->query("class")!="yin1"){
          command("say ��û�С�ն��Ե�������������Ϊͽ��");
          return;
        }
        
        if(ob->query("office_number")<30){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }

	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin2");
}

int end_fight(object killer,object victim)
{
    if(!victim->query_temp("perform_quest/duomeng_action1"))
    return 1;
    victim->add_temp("perform_quest/duomeng_wins",1);
    return 1;
}

int surrender(object killer,object victim)
{
   string msg;
   
   if(!killer->query_temp("perform_quest/duomeng_action1"))
   return 1;
   if(killer->query_temp("perform_quest/duomeng_wins")!=2)
   return 1;
   
   msg="$N��$n��Цһ������Ȼ����������ǰ�ˣ���Ȼ���Ѿ������ҺͶ����ɵĶ�Թ��\n"+
       "��ô�����ְɣ�\n";
   msg+="\n$n�뵽��һ�����ֵĶ���ԹԹ���ƶ�����������Լ���һ����û���κι�ϵ��\n"+
        "Ʈ�ν���Ҳ�������λ����ޣ���ȥ��һ��Ҳֻ�������λö��ѡ�\n";
   message_vision(msg,victim,killer);
   killer->delete_temp("perform_quest/duomeng_action1");
   killer->delete_temp("perform_quest/duomeng_wins");
   killer->set("perform_quest/duomeng",1);
   return 1;
}