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
	if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tail <档案>

此指令可让你(□)直接读取某档案最末尾的几行。
HELP
    );
    return 1;
}
