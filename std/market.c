// market.c
// create by songyun

#include <dbase.h>
#include <ansi.h>



string is_vendor_cargo(string arg)
{
	string *cargo;
	object ob;
	int i;

	if (arrayp(cargo = query("vendor_cargo"))) 
		for (i = 0; i < sizeof(cargo); i++) 
			if (cargo[i]->id(arg))
				return cargo[i];
	return "";
}

int market_des(object arg)
{
	
	object obj;
	int h,w,s,d,market_des;
	obj=arg;
			
	h=(int)environment(this_player())->query("h");
	w=(int)environment(this_player())->query("w");
	
	s=(int)obj->query("s");
	d=(int)obj->query("d");
	
	if((h-s)^2+(w-d)^2<=100)
	market_des=1;
	
	if((h-s)^2+(w-d)^2>100&&(h-s)^2+(w-d)^2<400)
	market_des=2;
	
	if((h-s)^2+(w-d)^2>400&&(h-s)^2+(w-d)^2<=900)
	market_des=3;

	if((h-s)^2+(w-d)^2>900)
	market_des=4;
	
	return market_des;
}
int do_value(string arg)
{
	object ob,carry;
	int value,market_des,val_factor;

	carry=present(this_player()->query_temp("carry"),environment(this_player()));
	if (!carry) return notify_fail("��û�л��\n");

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	
	if (!ob->query("cargo_id"))
		return notify_fail("�г���ֻ�ܸ�������ۡ�\n");

	val_factor = environment(this_player())->query("val_factor");
	market_des=market_des(ob);
	value = ob->query("base_value")*market_des;
	val_factor = this_object()->query("val_factor");
	write(ob->query("name") + "���������ÿ"+ob->query("base_unit")+"ֵ" + 
	MONEY_D->price_str(value * val_factor) + "��\n");
	return 1;
}

int do_sell(string arg)
{
	object ob,ob2;
	int value,amount,market_des,val_factor;
	
	if (!arg)
	return notify_fail("��Ҫ��ʲô��\n");
	
	val_factor=environment(this_player())->query("val_factor");
	if (sscanf(arg,"%s",ob)==1)
	{
		if( !objectp(ob = present(ob, this_player())) )	
			return notify_fail("������û���������\n");
	
		if (!ob->query("cargo_id"))
			return notify_fail("�г���ֻ�ܽ��л��ｻ�ס�\n");
	
		else
		{	
			market_des=market_des(ob);
			value = ob->query("value")*market_des;	
			message_vision("$N������һ" + ob->query("unit") + 
			ob->query("name") + "��$n��\n", this_player(), this_object());
			MONEY_D->pay_player(this_player(), value * val_factor);
			
			if (value < 50)
			destruct(ob);
			else
			ob->move(this_object());
		}
	}

	if(sscanf(arg, "%d %s", amount, ob)==2) 
	{	
		if( !objectp(ob = present(ob, this_player())) )	
			return notify_fail("������û���������\n");
		
		if (!ob->query("cargo_id"))
			return notify_fail("�г���ֻ�ܽ��л��ｻ�ס�\n");
		
		if( amount < 1 )
			return notify_fail("���������������һ����\n");
	
		if( amount > ob->query_amount() ) 
			return notify_fail("��û��������" + ob->name() + "��\n");
		
		
		if( amount == (int)ob->query_amount() )
		{
		
			market_des=market_des(ob);
			message_vision("$N������һ" + ob->query("unit") + 
			ob->query("name") + "��$n��\n", this_player(), this_object());
			MONEY_D->pay_player(this_player(), value * val_factor);
			value = ob->query("value")*market_des;	
			if (value < 50)
			destruct(ob);
		else
			ob->move(this_object());
		}
		
		else 
		{
			market_des=market_des(ob);
			ob->set_amount( (int)ob->query_amount() - amount );
			ob2 = new(base_name(ob));
			ob2->set_amount(amount);
			value = ob2->query("value")*market_des;
			message_vision("$N������һ" + ob->query("unit") + 
			ob->query("name") + "��$n��\n", this_player(), this_object());
			MONEY_D->pay_player(this_player(), value * val_factor);
			
			if (value < 50)
			destruct(ob2);
			else
			ob2->move(this_object());
		}
	
	}	

	else
	{
	return notify_fail("sell <����> <��������>\n");
	}
	return 1;
}

int do_list()
{
	
	string *cargo;
	object *inv;
	int i,market_des;
	
	inv = all_inventory(this_object());
	
	if (!sizeof(inv) && !arrayp(cargo = query("vendor_cargo")))
		return notify_fail("Ŀǰû�п������Ķ�����\n");
	
	printf("�������%s����������Ʒ��\n", query("name"));
	for (i = 0; i < sizeof(inv); i++) 
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		call_out("market_des",inv[i]->query("name"));
		printf("%30-s��%s(%s)\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * market_des * environment(this_player())->query("val_factor")),
		(int)inv[i]->query_amount());
	
	if (arrayp(cargo = query("vendor_cargo")))
		for (i = 0; i < sizeof(cargo); i++)
			printf("%30-s��%s(����)\n", cargo[i]->short(),
			MONEY_D->price_str(cargo[i]->query("value"))* market_des * environment(this_player())->query("val_factor"));
	return 1;
}	

int do_buy(string arg)
{
	int value, val_factor, amount,market_des;
	string ob_file;
	object ob,ob2;
	mapping fam;
	
	if( !arg || sscanf(arg, "%d %s", amount, ob)!=2 )
		return notify_fail("������ʲô������٣�usage:buy <����> <����>\n");
	
	if (!(ob = present(arg, this_object())))
		return notify_fail("�Բ�������û��������Ʒ\n");
	
	if ((ob_file = is_vendor_cargo(arg)) == "")
		return notify_fail("�Բ�������û��������Ʒ\n");

	if((ob = present(arg, this_object()))&&(int)ob->query_amount()<amount)
		return notify_fail("�Բ�������û����ô��\n");

	if(ob = present(arg, this_object()))
	{
			val_factor = environment(this_player())->query("val_factor");
			market_des=market_des(ob);
			ob->set_amount( (int)ob->query_amount() - amount );
			ob2 = new(base_name(ob));
			ob2->set_amount(amount);
			value = ob2->query("value")*market_des;
	switch (MONEY_D->player_pay(this_player(), value * market_des *  val_factor ))
       {
	
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		set_temp("busy", 1);
		message_vision("$N��$n����������"+chinese_number(amount) + ob->query("unit") + 
		ob->query("name") + "��\n", this_player(), this_object());
		ob->move(this_player());
	}
	}
	
	
	
	else 
	{
	
	val_factor = environment(this_player())->query("val_factor");
	ob = new(ob_file);
	ob->set_amount(amount);
	
	
	switch (MONEY_D->player_pay(this_player(), value * market_des *  val_factor ))
	{
	
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		set_temp("busy", 1);
		message_vision("$N��$n����������"+chinese_number(amount) + ob->query("unit") + 
		ob->query("name") + "��\n", this_player(), this_object());
		ob->move(this_player());
	}
	

	return 1;
}
	
}
