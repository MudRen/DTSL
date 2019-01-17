
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string do_zhaoxiang();
void create()
{
   set_name("����ʢ",({ "tao shusheng","tao"}) );
        set("gender", "����" );
        set("age", 40);
        set_skill("force",100);
        set_skill("tianmo-huanzong",100);
        set_skill("tianmo-dafa",100);
        set_skill("parry",100);
        set_skill("linglong-yuquan",100);
        set_skill("pojun-quan",100);
        set_skill("dujie-zhi",100);
        set_skill("cuff",100);
        set_skill("finger",100);
        set_skill("dodge",100);
        set_temp("apply/armor",30);
   set("long", "�����Ƿ����������Ĵ�ִ��֮����\n"); 
   set("inquiry",([
       "�н�":(:do_zhaoxiang:),
       ]));
   setup();
  
}

int kill_object(object killer,object victim)
{
  if(query("target_id")==victim->query("target_id")){
   message_vision(HIR"$N������Ц����ƾ��Ҳ�뼩ɱ����ү��\n"NOR,killer);
   destruct(killer);
   return 1;}
  return 1;
}

void init()
{
  set("last",time());
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
   object ob;
   if(clear())
   return 1;
   ob=query_temp("last_damage_from");
   if(!ob) return ::chat();
   if(!ob->query_temp("shang_kill_pantu")||
     query("target_id")!=ob->query("id"))
   return ::chat();
   if(query("zx_flag"))
   return ::chat();
   if(query("eff_kee")*100/query("max_kee")<JOBSYS_D->get_up_lev())
     if(random(100)<JOBSYS_D->get_random_lev())
       return ::chat();
     else{
      if(!query("no_msg"))
      tell_object(ob,HIC+query("name")+"׼��Ͷ���ˣ�������н�"+query("name")+"����ʹ��\n"+
                     "ask xxx about �н� ���\n"NOR);
      set("no_msg",1);
      ob->set_temp("shang_kill_pantu_zx",this_object());
      set("busy_time",time());
      return ::chat();}
   else return ::chat();
   return ::chat();
}

string do_zhaoxiang()
{
   object ob;
   object thing;
   
   ob=this_player();
   if(!ob->query_temp("shang_kill_pantu_zx"))
   return "��˵ʲô�أ�����һ��Ҳ��������\n";
   if(ob->query_temp("shang_kill_pantu_zx")!=this_object())
   return "��˵ʲô�أ�����һ��Ҳ��������\n";
   set("zx_flag",1);
   ob->remove_all_enemy();
   this_object()->remove_all_enemy();
   if(!query("no_fight"))
   message_vision("\n$N��$n�������һԾ������սȦ��\n",ob,this_object());
   set("no_fight",1);
   if(time()-query("busy_time")<30)
   return "����������һ�룡\n";
  
   ob->delete_temp("shang_kill_pantu_zx");
   ob->set_temp("zhaoxiang_killer",1);
   if(random(2)==1){
     kill_ob(ob);
     return "��ү�Ҹı������ˣ�ҪɱҪ������ı��ˣ�\n";}
    thing=new("/d/job/funjob/thing");
    thing->move(ob);
    tell_object(ob,query("name")+"������һ��"+thing->query("name")+"��\n");
   
   return "���ڱ���ķ��ϣ��ܲ��ܷŹ����£�";
  
}

