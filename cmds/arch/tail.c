// tail.c

inherit F_CLEAN_UP;

int help(object me);

int tail(string path)
{
	if (stringp(path) && file_size(path) >= 0)
	{
		write(read_file(path, file_length(path) - 9));
		return 1;
	}

	return 0;
}

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : tail <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ������ĩβ�ļ��С�
HELP
    );
    return 1;
}
