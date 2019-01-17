
inherit NPC;
#include <ansi.h>
string give_msg();
string do_quest();
string do_jzzy_quest();

int do_action1();
int do_action2();
int do_action3();
int do_action4();
int do_action5();
int do_action6();
int do_action7();

void create()
{
       int i;
       object *ob;
       set_name("ʯ���", ({ "shi qingxuan","shi","qingxuan","xuan"}) );
       set("gender", "Ů��" );
       set("age", 20);
       set("long","������ʯ֮����Ů��ʯ��诣���������Ľ�����������ô��
����ĸ���ϥ�ϣ����ö�Ŀ���������ľ�����䴰ǰ����
����������������ϼ�ʵ������У����˸ж�����Ϣ��\n");
       set("combat_exp", 600000);
       set("attitude", "peacuful");
       set_skill("force",170);
       set_skill("parry",170);
       set_skill("dodge",170);
       set_skill("sword",170);
       set_skill("sekong-jianfa",170);
       set("max_gin",3000);
       set("max_sen",3000);
       set("max_kee",3000);
       set("max_force",3000);
       set("force",3000);
       set("inquiry",([
	   "��ɽ":(:give_msg:),
	   //"����ӡ":(:do_quest:),
	   "������":"�ԴӼ���ǰһ����������Ҳû�������ˡ�\n",
	   "����":"��������һ�����ٲ������Һܾ�û�������ˡ�\n",
	   //"������":(:do_action6:),
	   //"����":(:do_action7:),
	   "ʯ֮��":"Ҳ��֪���ҵ��������������Ҳ��������ġ�\n",
	   //"����ɽ":(:do_jzzy_quest:),	
	   "а������":(:do_action1:),
	   "����":(:do_action2:),
	   "�д�":(:do_action3:),
	   "���մ�":(:do_action4:),
	   "��ɽ����":(:do_action5:),
	   ]));
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 ob=children(__DIR__"obj/xiao");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
 carry_object(__DIR__"obj/xiao")->wield();


}
string give_msg()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("badao",1)>=160)
  ob->set_temp("ask_shi",1);
  return "��ɽ�����˼���͹����ˣ���ȥ���ķ�ǰ�����ɣ�\n";
}

/*string do_quest()
{
  object ob;
  object book;
  object *inv;
  int i;
  
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_bsy/step2"))
  return "����˵ʲô��������������\n";
  if(ob->query("dtsl_quest_bsy_ok")){
  book=new("/d/quest/busiyin/obj/busi-yin");
  book->move(ob);
  ob->set_temp("get_busiyin",1);
  tell_object(ob,"ʯ��诸�����һ��������ӡ��.\n");
  return "�ðɣ������ű�������ӡ��ȥ�ж��ɣ�\n";}
  if(ob->query_temp("get_busiyin"))
  return "���Ѿ��������ˣ��㻹�Ǻúö��ɣ�\n";
  tell_object(ob,"��Ȼ�Ҹ��Ѿ������Ѳ���ӡ���ڸ��㣬�ðɣ��Ҵ���ȥ��\n");
  inv=all_inventory(ob);
  for(i=0;i<sizeof(inv);i++)
   if(inv[i]->is_character())
    inv[i]->move(environment(ob));
  message_vision(HIC"$N����$n���֣�����һ�Σ�������������ȥ��\n"NOR,this_object(),ob);
  this_object()->move("/d/quest/busiyin/xiaolu1");
  ob->move("/d/quest/busiyin/xiaolu1");
  message_vision(HIC"$N����˵����ǰ�����ĸ�����Ҳ�����᲻��ӡ���������ɱ���Ϳ����ˣ�\n"NOR,this_object());
  message_vision(HIC"$N˵�գ������̰㳯ɽ��Ʈȥ��\n"NOR,this_object());
  this_object()->move("/d/chengdu/wu");
  return "����ķ������Ͳ��٣�Ϊ�β�����ɽ�֣���Щ���е������أ�\n";
}
*/
void init()
{
  object ob;
  ob=previous_object();
  if(userp(ob)&&living(ob)&&!ob->is_fighting())
  call_out("welcome",0,ob);
}

void welcome(object ob)
{
  if(!ob||environment(this_object())!=environment(ob)||
     !living(ob)||ob->is_fighting())
     return;
     
  if(ob->query("family/famliy_name")=="������"){
   message_vision("$N��$nЦ����ԭ���Ǳ������ˣ�������������ɣ�\n",this_object(),ob);
   return;}
  switch(random(5)){
  
  case 0:message_vision("$N�����̾�˿�����\n",this_object());break;
  case 1:message_vision("$N��$nЦ��Ц�������߹����֣�Ҳ�����˲����ˣ�\n",
         this_object(),ob);break;
  case 2:message_vision("$N��̾���������ķ������Թ��ң�Ϊ��û����ϲ���������������أ�\n",
         this_object());break;
  case 3:message_vision("$N���Ż�԰�е��ʻ���̾������֪����ʱ���ܿ������ꡣ\n",
         this_object());break;
  case 4:message_vision("$N̾����Ҳ��֪���Ҹ�������ô���ˡ�\n",this_object());break;
  case 5:message_vision("$N�þ����������$n��һ�ۡ�\n",this_object(),ob);}
  return;
}

