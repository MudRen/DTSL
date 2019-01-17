
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("Ľ����",({ "mu tiexiong","mu","tiexiong" }) );
   set("gender", "����" );		
   set("age",30);
   set("nickname","��ʨ");
   set("long", "������ͻ���˳ơ���ʨ����Ľ���ۡ�\n");       
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("finger",100);
   set_skill("literate",100);
  
   set_skill("yanyang-dafa",100);
   set_skill("canglang-jue",100);
   set_skill("youlong-shenfa",100);  
   set_skill("tianlang-zhi",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("ͻ��",7,"��ʿ");
   set("inquiry",([
     "����":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   
  
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="ͻ��")
	if((int)ob->query("family/generation",1)<=7)
	{   
	  command("say �˻��Ӻ�˵��");
	  return;
	}
	if(!ob->query_temp("bai_mutiexiong_ok")){
            command("say ��û�������飬�ҿɲ�Ҫ�㣡");
            return;
        }
        
	ob->delete_temp("bai_mutiexiong_ok");
	command("say �ã���ͻ�ʺú�ѧϰ�书������һͳ��ԭ��\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue1");
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
  if(ob->query("family")
  &&ob->query("family/family_name")=="ͻ��"
    ){
    command("say ��Ȼ������ͻ���ɵ��ӣ������ٿ����ˣ�");
    return 1;
  }
  
  if(ob->query_temp("bai_mutiexiong_ok")){
    command("say �㾭�����飬���԰�ʦ�ˣ�");
    return 1;
  }
  msg="$N��$n�����ã�Ҫ��Ϊͻ�ʵ����ȿ�����һ�°ɣ�ͻ�ʵ���Ҫ���¸ң�\n"+
      "�����ܲ��ܰ����ҵĿ����ˣ�\n\n";
  msg+=HIR"$N���һ�Ѽ⵶����$n�ļ����ȥ��\n\n"NOR;
  msg+="$n�۵ļ���������ȥ��\n"+
       "$N΢΢һЦ�����������Ѿ��㹻�ˣ�\n";
  ob->set("kee",10);
  ob->set_temp("bai_mutiexiong_ok",1);
  message_vision(msg,this_object(),ob);
  
  return 1;
}