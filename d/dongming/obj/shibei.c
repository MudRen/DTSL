

inherit ITEM;

void create()
{
   set_name("ʯ��", ({"shi bei","shi","bei"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʯ����\n");
                set("unit", "��");


        }
}

int is_get_of(object ob,object obj)
{
   ob->set("sen",0);
   ob->set("kee",0);
   return notify_fail("���ʯ��̫���ˣ��㿸��������\n");
}

string long()
{
  object ob;

  ob=this_player();

  if(ob->query("family")||
    ob->query_temp("bai_dongming/action2")
    )
  return query("long");

  call_out("killer_come",20,ob);
  ob->set_temp("bai_dongming/action1",1);
  return query("long")+"��ɽ���ҿ������������ԣ�Ҫ�Ӵ�·����������·�ƣ�\n";
}

void killer_come(object ob)
{
  object killer,guard;
  string msg;

  if(!ob||!living(ob)||
     ob->is_ghost())
  return;

  guard=ob->query_temp("guard_npc");
  if(objectp(guard)&&
     environment(guard)==environment(ob)
    ){
   killer=new(__DIR__"killer");
   killer->move(environment(ob));
   msg="$NͻȻ�ܹ�����$n�ȵ�������Ǯ����������ɣ�\n";
   killer->kill_ob(ob);
   msg+=guard->name()+"����$n��ǰ����$N��Ц������ƾ��������ǿ��Ҳ�뺦�ˣ�\n";
   guard->kill_ob(killer);

   message_vision(msg,killer,ob);

   COMBAT_D->do_attack(guard,killer,guard->query_temp("weapon"),0,2);

   killer->die();

   msg="$N����δ��֮�ʣ�ֻ�����ߵĴ������˽��εε�˵����"+RANK_D->query_respect(ob)+"Ϊʲô������׷���أ�\n";
   msg +="$N�������л����֮������ֻ��·����ȴ���������١�\n";
   msg +="���˼����ʵ���"+RANK_D->query_respect(ob)+"�պ��кδ��㣿\n";
   msg +="$N��ͷ����û�����㡣\n";
   msg +="���˵������������Ա�ɣ�\n";
   message_vision(msg,ob);
   ob->set_temp("bai_dongming/action2",1);

  }
  return;
}
