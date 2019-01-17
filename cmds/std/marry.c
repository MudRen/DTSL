
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object who;

  
   if(me->query("age")<21)
   return notify_fail("������̫С�ˣ��ȵȰɣ�\n");
   if (!arg) return notify_fail("��Ҫ�޸�˭��\n");

   if (me->query("gender")=="����")
     return notify_fail("ֻ��Ů�˲��ܴ�Ӧ���˵���飡\n");

   if (!me->query("proposed"))
     return notify_fail("�ţ�û��������鰡��\n");

   if (!objectp(who=present(arg,environment(me))))
     return notify_fail("����û������ˡ�\n");

   if (!who->is_character())
     return notify_fail("�������"+who->name()+"��ʲôѽ��\n");

   if (who==me)
     return notify_fail("��ʲô��Ц������\n");

   if (!living(who))
     return notify_fail("��...�㻹���Ȱ�"+who->name()+"Ū�Ѱɡ�\n");

   if (me->query("propose_man")!=getuid(who))
     return notify_fail("�ţ�"+who->name()+"û��������鰡��\n");
   

   if (who->query("propose_target")!=getuid(me))
     return notify_fail("�Բ���"+who->name()+"�Ѿ��ı����ⲻ��������ˡ�\n");

   message_vision("$N��ͷ���˻ᣬ���ߴ���˵�����ðɣ�\n",me,who);
   me->set_temp("marry",who);
   who->set_temp("marry",me);

   who->delete("proposing");
   who->delete("propose_target");
   who->set("waiting_marry",1);
   who->set("partner", getuid(me));

   me->delete("proposed");
   me->delete("propose_man");
   me->set("waiting_marry",1);
   me->set("partner", getuid(who));

   return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : marry <ĳ��>
 

 
HELP
    );
    return 1;
}
