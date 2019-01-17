
inherit F_MASTER;
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string do_action1();

void create()
{
   set_name("��ʿ��",({ "lin shihong","lin" }) );
        set("gender", "����" );		
        set("age", 34);
   set("long", "������۶��������½��ԳƳ��۵���ʿ�ꡣ\n");
       
   set("combat_exp",300000);
  
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("literate",100);
   set_skill("tianmo-dafa",100);
   set_skill("tianmo-huanzong",100);
   set_skill("tianmo-jue",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("������",7,"����");
   set("class","yin1");
   set("inquiry",([
     "������":(:do_action1:),
     ]));
   setup();
   
}

int accept_object(object who,object obj)
{
   if(!obj->query("yinguibaishimihan"))
    return 0;
   if(who->query("gender")=="Ů��")
   return notify_fail("�����������Ҳ�̫���ʣ��㻹ȥ�ҵ�÷�ɣ�\n");
   who->set_temp("bai_yingui/step2",1);
   tell_object(who,query("name")+"�ٺ�һЦ��ԭ����֣���Ƽ������˲ţ��ã��ã���\n"+
   "����㲻�������Ͱ���Ϊʦ�ɣ�\n");
   return 1;
}
   

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�÷�ɣ�\n");
	return;
        }
        
        if(!ob->query_temp("bai_yingui/step2")){
        command("say �㵱����ʲô�ˣ���ô�������ͽ�ܣ�");
        return;
        }
	
	ob->delete_temp("bai_yingui/step2");
	ob->delete_temp("bai_yingui/step1");
	
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "none");
}

string *dirs=({
"/d/huashan",
});

string do_action1()
{
   object ob,target;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������")
   return "��Ҳ����������𣿿��߿���\n";
   
   if((int)ob->query("family/generation",1)<=7)
   return "��Ա����Ѿ�֪���ܶ��ˣ���������ʲô��\n";
   
   if(ob->query_skill("tianmo-dafa",1)<100)
   return "�����ħ����Ϊ̫���ˣ������ȱ���̫�౾�ɵ����˰ɣ�\n";
   
   if(ob->query_temp("bai_yingui/step3"))
   return "����㲻�ܡ�ն��Ե��������Զ���ܳ�Ϊ������������ӣ���\n";
   
   if(ob->query_temp("bai_yingui/step4")||
      ob->query("yingui_pass_ok")){
   ob->set("yingui_pass_ok",1);
   ob->delete_temp("bai_yingui/step4");
   return "��Ȼ���Ѿ���ն��Ե������ôȥ�����ܵ�ȥ��ʦ�ɣ�\n"+
          "�����������и�С���ӣ��ڴ�����������ݴԾͿ����ˣ�\n";
   }
   
   target=new(__DIR__"qinren");
   
   if(!random_place(target,dirs))
   return "�Ȼᣬ�Ȼ�... ...\n";
   if(!environment(target))
   return "�Ȼᣬ�Ȼ�... ...\n";
   
   target->set("long","����"+ob->name()+"������"+target->query("name")+"��\n");
   target->set("name",ob->name()+"��"+target->query("name"));
   target->set("target_id",ob->query("id"));
   ob->add_temp_array("job_temp_killer",target);
   
   ob->set_temp("bai_yingui/step3",1);
   
   return "�ðɣ��ҵı����㶼ѧ���ˣ�\n"+
   "��������ѧϰħ����Ҫ��Ϊ���˼������Ӳſ��ԣ�\n"+
   "�����й�ؽС�ն��Ե�������Ѿ��ҵ���������ˣ�\n"+
   "��˵"+target->query("gender_id")+"��"+MISC_D->find_place(environment(target))+"����ȥ��"+
   target->query("gender_id")+"��ɱ�ˣ���\n";
}