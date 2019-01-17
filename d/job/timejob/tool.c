
#include <weapon.h>
inherit STAFF;
int do_pao();
void create()
{
	set_name("��ͷ", ({ "chu tou", "chu","tou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͷ��\n");
		set("no_drop",1);
		set("no_get",1);
		set("value",0);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N����$n�������С�\n");
		set("unwield_msg", "$N���������е�$n��\n");
	}
	init_staff(20,250,250);
	setup();
}
void init()
{
  add_action("do_pao","pao");
}
int do_pao()
{
  object ob,thing;mapping *jobs;  
  object jobctrl;
  int j;
  
  string here;int i;
  ob=this_player();
  if(environment(this_object())!=ob)
  return notify_fail("ʲô��\n");
  if(ob->query("sen")<50)
  return notify_fail("��ľ���̫���ˣ�\n");
  ob->add("sen",-50);
  jobctrl=load_object(__DIR__"jobctrl.c");
  jobs=jobctrl->get_jobs();
  if(!sizeof(jobs)||query("no_use"))
  return notify_fail("�������ͷ���˰��죬ʲôҲû�ٵ���\n");
  here=base_name(environment(ob))+".c";
  for(i=0;i<sizeof(jobs);i++){
    if(jobs[i]["local"]==here&&jobs[i]["over"]!=1){
    	thing=new(__DIR__"thing");
    	thing->set("owner",ob);
        thing->move(environment(ob));
        message_vision("$NͻȻ���ú����ڵ���ʲô��������æͣ��������\n",ob);
        set("no_use",1);
        jobctrl->add_tasks(1);
        jobs[i]["over"]=1;
        jobctrl->set_jobs(jobs);
        break;}
   }
  if(i<sizeof(jobs)){
   tell_object(ob,"ֻ�����ҡ���һ������ͷ�������ˣ�\n");
   if(query("equipped"))
      unequip();
   ob->delete_temp("random_job");
   ob->delete_temp("dtsl_job");
   destruct(this_object());
   return 1;}
  return notify_fail("�������ͷ���˰��죬ʲôҲû�ٵ���\n");
}
 int is_get_of(object me,object ob)
{
 if(query("owner")!=me)
 return notify_fail("�ǲ�����ĳ�ͷ��\n");
 return 1;
}
