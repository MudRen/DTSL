inherit F_CLEAN_UP;
int main(object me)
{
	me->start_more( read_file("/log/meeting"));
	return 1;
}
int help(object me)
{
	write(@HELP
���ָ�����㿴����Ļ����¼��
HELP
	);
	return 1;
}

