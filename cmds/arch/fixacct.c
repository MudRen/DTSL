//Cracked by Kafei
// fixacct.c

#include <ansi.h>
#define SYNTAX	"ָ���ʽ��fixacct [<δ��������>]\n"

inherit F_CLEAN_UP;

private int do_fixacct(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%d", day) && day >= 30)
		return do_fixacct(day);
	else
		return notify_fail("ֻ��������ʮ��ǰ�Ǽǵ��ʺš�\n");
}

private int do_fixacct(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	object ob;

	seteuid(getuid());
	message("system", "\n*** ������Ҵ��浵�У����Ժ�.... ***\n", users());
	write("�����У�");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s.o", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			if( (time()-(int)info[1])/86400 >= day ) {
				ob = new(LOGIN_OB);
				ob->set("id", name);
				if (!ob->restore())
					continue;
				if (!ob->query("last_from") &&
					!ob->query("last_on")) {
					rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
					rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
					write(name + "\n");
					count ++;
				}
				destruct(ob);
			}
		}
	}
	write("\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
	write( count + " ������ " + day + " ��δ�Ǽǵ�ʹ���߱�������ˡ�\n");
	write("�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n");
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who registered incorrectly\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, ppl_cnt - count));

	return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ��fixacct [<δ��������>]

����Ǽ�ʧ�ܵ��û���
HELP
	);
    return 1;
}
