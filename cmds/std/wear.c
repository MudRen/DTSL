// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲ�᣿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;
        
        if(ob->query("wear_str")&&!ob->query("no_need_sx")){
         if(me->query_str()<ob->query("wear_str")-ob->query("reduce_sx"))
         return notify_fail("��ı���̫���ˣ�\n");
        }
        
        if(ob->query("wear_force")
        &&!ob->query("no_need_force")
        &&me->query("force")<ob->query("wear_force")-ob->query("reduce_force")
          )
         return notify_fail("�������������\n");
        
        if(ob->query("wear_maxforce")
        &&!ob->query("no_need_maxforce")
        &&me->query("max_force")<ob->query("wear_maxforce")-ob->query("reduce_maxforce")
          )
         return notify_fail("������������Ϊ������װ���˱�����\n");
        
        if(ob->query("wear_dex")
        &&!ob->query("no_need_sx")
        &&me->query_dex()<ob->query("wear_dex")-ob->query("reduce_sx")
          )
         return notify_fail("�����̫���ˣ�\n");
       
        if(ob->query("wear_con")
        &&!ob->query("no_need_sx")
        &&me->query_con()<ob->query("wear_con")-ob->query("reduce_sx")
          )
         return notify_fail("��ĸ���̫���ˣ�\n");
        
        if(ob->query("wear_int")
        &&!ob->query("no_need_sx")
        &&me->query_int()<ob->query("wear_int")-ob->query("reduce_sx")
          )
         return notify_fail("�������̫���ˣ�\n");
        
	if( ob->query("female_only")
	&&	(string)me->query("gender") != "Ů��" )
		return notify_fail("����Ů�˵Ķ�������һ��������Ҳ���ã���Ҳ���ߣ�\n");
        if( ob->query("male_only")
	&&	(string)me->query("gender") != "����" )
		return notify_fail("�������˵Ķ�������һ��Ů�˼�Ҳ���ã���Ҳ���ߣ�\n");
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "waist":
					str = YEL "$N��һ" + ob->query("unit") + "$n" +  "�������䡣\n" NOR;
					break;
				default:
					str = YEL "$Nװ��$n��\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wear <װ������>
 
���ָ������װ��ĳ�����ߡ�
 
HELP
    );
    return 1;
}
