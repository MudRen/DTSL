// bank.c

inherit ROOM;

void init()
{
	add_action("do_convert", "convert");
	add_action("do_deposit", "deposit");
	add_action("do_balance", "balance");
	add_action("do_withdraw", "withdraw");
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
        if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܶһ�Ǯ��\n");
	if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
		return notify_fail("ָ���ʽ��convert <����> <��������> to <��������>\n");

	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());
	if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
		return notify_fail("����һ���һ��Ǯ��\n");

	if( !from_ob )		return notify_fail("������û�����ֻ��ҡ�\n");
	if( amount < 1 )	return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");
		
	if( (int)from_ob->query_amount() < amount )
		return notify_fail("������û�������" + from_ob->query("name") + "��\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 )	return notify_fail("��Щ" + from_ob->query("name") + "�ļ�ֵ̫���ˣ�������\n");
        from_ob->add_amount(-amount);
	if( !to_ob ) {
		to_ob = new("/obj/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		this_player() );
	this_player()->start_busy(1);
	return 1;
}


int do_deposit(string arg)
{
	int bv,amount;
	int damount;
	string type;
	object type_ob;
        if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܴ�Ǯ��\n");
        if( !arg || sscanf(arg, "%d %s", amount, type)!=2 )
                return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	if( amount <= 0)
		return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	type_ob = present(type + "_money", this_player());
        if( !type_ob)          return notify_fail("������û�����ֻ��ҡ�\n");
        if( (int)type_ob->query_amount() < amount )
                return notify_fail("������û�������" + type_ob->query("name") + "��\n");
        bv = type_ob->query("base_value");
        if( !bv ) return notify_fail("���ֶ�����ֵǮ��\n");
	damount = (int) this_player()->query("deposit");
	damount += amount * bv;
	this_player()->set("deposit", damount);
	type_ob->add_amount(-amount);
	message_vision(sprintf("$N������%s%s%s��\n",
	chinese_number(amount), type_ob->query("base_unit"), type_ob->query("name")), this_player());
	this_player()->start_busy(1);
	return 1;

}
int do_balance(string arg)
{
	int value;
	value= (int) this_player()->query("deposit");
	tell_object(this_player(),"�����ڹ��д�\n");
        if( value < 100 )
		{
		tell_object(this_player(),chinese_number(value)+"��Ǯ��\n");
                return 1;
		}
        else
			{
		tell_object(this_player(), chinese_number(value/100) + "��"
	+ (value%100? "��" + chinese_number(value%100) + "��Ǯ��": "") + "\n");
			return 1;
			}
}

void pay_player(object who, int amount)

{
	object ob;


	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}
int do_withdraw(string arg)
{
	int amount;
	int hamount;
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("ָ���ʽ��withdraw <����> \n");
	hamount = (int) this_player()->query("deposit");
	if(amount <=0 )
		return notify_fail("ָ���ʽ��withdraw <����> \n");
	if(amount>hamount) 
		return notify_fail("��û��ô���� ����\n");
	hamount -=amount;
	this_player()->set("deposit", hamount);
	pay_player(this_player(), amount);
	tell_object(this_player(), "�ϣ� \n");
	return 1;

}
