// sboard.c

#include <ansi.h>
#include <org.h>
#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;
	    if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_join", "join");//sample is: join yanyan,
	add_action("do_list", "list");//see the members .
	add_action("do_discard", "discard");//the leader can do it
	add_action("do_check","check");//check the exp and money.
	add_action("do_qu","qu");//get the money
	add_action("do_jiangli","jiangli");//jiangli the exp to member.
	add_action("do_appoint",({"appoint","renming"}));//appoint cmds.
	add_action("do_history","history");//check the banghui history
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "sboard/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ �˰��û���κ���Ա ]";

        return sprintf("%s [ %d ����Ա ]", ::short(), sizeof(notes));
}

string long()
{
	return ::long() + @LONG
�����ᣨ�������ķ�����
list                             : �鿴�˰����Ա��
join id                          : �����ᣨҪ������������ɣ�
discard ��ĳ��Ա���������       : �������
check                            : �鿴������������
qu �Ӵ�����ȡ��Ǯ                : �������
jiangli ���������Ա����         : �������
renming(appoint)                 : ��������Ա����ְ�񡣰�������
LONG;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note)
{
	mapping *notes;

	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	save();
	note["msg"] = "���� " + ::short() + "\n" ;
	me->set("shili/name",query("board_id"));
	me->set("shili/deadtimes",query("deadtimes"));
	tell_object(me, "��ϲ��������µİ�ᡣ\n");
	this_object()->set("shili/name",me->query("shili/name"));
	me->save();
	CHANNEL_D->do_channel(this_object(), "banghui",
			sprintf("��ӭ%s������%s", 
			me->name(),ORG_D->get_shili(me)));
	me->delete_temp("mark_join");
	this_object()->delete("shili");
	save();
	return;
}

int do_join(string arg)
{
	mapping note;

	if(!arg) return notify_fail("��ָ�������ID��\n");
	if(this_player()->query("shili/name")==query("board_id"))
	 return notify_fail("���Ѿ������ˣ���ʲô��Ц����\n");
	if(this_player()->query_temp("mark_join")!=query("board_id")
	  &&this_player()->query("shili/leader")!=query("board_id"))
	 return notify_fail("û�а�������ɣ��㲻�ܼ���˰�ᣡ\n");
	if(this_player()->query("id")!=arg)
	 return notify_fail("��ֻ��ʹ���Լ���ID��\n");
	note = allocate_mapping(4);
	note["title"] = arg;
	note["id"]=this_player()->query("id");
	note["author"] = this_player()->query("name") + "("+this_player()->query("id")+")";
	done_post(this_player(), note);
	return 1;
}
int valid_discard(object ob,string id)
{
  if( ob->query("shili/leader")!=query("board_id")
	&&wizhood(ob) != "(admin)" 
	&&wizhood(ob) != "(arch)"
	&&ob->query("id")!=id)
    return 0;
  return 1;
}
void clear_ob(object ob,object ob2)
{
  destruct(ob);
  destruct(ob2);
}

