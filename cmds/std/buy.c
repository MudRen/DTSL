// buy.c

inherit F_CLEAN_UP;

#define EVENT_D "/obj/event.c"

int buy_object(object me,object owner, string item);
int main(object me, string arg)
{
	string item, targ;
	object ob, owner;
	int price, afford;
	object* inv;

    if( this_player()->is_busy() )
			return notify_fail("��������æ���ء�\n");

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭������\n");

	if( userp(owner) ) {
		message_vision("$N����$n����" + item + "����\n", me, owner);
	        notify_fail("�Է�����Ը����㽻�ס�\n");
		return 1;
	}
        if(owner->do_buy(item)) return 1;
	price=buy_object(me,owner,item);
	if( price < 1 ) return 0;
        switch(MONEY_D->player_pay(me, price)){
        	
		case 0: return notify_fail("�����ϴ���Ǯ������!\n");
		case 2: return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		}
        me->start_busy(1);
	return (int)owner->complete_trade(me, item);

}
int buy_object(object me, object owner,string what)
{
   string ob;
   object vendor;
   int i;
   int trade_skill;

   if( stringp(ob = owner->query("vendor_goods/" + what)) ){
     vendor=new(ob);
     i=ob->query("value");
     
     i=EVENT_D->get_trade_value(ob,i);
     trade_skill = me->query_skill("trade",1);
     if(trade_skill>300)
     	trade_skill = 300;
     
     i=i-i*trade_skill/(1200);
     if(i<=0) i=5;
     destruct(vendor);
     return i;}
   else
     return 0;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: buy <something> from <someone>

��һָ��������Դ�ĳЩ����������Ʒ��
HELP
   );
   return 1;
}
