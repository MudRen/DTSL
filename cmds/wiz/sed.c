// /cmds/wiz/sed.c
//
// lanxin@jianghu

inherit F_CLEAN_UP;
inherit F_SED;				// �̳б༭����
inherit F_CMD;


int main(object me, string arg)
{
	string file;
	object ob;
	
	if (in_edit(me)) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
	if (!arg) return notify_fail("ָ���ʽ��me <����>|<�����>\n");
	
	seteuid(geteuid(me));
	file = resolve_path(me->query("cwd"), arg); // ȡ�õ���
	if (file_size(file) < 0)
	{	// �µ�
		ob = present(arg, me);	// ������ϵ����
		if (!ob) ob = present(arg, environment(me)); // ��鷿��������
		if (ob && me->visible(ob))
			file = base_name(ob) + ".c"; // ȡ������ĵ���
	}
	
	start_edit(file);		// ���б༭������ʼ�༭
	return 1;
} // main()


int  help(object me)
{
	write(@HELP
ָ���ʽ��sed <����>|<�����>

���ô�һָ���ֱ�������ϱ༭��������ϸ˵���뿴�༭���ڵ����ϸ���˵����

���ָ�edit��update��
HELP
		);
	return 1;
} // help()
