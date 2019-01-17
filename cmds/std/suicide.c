// suicide.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");

	if( !arg || arg != "-f") {
		write("���� suicide -f ȷ����ɱ��\n");
		return 1;
	}
        
        if(environment(me)->query("no_suicide"))
          if(stringp(environment(me)->query("no_suicide")))
           return notify_fail(environment(me)->query("no_suicide"));
          else return notify_fail("���ﲻ׼��ɱ��\n");
	if (!me->query_temp("link_ob"))
		return notify_fail("�㲻���������߽���ģ�������ɱ��\n");
        if(me->query("shili"))
        return notify_fail("����Ϊ���һԱ�������˳��������ɱ�ɣ�\n");
	write(
		"������Ȼ�ն�����Ͼ����ã��벻Ҫ������ɱ��\n"
		"ѡ����ɱ��ζ�������������Ͼ���Զɾ���ˣ�����ؿ��������\n"
		"ȷ���Ļ��������������룺");
	input_to("check_password", 1, me, 1);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n�����Ҫ��ɱ�ˣ���������ˡ�\n\n" NOR);
        CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + "����Ҫ��ɱ�ˡ�");
		me->set_temp("suicide_countdown", 15);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :),
			(: call_other, this_object(), "halt_suicide" :) );
	}
}

private int slow_suicide(object me)
{
	object link_ob;
	int stage;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "�㻹��" + chinese_number(stage+stage) + "�������ʱ�䡣\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	if (me->query("combat_exp") < 20000) {
		rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
		rm( me->query_save_file() + __SAVE_EXTENSION__ );
	} else {
		link_ob->save();
        if (!environment(me)->query("no_save") && !me->is_ghost())
			me->set("startroom", base_name(environment(me)));
		me->save();
		rename( link_ob->query_save_file() + __SAVE_EXTENSION__, link_ob->query_save_file() + ".ooo" );
		rename( me->query_save_file() + __SAVE_EXTENSION__, me->query_save_file() + ".ooo" );
	}
	write("�ðɣ�������:)��\n");
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
   CHANNEL_D->do_channel(this_object(),"rumor",me->short(1) + "��ɱ�ˣ��Ժ�����Ҳ������������ˡ�");
    destruct(link_ob);
	destruct(me);
	return 0;
}

int halt_suicide(object me)
{
	tell_object(me, "���������ɱ����ͷ��\n");
	CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "���������¸ҵػ���ȥ��");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:

suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ѡ�� :)
HELP
);
        return 1;
}
