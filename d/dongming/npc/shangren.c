
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
   set("gender", "����" );
   set("nickname","����ս��");
   set("age", 24);
   set("long", "���Ƕ����ɵĻ����Ľ�֮һ.\n");
       
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   
   set_skill("dongming-xinfa",100);
   set_skill("bihai-force",100);
   set_skill("youyue-zhangfa",100);
   set_skill("nishang-piaoming",100);
   set_skill("literate",100);
  
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("������",7,"����");
   setup();
   
}

void attempt_apprentice(object ob)
{   
	string name;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�ϼ�ɣ�\n");
	return;
        }
        
        if(!ob->query_temp("bai_dongming/action4")){
        command("say �㵱�Ҷ�������ʲô�ط���������ô�������ͽ�ܣ�");
        return;
        }
	
	ob->delete_temp("bai_dongming/action4");
	
	name=ob->query("name");
	name="��"+name[2..3];
	ob->set("name",name);
	tell_object(ob,"�Ժ����������"+HIY+name+NOR+"��\n");
		
	command("say ���Ƕ�����������������ԭ�ķ������㽫������ʱ��ҪС�Ľ�����\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming1");
}