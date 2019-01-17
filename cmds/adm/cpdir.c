// cpdir.c
// by dsm @Jianghu 5/7/99
 
inherit F_CLEAN_UP;
int do_copy(object me,string src,string dst);
//private void confirm_dest(string yn, object ob,string dst);
int main(object me, string arg)
{
	string src,dst;
	mixed *file; 

	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cpdir <ԴĿ¼> <Ŀ��Ŀ¼> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(src)!=-2 ) return notify_fail("û��ԴĿ¼\n");

	if( src[strlen(src)-1] != '/' ) src += "/"; 
	file = get_dir(src,-1); 
	if( !sizeof(file) ) return notify_fail("ԴĿ¼�ǿյġ�\n"); 

	if( file_size(dst)==-2 ) {
        	write("Ŀ��Ŀ¼�Ѵ���,ͬ���ļ����ᱻ����,�Ƿ����[y/n]?");
        	input_to( "confirm_dest",1,me,src,dst );
	}else do_copy(me,src,dst);
	return 1;
}
 
private void confirm_dest(string yn, object me,string src,string dst)
{
	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�������.\n");
		return;
	}else do_copy(me,src,dst);
}

int do_copy(object me,string src,string dst)
{
	int i,j;
	mixed *file; 

	file = get_dir(src,-1); 

	mkdir(dst);
	if( dst[strlen(dst)-1] != '/' ) dst += "/"; 

	for(i=0, j = sizeof(file); i<j; i++) 
	{ 
		cp(src+file[i][0], dst+file[i][0]);
	} 
	write("ok.\n");
	return 1; 
} 
 
int help(object me)
{
  write(@HELP
ָ���ʽ : cpdir <ԴĿ¼> <Ŀ��Ŀ¼>
 
HELP
    );
    return 1;
}
