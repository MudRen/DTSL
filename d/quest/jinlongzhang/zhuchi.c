
inherit NPC;

string do_quest();

void create()
{
   set_name("������ʦ",({ "qing zhi","qing","zhi" }) );
        set("gender", "����" );
        set("age", 60);
        set("class","bonze");
   set("long", "���ǻ����µ����֡�\n");       
   set("combat_exp",500000);
   set("str",30);
   set("attitude", "peaceful");
  set_skill("dodge",171);
   set_skill("force",171);
   set_skill("parry",171);
   set_skill("finger",171);
   set_skill("dujie-zhi",171);
   set_skill("liuyun",171);
   set("force",1000);
   set("max_force",1000);
   set("max_kee",1500);
   set("max_gin",1500);
   set("max_sen",1500);
   set("inquiry",([
     "��������":(:do_quest:),
     "����":(:do_quest:),
     "staff":(:do_quest:),
     ]));
   setup();
   carry_object(__DIR__"jiasha")->wear();
  
}

string do_quest()
{
   object ob;
   object *t;
   
   ob=this_player();
   
   t=children(__DIR__"jinlong-zhang");
   if(sizeof(t)>=2)
   return "���������Ѿ��͸������ˣ��������ˣ�\n";
   
   ob->set_temp("dtsl_lev1_quest_chanzhang/step1",1);
   return "�ðɣ��������սʤ�ң����ľ͸��߽������ȵĵط���\n";
}

int end_fight(object killer,object victim)
{
  if(victim->query_temp("dtsl_lev1_quest_chanzhang/step1")){
   message_vision("$N�Ǻ�һЦ��������������ﻹ���Զ�أ�\n",this_object());
   return 1;}
  return 1;
}

int surrender(object killer,object victim)
{
  if(killer->query_temp("dtsl_lev1_quest_chanzhang/step1")){
  message_vision("$N��ɫһ�䣺���������ðɣ���������ϱߵ��᷿�У�\n"+
                 "�ܲ����õ��Ϳ���������ˣ�\n",this_object());
     killer->delete_temp("dtsl_lev1_quest_chanzhang/step1");
     killer->set_temp("dtsl_lev1_quest_chanzhang/step2",1);
     return 1;}
  return 1;
}