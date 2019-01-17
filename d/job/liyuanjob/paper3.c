
#include <ansi.h>
#include <job_money.h>
inherit ITEM;

int do_find();

void create()
{
        set_name("ͨ����", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

string long()
{
  return "\n"+
  "��������������������������������\n"+
  "  ����һ��ͨ�������д��  \n"+
  "����������������������������\n"+
  "��������  ��ɱ����          \n"+
  ""+"         "+query("target_name")+"      \n"+
  "          �����ڡ�����������\n"+
  ""+"         "+query("target_place")+"      \n"+
  "��������������������������������\n";
}

void init()
{
  add_action("do_find","soucha");
}
int do_find()
{
  object ob;string here;
  object killer;
  ob=this_player();
  if(!ob->query_temp("liyuan_job/step"))
  return notify_fail("�㿴�˿���ͼ�����ִ̿ͺ����ǲ������\n");
  here=base_name(environment(ob));
  if(here!=query("target_where"))
  return notify_fail("�����ŵ�ͼ���˿������ִ̿ͳ�û�ĵط������Ǵ˴���\n");
  killer=new(__DIR__"killer2");
  killer->set("combat_exp",ob->query("combat_exp"));
  set_all_skill(killer,ob->query("max_pot")-70);
  copy_hp_item(ob,killer,"gin");
  copy_hp_item(ob,killer,"kee");
  copy_hp_item(ob,killer,"sen");
  killer->set("max_force",ob->query("max_force"));
  killer->set("force",ob->query("max_force"));
  killer->set("target_id",ob->query("id"));
  killer->set("name",query("target_name"));
  killer->set("long","��˵���˾���ͬ����ԣ�������Ѿ���"+ob->query("name")+"����ɱ���ˡ�\n");
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIR"$NͻȻ�����������$n��Ц������Ȼ���㷢�֣�Ҳֻ��ƴ���ˣ���\n"NOR,killer,ob);
  killer->kill_ob(ob);
  message_vision("\n$N��һ�ţ�ͨ��������˵��ϣ�\n",ob);
  destruct(this_object());
  return 1;
}
