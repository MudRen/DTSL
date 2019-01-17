
inherit NPC;

void create()
{
   set_name("�����",({ "ba dai","ba" }) );
   set("gender", "Ů��" );
		
   set("age",22);
   set("long", "����ͻ���ɺ��ն���С���ӡ�\n");
       
   set("combat_exp",300000);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("force",130);

   setup();
  
}

void init()
{
   add_action("do_ok","task");
}

int set_status(object ob)
{
  set_leader(ob);
  set("target_id","###");
  set("job_owner",ob);
  return 1;
}

int do_ok(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(query("job_owner")!=ob)
   return 0;
  if(!arg||arg!="ok")
  return notify_fail("ʹ�� task ok ����������\n");
  if(base_name(environment(ob))!="/d/luoyang/xinzhongqiao2"){
    command("say �㻤�͵ĵط����԰���");
    return 1;
  }
  if(!ob->query_temp("husong_badai_killer")){
    command("say ������������Ϊ�˿����㣬������ûɱ��ɱ�֣����������ˣ�");
    destruct(this_object());
    return 1;
  }
  ob->delete_temp("husong_badai_killer");
  ob->delete_temp("husong_badai");
  ob->set_temp("husong_badai_ok",1);
  command("say лл���ˣ�");
  destruct(this_object());
  return 1;
}
  