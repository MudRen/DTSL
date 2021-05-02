// ����˫����

//fucailin.c ������


inherit F_MASTER;
inherit NPC;

#include <ansi.h>
#include <job_money.h>
#include "qipu.h"

string do_quest();
string move_room();
string do_action1();
int do_ok(string arg);
int do_action2();
int do_action3();
int do_action4();
int do_action5();

void create()
{
  int i;
  object *ob;

  set_name("������", ({"fu cailin", "fu", "cailin"}));
  set("title", "�Ľ��ɿ�ɽ��ʦ");
  set("gender", "����");
  set("age", 48);
  set("str", 35);
  set("int", 30);
  set("per", 18);
  set("max_kee",6000);
  set("max_gin",6000);
  set("max_sen",6000);
  set("max_force",15000);
  set("force",15000);
  set("combat_exp",8000000);

  set_skill("literate", 400);
  set_skill("leg", 400);
  set_skill("fengxue-leg", 400);
  set_skill("blade", 400);
  set_skill("wuba-daofa", 400);
  set_skill("sword", 500);
  set_skill("force", 400);
  set_skill("dodge", 400);
  set_skill("parry", 400);
  set_skill("jiuxuan-dafa",400);
  set_skill("yijian-shu",500);
  set_skill("jiuzhuan-jianjue",400);
  set_skill("xingyun-dodge",400);
   set("perform_quest/jue",1);
   set("chat_chance_combat",100);
   set("chat_msg_combat",({
                (: command("perform xingchen") :),
                (: command("execute shu") :),
                (: command("execute yijian") :),
               // (: command("perform nitian") :),
        }));
   set("apply_points",2000);

  set("inquiry",([
    "����":(:do_quest:),
    "����":(:move_room:),
    "�����":(:do_action1:),
    "��΢":(:do_action2:),
    "��������":(:do_action3:),
    "�Ľ���":(:do_action4:),
    "����":(:do_action5:),
    ]));
  set("execute_quest/yijianshu",1);
  setup();

  create_family("�Ľ���", 1, "��ʦ");
  ob=children(__DIR__"obj/jinsijia");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("worn"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/jinsijia")->wear();
  carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
   add_action("do_ok","jiaochai");
   add_action("do_play","luozi");
   add_action("do_check","check");
}

void attempt_apprentice(object ob)
{

    if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say ��ľ�������Ϊ�������ҿɲ�Ҫ������ͽ�ܣ�");
       return;
     }

     if(ob->query("office_number")<60){
       command("say ��Ĺ���̫���ˣ��ҿɲ�Ҫ��ô����ĵ��ӣ�");
       return;
     }

     if(ob->query_int()<35){
       command("say �������̫���ˣ��ҿɲ�Ҫ�������ĵ��ӣ�");
       return ;
     }

     ob->set("yjp/family3",1);

     command("say �Ľ�����������������ֻ����᲻���Դ�������ѧϰ��Ҫ�ú���ᣡ");

     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yijian3");
}

