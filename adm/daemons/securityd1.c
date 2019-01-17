// securityd.c

#include <login.h>
inherit F_DBASE;

mapping wiz_status=([]);

string *wiz_levels = ({

	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(honorary)",
	"(admin)"
});
// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

mapping trusted_write = ([
	"/": 		({ "Root", "(admin)" }),
	"d":		({ "(arch)","(wizard)"}),
	"d/huating":	({ "sho" }),
	"daemon":	({ "(arch)","(wizard)"}),
	"cmds/usr":	({"(arch)","(wizard)"}),
	"cmds/std":	({"(arch)","(wizard)"}),
	"doc" : 	({"(arch)","(wizard)"}),
	"u":		({"(arch)","(wizard)","(apprentice)"}),
	"adm" : 	({"(admin)"}),
	"open" :	({"(apprentice)","(wizard)","(arch)"}),
	"u/market" :	 ({ "(admin)"}),
	"data/orgroom" : ({ "(player)","Domain" }),
	//"data/games" : ({ "(player)","Domain" }),
]);

mapping exclude_write = ([
	"/": 		({"(honorary)","(wizard)","(apprentice)","(immortal)","(player)" }),
	"adm" : 	({"(arch)"}),
	"adm/daemons/securityd.c":({ "(admin)"}),
	"u/dsm" : 	({"(arch)"}),
	"u/songyun" : 	({"(arch)"}),
	"u/lanxin" : 	({"(arch)"}),
	"u/gmm" : 	({"(arch)"}),
	"u/mudadm" : 	({"(arch)"}),
	"data":		({ "(arch)"}),
	"data/login/R":	({ "(admin)"}),
	"data/user/R":	({ "(admin)"}),
	"log":		({ "(admin)"}),
	"data/npc/boss" : ({ "(player)","Domain" }),
	"data/orgroom" : ({ "(player)","Domain" }),
	//"data/games" : ({ "(player)","Domain" }),
	"www":		({"(honorary)","(arch)"}),
]);

mapping trusted_read = ([
	"/":            ({ "Root","(admin)","(honorary)","(arch)"}),
		//��ζ�⼸�����Զ�/������û�б�exclude_read������Ŀ¼��
	"d":		({ "(arch)","Domain","(wizard)"}),//Domain����ĸ�����д�д��ĸ
	"d/huating":	({ "sho" }),
	"u":		({ "(arch)","(wizard)"}),
			//"domain"Ϊ/d,/obj,/daemon�µ�object��euid!
	"daemon":	({ "(wizard)","Domain","(wizard)" }),
	"daemon/skill":	({ "(player)","Domain","(wizard)" }),//����Ҳ��������ǻ��кܶ�skill�ļ���ʧ��
	"obj":		({ "(arch)","Domain" }),
	"quest":	({ "(player)","(apprentice)","(immortal)"}),
	"std":		({"(arch)"}),
	"include":	({"(arch)"}),
	"adm/etc/wizlist":({"(player)"}),
	"adm/etc/welcome":({"(player)"}),
	"adm/etc/job":	({"(player)"}),
		//��Ϊÿ��update����ļ�ʱ���Լ���Ȩ�ޱ���Ϊ(player),��������Ϊplayer�ɶ���
	"data/npc/boss":({ "(player)","Domain" }),//���ö�Ȩ��
	"data/orgroom" : ({ "(player)","Domain" }),
	//"data/games" : ({ "(player)","Domain" }),
	"adm":		({"(admin)"}),
	"open" :	({"(apprentice)","(wizard)","(arch)"}),
	"u/market" : ({"(admin)"}),

]);

mapping exclude_read = ([
	"/": 		({"(wizard)", "(apprentice)","(immortal)","(player)" }),
	"adm":		({"(honorary)","(arch)"}),
	"cmds/adm":	({"(honorary)","(arch)"}),
	"cmds/arch":	({"(honorary)","(arch)"}),
	"www":		({"(honorary)","(arch)"}),
	"u/dsm" : 	({"(honorary)","(arch)"}),
	"u/gmm" : 	({"(honorary)","(arch)"}),
	"u/songyun" : 	({"(honorary)","(arch)"}),
	"u/lanxin" : 	({"(honorary)","(arch)"}),
	"u/mudadm" : 	({"(honorary)","(arch)"}),
]);


