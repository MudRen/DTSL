inherit ROOM;
#include <ansi.h>

int do_install(string arg);

void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����ǾŽ��Ĵ�԰�������������˺ܶ࣬���ֵ����������ڶ�����
�߻���һ����¥����ǰ�����ϡ�����¥����������Ĵ�����������ҫ��
�������⡣¥�ϴ����˺Ⱦơ���Ц��������������ָ���԰������һ��
���֡�
LONG);

  set("exits", ([ 

  "up":__DIR__"chunzailou",
  "west":"/d/jiujiang/beidajie2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  set("cisha_job",1);
  setup();
 
}

void init()
{
  add_action("do_install","install");
}

int do_install(string arg)
{
   object ob;
   object tool;
   object *t;
   int i;
   ob=this_player();
   if(!ob->query_temp("dtsl_job_cisha/step2"))
   return notify_fail("���ﲻ׼��װ������\n");
   if(!arg)
   return notify_fail("��Ҫ��װʲô��\n");
   if(!objectp(tool=present(arg,ob)))
   return notify_fail("������û�����������\n");
   if(!tool->query("cisha_job"))
   return notify_fail("����������������ﰲװ��\n");
   message_vision("$N�����㹳�ҵ����Աߵ����ϣ�ͬʱ����һ˦����\n"+
        "��һ��˦�ҵ����ԱߵĴ���¥�ϣ�\n",ob);
   tell_room(__DIR__"chunzailou","¥��һ����˦����һ�����ߣ���������ת�˼�ת���㹳������Ƕ���������У�\n");
   t=ob->query_team();
   if(sizeof(t)>0){
    for(i=0;i<sizeof(t);i++)
     if(t[i]&&environment(t[i])==environment(ob)&&living(t[i]))
       message_vision(YEL"$N˫��һ�����ߣ�����һ�Σ��ݵ����ԱߵĴ���¥�У�\n"NOR,t[i]);}
   else message_vision(YEL"$N˫��һ�����ߣ�����һ�Σ��ݵ����ԱߵĴ���¥�У�\n"NOR,ob);
   if(sizeof(t)<=0)
   tell_room(__DIR__"chunzailou","¥��һ����Ӱ���һ������������\n");
   else
   tell_room(__DIR__"chunzailou","¥�¼�����Ӱ���һ������������\n");
   destruct(tool);
   if(sizeof(t)>0){
    for(i=0;i<sizeof(t);i++)
     if(t[i]&&living(t[i])){
     if(t[i]->query_temp("dtsl_job_cisha/step2"))
     t[i]->set_temp("dtsl_job_cisha/step3",1);
     t[i]->set_temp("dtsl_job_cisha/can_flee",1);
     t[i]->move(__DIR__"chunzailou");}}
   else{
   ob->set_temp("dtsl_job_cisha/can_flee",1);
   ob->move(__DIR__"chunzailou");
   ob->set_temp("dtsl_job_cisha/step3",1);}
   ob->apply_condition("cisha_job",1);
   return 1;
}
   
int valid_leave(object ob,string dir)
{
  object *target;
  int i;
  target=all_inventory(environment(ob));
  for(i=0;i<sizeof(target);i++)
   if(target[i]->query("target_id")==ob->query("id"))
    return notify_fail(target[i]->name()+"һ����ס���㣡\n");
  return ::valid_leave(ob,dir);
}
