
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <job_money.h>

int do_action1();
int do_action2();
int do_action3();

void create()
{
   set_name("������",({ "shan wanjing","shan","wanjing" }) );
   set("gender", "Ů��" );
   set("nickname","���鹫��");
   set("age", 24);
   set("long", "���Ƕ����ɵĹ�����\n");
       
    set("combat_exp",3000000);
   set("per", 25);
    set_skill("dodge",300);
    set_skill("parry",300);
    set_skill("force",300);
    set_skill("sword",300);
    set_skill("dongming-xinfa",300);
    set_skill("bihai-force",300);
    set_skill("piaomeng-jianfa",300);
    set_skill("nishang-piaoming",300);
    set_skill("strike",300);
    set_skill("literate",300);

    set("perform_quest/duomeng",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform duomeng") :),
        (: command("exert shui") :),
        (: command("exert huo") :),
    }));

    set("max_gin",4000);
    set("max_sen",5000);
    set("max_kee",6000);
    set("max_force",8000);
    set("force",8000);
   create_family("������",3,"����");
   
   set("inquiry",([
     "�����˱�":(:do_action1:),
     "����ϭ":(:do_action2:),
     "Ʈ�ν���":(:do_action3:),
     ]));
   
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("gender")=="����"){
	
	command("say �Ҳ����е��ӵģ����������Ͷ�뱾�ɣ�ȥ�����ʰɣ�\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<150){
          command("say �̺��������Ƕ����ɵĸ������㲻�ú�ѧ����ô������Ϊ�����أ�");
          return;
        }
        if(ob->query("office_number")<50){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(!ob->query_temp("bai_shanwanjing/ok")){
          command("say ������Ϊ�����˱����·��ģ���Ȼ�ɣ�");
          return;
        }
        
        command("say ���˰��ˣ��˱������ܱ��������Ϻá������Ĳ����Ҿ�����Ϊͽ�ɡ�");
        ob->delete_temp("bai_shanwanjing/ok");

               
	command("say ����ս�ҷ������Ƕ���δ�����������⣬�����Ҫ�ú���ϰ���գ������������ɣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming3");
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="������")
   if((int)ob->query("family/generation",1)<=4){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="������"){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(!ob->query("family")){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(ob->query_skill("bihai-force",1)<150){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   
   ob->set_temp("bai_shanwanjing/action1",1);
   command("say �����˱��ѱ�������Ϳ��ٵ��ߣ���շת���ۣ����ھ�����˭�����ҿɲ�֪����\n"+
           "�����ڽ����䲼������ϭ����ϣ������Ѱ�ء�\n");
   return 1;
}

string *dirs=({
"/d/hengshan","/d/taishan",
});

int do_action2()
{
   object ob,killer;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_shanwanjing/action1")){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="������")
   if((int)ob->query("family/generation",1)<=4){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="������"){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(!ob->query("family")){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   if(ob->query_skill("bihai-force",1)<150){   
	 command("say ���������ﲻ��æ�ġ�\n");
	 return 1;
   }
   
   if(ob->query_temp("bai_shanwanjing/action2")){
     command("say �㵽����û�е���ȥ��");
     return 1;
   }
   
   
   killer=new(__DIR__"killer");
   killer->set_status(ob);
   
   if(!random_place(killer,dirs)){
     command("say ���һ��... ...");
     return 1;
   }
   if(!environment(killer)){
     command("say ���һ��... ...");
     return 1;
   }
   
   ob->set_temp("bai_shanwanjing/action2",1);
   ob->add_temp_array("job_temp_killer",killer);
   
   command("say ��˵�����˱���һ����"+killer->name()+"���ţ�����Ŀǰ������"+
           MISC_D->find_place(environment(killer))+"��\n"+
           "��ȥ���˱��������ɣ�\n");
   return 1;
}

int do_action3()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("piaomeng-jianfa",1)<160){
    command("say ���Ʈ�ν�����Ϊ̫���ˣ����ڻ��޷�������еľ��ϣ�");
    return 1;
   }
   if(ob->query("perform_quest/duomeng")){
    command("say ���Ѿ�������Ʈ�ν����ľ��ϣ��Ժ���Լ���Ŭ���ɣ�");
    return 1;
   }
   if(ob->query("perform_quest/yanyu")){
    command("say ���Ѿ�������ˮ���䷨�ľ��ϣ��޷�������Ʈ�ν����ľ��ϣ�");
    return 1;
   }
   if(ob->query("perform_quest/pili")){
    command("say ���Ѿ����������������ľ��ϣ��޷�������Ʈ�ν����ľ��ϣ�");
    return 1;
   }
   
   ob->set_temp("perform_quest/duomeng_action1",1);
   command("say ��Ϊ��ɱ�߲����������˴˽�����\n"+
           "�������ҵ����������Ҷ���һ����鶼û�У���һ��Ҫ������ɱ�ˡ�\n");
   return 1;
}
