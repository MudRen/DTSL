// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

//bankowner.c


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
        if(from==to)
        return notify_fail(this_object()->query("name")+"�۾�һ�ɣ���ô���뵷���𣿣�\n");
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
int do_check(string arg)
{
	int value;
	value= (int) this_player()->query("deposit");
        if(value == 0){
        tell_object(this_player(),"������û�д�\n");
	return 1;
	}
	tell_object(this_player(),"�����ڹ��д��"+MONEY_D->money_str(value)+"\n");
	return 1;
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
	int amount;string str;int i;
	int hamount;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܴ�Ǯ��\n");
        if( !arg || sscanf(arg, "%d %s", amount,str)!=2 )
                return notify_fail("ָ���ʽ��withdraw <����> <��������>\n");
        if(str!="coin"&&str!="silver"&&str!="gold")
         return notify_fail("��ֻ��ȡͭǮ���������ƽ�\n");
	hamount = (int) this_player()->query("deposit");
	if(amount <=0 )
		return notify_fail("ָ���ʽ��withdraw <����> \n");
        if(amount>10000)
         return notify_fail("��һ��ȡ��ô������������ɣ�\n");
	i=amount;
	if(str=="silver") amount=amount*100;
	else if(str=="gold") amount=amount*10000;
	if(amount>1000000)
	return notify_fail("��һ��ȡ��ô������������ɣ�\n");
		if(amount>hamount) 
		return notify_fail("��û��ô���� ����\n");
	if(str=="silver") str="����";
	else if(str=="gold") str="�ƽ�";
	else str="ͭǮ"; 
	hamount -=amount;
	this_player()->set("deposit", hamount);
	pay_player(this_player(), amount);
	if(str!="ͭǮ")
	tell_object(this_player(),"��ȡ����"+chinese_number(i)+"��"+str+"\n");
	else tell_object(this_player(),"��ȡ����"+chinese_number(i)+"��"+str+"\n");
	this_player()->start_busy(1);
	return 1;

}
int do_loan(string arg)
{
        int amount;
        int hamount;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܽ�Ǯ��\n");
        if( !arg || sscanf(arg, "%d", amount)!=1 )
                return notify_fail("ָ���ʽ��loan <����> \n");
        hamount = (int) this_player()->query("deposit");
	if(hamount > 0 ) return notify_fail("�㻹�д�\n");
        if(amount <=0 )
                return notify_fail("ָ���ʽ��loan <����> \n");
	if((int)this_player()->query("combat_exp") < amount - hamount)
			return notify_fail("��費����ô��Ǯ������\n");
        hamount -=amount;
        this_player()->set("deposit", hamount);
        pay_player(this_player(), amount);
        tell_object(this_player(), "�ϣ� \n");
	this_player()->start_busy(1);
        return 1;

}