void create()
{
	string *wizlist, wiz_name, wiz_level;
	int i;

	set("channel_id", "ϵͳ��ȫ�ػ�����(SECURITY_D)");
	CHANNEL_D->do_channel( this_object(), "sys", "���������ɹ���\n");
	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++) {
		if( wizlist[i][0]=='#' 
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;
	
	if( objectp(ob) ) {
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
		if(euid=="Root") return "(admin)";
	}
	else if( stringp(ob) ) euid = ob;

	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob,string status,object who)
{
	string uid, *wiz, wizlist;
	int i;

	if(!who) who=ob;

	if(!userp(who)) return 0;

	if(status=="(admin)" && getuid(who)!=ROOT_UID&&getuid(who)!="kouzhong"){
		write("YOU CAN'T PROMOTE ANYONE TO ADMIN!!!\n");
		write("IF YOU REALLY WANT IT,ASK Forever.\n");
		log_file("static/out_promote",getuid(who)+" try to promote "+getuid(ob)+" to "+status+" on "+ctime(time())+".\n" );
		return 0;
	}
	if(status=="(arch)" && (getuid(who)!="kouzhong"&&getuid(who)!=ROOT_UID&&getuid(who)!="kouzhong") ){
		write("YOU CAN'T PROMOTE ANYONE TO ARCH!!!\n");
		write("IF YOU REALLY WANT IT,ASK ADMIN.\n");
		log_file("static/out_promote",getuid(who)+" try to promote "+getuid(ob)+" to "+status+" on "+ctime(time())+".\n" );
		return 0;
	}

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

	if( userp(ob) )			uid = getuid(ob);
	else if(stringp(ob))	uid = ob;
	else return 0;
	
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wiz = keys(wiz_status);
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file( "static/promotion", capitalize(uid)
	 + " become a " + status + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }
int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_read: Invalid argument type of user.\n");
	//if( sscanf(file, LOG_DIR + "%*s") && func=="read_file" ) return 1;

	if( func=="restore_object" ) {
		if( sscanf(base_name(user), "/obj/%*s")
			&& sscanf(file, "/data/%*s")
			&& file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
			return 1;
		if( sscanf(file,"/data/board/%*s"))
			return 1;//������������ȡboard����
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;
	if((file=="/u/"||file=="/u")&&wiz_level(status)>wiz_level("(immortal)"))
		return 1;

	if( sscanf(file, "/u/" + euid + "/%*s")
		||file=="/u/"+euid)
		return 1;
		path = explode(file, "/");

// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( member_array(status, exclude_read[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_read["/"])!=-1 ) return 1;
	if( member_array(status, trusted_read["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;

	}
	if(wizhood(user)!="(player)")
		log_file("wiz_read_fail.log", sprintf("%s(%s) read attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	else
		log_file("read_fail.log", sprintf("%s(%s) read attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	return 0;
}
// valid_write - called by the master object to determine whether if an user
//	       is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object. 												- Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_write: Invalid argument type of user.\n");

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	// Let user save their save file
	if( func=="save_object" ) {
		if( sscanf(base_name(user), "/obj/%*s")
		&&	sscanf(file, "/data/%*s")
		&&	file == (string)user->query_save_file()+__SAVE_EXTENSION__  )
//		&&  file == (string)user->query_save_file()+".o" )

		sscanf(base_name(user), "/obj/%*s");
			return 1;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	if( euid==ROOT_UID || euid=="NONAME") return 1;
	//���ɶ��Ͳ���д add by jackyboy
	if(valid_read(file,user,func)==0) return 0;
	status = get_status(user);
	path = explode(file, "/");
	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	log_file("write_fail", sprintf("%s(%s) write attempt on %s failed.\n", geteuid(user), wizhood(user), file));
	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&  wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}