string do_jzzy_quest()
{
  object ob;
  object book;
  
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_jzzy/step8"))
  return "��˵���ҿ���һ��Ҳ������\n";
  if(ob->query_skill("huanri-dafa",1)<100)
  return "��˵���ҿ���һ��Ҳ������\n";
  ob->delete_temp("dtsl_quest_jzzy/step8");
  book=new("/d/quest/bawangdao/book2");
  book->move(ob);
  tell_object(ob,query("name")+"������һ��"+book->query("name")+"\n");
  return "����������־�ú����ɣ�\n";
}

int do_action1()
{
  object ob,*target;
  int i;
  
  ob=this_player();
  
  if(ob->query_skill("tiandao-bajue",1)>=1){
  	command("say �Ҹ����쵶�����Ʋ�������������ܰ��ң�");
  	return 1;
  }
  
  if(ob->query("perform_quest/badao_fail")){
  	command("say �������ǰﲻ���ҵģ��㻹�ǻ�ȥ�ɣ�");
  	return 1;
  }
  
  if(ob->query_temp("dtsl_quest_badao_killer")>=4){
    command("say ���Ѿ�����ɱ���ĸ�а�����֣�̫��л�ˣ�");
    return 1;
  }
  if(ob->query("dtsl_quest_badao_ok")){
    command("say ���Ѿ������һ���ˣ�ʵ�ڲ������鷳�㡣");
    return 1;
  }
  
  if(!query("can_kill_enemy")){
    command("say ����������ʲô��Ҳ���������𣿣�");
    return 1;
  }
     
  command("say �����м���а�����������������ᣬ������ܰ��ң���һ�������ô��ģ�");
  ob->move("/d/quest/bawangdao/migong1");
  
  target=all_inventory(load_object("/d/quest/bawangdao/migong8"));
  for(i=0;i<sizeof(target);i++)
   if(!userp(target[i]))
    target[i]->set_status(ob);
  delete("can_kill_enemy");
  return 1;
}

void clear_enemy_flag()
{
  remove_call_out("do_clear_enemy_flag");
  call_out("do_clear_enemy_flag",5);
}

void do_clear_enemy_flag()
{
  delete("can_kill_enemy");
  
}

int do_action2()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_badao_ok")){
    command("say ���˲�Ҫ̫̰�İ���");
    command("pat "+ob->query("id"));
    return 1;
  }
  
  if(ob->query_temp("dtsl_quest_badao_killer")<4){
    command("say �ĸ�а��������ûɱ�꣬����θ���ô���");
    return 1;
  }
  ob->delete_temp("dtsl_quest_badao_killer");
  
  if(ob->query_kar()<30){
  	command("say �������û��ʲôԵ�֣��һ���лл���ˣ�");
  	ob->add("perform_quest/badao_fail_times",1);
  	if(ob->query("perform_quest/badao_fail_times")>=2){
  		ob->set("perform_quest/badao_fail",1);
  		command("say ���Ժ����������ˡ�");
  	}
  	return 1;
  }
  command("thank "+ob->query("id"));
  command("�Ҿͽ�����ǰ���ĵ���ָ���㼸�аɣ�");
  message_vision("\n$N����˼��аԵ���\n\n",ob);
  ob->set_skill("badao",10);
  ob->set("dtsl_quest_badao_ok",1);
  
  return 1;
}

int do_action3()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query("execute_quest/busiyin_ok")){
    command("say ��û�еõ��������ѧ���裬�ҿɲ������д裡");
    return 1;
  }
  if(ob->query("dtsl_quest_bsy_help_ok")){
    command("say �����Ѿ����Թ��ˣ��Ҵ򲻹��㡣");
    return 1;
  }
  
  command("say �ã������Ǿ������Ա��԰ɣ�");
  ob->set_temp("dtsl_quest_bsy_help_action",1);
  fight_ob(ob);
  
  return 1;
}

