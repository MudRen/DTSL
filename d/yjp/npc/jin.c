// ����˫����

inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
  set_name("������", ({"jin zhengzong", "jin", "zhengzong"}));
  set("gender", "����");
  set("age", 38);
  set("str",30);
  set("per",23);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",800000);
  set_skill("unarmed",200);
  set_skill("strike",200);
  set_skill("leg",200);
  set_skill("literate",200);
  set_skill("sword",200);
  set_skill("force",200);
  set_skill("dodge",200);
  set_skill("parry",200);
  set_skill("whip",200);
  set_skill("blade",200);
  set_skill("cuff",200);
  set_skill("finger",200);
  set("inquiry",([
  "ٺ»":(:do_action1:),
  ]));
  setup();
  
  create_family("�Ľ���", 6, "����");
 
}
void attempt_apprentice(object ob)
{
     
     if(!ob->query_temp("bai_yjp_action4")){
       command("say �ҿɲ��������յ��ӵģ�");
       return;
     }
    
     ob->set("yjp/family1",1);
     
     command("say �����书�Ҷ���һЩ�������������ѧ���������ɣ�");
     
     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "gaoli1");
}

int do_action1()
{
   object ob;
   int money;
   
   
   ob=this_player();
   
   if(ob->query_skill("jiuxuan-dafa",1)<100){
   	command("say ��Ĺ�����ô�����������ٺ»��");
   	return 1;
   }
   if(ob->query("yjp/fenglu_age_"+ob->query("age"))){
     command("say ������ٺ»�Ѿ������ˣ�");
     return 1;
   }
   ob->set("yjp/fenglu_age_"+ob->query("age"),1);
   money=ob->query("office_number")*100;
   ob->add("deposit",money);
   command("say �ã�������ٺ»��"+MONEY_D->money_str(money)+"�����Ѿ��浽����Ǯׯ�У�");
   return 1;
}