// ����˫����

//�����


inherit NPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
  set_name("�������", ({"di zi", "di", "zi"}));
  set("gender", "����");
 
  set_skill("sword",182);
  set_skill("force", 182);
  set_skill("dodge", 182);
  set_skill("parry", 182);
  
  set_skill("tianmo-dafa",182);
  set_skill("tianmo-jianfa",182);
  set_skill("tianmo-huanzong",182);
  
  setup();
  
  create_family("������",7, "����");
  carry_object(__DIR__"obj/sword")->wield();

}


void set_status(object ob)
{
   set("target_id",ob->query("id"));
   
   set("combat_exp",ob->query("combat_exp"));
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   
   set("max_force",ob->query("max_force"));
   set("force",ob->query("max_force"));
   
   set_all_skill(this_object(),ob->query("max_pot")-110);
   
   set("last",time());
}

int clear()
{
  if(time()-query("last")<800)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;

}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
  
   return ::chat();
}

int do_jiejiu(string arg)
{
   object ob,target,guard;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ���˭��\n");
   
   if(query("owner_ob")!=ob)
   return notify_fail("�㲻�ܽ�ȶԷ���\n");
   
   guard=query("killer_ob");
   if(objectp(guard)){
     command("say ���Ȱ�ץ�ҵ������ɶ���ɱ�˰ɣ�");
     return 1;
   }
   command("say ��л��ľ���֮����");
   command("follow "+ob->query("id"));
   return 1;
}
   
   