inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
  object me;
  object where = environment(who);
  object rider;
  object ridee;

  if( who->is_fighting())
   return notify_fail ("���ȴ�����˵�ɣ�\n");

  if (! arg ||
      ! where ||
      ! (me = present(arg,where)) ||
      ! me->query("ride/msg"))
    return notify_fail ("������ʲô��\n");

  ridee = who->query_temp("ridee");
  if (ridee &&
      environment(ridee) != environment(who))
   ridee = 0;

  if (ridee)
    return notify_fail ("���Ѿ�"+ridee->query("ride/msg")+"��"+ridee->name()+"���ˣ�\n");

  if (me->query_temp("owner")
  &&  me->query_temp("owner") !=  who->query("id") )
    return notify_fail ("�㲻����"+me->name()+"�����ˣ�\n");

  rider = me->query_temp("rider");
  if (rider &&
      environment(rider) != environment(me))
   rider = 0;

  if (rider)
    return notify_fail (me->name()+"���������ˣ�\n");

  message_vision ("$N������һ���������ȵ�"+me->query("ride/msg")+"��$n�ϣ�\n",who,me);
  me->set_temp("no_return",1);
  me->set_temp("rider",who);
  me->set_temp("owner",who->query("id"));
  who->set_temp("ridee",me);
  me->move(where);
  who->set_temp("ride/dodge",me->query("ride/dodge"));
  who->add_temp("apply/dodge",me->query("ride/dodge"));
  return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : qi <��������>
���ָ����������ﵽ�������ϡ�
���ָ��: xia

HELP
);
  return 1;
}
