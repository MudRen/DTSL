
inherit ROOM;
#include <ansi.h>
#include <job_money.h>

int do_start();
void create ()
{
  set ("short",HIR"����������̨"NOR);
  set ("long", @LONG
������Ǻ����������Ů���������׵���̨�ˡ�ֻ����̨��
���߹��ŷ�������д�ţ����������ɾ���Ц���� ֻ��̫ƽ��
�����໶�衣 ��̨�����߻��м����Ҷ��ڰ����š�ֻ������
��ȺĦ����࣬ˮк��ͨ������̨�ı߽�����һ���������
��ɴ�����������������Ů���ˡ�
LONG);

  set("exits", ([ 

 "down":"/d/hangzhou/houyuan",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_start","biwu");
}

int do_start()
{
  object ob;
  object killer;
  ob=this_player();
  if(!ob->query_temp("li_job"))
  return notify_fail("��һ��˫ȭ��������������ǰ���������ף�\n");
  if(ob->query_temp("target_come")&&
     ob->is_fighting())
  return notify_fail("���ͣ����ͣ���\n");
  else if(ob->query_temp("target_come"))
        return notify_fail("��һ��˫ȭ��������������ǰ���������ף�\n");
  message_vision("$Nһ��˫ȭ��������������ǰ���������ף�\n",ob);
  if(ob->query("gender")=="Ů��"){
  message_vision("$Nֻ��������Ⱥ����һ���Ц��Ů���ѵ���ȢŮ���𣿣�\n",ob);
  message_vision("$N�����ߵ�����ͨ�죡\n",ob);}
  if(ob->query("gender")=="����")
   if(ob->query("age")>50)
    message_vision("$Nֻ��������Ⱥ����һ���Ц�������Ͷ��������˼ҵĵ��ˣ���\n",ob);
  if(ob->query("gender")=="����")
   if(ob->query("class")=="bonze")
    message_vision("$Nֻ��������Ⱥ����һ���Ц������Ҳ��Ȣ�����𣿣�����\n",ob);
  if(ob->query("gender")=="Ů��"&&
     ob->query("per")>=25)
   message_vision("ֻ�������м�����Ʀ��å��$N��Ц������ôƯ�����ˣ����Ǽ޸������ˣ�\n",ob);
  if(ob->query("gender")=="����"&&ob->query("class")!="bonze")
   if(ob->query("per")<=10)
     message_vision("$Nֻ��������Ⱥ����һ���Ц�����������ò����������������Ⱑ����\n",ob);
   else
   if(ob->query("per")<=15)
     message_vision("$Nֻ��������Ⱥ����һ���Ц��Ҳ���ؼ����վ��ӣ�������˼������\n",ob);
   else
   if(ob->query("per")<=20)
     message_vision("$Nֻ�������˷׷����ۣ����С�ӳ��ò�����������Ϸ��\n",ob);
   else
    if(ob->query("per")<=25)
     message_vision("$Nֻ�������˷׷����ۣ�������ò���ã�ֻ��֪�书��ΰ���\n",ob);
   else
  message_vision("$Nֻ�������˱���һ���Ȳʣ���һ��Ӣ��������\n",ob);
  killer=new(__DIR__"guanbing");
  set_all_skill(killer,ob->query("max_pot")-130);
  killer->set("combat_exp",ob->query("combat_exp"));
  killer->set("max_pot",ob->query("max_pot"));
  killer->set("gin",ob->query("max_gin"));
  killer->set("eff_gin",ob->query("max_gin"));
  killer->set("max_gin",ob->query("max_gin"));
  killer->set("kee",ob->query("max_kee"));
  killer->set("eff_kee",ob->query("max_kee"));
  killer->set("max_kee",ob->query("max_kee"));
  killer->set("sen",ob->query("max_sen"));
  killer->set("eff_sen",ob->query("max_sen"));
  killer->set("max_sen",ob->query("max_sen"));
  killer->move(environment(ob));
  killer->set("target_id",ob->query("id"));
  ob->set_temp("target_come",1);
  message_vision("ֻ�����һ����$NԾ��������\n",killer);
  message_vision(YEL"$N��$n��Ц�����ҷ�����͢���£��������������\n"NOR,killer,ob);
  killer->kill_ob(ob);
  return 1;
}
