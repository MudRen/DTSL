// ����˫����

//�����


inherit NPC;
#include <ansi.h>

int do_jiejiu(string arg);

void create()
{
  set_name("�����", ({"fu junyu", "fu", "junyu"}));
  set("gender", "Ů��");
 
  set("per",26);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",4000);
  set("combat_exp",600000);
  set_skill("unarmed", 182);
  set_skill("strike",182);
  set_skill("leg",182);
  set_skill("literate", 182);
  set_skill("sword", 182);
  set_skill("force", 182);
  set_skill("dodge", 182);
  set_skill("parry", 182);
  
  set_skill("jiuxuan-dafa",182);
  set_skill("fengxue-leg",182);
  set_skill("jiuzhuan-jianjue",182);
  set_skill("xingyun-dodge",182);

  
  set("target_id","####");
  
  setup();
  
  create_family("�Ľ���",4, "����");

}

void init()
{
   add_action("do_jiejiu","jiejiu");
}

void set_status(object ob,object guard)
{
   set("owner_ob",ob);
   set("killer_ob",guard);
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
   ob->delete_temp("perform_quest/ditian_action1");
   ob->set_temp("perform_quest/ditian_action2",1);
   return 1;
}
   
   