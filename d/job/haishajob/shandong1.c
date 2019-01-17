
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"ɽ��"NOR);
  set ("long", @LONG
������һ��ɽ�����ںڵģ�������������ʲô��·����˵�������
���˺ܶ������ص��ˣ��㲻��С��������
LONG);

  set("exits", ([ 
 "enter":__DIR__"shandong2",
 "out":"/d/taishan/nantianmen",
        ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  object killer;
  object *targets;
  int i;
  if(ob->query("job/duobao_job")&&!ob->query("job/flag1"))
  {
    ob->set("job/flag1",1);
    killer=new(__DIR__"killer"+(1+random(6)));
    killer->move(environment(ob));
    killer->set("combat_exp",ob->query("combat_exp"));
    if("/cmds/usr/hp.c"->get_pot(killer));
    set_all_skill(killer,ob->query("max_pot")-80);
    killer->set("target_id",ob->query("id"));
    killer->kill_ob(ob);
    ob->kill_ob(killer);
    return notify_fail("��Ȼ����һ���ˣ���Ц������Ȼ���ˣ��ͱ����ˣ�\n");
   }
  if(ob->query("job/duobao_job")){
   targets=all_inventory(environment(ob));
   for(i=0;i<sizeof(targets);i++)
   if(targets[i]->query("target_id")==ob->query("id")&&
      targets[i]!=ob)
   return notify_fail("ɱ��һ��ץס���㣡\n");}
   
  return ::valid_leave(ob,dir);
}