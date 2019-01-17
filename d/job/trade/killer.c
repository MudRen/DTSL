
inherit NPC;
#include <ansi.h>
#include <job_money.h>

string *name=({"��","ɽ","���","����"});

void create()
{
   set_name("��"+name[random(sizeof(name))],({ "killer" }) );
        set("gender", "����" );
		set("tilte","ǿ��");
        set("age", 22);
   set("long", "�����ܹ͵�ɱ��.\n");
       
   set("combat_exp",50000);
   set("str", 25);
   set("per", 25);
   set_skill("dodge",60);
   set_skill("parry",60);
   set_skill("force",60);
   set_skill("sword",60);
   set_skill("yingzi-jianfa",60);
   set_skill("sanhua-zhi",120);
   set_skill("finger",60);
   set_skill("huanmo-shenfa",60);
   set_skill("tianyi-xuangong",60);
   set("gin",300);
   set("eff_gin",300);
   set("kee",300);
   set("eff_kee",300);
   set("sen",300);
   set("eff_sen",300);
   set("force",300);
   set("max_force",300);
  
   setup();
   carry_object(__DIR__"changjian")->wield(); 
}
 int kill_object(object killer,object victim)
{
 if(killer->query("target_id")==victim->query("id"))
{
 message_vision("$Nһ����Ц����Ҫ���ң�����Ҫ��ɱ�㣡\n",killer);
 victim->delete_temp("order_job");
 return 1;
}
return 1;
}

void die()
{
   object ob;
   ob=query_temp("last_damage_from");
   if(ob)
   if(query("target_id")==ob->query("id"))
     ob->add_temp("need_killer_flags",1);
   return ::die();
}


int clear()
{
  if(time()-query("last")<180)
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

int set_status(object me)
{
        set("combat_exp",me->query("combat_exp"));
	set_all_skill(this_object(),me->query("max_pot")-110);
	copy_hp_item(me,this_object(),"gin");
	copy_hp_item(me,this_object(),"kee");
	copy_hp_item(me,this_object(),"sen");
	set("max_force",me->query("max_force"));
	set("force",me->query("max_force"));
	set_temp("apply/armor",50+random(50));
	set("last",time());
	set("target_id",me->query("id"));
	
	return 1;
}