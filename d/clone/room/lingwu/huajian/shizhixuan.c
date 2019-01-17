
#include <ansi.h>
inherit NPC;

string move_room();
string do_quest();
int do_action1();
int do_action2();
int do_action3();
int do_action4();

void create()
{
   set_name("ʯ֮��",({ "shi zhixuan","shi"}) );
   set("gender", "����" );
   set("age", 46);
   set("long", "���ǻ����ɵ������ˡ�\n");
    set("combat_exp",8000000);
   set("str", 28);
    set_skill("dodge",370);
    set_skill("parry",370);
    set_skill("force",370);
    set_skill("strike",400);
    set_skill("busi-yin",400);
   set_skill("flower-force",370);
    set_skill("blade",370);
    set_skill("literate",300);
    set_skill("bencao-shuli",300);
    set_skill("tianyi-xuangong",370);
    set_skill("huanmo-shenfa",370);
    set_skill("zhehua-baishi",370);
    set_skill("baihua-zhang",370);

    set("perform_quest/yin",1);
   set("perform_quest/zhi",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("execute yin") :),
        (: command("perform zhi") :),
    }));

    set("max_gin",7000);
    set("max_sen",8000);
    set("max_kee",9000);
    set("max_force",15000);
    set("force",15000);
   set("jiali",10);
   create_family("������",3,"����");
   
   set("inquiry",([
      "���令��":(:do_quest:),
      "����":(:move_room:),
      "����ʮ��֧":(:do_action1:),
      "�����":(:do_action2:),
      "������":(:do_action3:),
      "����":(:do_action4:),
      ]));
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
}


string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("flower-force",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="huajian")
  return "��Ϊ���令���ͱ��������ɼ����㲻ȥ����Լ�������������ʲô��\n";
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_shi",1);
  
  obj=new(__DIR__"q_shizhixuan");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "�ߣ������Ϊ���令���������ȴ�Ӯ���ľͷ�ˡ�\n";
}

/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shi"))
   return 1;
   message("vision",HIG"�������ɡ�:ʯ֮��������"+killer->name()+",������Ц���һ����ֶ���һλ������\n"NOR,users());
   message_vision(HIR"$N���쳤Ц�����һ������ں�������ˣ�\n"NOR,victim);
   message_vision(HIR"$NͻȻ��ɫһ�䣬���߳�ŭ���������ȥ���Ҵ�һ��ɣ�\n"NOR,victim); 
   killer->set("family_lingwu","huajian");
   killer->set("title","���令��");
   tell_object(killer,"ʯ֮��˫��һ�ƣ�һ�ɾ޴�����������Ƶ�һ�����ң�\n");
   killer->move("/d/clone/room/lingwu/huajian/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_shi"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("family_lingwu")!="huajian")
   return "������������ʲô��\n";
  ob->move("/d/clone/room/lingwu/huajian/huajian");
  return "�������˽����ҵ�һ�����ģ�\n";
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/zhi_action1")){
     command("say ��ô����ļ��������������ģ�");
     return 1;
   }
   command("say �ܺã�û�뵽�һ�����Ҳ���������ܳ��ĵ��ӣ�\n"+
           "�������㻹û�дﵽ��΢�ľ��磡");
   ob->set_temp("perform_quest/zhi_action2",1);
   return 1;
}

int do_action2()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������"){
     command("say �㲻�Ǳ��ɵ��ӣ����������ʲô��");
     return 1;
   }
   
   if(!ob->query("execute_quest/busiyin")){
     command("say �㻹�ǰ���ѧ�����ɵ��书�ɣ�");
     return 1;
   }
   ob->set("execute_quest/wanshijue",1);
   command("say ������û�н�����Щ������ȥ���ҵ�ͽ��������ѧ�ɣ�");
   
   return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	
        return 1;
}

int prevent_learn(object ob,string skill)
{
   if(!ob->query("dtsl_quest_bsy_ok")){
     command("heng");
     return 1;
   }
   if(ob->query_skill("busi-yin")>=120){
     command("heng");
     return 1;
   }
   if(skill!="busi-yin"){
    command("heng");
    return 1;
   }
   return 0;
}

int do_action3()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("busi-yin",1)<190){
     command("heng");
     return 1;
   }
   
   if(ob->query("execute_quest/busiyin_ok")){
     command("say ��һֱ���öԲ�����������");
     return 1;
   }
   
   ob->set_temp("do_bsy_quest1",1);
   
   message_vision("$N�������������Ҳ�֪�������ĶԲ��ԣ���һֱ���������ҡ�\n",this_object());
   
   return 1;
   
}

int do_action4()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("busi-yin",1)<190){
     command("heng");
     return 1;
   }
   
   if(ob->query("execute_quest/busiyin_ok")){
     command("say ��һֱ���öԲ������ģ�����");
     return 1;
   }
   
   if(!ob->query_temp("do_bsy_quest1")){
     command("say �ѵ���Ҫ����ʲô����ô��");
     return 1;
   }
   
   ob->set_temp("do_bsy_quest1",0);
   ob->set_temp("do_bsy_quest2",1);
   
   message_vision("$N��ͷ˼��һ���ƺ����ڼ���ʹ��֮�С�\n",this_object());
   message_vision("$N�͵�̧��ͷ�����ƺ���Ҫɱ��$n��\n",this_object(),ob);
   
   call_out("do_kill",2,ob);
   
   return 1;
   
}

void do_kill(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment(this_object()))
   return;
   
   command("kill "+ob->query("id"));
   
}

int accept_object(object ob,object obj)
{
   if(!obj->query("hj_bsy_quest_obj"))
    return 0;
   
   if(!ob->query_temp("do_bsy_quest2"))
    return 0;
   
   message_vision("$Nҡͷ��������ѩ����ò���棬����������˴����������޻��Ķ�������������һ֦��\n"+
                  "���İ������ѵ����ǻ��ľ�������ʯ֮������������Ŀຣ�������Ƿ��ұ���Ϊ�Լ�\n"+
                  "���޴��������ۣ�\n\n",this_object());
   
   tell_object(ob,"�����Ա����ţ����鲻��һ���������������˲���ӡ���ľ�ѧ��\n");
   
   ob->set_temp("do_bsy_quest2",0);
   ob->set("execute_quest/busiyin_ok",1);
   
   return 1;
   
}
   