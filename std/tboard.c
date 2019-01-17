// tboard.c
//for topc.c
#include <ansi.h>

//#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
	set("location", loc);
}

void init()
{
	add_action("do_join", "join");
	add_action("do_list", "list");
	add_action("do_discard", "discard");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "tboard/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ �����а�û���κ���Ա ]";

        return sprintf("%s [ %d ����Ա ]", ::short(), sizeof(notes));
}

string long()
{
	return ::long() + @LONG
���Ǵ���˫����ѧ��Ϊ�����а����а��е����ϴ������ȡ��
ֻ��arch��admin����ɾ����������������а����֧��200�ˡ�
list:����������
discard ��ţ�ɾ��ĳһ��š�
LONG;
}


void done_post(object me, mapping note)
{
	mapping *notes;int i;
        if(wizardp(me)) return;
	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else{
	      for(i=0;i<sizeof(notes);i++)
	      {
	      	if(notes[i]["id"]==note["id"])
	      	{ notes[i]=note; break;}
	      	
	      }
	      if(i==sizeof(notes))
		notes += ({ note });
	    }

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > query("capacity") )
		set("capacity",sizeof(notes));

	set("notes", notes);
	save();
	return;
}

void reset_list()
{
   mapping *notes;
   notes = query("notes");
   if(sizeof(notes)<=100)
   return;
  set("notes",notes[0..100]);
  save();
  return;
}
  
int query_score(object me)
{
int damage,parry,dodge;
mapping action;
string skill_name;

if(!me->query("actionp")){
	skill_name=me->reset_action(me->query_temp("weapon"));
    action=me->query("actions");
}
else{
    action=me->query("actionp");
    skill_name=action["skill_name"];
}         

damage = COMBAT_D->get_damage(me,0,me->query_temp("weapon"),action,0,skill_name);

dodge = COMBAT_D->get_attack(me,0,action,0);
parry = COMBAT_D->get_parry(me);

   return damage/10+(dodge+parry)/20+me->query("max_force")/100;
}


int do_join(string arg)
{
	mapping note;
	
	note = allocate_mapping(7);
	note["title"] = arg;
	note["id"]=this_player()->query("id");
	note["author"] = this_player()->query("name") + "("+this_player()->query("id")+")";
	note["party"]=this_player()->query("family/family_name");
	note["exp"]=query_score(this_player());
	done_post(this_player(), note);
	return 1;
}

int do_join2(object ob,string arg)
{
	mapping note;
	
	note = allocate_mapping(7);
	note["title"] = arg;
	note["id"]=ob->query("id");
	note["author"] = ob->query("name") + "("+ob->query("id")+")";
	note["party"]=ob->query("family/family_name");
	note["exp"]=query_score(ob);
	done_post(ob, note);
	return 1;
}

int do_discard(string arg)
{
	mapping *notes;object ob,*user;
	int num;int i;object member;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û�������š�\n");
	num--;
	if((string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
	&& (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
		return notify_fail("����Ȩɾ�����а���Ա��\n");
	notes = notes[0..num-1] + notes[num+1..<1];
	set("notes", notes);
	save();
	write("���� " + (num+1) + " ����Աɾ�����а�....Ok��\n");
	return 1;
}

int do_list(string arg)
{
	mapping *notes, last_read_time = 0;
	int num, i, last_time_read;
	string msg = "", myid;

	notes = query("notes");
	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	if ( !arg || sscanf(arg, "%d", num)!=1 || num < 1 ) num = 1;
	if ( arg == "new") {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
	};

	if (num > sizeof(notes)) return notify_fail("û�����뿴����Ա��\n");
	if (mapp(last_read_time)) last_time_read = last_read_time[myid];
	for(i=num-1; i<sizeof(notes); i++) {
		msg += sprintf("%s[%2d]" NOR,
			notes[i]["time"] > last_time_read ? HIY: "",
			i+1);
		msg += (sprintf("     %-=36s %18s (%s)\n",
			notes[i]["title"], notes[i]["author"],
			ctime(notes[i]["time"])[0..15] ))[4..<0];
	}
	this_player()->start_more(msg);
	return 1;
}