int surrender(object killer,object victim)
{
    object *objs,target;
    int i;
    
    if(!killer->query_temp("dtsl_quest_bsy_help_action"))
    return 1;
    
    objs=all_inventory(environment(killer));
    objs=filter_array(objs,(:userp:));
    objs=filter_array(objs,(:$1!=$2:),killer);
    objs=filter_array(objs,(:!$1->query("dtsl_quest_bsy_ok"):));
    objs=filter_array(objs,(:$1->query_temp("dtsl_quest_bsy/step2"):));
    
    killer->set("dtsl_quest_bsy_help_ok",1);
    killer->delete_temp("dtsl_quest_bsy_help_action");
    
    
    if(random(killer->query_quest_kar()+killer->query_kar())<33){
    	command("say ����ӡ���������鴫��");
    	return 1;
    }
    
    if(sizeof(objs)){
       target=objs[random(sizeof(objs))];                                   
       
       message_vision("$N�����֮��ͻȻ�ó�һ�У�\n",this_object());
       COMBAT_D->do_attack(this_object(),killer,query_temp("weapon"),0,1);
       command("say �Ҳ��᲻��ӡ������ᣬ�ղŶ���Ťת��ʽ��\n");
       if(random(target->query_quest_kar()+target->query_kar())<34){
       	message_vision("$N����$n����������������һЩģ����Ӱ�ӣ����վ��޷����壬���ɵ�̾�˿�����\n",target,this_object());	
       	target->delete_temp("dtsl_quest_bsy/step2");
       	target->add("execute_quest/busiyin_fail_times",1);
       	if(target->query("execute_quest/busiyin_fail_times")>=2){
       		tell_object(target,HIR"\n���³���һ����Ѫ�����������ž�������Ҳ�޷�����ˣ�\n\n"NOR);
       		target->set("execute_quest/busiyin_fail",1);
       	}
       }
       else{
       	target->set("dtsl_quest_bsy_ok",1);
       	target->set("execute_quest/busiyin",1);
       	target->set("execute_quest/busiyin_ok",1);
       	target->delete_temp("dtsl_quest_bsy/step2");
       	message_vision("$N����$n���������ƺ���������\n",target,this_object());
       }
       
    }
    return 1;
}


int do_action4()
{
  object ob,book;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_help_huanri_ok")){
    command("say �Ҳ�������������������ô��������Ҫ����");
    return 1;
  }
  
  if(present("huanri book",ob)){
    command("say ���˲�Ҫ̫̰�İ���");
    command("pat "+ob->query("id"));
    return 1;
  }
  
  if(ob->query_temp("dtsl_quest_badao_killer")<4){
    command("say �ĸ�а��������ûɱ�꣬����θ���ô���");
    return 1;
  }
  if(!ob->query("force_quest/csj1")){
    command("say �Ȿ����Ǹ�����Ҳûʲô�ô���\n");
    return 1;
  }
  ob->delete_temp("dtsl_quest_badao_killer");
  command("thank "+ob->query("id"));
  command("�ðɣ��Ҿ͸����Ȿ�飬������δ���ܿ��ö���"); 
  book=new("/d/quest/bawangdao/obj/book");
  book->move(ob);
  message_vision("$N����$nһ"+book->query("unit")+book->query("name")+"��\n",this_object(),ob);
  ob->set("dtsl_quest_help_huanri_ok",1);
  
  return 1;
}

int do_action5()
{
  object ob,book;
  
  ob=this_player();
  
  if(present("yueshan shoujuan",ob)){
    command("say ���˲�Ҫ̫̰�İ���");
    command("pat "+ob->query("id"));
    return 1;
  }
  
  if(ob->query_temp("dtsl_quest_badao_killer")<4){
    command("say �ĸ�а��������ûɱ�꣬����θ���ô���");
    return 1;
  }
  
  ob->delete_temp("dtsl_quest_badao_killer");
  command("thank "+ob->query("id"));
  command("�ðɣ��Ҿ͸�������ǰ�������"); 
  
  book=new("/d/quest/bawangdao/obj/book2");
  book->move(ob);
  message_vision("$N����$nһ"+book->query("unit")+book->query("name")+"��\n",this_object(),ob);
  
  return 1;
  
}

/*int do_action6()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query("perform_quest/badao")){
    command("say �������ﰡ������ȥ���ˣ���... ...");
    return 1;
  }
  
  if(ob->query("dtsl_quest_bsy_help_ok")){
    command("say �������ﰡ������ȥ���ˣ���... ...");
    return 1;
  }
  
  if(ob->query_temp("do_bsy_quest2")){
  	command("say �������ﰡ������ȥ���ˣ���... ...");
        return 1;
  }
  
  ob->set_temp("do_help_hj_bsy_quest1",1);
  
  command("say �������ﰡ������ȥ���ˣ��Һ���������");
  
  return 1;
  
}*/
/*
int do_action7()
{
  object ob,obj;
  
  ob=this_player();
  
  if(!ob->query("perform_quest/badao")){
    command("say ������˭�����ԣ�");
    return 1;
  }
  
  if(ob->query("dtsl_quest_bsy_help_ok")){
    command("say ���Ѿ��������ˣ��㲻Ҫ�����ˡ�");
    return 1;
  }
  
  if(!ob->query_temp("do_help_hj_bsy_quest1")){
  	command("say ������˭�����ԣ�");
        return 1;
  }
  
  ob->set_temp("do_help_hj_bsy_quest1",0);
  ob->set("dtsl_quest_bsy_help_ok",1);
  
  obj=new("/d/chengdu/npc/obj/yiyan_book");
  obj->move(ob);
  
  message_vision("$N����$nһ"+obj->query("unit")+obj->query("name")+"��\n",this_object(),ob);
  
  command("say ��Ȼ��������ǰ���ĵ��ӣ����ҾͰ���������Ը��㿴���ɣ�");
  
  return 1;
  
}*/
