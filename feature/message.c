// message.c

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});

void receive_message(string msgclass, string msg)
{
    string subclass, *ch;
    int len;

    if(!msg || (len=strlen(msg))<1) return;

    if(len>80000) msg=msg[0..80000]+"\n\n......\n";

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
                if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
                        msg_buffer += ({ msg });
        } else
                receive( msg );
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

        if(str=="&1") return HIG"体力："+ob->query("sen")+"> "NOR;
       if(str=="&2") return HIG"状态："+ob->query("gin")+"|"+ob->query("kee")+"|"+ob->query("sen")+"> "NOR;

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
        if( sizeof(msg_buffer) ) {
                receive(BOLD +"[输入时暂存讯息]\n" + NOR);
                for(int i=0; i<sizeof(msg_buffer); i++)
                        receive(msg_buffer[i]);
                msg_buffer = ({});
        }
          write("");
}

void receive_snoop(string msg)
{
    if ( msg && msg!="" && msg[0]!='%' ) receive(msg);
}
