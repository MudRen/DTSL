// ����˫����

//qiang.c ������

inherit F_MASTER;
inherit NPC;

#include <ansi.h>

void create()
{
  set_name("������", ({"fu junqiang", "fu", "junqiang"}));
  set("title", "�Ľ����״�����");
  set("gender", "Ů��");
  set("age", 23);
  set("str", 30);
  set("int", 25);
  set("per", 30);
  set("max_kee",1000);
  set("max_gin",1000);
  set("max_sen",1000);
  set("max_force",1000);
  set("force",1000);
  set("combat_exp",100000);
  set_skill("leg",100);
  set_skill("literate", 100);
  set_skill("force", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  
  set_skill("jiuxuan-dafa",100);
  set_skill("fengxue-leg",100);
  set_skill("xingyun-dodge",100);
  set_skill("yijian-shu",100);
 
  setup();
  
  create_family("�Ľ���",4, "����");

}

void attempt_apprentice(object ob)
{
     
     if(!ob->query_temp("bai_yjp_action4")){
       command("say �ҿɲ��������յ��ӵģ�");
       return;
     }
     
     ob->set("yjp/family1",1);
     
     command("say �����Ľ��ɵ��书��������Ҫ�ú�ѧϰ��");
     
     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yijian1");
}