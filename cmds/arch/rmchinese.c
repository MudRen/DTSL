inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��rmchinese <Ӣ��>\n");

	if( sscanf(arg, "<%s>", key)==1 ) {
		CHINESE_D->remove_translate(key);
		write( "remove " + key + "\nOk.\n");
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
ָ���ʽ��rmchinese <Ӣ��>
HELP
	);
	return 1 ;
}
