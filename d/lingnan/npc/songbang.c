
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("�ΰ�",({ "song bang","song","bang" }) );
   set("gender", "����" );
   set("age", 25);
   set("long", "�������μұ����ΰ�����μұ�����һ���еĸ��֡�\n");       
   set("combat_exp", 300000);
   
   set_skill("cuff",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   
   set_skill("poyu-quan",100);   
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("tiangang-sanjue",100);
   set_skill("wangdao-jue",100);
   
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   
   set("inquiry",([
     "����":(:do_action1:),
     ]));
   
   create_family("�μұ�",7,"����");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   
}

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="�μұ�")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
        if(!ob->query_temp("bai_sjb/step2")){
        command("say ��û�����ҵĿ��飬����ô�����������Ϊ�μұ����ӣ�");
        return;
        }
	
	ob->delete_temp("bai_sjb/step2");
	
	command("say ϣ�����ܳ�Ϊ�μұ���һ���ĸ��֣������ǳư����£�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song1");
}

int do_action1()
{
   object ob,obj;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family")
     &&ob->query("family/family_name")!="�μұ�"){
    command("say ���Ѿ����������ɵĵ��ӣ������μұ�����Ҫ�ģ�");
    return 1;
   }
   
   if(ob->query("family")
   &&ob->query("family/family_name")=="�μұ�"
   &&ob->query("family/generation",1)<=7){   
    command("say ���Ѿ����������ˡ�");
    return 1;
   }
   
   if(present("sjb_mengshi_bishou",ob)){
     command("say �㵽����û�е������ģ�");
     return 1;
   }
   
   obj=new(__DIR__"obj/xiaodao");
   obj->move(ob);
   msg="$N����$nһ"+obj->query("unit")+
      obj->query("name")+"��\n";
   msg +="\n$N˵�������Ϊ�μұ����ӣ���߱Ѫ����(mengshi)�ɣ�\n\n";
   
   message_vision(msg,this_object(),ob);
   ob->set_temp("bai_sjb/step1",1);
   return 1;
}
   