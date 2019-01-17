
inherit NPC;
#include <ansi.h>

mapping f_name=([
"������":"�Ⱥ���ի",
"�Ⱥ���ի":"������",

"�μұ�":"�Ľ���",
"�Ľ���":"�μұ�",

"������":"������Ժ",
"������Ժ":"������",

"������":"ͻ��",
"ͻ��":"������",
"��ͨ����":"������Ժ",

]);

void create()
{
        set_name("����",({ "lian rou","lian","rou"}) );
        set("gender", "Ů��" );
        set("age", 16);
        set("per",26);
        set("long","������˧��Ů�����书�Ѿ��õ����׵��洫��\n");
        set("combat_exp",400000);
        
        set("max_kee",1000);
        set("max_sen",1000);
        set("max_gin",1000);
        set("max_force",1000);
        set("force",1000);
        set_skill("parry",130);
        set_skill("dodge",130);
        set_skill("force",130);
        
        set_skill("blade",130);
        set_skill("leveltwo-blade",130);
        set_skill("jiuying-dodge",130);
        
        set("daughter","lianrou");
    setup();
  
   carry_object(__DIR__"obj/blade")->wield();
  
}

void init()
{
   add_action("do_jiejiu","jiejiu");
 
}

void unconcious()
{
   object killer;
   
   killer=query_temp("last_damage_from");
   if(!killer) return ::unconcious();
   
   if(!killer->query("family/family_name")) return ::unconcious();
   
   set("hitted_family",killer->query("family/family_name"));
   set("long",query("long")+"�������ܵ���"+killer->query("family/family_name")+"���ӵ�Ϯ����\n");
   return ::unconcious();
 
}

int return_home(object home)
{
   return 0;
   
}

int do_jiejiu(string arg)
{
  object ob,target;
  object obj1,obj2;
  string f_msg;
  
  ob=this_player();
  
  if(!arg||!objectp(target=present(arg,environment(ob))))
  return notify_fail("��Ҫ���˭��\n");
  
  if(target!=this_object())
  	return 0;
  
  if(target->query_temp("no_guard")){
    command("say ���Ѿ����˽���ˡ�\n");
    return 1;
  }
  if(ob->query("dtsl_quest_ysdodge_ok")){
    command("bow "+ob->query("id"));
    return 1;
  }
  
  if(!ob->query_temp("kill_lianrou_killer")
    &&present("ren fanzi",environment(ob))){
    command("say ��û��ɱ�������ҵ��˷��ӣ��ҿɲ�����������ң�\n");
    return 1;
  }
  if(ob->query("dtsl_quest_ysdodge/fail")){
    command("say �ҿɲ����������ҡ�\n");
    return 1;
  }
  f_msg=ob->query("family/family_name");
  if(!stringp(f_msg)) f_msg="��ͨ����";
  
  if(f_name[f_msg]!=target->query("hitted_family")){
    command("say �һ���Ϊ����"+f_name[target->query("hitted_family")]+"���������ҵ��أ�����Ҳ�ǳ�лл���ˣ�");
    ob->set("dtsl_quest_ysdodge/fail",1);
    destruct(target);
    return 1;
  }
  
  obj1=new(__DIR__"obj/cangbaotu");
  obj2=new(__DIR__"obj/miji1");
  
  obj1->move(ob);
  obj2->move(ob);
  command("thank "+ob->query("id"));
  message_vision("$N����$nһ"+obj1->query("unit")+obj1->query("name")+"��\n"+
                 "$N����$nһ"+obj2->query("unit")+obj2->query("name")+"��\n",target,ob);
  target->set_temp("no_guard",1);
  call_out("go_out",60,target);
  ob->delete_temp("kill_lianrou_killer");
  return 1;
}

int accept_object(object ob,object obj)
{
   object b_obj;
   
   if(!obj->query("give_lianrou"))
   return 0;
   
   b_obj=new(__DIR__"obj/lianrou_blade");
   b_obj->set("user",ob->query("id"));
   b_obj->move(ob);
   message_vision("$N����$nһ"+b_obj->query("unit")+b_obj->query("name")+"��\n",
    this_object(),ob);
   return 1;
}

void go_out(object target)
{
  if(!target) return;
  message_vision("$N�Ҵҵ����ˡ�\n",target);
  destruct(target);
  return;
}