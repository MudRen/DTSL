
inherit NPC;

void create()
{
   set_name("����",({ "di zi","di","zi"}) );
        set("gender", "����" );
        set("age", 32);
        set("target_id","####");
        set("long","����ʯ����ݵĵ��ӣ��������ǳ����䡣\n");
    setup();
   
}

void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   switch(random(3)){
   
   case 0:
    message_vision("$N��$nЦ��������ʯ����ݱ����ɣ�һ��������ѧ�����գ�\n",
    this_object(),ob);
    break;
   case 1:
     command("hi "+ob->query("id"));
     break;
   
   case 2:
     command("dtsl "+ob->query("id"));
    }
  return;
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}