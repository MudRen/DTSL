
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
int do_search(string arg);
void create()
{
   set_name(HIR"ͨ����"NOR, ({ "paper"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ��ͨ����������(search)�����ҷ��ˡ�\n");
     set("material", "��ֽ");
     set("unit", "��");
     set("value", 0);
     set("no_sell",1);
     set("no_steal",1);
     set("no_drop",1);
     set("no_give",1);
  }
   setup();
}

void init()
{
   add_action("do_search","search");
}

int do_search(string arg)
{
  object ob,killer;int flag;
  object *t;
  object swap_ob;
  int i;
  
  ob=this_player();
  if(!arg||arg!="����")
  return notify_fail("��Ҫ�Ѳ�ʲô�ˣ�\n");
  if(!ob->query_temp("butou_job"))
  return notify_fail("��û���ʸ�����ɱ������\n");
  
  t=ob->query_team();
  if(sizeof(t)<2)
  return notify_fail("��û�н��,����һ���˼�ɱ����̫Σ����!\n");
  if(sizeof(t)>2)
  return notify_fail("��Ķ���������ô��,����ûʲô��Ҫ��?\n");
  for(i=0;i<sizeof(t);i++)
    if(environment(ob)!=environment(t[i]))
      return notify_fail("��Ļ�鲻�������ɱ����̫Σ���ˣ�\n");
  for(i=0;i<sizeof(t);i++)
    if(!t[i]->query_temp("butou_job"))
      return notify_fail("��Ķ����л����������ˣ��޷���ɱ������\n");
  if(query("where")!=base_name(environment(ob)))
  return notify_fail("�������һ�ᣬ���ֵ������������\n");
  if(query("no_search"))
  return notify_fail("���ͣ����ͣ�\n");
 
  if(t[0]->query("combat_exp")>t[1]->query("combat_exp"))
   swap_ob=t[0];
  else swap_ob=t[1];
  
  set("no_search",1);
  killer=new("/d/job/butou/killer");
  killer->set("combat_exp",swap_ob->query("combat_exp")+100000);

  copy_hp_item(swap_ob,killer,"kee");
  copy_hp_item(swap_ob,killer,"gin");
  copy_hp_item(swap_ob,killer,"sen");
  killer->set("max_force",swap_ob->query("max_force"));
  killer->set("force",swap_ob->query("max_force"));
  set_all_skill(killer,swap_ob->query("max_pot")-80);
  for(i=0;i<sizeof(t);i++)
  killer->add_array("target_id",t[i]->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIW"$NͻȻ����Ծ������$n�ȵ�����Ȼ�����Ƿ��֣�ֻ��ɱ������ˣ�\n"NOR,
                 killer,ob);
  for(i=0;i<sizeof(t);i++)
    killer->kill_ob(t[i]);
  message_vision("$Nһ����ң����е�"+query("name")+"�����˵��ϡ�\n",ob);
  destruct(this_object());
   return 1;
}