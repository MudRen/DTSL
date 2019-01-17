
inherit NPC;

string *names=({
"���","yucheng",
"��","qiu",
"����","shengnan",
"����","xiongling",
"����","chengtian",
"����","jinlong",
"��","xia",
"��","hu",
"־��","zhixiong",
});

int do_answer(string arg);

void create()
{
   int i;
   i=random(sizeof(names));
   if(i%2!=0)
    i--;   
   set_name("��"+names[i],({ "song "+names[i+1],"song",names[i+1]}) );
        set("gender", "����" );
        set("nickname","��ͽ");
        set("age", 24);
   set("long", "�����ӳ��μұ���һ����ͽ��\n");
       
   set("combat_exp", 70000);
   set_skill("cuff",60);
   set_skill("parry",60);
   set_skill("dodge",60);
   set_skill("force",60);
   
   set_skill("poyu-quan",60);
   set_skill("anxiang-fuying",60);
   
   set("force",200);
   set("max_force",200);
   create_family("�μұ�",7,"����");
  
   setup();
   
}

void init()
{
  add_action("do_answer","answer");
}

int set_status(object ob)
{
   set("target_id",ob->query("id"));
   set("last",time());
   set("long",query("long")+"�μұ��Ѿ���"+ob->name()+"ɱ���ˡ�\n");
   return 1;
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N���ҿ��˿��������������ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;

}

void dispear()
{
   destruct(this_object());
   return;
}

int surrender()
{
   object ob;
   ob=query_temp("last_damage_from");
   set("touxiang",1);
   if(!ob||
      ob->query("id")!=query("target_id")
      ||
      !ob->is_killing(query("id"))
     )
   return 1;
   remove_killer(ob);
   ob->remove_killer(this_object());
   command("say ��������֪�Լ��Ĺ��������μұ����������ϣ�\n"+
           "�ܲ��������Լ��˶ϣ�");
   ob->set_temp("need_answer",this_object());
   return 1;
}
   

int chat()
{
   
   if(clear())
   return 1;
   
   if(  query("eff_kee")*100/query("max_kee")<40
        &&!query("touxiang")
     )
    return surrender();
   
   return ::chat();
}

int do_answer(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_temp("need_answer")!=this_object())
   return 0;
   if(!arg)
   return notify_fail("�㵽��ͬ�⻹�ǲ�ͬ��(answer �� answer ����)��\n");
   if(arg=="����"){
     command("say �ðɣ���Ȼ��ˣ���ֻ��ƴ���ˣ���");
     kill_ob(ob);
     ob->delete_temp("need_answer");
     return 1;
   }
   ob->delete_temp("need_answer");
   command("say �ã�����Ϊ�μ����濼�ǣ�ȷʵ��һ�����ܣ���");
   message_vision("\n$N���Ƴ��Լ����������ȥ��\n",this_object());
   ob->set_temp("bai_songshuang/action2",1);
   ob->delete_temp("bai_songshuang/action1");
   ::die();
   return 1;
}