string do_quest()
{
  object ob,obj;

  ob=this_player();
  if(ob->query_skill("jiuxuan-dafa",1)<200)
  return "��Ĺ���̫���ˣ�������н��ɵĳƺ��أ�\n";
  if(ob->query("family_lingwu")=="yjp")
  return "����������ǰ�ˣ����Ѿ�̤��ͻ�������ϰ�̤���µľ��磬Ҫ���Լ�ȥ��������ľ����ˣ�\n";
   if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_fu",1);

  obj=new(__DIR__"q_fucailin");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);

  obj->move(environment(ob));
  return "���ɲ�����ô���׾ͳ�Ϊ�ģ���ͻ�Ʊ�����ϰ��ɣ�������Ϊʦ����������ľ�ˡ�\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_fu"))
   return 1;
   message("vision",HIG"���Ľ��ɡ���������������Х�����Ľ��������ֶ���һλ"+HIW+"��  ��"+HIG+killer->name()+"\n"NOR,users());
   message_vision(HIR"$N���쳤Ц�������Ľ������ں�������ˣ�\n"NOR,victim);
   tell_object(killer,"�����Ľ�����һ�����ܣ����Լ������ɵ����Ҳ���ɣ�\n");
   killer->set("family_lingwu","yjp");
   killer->set("title","��  ��");
   message_vision("ֻ��$N����һ�ӣ�$n����һ������������һ���µĵط���\n",victim,killer);
   killer->move("/d/clone/room/lingwu/yjp/qishi");
   return 1;
}
*/
int end_fight(object killer,object victim)
{

  if(victim->query_temp("bai_fu_action6")){
     victim->delete_temp("bai_fu_action6");
     victim->set_temp("bai_fu_action7",1);

     command("say �ұ�������׷Ѱ���õ������ֻ�����Թ��ߵ���̬ȥ����Ʒζ��\n"+
          "�������Ľ��ľ��壬�ܷ����Ϳ�����Լ��ˡ�");
     return 1;
  }

  if(!victim->query_temp("gage_fu"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}

string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "ͨ����������ʵ��ɣ�\n";
  if(ob->query("family_lingwu")!="yjp")
  return "���Ǹ����ܣ����ڻ����ܸ����㣡\n";
  ob->move("/d/clone/room/lingwu/yjp/qishi");
  return "ϣ����ú����򣬹�������Ľ��ɣ�\n";
}

string *dirs=({
"/d/huashan","/d/hengshan","/d/taishan",
"/d/emeishan",
});

string do_action1()
{
   object ob,target,guard;

   ob=this_player();

   if(ob->query_skill("dijian-jue",1)<160||
      ob->query("perform_quest/ditian")||
      ob->query("perform_quest/bajue"))
   return "�����ҵ�ͽ�ܣ����������ʲô��\n";

   if(ob->query_temp("perform_quest/ditian_action1"))
   return "��������Σ��֮�У���ȥ�����ɣ�\n";

   target=new(__DIR__"fujunyu");
   guard=new(__DIR__"yingui_killer");

   target->set_status(ob,guard);
   guard->set_status(ob);

   if(!random_place(target,dirs))
   return "�����ҵ�ͽ�ܣ����������ʲô��\n";
   if(!environment(target))
   return "�����ҵ�ͽ�ܣ����������ʲô��\n";

   guard->move(environment(target));
   guard->set_leader(target);

   ob->set_temp("perform_quest/ditian_action1",1);
   ob->add_temp_array("job_temp_killer",target);
   ob->add_temp_array("job_temp_killer",guard);

   return "�����ҵ�ͽ�ܣ���˵���������ץ��"+MISC_D->find_place(environment(target))+
   "�ˣ���ȥ������Ȼ����ɣ�\n";
}

int do_ok(string arg)
{
  object ob,target;
  string name,msg;

  ob=this_player();

  if(!ob->query_temp("perform_quest/ditian_action2"))
  return 0;

  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("����ʲô����(jiaochai with xxx)��\n");

  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("����û������ˡ�\n");

  if(target->query("owner_ob")!=ob){
   command("heng");
   command("say ����ƭ����");
   return 1;
  }

  msg="\n$N����ߵ��ͷ��ʦ�����ϣ��ܵ���һ�ݣ�\n"+
      "��ε������ѣ����"+ob->name()+"����ȣ���ʹͽ�����ա�\n\n"+
      "$n΢΢һЦ���ðɣ����Ƚ�ȥ��Ϣ�ɣ�\n\n"+
      "$N�����񣬻��Լ�����ȥ�ˡ�\n\n";
  message_vision(msg,target,this_object());
  destruct(target);
  call_out("do_ok2",3,ob);
  return 1;
}

void do_ok2(object ob)
{
  string msg;

  if(!ob||
  environment(ob)!=environment(this_object())
  )
  return;
  command("say ԭ�����������μҵĵ��ӣ����ҿ���һ������书�ɣ�\n");

  msg="\n$N������һ�������ȥ������$nȴ�ڻ��ֻ��Ѱ�������е��κ�������\n"+
      "��$n�Լ����κη������ƺ���$N��Ԥ��֮�У�\n"+
      HIR+"ֻ�����һ����$N�ĳ�����$n��ü�Ļ���һ�£�\n"NOR+
      "$N΢΢һЦ���μҵĵؽ����������ڷ��أ������ɵĽ�����ͬ�������\n"+
      "�����ڴˣ��ػᵲס�ҵ�һ������ú�����ɣ�\n\n"+
      "$n�ƺ��������򣬳�ʩһ�񣺶�л��ʦָ�㣡\n\n";
  message_vision(msg,this_object(),ob);
  ob->delete_temp("perform_quest/ditian_action2");
  ob->set("perform_quest/ditian",1);
  return;
}

int do_action2()
{
  object ob;

  ob=this_player();

  if(!ob->query_temp("perform_quest/zhi_action2")){
     command("say ���������޷�����������ģ�");
     return 1;
  }
  if(ob->query("perform_quest/zhi_fail")){
    command("say ��Щ��������ÿ���˶������ģ��㲻Ҫǿ���ˣ�");
    return 1;
  }
  ob->delete_temp("perform_quest/zhi_action1");
  ob->delete_temp("perform_quest/zhi_action2");

  command("say ��΢�ľ������ڰ���ס�Լ���������Ϊ�����һ˿һ���ı仯��\n"+
          "������Ӱ���Լ���\n");
  if( ob->query("MKS")!=ob->query("huajian_menpai/huajian_MKS")
    ||ob->query("PKS")!=ob->query("huajian_menpai/huajian_PKS")
    ||ob->query("deadtimes")!=ob->query("huajian_menpai/huajian_deadtimes")
    ||ob->query("age")>=50
    ){
     message_vision("\n$N��ͷ˼��һ��ȴʲôҲ���򲻳�����\n",ob);
     ob->set("perform_quest/zhi_fail",1);

  }
  else{
    message_vision("\n$N��ͷ˼��һ���ƺ���������\n",ob);
   ob->set("perform_quest/zhi",1);
  }
  return 1;
}

int do_action3()
{
   object ob;

   ob=this_player();

   if(ob->query("execute_quest/yijianshu")){
     command("say ���Ѿ�������Ľ����ľ��裬�Ժ��Լ�ȥ��߰ɣ�\n");
     return 1;
   }

   if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say ��ľ�������Ϊ�������޷����������磡");
       return 1;
   }

   //�ճ�����
   command("say ��������û�����ܽ⿪���գ�ȴ�����޼���Ѱ������������ÿһ���˵�����\n"+
           "ȴ���������޷���Խ�ĺ蹵���նϡ�����Ϊ�����������Ŭ��׷Ѱ�ķ����Ŀ�꣬\n"+
           "ֻ����͸������ڵ����ܣ�����֮�ղ��л��ᱻ�⿪��");
   command("sigh");
   command("say ������������Գ���ľ�У�ľ�ʳ��أ���ɫ������в����Ĳ��ݣ��򱥺���\n"+
           "֬������������������ɲ�̬�γɵķ���ľ�ʿɳ����λ�����֮״����������\n"+
           "�����εĺڳ��㡣");

   ob->set_temp("bai_fu_action1",1);
   return 1;
}

