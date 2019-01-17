
inherit NPC;

#include <job_money.h>

int do_wei(string arg);

void create()
{
   set_name("����",({ "sheep"}) );
        set("race", "Ұ��" );
        set("combat_exp",20000);
     set("long", "����һֻ����\n");
	 set("verbs",({"hoof"}));
	 set("target_id","####");
     set("limbs",({"ͷ","β��","����","����"}));
  setup();

}

int accept_fight(object ob)
{
   return 0;
}

void init()
{
  add_action("do_wei","wei");
}

int do_wei(string arg)
{
   object ob,target;
   
   ob=this_player();
   
   if(!arg) return notify_fail("��Ҫιʲô��\n");
   
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û�����������\n");
   
   if(target->query("owner")!=ob)
   return notify_fail("��Ū������˰ɣ���\n");
   
   if(target->query("place")!=base_name(environment(ob))+".c")
   return notify_fail("������ߴ�ط��ˡ�\n");
   
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   
   if(this_object()->is_busy())
   return notify_fail("�Է���æ���أ�\n");
   
   if(ob->is_fighting())
   return notify_fail("���ȴ����̰ɣ�\n");
   
   if(this_object()->is_fighting())
   return notify_fail("�Է�����ս���У�\n");
   
   if(query("job_ok")){
     tell_object(ob,query("name")+"�Ѿ��Ա��ˣ�������ι�ˡ�\n");
   return 1;
    }
   
   tell_object(ob,"��ӵ��ϰ���Щ�ݣ�ι��"+query("name")+"���ˡ�\n");
   
   if(ob->query("combat_exp")>=50000&&!query("flag")){
     set("flag",1);
     call_out("wolf_come",5+random(3),ob);
     }
   
   add("food",1);
   ob->receive_damage("sen",10+random(5));
   
   if(query("food")>=10+random(5)){
   
   set("job_ok",1);
   tell_object(ob,query("name")+"�Ѿ��Ա��ˣ�������ι�ˡ�\n");
   return 1;
    }
   ob->start_busy(random(2));
   this_object()->start_busy(random(2));
   return 1;
   
}

void wolf_come(object ob)
{
   object beast;
   
   beast=new(__DIR__"wolf");
   beast->set("combat_exp",ob->query("combat_exp"));
   
   copy_hp_item(ob,beast,"kee",2/3);
   
   beast->move(environment());
   tell_object(ob,"\n\nͻȻ�ݳ�һֻ"+beast->query("name")+
   "��"+query("name")+"��ȥ����\n\n");
   
   beast->kill_ob(this_object());
   
   return;
}