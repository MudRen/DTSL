//last modify by mudadm

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;
	object ob, *guards;
	mixed old_target;

        if( ( me->is_busy() || me->is_fighting()
           || me->query_temp("guardfor")) && arg
           && arg != "none" )
		return notify_fail("������û�а취����ȥ�������£�\n");
        if(me->query("pker"))
        return notify_fail("��Ϊͨ����������ʵһЩ�ɣ�\n");
	old_target = me->query_temp("guardfor");

	if( !arg || arg=="" ) {
		if( !old_target )
                        return notify_fail("ָ���ʽ��guard <����>|<��Ʒ>\n");
		if( objectp(old_target) )
			if( living(old_target) )
				write("�������ػ���" + old_target->name() + "��\n");
			else
				write("��������" + old_target->name() + "һ�ԣ���ֹ�������ߡ�\n");
		return 1;
	}

	ob = present(arg, environment(me));

	if( ob ) {
		if( ob==me ) return notify_fail("�����Լ�������˵��Ҳ�������԰ɡ�\n");
		if(ob->query("pker"))
		return notify_fail("�κ��˲��ܱ���ͨ������\n");
		me->set_temp("guardfor", ob);
	}

        else if( arg!= "none" )
                return notify_fail("��Ҫ����˭��ʲ�᣿\n");

        if( objectp(old_target) ) {
		guards = old_target->query_temp("guarded");
		guards -= ({ me });
		old_target->set_temp("guarded", guards);
        }  


        if( arg=="none" ) {

	if( objectp(old_target) ) {

       tell_object( old_target, me->name() + "���ٱ������ˡ�\n");
       tell_object(me,"��������ڱ���"+old_target->name()+"�ˣ�\n");
       me->delete_temp("guardfor");
       old_target->reduce_temp_array("guarded",me);
       me->set_leader(0);
       write("Ok.\n");
       return 1;
	}
       else
    {
       tell_object(me,"��������ٱ������ˡ�\n");
       me->delete_temp("guardfor");
       me->set_leader(0);
       write("Ok.\n");
       return 1;
    }
 }
	if( objectp(ob) ) {

                ob->add_temp("guarded", ({ me }) );
		if( living(ob) )
                    {
                       message_vision("$N��ʼ����$n��\n", me, ob);
                       me->set_leader(ob);
                    }
		else
                       message_vision("$Nվ�����ϵ�$nһ���������������ȡ�ߡ�\n", me, ob);
	return 1;
}
}
int help(object me)
{
	write(@TEXT
ָ���ʽ��guard [<ĳ��>|<����ĳ��>|none]

���ָ�����������÷�ʽ���ֱ����᣺

guard <ĳ��>      ����<ĳ��>�����������ܵ�����ʱ�������߻��Զ�����ս��������
                  �ܹ�����˳λ�����ڱ�������ǰ�棬���ֻ�й���˳λǰ�ĸ�Ŀ��
                  �Ż��ܵ����������������������ĸ���  guard �㣬��Ͳ�����
                  ���κι�����

guard <����ĳ��>  ��ס���ڵ��ϵ�ĳ����������ֹ�������ã�ֻҪ�㻹��������䣬
                  ����û��æ�������£����˾��޷��������������

guard none        ȡ����ǰ�� guard ����
guard             �����κβ�������ʾ��Ŀǰ guard �Ķ���

ע�⣬ͨ������ guard <ĳ��> ���������⣬ֻҪ��һ�ƶ���guard ��״̬�ͻ�����
����ͨ�������޷��������˵ġ�
TEXT
	);
	return 1;
}