int accept_object(object ob,object obj)
{

   if(!obj->id("bai_fucailin_quest_obj"))
    return 0;

   if(!ob->query_temp("bai_fu_action4"))
    return 0;

   ob->delete_temp("bai_fu_action4");
   ob->set_temp("bai_fu_action5",1);

   command("say �ã�����ʱ�����������Ұɣ�");

   return 1;
}

int do_action4()
{
  object ob;
  string time;

  ob=this_player();

  if(!ob->query_temp("bai_fu_action5")){
    command("say ��������ļ���������޷����գ�");
    return 1;
  }
  time=NATURE_D->game_time();

  if(time[sizeof(time)-8..sizeof(time)]!="��ʱ����"){
    command("say ������"+time[sizeof(time)-8..sizeof(time)]+" ��������ʱ�����԰���");
    return 1;
  }

  ob->delete_temp("bai_fu_action5");
  ob->set_temp("bai_fu_action6",1);

  command("say �Ľ�����������������ֻ����᲻���Դ������ٺ���������Ǻܺõ������ˡ�\n"+
          "Ϊ��������Ľ����н�һ���˽⣬����������������ܣ�������������Ľ����Խ�\n"+
          "�ĵС�\n");
  fight_ob(ob);
  command("execute yijian "+ob->query("id"));
  return 1;
}

