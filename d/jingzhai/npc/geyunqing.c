
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
   set_name("������",({ "ge yunqing","ge" }) );
   set("gender", "Ů��" );
   set("age", 22);
   set("long", "���ǴȺ���ի�ĸ����塣\n");
       
   set("combat_exp",100000);
   set("int", 25);
   set("per", 26);
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
  
   set_skill("dodge",100);
   set_skill("finger",100);
   set_skill("literate",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("xiuluo-zhi",100);
   set_skill("wuwang-jing",110);
   set_skill("qingxin-force",100);
   set_skill("lingyun-shenfa",100);
  
   create_family("�Ⱥ���ի",6,"����");
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
  
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("gender")=="����")
	{
	  command("say ���ǴȺ���ի�����е��ӵģ������һ�����ȥ������Ժ�ɣ�\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="�Ⱥ���ի"
	  &&ob->query("family/generation")<=6)
	{
	  command("say �⻰�Ӻ�˵��\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say �������������ڷ���Ե���㻹��Ͷ���������ɰɣ�\n");
	  return;
	}
	if(ob->query("per")<25){
	  command("say �����ò̫���ˣ��ҿɲ�Ҫ�����ĵ��ӣ�");
	  return;
	}
	if(ob->query_int()<25)
	{
	  command("say ���ͷ�Բ������������ú�ѧѧ�����ɣ�\n");
	  return;
	}
	
	if(ob->query("PKS")>=5){
	  command("say ����������̫�࣬�ҿɲ�Ҫ�����ĵ��ӣ�");
	  return;
	}
	
	if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ�����������ŵ��书��");
	  return;
	}
	
	command("say �Ⱥ���ի�������ǳ���࣬ϣ�����֮�Ժ㣬������ɷ���ѧ��\n");
	
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "jingzhai1");
}
