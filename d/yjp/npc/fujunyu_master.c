// ����˫����

//�����


inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_jiejiu(string arg);

void create()
{
  set_name("�����", ({"fu junyu", "fu", "junyu"}));
  set("gender", "Ů��");
 
  set("per",26);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",800000);
 
  set_skill("literate",200);
  set_skill("sword", 200);
  set_skill("force", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  
  set_skill("jiuxuan-dafa",200);
  set_skill("yijian-shu",200);
  set_skill("jiuzhuan-jianjue",200);
  set_skill("xingyun-dodge",200);
 
  setup();
  
  create_family("�Ľ���",3, "����");
  carry_object(__DIR__"obj/sword");

}

void attempt_apprentice(object ob)
{
     
     int lev;
     
     if(ob->query_skill("jiuxuan-dafa",1)<100){
       command("say ��ľ�������Ϊ�������ҿɲ�Ҫ������ͽ�ܣ�");
       return;
     }
     
     if(ob->query("office_number")<30){
       command("say ��Ĺ���̫���ˣ��ҿɲ�Ҫ��ô����ĵ��ӣ�");
       return;
     }
     
     if(!ob->query("yjp/family2")){       
       lev=ob->query_skill("leg",1);
       lev=lev*lev/(lev+100);
       ob->party_reward_skill("sword",lev);
       tell_object(ob,HIY"��ӻ����ȷ������Ե��˻���������\n"NOR);

     }
     ob->set("yjp/family2",1);
               
     command("say �����Ľ��ɵ��书��������Ҫ�ú�ѧϰ��");
     
     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yijian2");
}