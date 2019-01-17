// help.c

#include "/doc/wizhelp.h"

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;

#define WIZ_HELP_DIR "/doc/wizhelp/"

int main(object me, string arg)
{
	int i;
	string file, *search;

	// If no topic specified, give the topics.
	if( !arg ) {
		cat(WIZ_HELP_DIR + "topics");
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	
	// Search the individual search path first.
	
	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
	}

	return notify_fail("û��������������˵���ļ���\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��help <����>              ���磺> help cmds
          help <��������>()        ���磺> help call_out()

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
	);
	return 1;
}

