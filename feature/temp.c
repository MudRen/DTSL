
#define MAX_PAWN 79

string value_string(int value)
{
	if (value < 1)
		value = 1;
	else if (value < 100)
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value / 100) + "��" + (value % 100 ? "��" + chinese_number(value % 100) + "��Ǯ" : "");
}

void pay_him(object who, int amount)
{
	object ob;
	object cash, tencash, gold, silver, coin;
	tencash = present("tenthousand-cash_money", who);
	cash = present("thousand-cash_money", who);
	gold = present("gold_money", who);
	silver = present("silver_money", who);
	coin = present("coin_money", who);
	if (tencash)
		destruct(tencash);
	if (cash)
		destruct(cash);
	if (gold)
		destruct(gold);
	if (silver)
		destruct(silver);
	if (coin)
		destruct(coin);

	if (amount < 1)
		amount = 1;
	if (amount / 1000000)
	{
		ob = new (TECASH_OB);
		ob->set_amount(amount / 1000000);
		ob->move(who);
		amount %= 1000000;
	}
	if (amount / 100000)
	{
		ob = new (THCASH_OB);
		ob->set_amount(amount / 100000);
		ob->move(who);
		amount %= 100000;
	}
	if (amount / 10000)
	{
		ob = new (GOLD_OB);
		ob->set_amount(amount / 10000);
		ob->move(who);
		amount %= 10000;
	}
	if (amount / 100)
	{
		ob = new (SILVER_OB);
		ob->set_amount(amount / 100);
		ob->move(who);
		amount %= 100;
	}
	if (amount)
	{
		ob = new (COIN_OB);
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
	gold = present("gold_money", me);
	silver = present("silver_money", me);
	coin = present("coin_money", me);

	total = 0;
	if (tencash)
		total += tencash->value();
	if (cash)
		total += cash->value();
	if (gold)
		total += gold->value();
	if (silver)
		total += silver->value();
	if (coin)
		total += coin->value();

	if (total < amount)
		return 0;

	return total;
}

int do_pawn(string arg)
{
	object ob;
	string term,*terms, *vterms, *fterms;
	string data, p_c;
	int value, pawn_count=0, i,j;
	int rvalue;
	mapping pawn,vpawn,fpawn;
	object me;
	me = this_player();
	pawn = me->query_pawn();
        vpawn = me->query_vpawn();
        fpawn = me->query_fpawn();

	if( !arg || !(ob = present(arg, this_player())) )
	{
	write("��Ŀǰ�䵱����Ʒ�У�\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\tû���κε䵱����Ʒ��\n");
	else {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-3s��  %-15s  ������%s\n", terms[i], pawn[terms[i]],
			value_string(vpawn[vterms[i]]));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");

	value = ob->query("value");
	if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        if(sizeof(vterms) > MAX_PAWN)
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
                }
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	p_c = sprintf("%d",time()%10000);
	me->set_pawn(p_c, term);
        me->set_vpawn(p_c, value);
        me->set_fpawn(p_c, data);

	me->save();
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ value_string(value * 25 / 100) + "��\n", this_player());

	MONEY_D->pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_redeem(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        object me;
	string term, *terms;
	mapping pawn,vpawn,fpawn;
        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
	pawn = me->query_pawn();
	vpawn=me->query_vpawn();
	fpawn=me->query_fpawn();
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = fpawn[arg];
                ob = new(ob_file);
                ob->move(me);
		me->delete_pawn(arg);
                me->delete_vpawn(arg);
                me->delete_fpawn(arg);

		me->save();
                message_vision("$N�����$n��\n", me, ob);
                return 1;
        } else
                return notify_fail("���Ǯ������\n");

}
