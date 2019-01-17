
inherit NPC;

#include <ansi.h>

string do_quest1();

void create()
{
   set_name("��С��",({ "hong xiaoshang","hong","xiaoshang" }) );
        set("gender", "Ů��" );
		
        set("age", 23);
   set("long", "���������ɵĵ��ӣ�׼����ı�ӳ������ɡ�\n");
   set("per",20);
   set("combat_exp",300000);
  
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set_skill("sword",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("literate",100);
   set_skill("tianmo-dafa",100);
   set_skill("tianmo-huanzong",100);
   set_skill("linglong-yuquan",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("������",7,"����");
   set("inquiry",([
   "��ħ��":(:do_quest1:),
   ]));
   setup();
   
}

string do_quest1()
{
  object ob,*man,target;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_yinguifinal"))
  return "ƾ��Ĺ���ѧϰ��ħ��̫��ϧ�ˣ�\n";
  
  if(!ob->query_temp("tmz_quest/pass_xia")
    ||!ob->query_temp("tmz_quest/pass_yun")
    ||!ob->query_temp("tmz_quest/pass_wen")
    )
  return "��Ĺ���̫��ˣ���ôѧϰ����ħ�󡹰���\n";
  
  ob->set_temp("tmz_quest/hong_step1",1);
  
  man=children(__DIR__"hanzenan");
  if(sizeof(man)<2){
    target=new(__DIR__"hanzenan");
    target->move(environment(ob));
    tell_object(environment(ob),target->name()+"���˹�����\n");
    set("couple_ob",target);
  }
  
  return "���Ѿ��������ҵ����٣�����㲻�������ˣ�\n"+
         "��Ϊ�ر����һ�������С���ħ�󡹵��鼮��\n";
}

int accept_object(object ob,object obj)
{
   if(!obj->query("quest_hong"))
    return 0;
   
   ob->delete_temp("tmz_quest");
   ob->set("dtsl_quest_tmz",1);
   message_vision("$N��$n���һ����лл�������һ����·��\n"+
                  "�����ϸ������С���ħ�󡹵��鼮��\n",
                  this_object(),ob);
   call_out("do_kill",1,ob);
   return 1;
}

void do_kill(object ob)
{
   object target,book;
   string msg;
   
   if(!ob) return;
   
   target=query("couple_ob");
   book=new(__DIR__"obj/tmz_book");
   
   msg="\n$NͻȻ��Ц���������ˣ����Լ����õģ���\n"+
       "$NͻȻ��¶�׹⣬ͻȻ��$n����ɱ�֣�\n\n"+
       HIR+"ֻ��$n�ؿڽ�����һ��Ѫ�⣡��\n"NOR;
   message_vision(msg,ob,this_object());
    if(target){
      msg="\n$N�׹�ɨ��$n���ϣ�\n"+HIR+"ֻ��$n�ؿڽ�����һ��Ѫ�⣡��\n"NOR;
      message_vision(msg,ob,target);
    }
   if(target)
    target->die();
   book->move(ob);
   tell_object(ob,"���"+query("name")+"�����õ���һ"+book->query("unit")+
        book->query("name")+"��\n");
   message("vision",HIM"��ҥ�ԡ�ĳ�ˣ����������ĺ�С�Ѻͺ����ϱ�"+ob->name()+HIM+
    "ɱ���ˣ�\n"NOR,users());
   die();
}