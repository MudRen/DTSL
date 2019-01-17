

inherit NPC;

#include <ansi.h>

string do_quest1();
string do_quest2();
string do_quest3();

void create()
{
   set_name("�Ƴ���",({ "yun zhanglao","yun" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "�����������ɵ��Ƴ��ϣ�����а������˵������һ����\n");
       
   set("combat_exp",600000);
  
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("strike",180);
   set_skill("cuff",180);
   set_skill("jiutian-huanzhang",180);
   set_skill("linglong-yuquan",180);
   set_skill("literate",180);
   set_skill("tianmo-dafa",180);
   set_skill("tianmo-huanzong",180);
   
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("force",2000);
   set("max_force",2000);
   create_family("������",5,"����");
   set("inquiry",([
   "��ħ��":(:do_quest1:),
   "��Ҷ":(:do_quest2:),
   "����":(:do_quest3:),
   ]));
   setup();
   
}

string do_quest1()
{
   object ob;
  
  ob=this_player();
  
  if(ob->query("perform_quest/yulong"))
  return "���Ѿ���������ħ���ľ��裬�޷�ѧϰ��ħ���ˣ�\n";
  
  if(ob->query("perform_quest/wanhuan"))
  return "���Ѿ�������ǧ��ͭ��ľ��裬�޷�ѧϰ��ħ���ˣ�\n";
  
  if(ob->query("perform_quest/lingxiao"))
  return "���Ѿ���������ħն�ľ��裬�޷�ѧϰ��ħ���ˣ�\n";
    
  if(ob->query("class")!="yin3")
  return "�㻹�����ʸ���������⣡\n";
  
  if(ob->query_temp("tmz_quest/pass_yun"))
  return "��Ĺ������Ѿ�������ˣ���ȥ���������ϰɣ�\n";
  
  ob->set_temp("tmz_quest/yun_step1",1);
  
  return "��ѧ��ħ���ȴ������˵�ɣ�\n";
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("tmz_quest/yun_step1"))
   return 1;
   killer->delete_temp("tmz_quest/yun_step1");
   killer->set_temp("tmz_quest/yun_step2",1);
   
   message_vision(CYN"\n$N"+CYN+"��ɫһ�䣬��$n"+CYN+"����"+RANK_D->query_respect(killer)+"��Ȼ���ֲ�����\n"+
   "�����㻹Ҫ���Ұ������ſ��ԣ�\n"NOR,victim,killer);
   return 1;
}

string do_quest2()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("tmz_quest/yun_step2"))
  return "���ֲ�������Ҷ�ģ����������������ʲô��\n";
  
  ob->set_temp("tmz_quest/yun_buy_tea",1);
  
  return "ף����Ҫ�ȵĻ�ѿҶ����ȥ����������Ҫ��ֱͦ���룬ɫ����д�\n"+
         "�̣�ϸ����������Ѽ�࣬�����Ҷ�ļ�Ʒ��\n";
}

string do_quest3()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("tmz_quest/yun_step2"))
  return "���ֲ��������ϵģ����������������ʲô��\n";
  
  ob->set_temp("tmz_quest/yun_buy_xiangliao",1);
  
  return "��������Ҫ�����ϣ���ȥ������������ס����Ҫ�ӵ��������Ƴɵ����ϡ�\n";

}

int get_quest_obj1(object who,object obj)
{
   if(!obj->query("super_tea")){
     command("kok "+who->query("id"));
     return notify_fail("����ʲô���ò�Ҷ����ף���߻�������Ĳ�Ҷ�𣿣�\n");
   }
   who->delete_temp("tmz_quest/yun_step2");
   who->add_temp("tmz_quest/yun_need_goods",1);
   
   if(who->query_temp("tmz_quest/yun_need_goods")>=2){
     who->delete_temp("tmz_quest/yun_need_goods");
     who->set_temp("tmz_quest/pass_yun",1);
     tell_object(who,"\n"+query("name")+"һЦ���ҵĿ�����ͨ���ˣ������������ϣ�\n"+
     "��ȥ�������ǰɣ�\n");
     return 1;
   }
   return 1;
}

int get_quest_obj2(object who,object obj)
{
   if(!obj->query("quest_order")){
     command("kok "+who->query("id"));
     return notify_fail("����ʲô�������ϣ������������Ҫ�����Ķ����𣿣�\n");
   }
   who->delete_temp("tmz_quest/yun_step2");
   who->add_temp("tmz_quest/yun_need_goods",1);
   
   if(who->query_temp("tmz_quest/yun_need_goods")>=2){
     who->delete_temp("tmz_quest/yun_need_goods");
     who->set_temp("tmz_quest/pass_yun",1);
     tell_object(who,"\n"+query("name")+"һЦ���ҵĿ�����ͨ���ˣ������������ϣ�\n"+
     "��ȥ�������ǰɣ�\n");
     return 1;
   }
   return 1;
}
    

int accept_object(object who,object obj)
{
   if(!obj->query("order"))
   return 0;
   
   if(obj->query("order")==1)
    return get_quest_obj1(who,obj);
   else
    return get_quest_obj2(who,obj);
}