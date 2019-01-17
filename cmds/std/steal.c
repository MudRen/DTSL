// steal.c

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        int sp, dp;
        if( environment(me)->query("no_fight")||
            environment(me)->query("sleep_room")||
            environment(me)->query("no_steal") )
                return notify_fail("�����ֹ���ԡ�\n");

        if( me->query_temp("ridee") )
          return notify_fail("�㻹����������!\n");

        if( me->query_temp("stealing") )
                return notify_fail("���Ѿ����һ��������ˣ�\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me) return 
	notify_fail("�������ԵĶ��������\n");
	if( userp(victim) && !living(victim))
	return notify_fail("�㲻��͵�ε������ϵĶ�����\n");
if(userp(victim)&&victim->query("no_steal"))
return notify_fail("�����ڲ���͵���Ķ���\n");
	if( ! victim->is_character())
	return notify_fail("����ã������������������������������\n");
	if( !wizardp(me) && wizardp(victim) )
                return notify_fail("�㲻��͵���������ϵĶ�����\n");
	
        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + 
"���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
                inv=filter_array(inv,(:!$1->query("no_steal"):));
                inv=filter_array(inv,(:!$1->query("no_give"):));
                inv=filter_array(inv,(:!$1->query("nogive_player"):));
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + 
"���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
                ob = inv[random(sizeof(inv))];
        }
        if(ob->query("no_steal")||
        ob->query("no_give")||
        ob->query("nogive_player")
          )
        return notify_fail("�Ǹ���������͵��\n");
        sp =(int)me->query_kar() * (int)me->query_kar()/3;
        if( sp < 1 ) sp = 1;
        if( me->is_fighting() ) {
                sp /= 2;
                me->start_busy(3);
        }
        dp = (int)victim->query_dex() * (int)victim->query_dex()/5  + (int)ob->weight();
        if( victim->is_fighting() ) dp *= 10;
        if( ob->query("equipped") ) dp *= 10;

        write("\n�㲻����ɫ����������" + victim->name() + "���ȴ��������� 
...\n\n");

        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

        return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int 
dp)
{
  
  me->delete_temp("stealing");

	if(!victim){
  	tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ������ˡ�\n");
    return;
  }
  if( environment(victim) != environment(me) ) {
  	tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
    return;
  }
	if((int)ob->query("no_get")) {
		tell_object(me,"��͵�����Ǹ�������\n");
		return;
	}
  if( (!living(victim) || (random(sp+dp) > dp) )
  		&&(random(me->query("combat_exp")+800000)>victim->query("combat_exp"))) {
  	if( !ob->move(me) ){
    	tell_object(me, "������һ" + ob->query("unit") + ob->name() 
                        + "�����Ƕ������̫���ˣ����ò�������\n");
      return;
    }
    tell_object(me, HIW "�����ˣ�\n\n" NOR);
    tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");
    if( living(victim) )
    	if( random(sp) > dp/2 )
      	message("vision", "�㿴��" + me->name() + "�������ش�"
                         + victim->name() + "����͵����һ" + ob->query("unit")
                         + ob->name() + "��\n", environment(me), ({me, victim }) );
				ob->do_steal(me);
  } 
  else{
  	if( random(sp) < dp/2 ) {
    	tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
                      "���ã�û�б����֡�\n");
    	return;
    }
    tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
    message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
                   + "$N�ȵ�������ʲ�ᣡ��\n\n", victim, me);
    if( userp(victim) ) victim->fight_ob(me);
    else victim->kill_ob(me);
    me->fight_ob(victim);
    me->start_busy(5);
    me->add("thief", 1);
  }
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �����ʲ�����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
 
