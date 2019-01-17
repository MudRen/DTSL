
#include <ansi.h>
#include <job_money.h>
inherit ROOM;
int do_wa(string arg);
void create ()
{
  set ("short",HIB"ɽ��"NOR);
  set ("long", @LONG
������һ��ɽ�����ںڵģ�������������ʲô��·����˵�������
���˺ܶ������ص��ˡ������Ѿ���ɽ���ľ�ͷ�ˡ�
LONG);

  set("exits", ([ 
 "out":__DIR__"shandong4",
        ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int valid_leave(object ob,string dir)
{
  object killer,killer2;
  object *targets;
  int i;
  if(ob->query("job/duobao_job")&&!ob->query("job/flag3"))
  {
    ob->set("job/flag3",1);
    killer=new(__DIR__"killer"+(1+random(6)));
    killer->move(environment(ob));
    killer->set("combat_exp",ob->query("combat_exp")+300000);
    set_all_skill(killer,ob->query("max_pot")-80);
    killer->set("target_id",ob->query("id"));
    copy_hp_item(ob,killer,"gin");
    copy_hp_item(ob,killer,"kee");
    copy_hp_item(ob,killer,"sen");
    killer->set("max_force",ob->query("max_force"));
    killer->set("force",ob->query("max_force"));
    killer->kill_ob(ob);
    killer2=new(__DIR__"killer"+(1+random(6)));
    killer2->move(environment(ob));
    killer2->set("combat_exp",ob->query("combat_exp"));
    killer2->set("target_id",ob->query("id"));
    set_all_skill(killer2,ob->query("max_pot")-80);
    copy_hp_item(ob,killer2,"gin");
    copy_hp_item(ob,killer2,"kee");
    copy_hp_item(ob,killer2,"sen");
    killer2->set("max_force",ob->query("max_force"));
    killer2->set("force",ob->query("max_force"));
    killer2->kill_ob(ob);
    ob->kill_ob(killer);
    ob->kill_ob(killer2);
    return notify_fail("��Ȼ���������ˣ���Ц������Ȼ���ˣ��ͱ����ˣ�\n");
   }
  if(ob->query("job/duobao_job")){
   targets=all_inventory(environment(ob));
   for(i=0;i<sizeof(targets);i++)
   if(targets[i]->query("target_id")==ob->query("id")&&
      targets[i]!=ob)
   return notify_fail("ɱ��һ��ץס���㣡\n");}
  return ::valid_leave(ob,dir);
}

int do_wa(string arg)
{
  object ob,map;
  ob=this_player();
  if(!arg||arg!="�ر�ͼ"||!ob->query("job/duobao_job")
  ||ob->query("job/get_map"))
  return notify_fail("ʲô?\n");
  ob->set("job/get_map",1);
  map=new(__DIR__"map");
  message_vision("$N������ȥ������������\n",ob);
  message_vision("$N�ڵ���һ�ݲر�ͼ��\n",ob);
  map->move(ob);
  return 1;
}