#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_action1();
int do_action2();
int do_action3();

void create()
{
   int i;
   object *ob;
   
   set_name("��ϣ��",({ "hou xibai","hou"}) );
   set("gender", "����" );
   set("age", 26);
   set("long", "���ǻ����ɵĸ��֣�Ҳ�ǻ����ɵ�Ψһ���ˡ�\n");
    set("combat_exp",3000000);
   set("per", 26);
   
    set_skill("dodge",400);
    set_skill("parry",400);
    set_skill("force",400);
    set_skill("strike",400);
    set_skill("blade",400);
    set_skill("sword",400);

    set_skill("flower-force",400);
    set_skill("luohua-step",400);
    set_skill("zhehua-baishi",400);
    set_skill("baihua-zhang",400);
    set_skill("busi-yin",200);
    set_skill("huachan",400);
    set_skill("literate",400);

    set("apply_points",1000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform baihua") :),
        (: command("perform zhi") :),
        (: command("exert feihua") :),
        (: command("exert liushui") :),
        (: command("execute xihua") :),
    }));
    set("max_gin",3000);
    set("max_sen",4000);
    set("max_kee",5000);
    set("max_force",7000);
    set("force",7000);
    set("jiali",100);

   create_family("������",5,"����");
   
   set("inquiry",([
        "����ӡ":(:do_action1:),
        "�ۻ���ʽ":(:do_action2:),
        "����ʮ��֧":(:do_action3:),
       ]));
   
    setup();
    carry_object("/d/yangzhou/npc/obj/chouyi")->wear();
   
   ob=children(__DIR__"obj/tieshan");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/tieshan")->wield();
}

string long()
{
   if(this_player()->query_temp("bai_huajian/step2")||
      this_player()->query("family/family_name")=="������"){
       return query("long");
   }
   else
   return "��˵����һλ���ָ��֣����������黭��\n";
}

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=5){
	   command("say �⻰�Ӻ�˵��");
	   return;	
	
        }
        if(ob->query("gender")=="Ů��"){
          command("say �����ɵ��书���ʺ�Ů���������㻹�����ˣ�");
          return;
        }
	if(ob->query("per")<25)
	{
		tell_object(ob,"��ϣ��Ϊ�ѵ��������ò������������ô����Ϊͽ��\n");
		return;
	}
	if(!ob->query_temp("bai_huajian/step2")){
	  command("say �Һ�ϣ����ô��������ͽ��");
	  return;
	}
	
	ob->set("huajian_menpai/huajian_MKS",ob->query("MKS"));
        ob->set("huajian_menpai/huajian_PKS",ob->query("PKS"));
        ob->set("huajian_menpai/huajian_deadtimes",ob->query("deadtimes"));
	
	
	command("say �ã��һ����ɴӴ��ֶ���һ�����ˣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "hua1");
}

int accept_object(object ob,object obj)
{
   string msg;
   
   if(!obj->id("steal_busiyin_obj"))
   return 0;
   if(ob->query("execute_quest/busiyin"))
   return 0;
   
   msg="$NЦ�������Ǳ��ɵ��ؼ�����ӡ����лл����������ң�\n"+
       "��Ȼ����־ѧϰ����ӡ�������Ժ�ͺ���ѧϰ����ӡ�ɣ�\n";
   
   message_vision(msg,this_object());
   ob->set("execute_quest/busiyin",1);
   return 1;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������"){
     command("say ���Ǳ��ɵ����ܣ��ɲ��ܸ����㡣");
     return 1;
   }
   if(ob->query("execute_quest/busiyin")){
     command("say ����ӡ���һ����ɵľ�ѧ����Ҫ�ú�ѧϰ��");
     return 1;
   }   
   if(present("steal_busiyin_obj",ob)){
     command("say �������õ�ʲô���������ҿ�����");
     return 1;
   }
   ob->set_temp("steal_busiyin/action0",1);
   command("say ����ӡ�ǻ���Ͳ���������ķ��ͷ����ķ��ۺϵ�һ�ž�ѧ�������ں�\n"+
           "ʯʦ�Ĳ���������������᲻��ӡ������һ������һ�롣");
   return 1;
}

int do_action2()
{
   object ob,obj;
   string msg;
   
   ob=this_player();
   
   if(ob->query_skill("zhehua-baishi",1)<160){
     command("say ����ۻ���ʽ��Ϊ̫���ˣ����޷�������еľ��ϣ�");
     return 1;
   }
   if(ob->query_skill("huachan",1)<160){
     command("say ��Ļ����ķ�̫���ˣ����޷�����ۻ���ʽ�ľ��ϣ�");
     return 1;
   }
   if(ob->query("execute_quest/busiyin")){
     command("say ��ѧϰ�˲���ӡ���޷�������ۻ���ʽ���ϵģ�");
     return 1;
   }
   if(present("perform_quest_zhehuabaishi_obj",ob)){
     command("say �㻹�ǿ�ȥ�����ɣ�");
     return 1;
   }
   if(ob->query("perform_quest/zhi_times")>=3){
     command("say ���Ѿ�������ǻ����׷������������⾳���ܺð���");
     return 1;
   }
   obj=new(__DIR__"obj/shanzi");
   obj->move(ob);
   msg="$N����$nһ"+obj->query("unit")+obj->query("name")+"��\n";
   message_vision(msg,this_object(),ob);
   command("say ���������������������������ȥ���������ȥ������Ů�ӵ���ɣ�");
   return 1;
}

int do_action3()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query_skill("zhehua-baishi",1)<160){
     command("say ����ۻ���ʽ��Ϊ̫���ˣ����޷�������еľ��ϣ�");
     return 1;
   }
   if(ob->query_skill("huachan",1)<160){
     command("say ��Ļ����ķ�̫���ˣ����޷�����ۻ���ʽ�ľ��ϣ�");
     return 1;
   }
   if(ob->query("execute_quest/busiyin")){
     command("say ��ѧϰ�˲���ӡ���޷�������ۻ���ʽ���ϵģ�");
     return 1;
   }
   
   if(ob->query("perform_quest/zhi_times")<3){
     command("say �㻹û��������ǻ����׷������������⾳����������ô����Ĺ���");
     return 1;
   }
   
   ob->set_temp("perform_quest/zhi_action1",1);
   command("say ����ʮ��֧�ǻ��������������Ҳ��̫������ȥ��ʯʦ��һ�°ɣ�");
   
   return 1;
}
