
inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
   set_name("��ʦ��",({ "song shidao","song","shidao" }) );
        set("gender", "����" );
	set("age", 42);
   set("long", "�������μұ�����ʦ�������ĵ���Ҳ�ǲ��ס�\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("tiandao-bajue",100);
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
 
   create_family("�μұ�",5,"����");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}
/*

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
		if((string)ob->query("family/family_name")!="�μұ�")
		{
		 tell_object(ob,"��ʦ������üͷ�������μұ�������������������ͽ�ģ�\n");
	  return;
		}
		else if(ob->query("family/generation")<this_object()->query("family/generation"))
		{ tell_object(ob,"��ʦ��ЦЦ��ʦ�����ǻῪ��Ц��\n");
		return;}
	if(ob->query("vocation")=="ɱ��")
	{ tell_object(ob,"��ʦ������üͷ�������μұ���������ɱ�ֵģ�\n");
	  return;
	}
	if(ob->query("beipan")>=3)
	{  tell_object(ob,"��ʦ���ᷳ�����������ֶ����������ͽ���ҿɲ�Ҫ��\n");
	   return;
	}
	  
	command("say ��,ֻҪ���μұ��úø�,��֤�㽫��Х������!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song1");
}

*/