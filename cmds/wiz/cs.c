string CSI="\e[";

string *STR=({"$BLK$","$RED$","$GRN$","$YEL$","$BLU$","$MAG$","$CYN$","$WHT$",
	"$HIR$","$HIG$","$HIY$","$HIB$","$HIM$","$HIC$","$HIW$",
	"$BBLK$","$BRED$","$BGRN$","$BYEL$","$BBLU$","$BMAG$","$BCYN$","$BWHT$",
	"$HBRED$","$HBGRN$","$HBYEL$","$HBBLU$","$HBMAG$","$HBCYN$","$HBWHT$",
	"$NOR$","$B$","$BL$","$U$","$REV$","$HR$"});

string *SCLR=({"30m","31m","32m","33m","34m","35m","36m","37m",
	"1;31m","1;32m","1;33m","1;34m","1;35m","1;36m","1;37m",
	"40m","41m","42m","43m","44m","45m","46m","47m",
	"41;1m","42;1m","43;1m","44;1m","45;1m","46;1m","47;1m",
	"37;0m","1m","5m","4m","7m","1;7m"});

void do_to(object me, string arg, string str);
string add_color(string str);
int main(object me, string arg)
{
	if(!arg) return notify_fail("\a\e[32;1mno arg\e[37;0m\n");

	if(arg=="-s") return notify_fail("\e[2J\e[H\e[40m");
	if(sscanf(arg,"-s %s",arg)==1){
		message_vision(add_color(arg)+"\n\e[37;0m",me);
		return 1;
	}

	if(sscanf(arg,"-t %s",arg)!=1) do_to(me,0,arg);
	else me->edit( (: do_to, me, arg :) );
	return 1;
}
void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) str=arg + " " + str;
	str=add_color(str);
	me->force_me(str);
}
string add_color(string str){
	int i;
	for(i=0;i<sizeof(STR);i++){
		str=replace_string(str,STR[i],CSI+SCLR[i]);
	}
	return replace_string(str,"##",CSI);
}

