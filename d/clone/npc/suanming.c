
inherit NPC;
#include <ansi.h>

int do_quest();

void create()
{
   set_name("������",({ "shensuan zi","shensuan","zi"}) );
   set("gender", "����" );
   set("age",65);
   set("nickname","С̫��");
   set("long","����һ��������������˵���������׼��\n"+
              "��������һ����ᦣ�����д��ʮ���ƽ�һ�Ρ�\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   set("inquiry",([
     "����":(:do_quest:),
     ]));
   set("chat_chance",20);
   set("chat_msg",({
    "�����Ӹ�����������������������׼��ҪǮ�ˡ���������!\n",
    "�����Ӹ�������ÿ������ʮ���ƽ���������ඡ���������!\n",
    }));
   setup();
    
}
void die()
{
  message_vision(HIR"$N����һ̾��û�뵽��һ������������û������֮�أ�\n"NOR,this_object());
  return ::die();
}

int do_quest()
{
  object ob,who;
  int kar;
  who=this_player();
  ob=this_object();
  if(!who->query_temp("can_suanming")){
   command("say ����Ǯ����ô������������\n");
   return 1;
  }
  who->delete_temp("can_suanming");
  kar=who->query("kar");
  if(kar<=15){
  	message_vision("$N�������˿�̵��\n",this_object());
  	command("say ��ù����ù��������ô�������㣬̫�����ˣ�\n");
  }
  else
  if(kar<=20){
  	message_vision("$N��̾��һ�������˶࿲����������С�İɣ�\n",this_object());
        message_vision("$N����$nһ�ۣ����ε�ҡ��ҡͷ��\n",this_object(),who);
        command("say �㻹���߰ɡ�\n");
  }
  else
  if(kar<=25){
          message_vision("$N�ſ���$n���֣����Ǻ�����ֻ���޴󸻴��֮�ࡣ\n",this_object(),who);      
          message_vision("$N��̾������������������ѽ��\n",this_object());
          command("say ���Ժ�С�����°ɣ�\n");
  }
  else
  if(kar<=27){
  	  message_vision("$N��̾����������������һ��һ�ĺ�����\n",this_object());
  	  message_vision("$N͵͵����$nһ�ۣ�������ת�������ߡ�\n",this_object(),who); 
  	  command("say ���Ҫ�úð����Լ���\n");
  }
  else{
         message_vision("$N���쳤̾�����������ۣ��������ۣ��ҳ����Ұ������������޺��ˣ�\n",this_object());
         command("say ��һ��Ҫ���Ŭ�����ɾ�һ����ҵ��");
  }
  return 1;
  
}

int accept_object(object who,object ob)
{
  if(!ob->query("money_id"))
  return notify_fail("����������Ǯ��ʲôҲ��Ҫ��\n");
  if(ob->value()<100000)
  return notify_fail("��Ҳ̫С�����˰ɣ��Ÿ�����ô��Ǯ��\n");
  
  tell_object(who,"�ðɣ��������;������Ұɣ�\n");
  who->set_temp("can_suanming",1);
  return 1;
  
}