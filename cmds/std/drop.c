// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
                
	if(!arg) return notify_fail("��Ҫ����ʲ�ᶫ����\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;
        
        object env,*same_obj;
        int i;
        
        env=environment(me);
	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
	
	same_obj=all_inventory(env);
	if(sizeof(same_obj)>30)
	return notify_fail("���ﶫ��̫���ˣ��㻹�ǵ����Ӷ����ɣ�\n");
			if(obj->query("money_id")&&sizeof(same_obj)>1)
			for(i=0;i<sizeof(same_obj);i++){
			if(same_obj[i]==me) continue;
			if(same_obj[i]->is_character()) continue;
			if(base_name(same_obj[i])==base_name(obj)&&
			   same_obj[i]->query("name")==obj->query("name")&&
			   same_obj[i]->query_amount()&&obj->query_amount()){
			   obj->set_amount(same_obj[i]->query_amount()+
			                          obj->query_amount());
			                          destruct(same_obj[i]);
			                          break;} }

	if (obj->move(environment(me))) {
		if( obj->is_character() )
			message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
		else {
			message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),
				me, obj );
			
			me->save();
			if( !obj->query("value") && !obj->value() ) {
				write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}
 
