#include <dbase.h>
#define MARKETPLACE "/d/clone/room/paimai/paimaiwu"
#define SELLOR "/d/clone/room/paimai/paimaishi"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,obj;
	int argg;
	int invisibility_buyer;
	int number;
	int value;

	seteuid( geteuid(me) );

	if( me->is_busy() ) return notify_fail("������û�пգ�\n");
	if( !arg )
		return notify_fail("ָ���ʽ��bid <����>\n");

	if( sscanf(arg, "-i %s", arg) ) invisibility_buyer = 1;

	if( !arg )
		return notify_fail("ָ���ʽ��bid <����>\n");

	sscanf(arg,"%d for %d",argg,number);

//����ʦ���õ�·��
	if( !(room=find_object(MARKETPLACE)) )
		room= clone_object(MARKETPLACE);
	
	if( !(obj=present("paimai shi",room)) )
	{
		obj=new(SELLOR);
		obj->move(MARKETPLACE);
		return notify_fail("����ʦ���ڸ�������û����������\n");
	}

	else
	{
		if( !(obj->query("on_paimai")) ) 
			return notify_fail("����û����������\n");
	}

	if( me->query_condition("auction_forbindden") )
		return notify_fail("��Ŀǰ�����ܲ����������\n");
	if( invisibility_buyer)
		me->set_temp("invisibility_buyer",1);
	else
		me->set_temp("invisibility_buyer",0);
    
	if(!number)
		number = obj->query("number");

	if(number>obj->query("number"))
		return notify_fail("Ŀǰ��û�п�ʼ�����Ʒ������\n");
//    if(obj->query("ipaimai/"+sprintf("%d",number))=="paimai shi")
	if(number<obj->query("number"))
	   return notify_fail("���������������Ѿ������ˡ�\n");
	
	value = obj->query("vpaimai/"+sprintf("%d",number));

	if( argg <= value*21/20 )
	{
		tell_object(me,"�����̫�͡�\n");
		return notify_fail("������"+chinese_number(value)+"�����ӣ�\n");
	}
    if(argg < 0 || argg > 1000000)
		return notify_fail("����ļ۸��ǷǷ��ġ�\n");
	if( argg*105 > me->query("deposit") )
		return notify_fail("��û����ô��Ĵ�\n");
	obj->report_paimai(me,argg,number);
	tell_object(me,"�����"+chinese_number(argg)+"�����ӣ�\n");

	me->start_busy(2);

	return 1;

}

int help(object me)
{
   write( @HELP
ָ���ʽ: bid <����> 

��һָ��������Բ���Ͷ�꣬��λΪ �����ӡ�
HELP
   );
   return 1;
}
 