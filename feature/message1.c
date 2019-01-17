// message.c

#include <ansi.h>
#include <name.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

static string *msg_buffer = ({});

static string log_in = 0;
int is_loging_now()
{
        return log_in != 0;
}

int start_log()
{
        string file;
//        if (! is_root(previous_object())) return 0;

        if (log_in) return 0;

        if (! (file = EXAMINE_D->create_log_file(this_object())))
                return 0;

        log_file(file, sprintf("The system log the action of %s(%s) from %s on %s.\n\n",
                               name(1), query("id"),
                               query_ip_name(this_object()), ctime(time())));
        log_in = file;
        return 1;
}

void end_log()
{
        if (! log_in) return;
//        if (! is_root(previous_object())) return;

        log_file(log_in, sprintf("The system stop log at %s.\n\n",
                 ctime(time())));
        log_in = 0;
}

void log_command(string msg)
{
        if (! log_in) return;

        log_file(log_in, HIC + ctime(time())[11..18] +
                         HIY "> " + msg + NOR "\n");
}

void log_message(string msg)
{
        if (! log_in) return;

        msg = replace_string(msg, ESC "[256D" ESC "[K", "\n");
        msg = replace_string(msg, ESC "[1A", "");
        log_file(log_in, msg);
}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	int len;

	if(!msg || (len=strlen(msg))<1) return;

	if(len>8000) msg=msg[0..8000]+"\n\n......\n";

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels")) || member_array(msgclass, ch)==-1 ) return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") ) return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) ) return;
	
	if(!living(this_object())){		
		msg = HIR"!"NOR+msg;
	}

	if( in_input(this_object()) || in_edit(this_object()) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER ) msg_buffer += ({ msg });
	} else receive( msg );
}
string get_prompt(string str)
{
	object ob=this_player();
	string p1,p2;

       if(!str) str=ob->query("env/prompt");
        if(!str) return "> ";

	if(wizardp(ob)){
                if(str=="&W") return HIG+ob->query("cwd")+"> "NOR;
	}
	
        if(str=="&1") return HIG"������"+ob->query("sen")+"> "NOR;
       if(str=="&2") return HIG"״̬��"+ob->query("gin")+"|"+ob->query("kee")+"|"+ob->query("sen")+"> "NOR;

	if(wizardp(ob)){
		str=replace_string(str,"$DIR$",ob->query("cwd")+"");
	}

	str=replace_string(str,"$JING$",ob->query("gin")+"");
	str=replace_string(str,"$QI$",ob->query("kee")+"");
	str=replace_string(str,"$TILI$",ob->query("sen")+"");
	return ""+str+NOR;
}

void write_prompt()
{
	string msg = "[����ʱ�ݴ�ѶϢ]\n" ;

	if( sizeof(msg_buffer) ) {
		receive(BOLD + msg + NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
	write(get_prompt(0));
}

void receive_snoop(string msg)
{
	if ( msg && msg!="" && msg[0]!='%' ) receive("%" + msg);
}

