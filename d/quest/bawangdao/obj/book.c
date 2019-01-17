
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name("�����մ󷨡�", ({ "huanri book","book"}));
   set_weight(100);
   set("unit", "��");
   set("long","����һ���������մ󷨵������ؼ���\n");
   set("no_give",1);
   
}

void init()
{
  add_action("do_liaoshang","liaoshang");
}

int do_liaoshang(string arg)
{
  object ob,*mem,target;
  string msg;
  string *skills;
  int i;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("��Ҫ��˭���ˣ�\n");
  
  target=present(arg,environment(ob));
  if(!objectp(target))
  return notify_fail("����û������ˡ�\n");
  
  if(!target->query_temp("dtsl_quest_huanri_action1"))
  return notify_fail("ʹ�ô����޷���"+target->name()+"���ˣ�\n");
  
  if(!living(target))
  return notify_fail("�Ȱ�"+target->name()+"Ū�Ѱɣ�\n");
  
  mem=ob->query_team();
  if(mem)
  mem=mem-({});
  if(sizeof(mem)!=2)
  return notify_fail("���������˲��ܸ�"+target->name()+"���ˣ�\n");
  
  if(!mem[0]->query_skill("changsheng-jue",1)
    &&!mem[1]->query_skill("changsheng-jue",1)
    )
  return notify_fail("�����ó��������ܸ�"+target->name()+"���ˣ�\n");
  
  if( (mem[0]->query("force_quest/csj1")&&
      mem[1]->query("force_quest/csj1")
      )||
      (mem[0]->query("force_quest/csj2")&&
      mem[1]->query("force_quest/csj2")
      )
    )
   return notify_fail("����ʹ�ó������Ķ�����ϲ��ܸ�"+target->name()+"���ˣ�\n");
  
  msg=HIW"$N"+HIW+"��$n"+HIW+"��ϥ�������ֱ��ס"+target->name()+HIW+"��ǰ�ĺͺ󱳣�������֮��\n"+
      "��ϻ��մ󷨻�����"+target->name()+HIW+"���ˡ�\n\n"NOR;
  msg+=HIR"һ���Ӻ�"+target->name()+HIR"���˿���Ѫ��\n"NOR;
  
  message_vision(msg,mem[0],mem[1]);
  
  target->delete_temp("dtsl_quest_huanri_action1");
  if(random(target->query_quest_kar())<27){
  	tell_object(target,"\n��΢΢�˶���Ϣ��������û�������մ󷨡�\n\n");
  	target->add("force_quest/hrdf_fail_times",1);
  	if(target->query("force_quest/hrdf_fail_times")>=2){
  		target->set("force_quest/hrdf_fail",1);
  		tell_object(target,"\n��ľ����Ѿ������ܴ���������Ҳ�޷������մ��ˣ�\n\n");
  	}
  	destruct(this_object());
  	return 1;
  }
  	
  
  skills=keys(target->query_skills());
  
  if(sizeof(skills)){
  	for(i=0;i<sizeof(skills);i++)
  	 if(SKILL_D(skills[i])->query_type()=="force_skill")
  	   target->delete_skill(skills[i]);
  }
  target->set_skill("huanri-dafa",10);
  target->set("dtsl_quest_huanri_ok",1);
  
  for(i=0;i<2;i++){
   mem[i]->set("max_force",mem[i]->query("max_force")-100);
   if(mem[i]->query("max_force")<0)
      mem[i]->set("max_force",0);
   if(mem[i]->query("force")>mem[i]->query("max_force"))
    mem[i]->set("force",mem[i]->query("max_force"));
  }
  
  destruct(this_object());
  return 1;
}