
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("ɱ��",({ "killer" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ��ɱ�֣���˵�������ȥ�д���Ԩ��\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set_skill("finger",70);
   set_skill("strike",70);
   set_skill("cuff",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set_skill("tiangang-sanjue",70);
   set_skill("bencao-shuli",70);
   set_skill("huanmo-shenfa",70);
   set_skill("dujie-zhi",70);
   set_skill("sanhua-zhi",70);
   set_skill("xiuluo-zhi",70);
   set_skill("pojun-quan",70);
   set_skill("linglong-yuquan",70);
   set_skill("xukong-zhang",70);    
   set("max_force",200);
   set("force",200);
   
   setup();
  
}

int clear()
{
  if(time()-query("last")<300)
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
  int i;
  
  if(clear())
   return 1;
  i=random(10);
  if(i==4)
   command("apply dujie-zhi 3 8");
  else
  if(i==5)
   command("apply sanhua-zhi 3 8");
  else
  if(i==6)
   command("apply xiuluo-zhi 3 8");
  else
  if(i==7)
   command("apply pojun-quan 3 8");
  else
  if(i==8)
   command("apply linglong-yuquan 3 8");
  else
   command("apply xukong-zhang 3 8");
  if(random(100)>70)
  command("perform mie");
  return ::chat();
}

void init()
{
    set("last",time());

}

int clean_up()
{
  if(time()-query("last_time")<300)
   return 0;
  return 1;
}

int accept_fight(object ob)
{
  if(query("target_id")!=ob->query("id"))
  return notify_fail("�Է��������������ս������\n");
  return ::accept_fight(ob);
}