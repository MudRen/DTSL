// file.c

void cat(string file)
{
	write(read_file(file));
}

int is_root(mixed ob)
{
        if (stringp(ob))
               return (SECURITY_D->get_status(ob) == "(admin)");

        if (objectp(ob))
        {
                if (geteuid(ob) == ROOT_UID)
                        // Root object want to execute
                        return 1;

                return (SECURITY_D->get_status(geteuid(ob)) == "(admin)");
        }

        return 1;
}
void log_file(string file, string text)
{
	write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
	dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}

int file_exists(string file)
{
	return (file_size(file) >= 0);
}
