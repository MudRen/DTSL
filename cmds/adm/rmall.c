//by dsm 5/1/99

inherit F_CLEAN_UP; 
int main(object me, string arg) 
{ 

	int i, j; 
	string dir; 
	mixed *file; 
         
        seteuid( geteuid(me) ); 

	dir = resolve_path(me->query("cwd"), arg); 
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/"; 
	file = get_dir(dir, -1); 
	if( !sizeof(file) ) {
		if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n"); 
			else return notify_fail("û�����Ŀ¼��\n"); 
		} 

	i = sizeof(file); 

	for(i=0, j = sizeof(file); i<j; i++) 
	{ 
		rm(dir+file[i][0]); 
                } 
	rmdir(dir);
	write("Ŀ¼" + dir + "   ɾ����.\n"); 

	return 1; 
} 
