
inherit NPC;

void create()
{
   set_name("Ѿ��",({ "ya huan","ya","huan"}) );
        set("gender", "Ů��" );
        set("age",10+random(10));
        set("target_id","####");
        set("long","�����������������Ѿ�ߡ�\n");
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
    command("xixi "+ob->query("id"));
    break;
   case 1:
     command("bow "+ob->query("id"));
     break;
   
   case 2:
     command("wink1 "+ob->query("id"));
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