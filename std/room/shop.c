// hockshop.c

inherit ROOM;
#define MAX_PAWN 50
void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");

}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
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

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	value = ob->query("value");
	if( !value ) printf("%sһ�Ĳ�ֵ��\n", ob->query("name"));
	else 
		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), value_string(value),
			value_string(value * 25 / 100), value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value,  pawn_count, i;
	int rvalue;
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
	write("��Ŀǰ�䵱����Ʒ�У�\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\tû���κε䵱����Ʒ��\n");
	else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-5s��  %-15s  ������%O\n", terms[i], pawn[terms[i]],
			value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");

	value = ob->query("value");
	if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
                        for(i=0; i<sizeof(terms); i++)
                        {
                        pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
                        }
                }
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ value_string(value * 25 / 100) + "��\n", this_player());

	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲ����Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	value = ob->query("value");
	if( !value ) return notify_fail("����������ֵǮ��\n");


	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());

	pay_player(this_player(), value  * 80 / 100);
	destruct(ob);

	return 1;
}
void pay_him(object who, int amount)

{
	object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
	if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


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

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                ob->move(me);
                me->delete("pawn/"+sprintf("%d",num));
                me->delete("vpawn/"+sprintf("%d",num));
                me->delete("fpawn/"+sprintf("%d",num));
		me->save();
                message_vision("$N�����$n��\n", me, ob);
                return 1;
        } else
                return notify_fail("���Ǯ������\n");

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

int do_withdraw(string arg)
{
	int amount;
	int hamount;
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("ָ���ʽ��withdraw <����> \n");
        if(amount <=0 )
                return notify_fail("ָ���ʽ��withdraw <����> \n");
	hamount = (int) this_player()->query("deposit");
	if(amount>hamount) 
		return notify_fail("��û��ô���� ����\n");
	hamount -=amount;
	this_player()->set("deposit", hamount);
	pay_player(this_player(), amount);
	tell_object(this_player(), "�ϣ� \n");
	return 1;

}
