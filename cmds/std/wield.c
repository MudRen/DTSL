// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫװ��ʲ��������\n");
	
	if(me->is_busy())
	 return notify_fail("����æ���أ�\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");
        if(!ob->is_wield_of(me,ob))
        return ob->is_wield_of(me,ob);
	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;
        
        if(ob->query("wield_str")&&!ob->query("no_need_sx")){
         if(me->query_str()<ob->query("wield_str")-ob->query("reduce_sx"))
         return notify_fail("��ı���̫���ˣ�\n");
        }
        
        if(ob->query("wield_force")
        &&!ob->query("no_need_force")
        &&me->query("force")<ob->query("wield_force")-ob->query("reduce_force")
          )
         return notify_fail("�������������\n");
        
        if(ob->query("wield_maxforce")
        &&!ob->query("no_need_maxforce")
        &&me->query("max_force")<ob->query("wield_maxforce")-ob->query("reduce_maxforce")
          )
         return notify_fail("������������Ϊ������װ���˱�����\n");
        
        if(ob->query("wield_dex")
        &&!ob->query("no_need_sx")
        &&me->query_dex()<ob->query("wield_dex")-ob->query("reduce_sx")
          )
         return notify_fail("�����̫���ˣ�\n");
       
        if(ob->query("wield_con")
        &&!ob->query("no_need_sx")
        &&me->query_con()<ob->query("wield_con")-ob->query("reduce_sx")
          )
         return notify_fail("��ĸ���̫���ˣ�\n");
        
        if(ob->query("wield_int")
        &&!ob->query("no_need_sx")
        &&me->query_int()<ob->query("wield_int")-ob->query("reduce_sx")
          )
         return notify_fail("�������̫���ˣ�\n");
         
	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
		message_vision(str, me, ob);
		
		if(me->is_fighting())
			me->start_busy(1+random(1));
		
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wield <װ������>
 
���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}
