// object.c

varargs int getoid(object ob)
{
	int id;

	if (!ob) ob = previous_object();
	sscanf(file_name(ob), "%*s#%d", id);
	return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string name, rest, dir;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%s", dir, name, rest) == 3) {
        return name;
    }
    return 0;
}

// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
	string domain;
	if( sscanf(file, "/d/%s/%*s", domain) )
		//return "domain";
		return domain;

	return ROOT_UID;
}

// creator_file should return the name of the creator of a specific file.
string creator_file(string file)
{
	string *path;

	path = explode(file, "/") - ({ 0 });
	switch(path[0]) {
		case "adm":
			if( file==SIMUL_EFUN_OB ) return "MudOS";
			else return ROOT_UID;
		case "cmds":
			return ROOT_UID;
		case "u":
			if( sizeof(path)>=3 ) return path[1];
		case "d"://modify by jackyboy for valid_read()
		case "daemon":
		
			return "Domain";
			//ͳһ���漸��Ŀ¼��object�Ķ�дȨ��
			//���ҷ��ص�ֵ�����д�д��ĸ��
		case "obj":
				return ROOT_UID;
		case "www":
			if(path[1]=="cgi-bin")
				return ROOT_UID;
		case "open":
		case "ftp":
			if( sizeof(path)>=3 ) return path[1];
		default:
			if( this_player(1) )
				return getuid(this_player(1));
			else
				return "MudOS";
	}
}

// author_file should return the name of the author of a specific file.
string author_file(string file)
{
	string name;

	if( sscanf(file, "/u/%s/%*s", name) ) return name;
	return ROOT_UID;
}

/* int living(object ob)
{
        if( !ob->is_character() || ob->is_corpse() ) return 0;
        return !(int)ob->query_temp("disable_command");
} */

// added by mudadm
int living(object ob)
{
        if (ob && ob->query_temp("disabled") )
                return 0;
        return efun::living(ob);
 }

void destruct(object ob)
{
	if (ob) {
		  if( previous_object() ) ob->remove( geteuid(previous_object()) );
		  else ob->remove(0);
		}
	efun::destruct(ob);
}

void exec(object to,object from)
{
	if(base_name(to)!=USER_OB && base_name(to)!=LOGIN_OB && getuid(from)!=ROOT_UID) return;
	efun::exec(to,from);
}
