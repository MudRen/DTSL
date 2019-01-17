
inherit NPC;

#define JOBCTRL "/d/job/killhaidao/jobctrl.c"

string give_job();

void create()
{
  set_name("������", ({"han chaoan", "han"}));
  set("gender", "����");
  set("long","���Ǹ����ĵ����º�������\n");
  set("age", 36);
  set("str",30);
  set("per",24);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",4000);
  set("combat_exp",500000);
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
 
  set("target_id","###");
  
  set("inquiry",([
    "���":(:give_job:),
    ]));
  setup();
  
}

string give_job()
{
   object ob;
   object *member;
   object target;
   int i;
   int flag;
   
   ob=this_player();
   member=ob->query_team();
   if(sizeof(member)<=2)
   return "��ôΣ�յ������������Ѷ�̫���ˣ��������Ҽ�����ȥ�ɣ�\n";
   if(query("have_job"))
   return "�Ѿ�����ȥ����ˣ��㻹�ǵȻ������ɣ�\n";
   for(i=0;i<sizeof(member);i++)
     if(member[i]&&environment(member[i])!=environment(ob))
      break;
   if(i<sizeof(member))
   return "������еĶ�Ա����������ȵ���˵�ɣ�\n";
   for(i=0;i<sizeof(member);i++)
	  if(objectp(member[i]))
		  if(member[i]->query("combat_exp")<1000000)
         return member[i]->name()+"�ľ���̫���ˣ�̫Σ���ˣ�\n";
   set("have_job",1);
   flag=random(3);
   if(flag==0)
   tell_room(environment(ob),"\n\nԶ��һ�������������ؿ��˹�����\n\n");
   else if(flag==1)
   tell_room(environment(ob),"\n\nԶ��һ���̴������ؿ��˹�����\n\n");
   else
   tell_room(environment(ob),"\n\nԶ��һ��ս�������ؿ��˹�����\n\n");
   tell_room(environment(ob),"\n���������������������Ҵ��ˣ���\n\n");
   
   target=ob;
   for(i=0;i<sizeof(member);i++)
      if(member[i]&&member[i]->query("combat_exp")>target->query("combat_exp"))
       target=member[i];
   if(flag==0)
   JOBCTRL->start_job(target,sizeof(member)+15);
   else
   if(flag==1)
   JOBCTRL->start_job(target,sizeof(member)+25);
   else
   JOBCTRL->start_job(target,sizeof(member)+35);
   
   for(i=0;i<sizeof(member);i++)
    if(member[i]){
     message_vision("$N����һԾ�������˼װ壡��\n",member[i]);
     member[i]->move(__DIR__"out/out_6_0");}
  return "Ҫһ��С�ģ�\n";
}