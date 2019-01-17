// ����˫����

inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();
int do_action2();
int do_action3();

void create()
{
  set_name("������", ({"ge suwen", "ge", "suwen"}));
  set("nickname", "��Ե�");
  set("gender", "����");
  set("age", 36);
  set("str",30);
  set("per",24);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",1000000);
  set_skill("blade",200);
  set_skill("literate",200);
  set_skill("force",200);
  set_skill("dodge",200);
  set_skill("parry",200);
  
  set_skill("jiuxuan-dafa",200);
  set_skill("yijian-shu",200);
  set_skill("wuba-daofa",200);
  set_skill("xingyun-dodge",200);
  
  set("inquiry",([
     "����":(:do_action1:),
     "�嵶��Լ":(:do_action2:),
     "ͳһ����":(:do_action3:),
     ]));
  set("perform_quest/sanfen",1);
  setup();
  
  create_family("�Ľ���", 3, "����");
  carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
  add_action("do_answer","answer");

}

void attempt_apprentice(object ob)
{
     
     if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say ��ľ�������Ϊ�������ҿɲ�Ҫ������ͽ�ܣ�");
       return;
     }
     if(ob->query_skill("blade",1)<160){
       command("say ��Ļ���������Ϊ�������ҿɲ�Ҫ������ͽ�ܣ�");
       return;
     }
     if(ob->query("office_number")<60){
       command("say ��Ĺ���̫���ˣ��ҿɲ�Ҫ��ô����ĵ��ӣ�");
       return;
     }
         
     ob->set("yjp/family2",1);
     
     command("say ���Ҫ�ú�ѧϰ���գ���������һͳ������");
     
     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "gaoli2");
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("bai_fu_action1")){
    command("say ����������Ľ���ʦ���������Ҵ����͸�����Ϊ֧���Ҵ�ɽ�����");
    return 1;
  }
  ob->delete_temp("bai_fu_action1");
  ob->set_temp("bai_fu_action2",1);
  command("say ����������Ľ���ʦ���������Ҵ����͸�����Ϊ֧���Ҵ�ɽ�����");
  return 1;
}

int do_action2()
{
   object ob;
  
   ob=this_player();
   
   if(is_fighting()){
     command("say ���������أ���û�����𣿵Ȼ�ɣ�");
     return 1;
   }
   
   if(!ob->query_temp("bai_fu_action2")){
     command("say ƾ��Ҳ����Ҷ��嵶��Լ��");
     return 1;
   }
   ob->set_temp("bai_fu_action3",1);
   command("say ������˧���嵶��Լ�����˳�����֮�£�������ķ��ڷ���\n"+
           "������Ҳ������һ�£������ܵ����嵶֮�������������㡣");
   fight_ob(ob);
   set("apply_points",300);
   command("perform sanfen");
   remove_call_out("do_fight");
   call_out("do_fight",8,ob);
   return 1;
}

void do_fight(object ob)
{
   object obj;
   string msg;
   
   if(!ob) return;
   if(!living(ob)) return;
   if(ob->is_ghost()) return;
   if(!ob->is_fighting(this_object())) return;
   if(environment(ob)!=environment(this_object())) return;
   
   remove_enemy(ob);
   ob->remove_enemy(this_object());
   ob->delete_temp("bai_fu_action2");
  
   
   command("say �ã���ȷʵ�书�������Ҿ͸�����������㣡");
   ob->delete_temp("bai_fu_action3");
   ob->set_temp("bai_fu_action4",1);
   
   obj=new(__DIR__"obj/chenxiang");
   obj->move(ob);
   msg="$N����$nһ"+obj->query("unit")+obj->query("name")+"��\n";
   message_vision(msg,this_object(),ob);
   return;
}

int do_action3()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("perform_quest/sanfen")){
     command("say ���Ѿ���������Ե����ľ��裬�Լ�ȥ��߰ɣ�");
     return 1;
   }
   if(ob->query("perform_quest/xingchen")){
     command("say ���Ѿ������˾�ת�����ľ��裬�޷��������Ե����ľ��裡");
     return 1;
   }
   if(ob->query_skill("wuba-daofa",1)<160){
     command("say �����Ե�����Ϊ̫�ͣ��޷��������еľ��裡");
     return 1;
   }
   if(ob->query("perform_quest/sanfen_fail")){
     command("say �㵱��˵�Ļ���ʲô������Ҳ����ѧ����Ե����ľ��裡��");
     return 1;
   }
   ob->set_temp("perform_quest/sanfen_action",1);
   command("say ����ͳһ����Ϊ�Լ�������Ŀ�꣬��᲻�Ḩ���ң�");
   return 1;
}

int do_answer(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/sanfen_action"))
   return 0;
   if(!arg||
       (arg!="ͬ��"&&arg!="��ͬ��")
     )
   return notify_fail("���� ͬ�� ���� ��ͬ�� ��\n");
   if(arg=="ͬ��"){
     ob->delete_temp("perform_quest/sanfen_action");
     ob->set("perform_quest/sanfen",1);
     command("say �ã�����ʹ�������Ե����ľ���֮����\n");
     message_vision("$N�յ�$n���ߵ����˼��䣬$n�������򣬵��˵�ͷ��\n",this_object(),ob);
     return 1;
   }
   ob->delete_temp("perform_quest/sanfen_action");
   ob->set("perform_quest/sanfen_fail",1);
   command("say �ã�����һ����Ҳ����ѧ���ҵ���Ե�������֮��������");
   return 1;
}