int do_action5()
{
   object ob;
   mapping *old_maps,*myold_maps=({}),give_maps;
   string *old_numbers;
   int i;

   ob=this_player();

   if(ob->query("perform_quest/sanfen")){
      command("say ���Ѿ���������Ե����ľ��裬�޷�������Ľ��ɵľ�ѧ��");
      return 1;
   }
   if(ob->query("perform_quest/xingchen")){
      command("say ���Ѿ������˾�ת�����ľ��裬�Ժ��Լ�ȥ��߰ɣ�");
      return 1;
   }

   if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say ��ľ�������Ϊ�������������ҵ����׵ģ�");
       return 1;
   }


   if(ob->query_int()<40){
       command("say �������̫���ˣ��������ҵ����׵ģ�");
       return 1;
   }
   if(sizeof(ob->query_temp("bai_xiaqi_log"))>=9){
      command("say ��ֻ����Ÿ����ף���úÿ����ɣ�");
      return 1;
   }
   if(sizeof(ob->query_temp("bai_xiaqi"))>=1){
      command("say ���������Ǽ������������µ����װɣ�");
      return 1;
   }

   old_maps=weiqi_maps;
   if(!ob->query_temp("start_bai_xiaqi")){
      for(i=0;i<sizeof(old_maps);i++)
      ob->add_temp_array("bai_xiaqi_numbers",i);
      ob->set_temp("start_bai_xiaqi",1);
   }

   old_numbers=ob->query_temp("bai_xiaqi_numbers");
   if(arrayp(ob->query_temp("bai_xiaqi_log"))){
   	myold_maps=ob->query_temp("bai_xiaqi_log");
   	for(i=0;i<sizeof(myold_maps);i++)
   	old_numbers=old_numbers-({myold_maps[i]});
   }
   if(old_numbers==({})){
     command("say ������˼����ʦ����ⲻ���ˣ����Űɣ�");
     return 1;
   }
   i=(int)(old_numbers[random(sizeof(old_numbers))]);
   ob->set_temp("bai_xiaqi",({old_maps[i]}));
   ob->add_temp_array("bai_xiaqi_log",i);
   tell_object(ob,old_maps[i]["maps"]);
   command("say ����������ף����ѡ���ĸ��ǵ���Ϊ��һ���Ӵ��أ�");
   return 1;
}

int do_play(string arg)
{
   object ob;
   mapping *mymaps,map;

   ob=this_player();

   if(!arrayp(ob->query_temp("bai_xiaqi")))
   return 0;

   if(!arg||arg=="maps") return notify_fail("��Ҫ���������\n");

   mymaps=ob->query_temp("bai_xiaqi");
   if(!mymaps) return 0;
   map=mymaps[0];

   if(!map[arg])
   return notify_fail("�����ǵ㣡\n");

   ob->add_temp("bai_xiaqi_score",map[arg]);
   ob->add_temp("bai_xiaqi_times",1);
   tell_object(ob,"������һ�ӣ������ܵ�"+map[arg]+"�֡�\n");

   mymaps=mymaps-({map});
   if(mymaps==({})) ob->delete_temp("bai_xiaqi");
   else ob->set_temp("bai_xiaqi",mymaps);

   if(ob->query_temp("bai_xiaqi_times")>=9){
     if(ob->query_temp("bai_xiaqi_score")>=80){
       command("say �ã����ǿ���֮�ţ��Ҿʹ����ת�����ľ��裡");
       message_vision("$N����$n���ߣ�����˵�˼��仰��$n�ƺ���������\n",this_object(),ob);
       ob->set("perform_quest/xingchen",1);
     }
     else command("say �������ˮƽ��ô������������Ľ��ɵľ��裡");
     ob->delete_temp("bai_xiaqi_score");
     ob->delete_temp("bai_xiaqi_times");
     ob->delete_temp("bai_xiaqi");
     ob->delete_temp("bai_xiaqi_log");
     ob->delete_temp("bai_xiaqi_numbers");
     ob->delete_temp("start_bai_xiaqi");
  }

   return 1;
}

int do_check()
{
  object ob;
  mapping *mymaps;
  int i;
  string msg;

  ob=this_player();

  if(ob->query_temp("bai_xiaqi_score"))
   tell_object(ob,"��Ŀǰ�ĵ÷֣�"+ob->query_temp("bai_xiaqi_score")+"\n");
  if(!arrayp(ob->query_temp("bai_xiaqi")))
  return 1;

  mymaps=ob->query_temp("bai_xiaqi");
  msg="��Ŀǰ��û�н������ף�\n";
  for(i=0;i<sizeof(mymaps);i++)
    msg+=mymaps[i]["maps"]+"\n";

  ob->start_more(msg);

  return 1;
}