int do_discard(string arg)
{
	mapping *notes;object ob,*user;object mem_body,body;
	int num;int i;object member;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û�������š�\n");
	num--;
	if(!this_player()->query("shili")&&!valid_discard(this_player(),notes[num]["id"]))
	return notify_fail("û�м����ỹ�������ﵷ�ң���\n");
	mem_body=new(LOGIN_OB);
	if((string)mem_body->set("id",notes[num]["id"])!=notes[num]["id"])
	return notify_fail("�����趨ID��\n");
	if(!mem_body->restore())
	return notify_fail("û�������ң��������Ѿ���ɱ������������ʦɱ���ˡ�\n");
	body=LOGIN_D->make_body(mem_body);
	if(!body->restore()){
	destruct(mem_body);
	return notify_fail("���ϵͳ�����뱨����ʦ��\n");}
	if(this_player()->query("shili/name")!=body->query("shili/name")
	&&!valid_discard(this_player(),notes[num]["id"])){
	clear_ob(mem_body,body);
	return notify_fail("ι��������㣬������ĵ����𣿣�\n");}
	if(!this_player()->query("shili/power")
	&&!valid_discard(this_player(),notes[num]["id"])){
	clear_ob(mem_body,body);
	return notify_fail("С��޻��ǲ�Ҫ�������µĺã�\n");}
	if(body->query("shili/power")&&
	this_player()->query("shili/power")>=body->query("shili/power")
	&&!valid_discard(this_player(),notes[num]["id"])){
	clear_ob(mem_body,body);
	return notify_fail("����Ȩ�öԷ��˰\n");}
	
	if(this_player()->query("shili/leader")&&
	this_player()->query("id")==notes[num]["id"]){
	clear_ob(mem_body,body);
	return notify_fail("���������˰ֻ����power ��λ��\n");}
	clear_ob(mem_body,body);
        member=find_player(notes[num]["id"]);
        if(objectp(member)&&member!=this_player())
         {
         CHANNEL_D->do_channel( this_object(), "rumor",
			sprintf("%s��%s�ϳ�%s�ˡ�", 
			member->name(),this_player()->name(),ORG_D->get_board_shili(query("board_id"))));
         tell_object(member,"�㱻�ϳ������ˣ�\n");
        }
        if(!objectp(member))
          CHANNEL_D->do_channel( this_object(), "rumor",
			sprintf("%s��%s�ϳ�%s�ˡ�", 
			notes[num]["author"],this_player()->name(),ORG_D->get_board_shili(query("board_id"))));
	if(member==this_player())
	CHANNEL_D->do_channel( this_object(), "rumor",
			sprintf("%s�����˳�%s�ˡ�", 
			this_player()->name(),ORG_D->get_shili(member)));
	if(this_player()->query("id")!=notes[num]["id"])
	write("���� " + (num+1) + " ����Ա�ϳ����....Ok��\n");
	if(objectp(member))
	member->delete("shili");
	notes = notes[0..num-1] + notes[num+1..<1];
	set("notes", notes);
	save();
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

int do_check()
{
	object me;int exp,money;
	me=this_player();
	if(me->query("shili/name")!=query("board_id")&&!wizardp(me))
	return notify_fail("ֻ�б����ɵ�����Ȩ�鿴��������\n");
	exp=query("exp");
	money=query("money");
	tell_object(me,sprintf("���������д��"+MONEY_D->money_str(money)+"������%d��\n",exp));
	return 1;
}

int do_qu(string arg)
{
	int value;object me;int money;
	string type;string m_name;
	me=this_player();
	if(!arg||sscanf(arg,"%d %s",value,type)!=2)
	return notify_fail("��Ҫȡ������Ǯ��\n");
	if(value>10000)
	return notify_fail("һ��ȡ��ô���ʲô���������ɣ�\n");
	if(me->query("shili/leader")!=query("board_id"))
	return notify_fail("ֻ���������������ȡǮ��\n");
	money=query("money");
	if(type=="silver") value=value*100;
	else if(type=="gold") value=value*10000;
	if(value>money)
	return notify_fail("���������Ĵ��û����ô�࣡\n");
	MONEY_D->pay_player(me,value);
	money=money-value;
	set("money",money);
	tell_object(me,"OK!\n");
	log_file("org/"+me->query("shili/name"),me->name()+""+
	"ȡ����"+MONEY_D->money_str(value)+"    "+ctime(time())+"\n");
	this_object()->save();
	return 1;
}

int do_jiangli(string arg)
{
	object me,ob;int exp;string name;
	int bexp;
	me=this_player();
	if(!arg||sscanf(arg,"%s %d",name,exp)!=2) 
	return notify_fail("��Ҫ����˭��\n");
	if(me->query("shili/leader")!=query("board_id"))
	return notify_fail("ֻ������ſ��Խ������ˣ�\n");
	if(!objectp(ob=present(name,environment(me))))
	return notify_fail("����û������ˣ�\n");
	if(exp>100000)
	return notify_fail("һ����ཱ��100000\n");
	if(me->query("shili/name")!=ob->query("shili/name"))
	return notify_fail("���ǲ���һ�����������ܽ�����\n");
	bexp=query("exp");
	if(exp>bexp)
	return notify_fail("û����ô��ľ�����Խ�����\n");
	ob->add("combat_exp",exp);
	bexp=bexp-exp;
	set("exp",bexp);
	this_object()->set("shili/name",this_player()->query("shili/name"));
	CHANNEL_D->do_channel(this_object(), "banghui",
			sprintf("%s������%s "+chinese_number(exp)+"�㾭�顣", 
			this_player()->name(),ob->name()));
	message_vision("$N������$n"+chinese_number(exp)+"�㾭�飡\n",me,ob);
	this_object()->delete("shili");
	log_file("org/"+me->query("shili/name"),me->name()+""
	+"������"+ob->name()+chinese_number(exp)+"�㾭��"+"     "+ctime(time())+"\n");
	this_object()->save();
	return 1;
}

int do_history()
{
  object ob;string *msg;
  string file,result;int i;
  ob=this_player();
  if(!ob->query("shili")&&!wizardp(ob))
  return notify_fail("��û�м����κΰ�ᣬ��Ȩ���鿴�������ʷ��\n");
  if(ob->query("shili/name")!=query("board_id")&&!wizardp(ob))
  return notify_fail("�ⲻ������������Ӣ�۰�����Ȩ������鿴��\n");
  file=read_file("/log/org/"+query("board_id"));
  if(!stringp(file))
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰû��ʲô��ʷ��¼��\n");
  msg=explode(file,"\n");
  if(sizeof(msg)==0)
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰû��ʲô��ʷ��¼��\n");
  result=ORG_D->get_board_shili(query("board_id"))+"��¼\n";
  for(i=0;i<sizeof(msg);i++){
    result +=msg[i]+"\n";}
  ob->start_more(result);
  return 1;
}
  
  