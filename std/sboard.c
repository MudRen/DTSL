// sboard.c

#include <ansi.h>
#include <org.h>
#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

#define LEV1 "���"
#define LEV2 "��ر�"
#define LEV3 "����"
#define LEV4 "��ʿ��"
#define LEV5 "���"

#define LEV1_MONEY 500
#define LEV2_MONEY 500
#define LEV3_MONEY 500
#define LEV4_MONEY 500
#define LEV5_MONEY 500

#define LEV1_TRAIN 70
#define LEV2_TRAIN 70
#define LEV3_TRAIN 70
#define LEV4_TRAIN 70
#define LEV5_TRAIN 70

#define LEV1_SUPPLY 10
#define LEV2_SUPPLY 50
#define LEV3_SUPPLY 50
#define LEV4_SUPPLY 50
#define LEV5_SUPPLY 50

#define SMALL_CITY_TAX  15000
#define MIDDLE_CITY_TAX 20000
#define BIG_CITY_TAX    40000


void setup()
{
	string loc;
	    if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	
	
	restore();
	
        if(
	   query("board_id")=="haisha_b"||
	   query("board_id")=="feima_b"||
	   query("board_id")=="songjia_b"
	  )
	set("max_person",100000);
	else
	set("max_person",80000);
	
    delete("do_train");
    if(query("lev1_guard")<0) set("lev1_guard",0);
    if(query("lev2_guard")<0) set("lev2_guard",0);
    if(query("lev3_guard")<0) set("lev3_guard",0);
    if(query("lev4_guard")<0) set("lev4_guard",0);
    if(query("lev5_guard")<0) set("lev5_guard",0);
    
	set("person",query("max_person"));	
	set("guard_person",query("lev1_guard")*LEV1_SUPPLY+query("lev2_guard")*LEV2_SUPPLY+
        query("lev3_guard")*LEV3_SUPPLY+query("lev4_guard")*LEV4_SUPPLY+
        query("lev5_guard")*LEV5_SUPPLY);
   
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
	add_action("do_jiemeng","jiemeng");//����/���ˡ�
	add_action("do_deposit",({"deposit","cun"}));
	
	add_action("do_zhubing","zhubing");
	add_action("do_chebing","chebing");
	add_action("do_train",({"train","lianbing"}));
	add_action("do_wuzhuang","wuzhuang");
	add_action("do_chubing","chubing");
	add_action("do_shoubing","shoubing");
	add_action("do_checkwar","checkwar");
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
jiemeng                          : ������������/���ˡ���������
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
	     set("capacity",sizeof(notes));

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
	CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s������%s", 
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
		return notify_fail("ָ���ʽ��discard <������>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û�������š�\n");
	num--;
	
	return ORG_D->org_del_member(this_player(),this_object(),notes[num]["id"],notes[num]["author"],
                   notes,num);
	
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}

int do_list(string arg)
{
        mapping *notes;
        int num, i, on_line_id;
	string msg = "", myid;
    string head,end,online;

	notes = query("notes");
    num=sizeof(notes);
	myid = query("board_id");

if (num==0) return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰû���κ���Ա��\n");
     on_line_id=0;
     online="";
for(i=0; i<num; i++) {
		msg += sprintf("%s[%2d]" NOR,
                        HIY,
			i+1);
msg +=left(notes[i]["author"],36);
msg +="����ʱ�䣺��"+(sprintf("%s"+"��"+"\n",
			ctime(notes[i]["time"])[0..15] ))[4..<0];
if(objectp(find_player(notes[i]["title"]))){
on_line_id++;
online +=notes[i]["author"]+" ";
if(on_line_id%5==0)
online+="\n";}
	}
head="������������������������������������������������������������������������\n"+
"Ŀǰ"+ORG_D->get_board_shili(query("board_id"))+"����"+
HIW+chinese_number(num)+NOR+"����Ա���ܼƱ�PK����Ϊ"+
HIR+chinese_number(query("deadtimes"))+NOR+"\n\n"+
"Ŀǰ����"+HIY+chinese_number(on_line_id)+NOR+"��"+
"��Ա�����ϣ��ֱ�Ϊ��\n"+online+"\n\n";
end="������������������������������������������������������������������������\n";
msg=head+msg+end;
	this_player()->start_more(msg);
	return 1;
}

int do_check()
{
	object me;int exp,money;
	string msg;
	
	me=this_player();
	if(me->query("shili/name")!=query("board_id")&&!wizardp(me))
	return notify_fail("ֻ�б����ɵ�����Ȩ�鿴������\n");
	exp=query("exp");
	money=query("money");
	msg="\n"+ORG_D->get_board_shili(query("board_id"))+"���д�";
	if(money<=0)
	msg+="��";
	else
	msg+=MONEY_D->money_str(money);
	msg+="�����飺";
	if(exp<=0)
	msg+="��";
	else
	msg+=sprintf("%d",exp);
	msg+="��\n\n";
	tell_object(me,msg);
	return 1;
}

int do_qu(string arg)
{
	int value;object me;int money;
	string type;string m_name;
	me=this_player();
	if(!arg||sscanf(arg,"%d %s",value,type)!=2)
	return notify_fail("��Ҫȡ������Ǯ��\n");
	if(value<=0)
	return notify_fail("��ô���뵷���𣿣�\n");
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
	if(exp<=0)
	return notify_fail("��ô���뵷���𣿣�\n");
	if(exp>100000)
	return notify_fail("һ����ཱ��100000�㾭��ֵ��\n");
	if(me->query("shili/name")!=ob->query("shili/name"))
	return notify_fail("���ǲ���һ�����������ܽ�����\n");
        if(time()>ob->query("jiangli_inter_time")&&time()-ob->query("jiangli_inter_time")<3600*24)
        return notify_fail("������24��Сʱ�ſ��Խ������ľ��顣\n");
        if(exp>ob->query("famous")*50)
        return notify_fail("�����ڽ����е���������������һ�ν�����ô�ྭ�顣\n");
        if(exp+ob->query("reward_exp")>ob->query("famous")*100)
        return notify_fail("��ֻ���ٽ���"+ob->name()+HIY+
        (ob->query("famous")*100-ob->query("reward_exp"))+NOR"�㾭�飡\n");
 
	bexp=query("exp");
	if(exp>bexp)
	return notify_fail("����û����ô��ľ�����Խ�����\n");
	ob->add("combat_exp",exp);
        ob->set("jiangli_inter_time",time());
        ob->add("reward_exp",exp);
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
	ob->save();
	return 1;
}

int do_history(string arg)
{
  object ob;string *msg;
  string file,result;int i;
  ob=this_player();
  
  if(!arg||
     (arg!="-r"&&arg!="-w")
    )
  return notify_fail("history -r:�鿴��ᴢ��������ʷ��\n"+
                     "history -w:�鿴���������\n");
  
  if(!ob->query("shili")&&!wizardp(ob))
  return notify_fail("��û�м����κΰ�ᣬ��Ȩ���鿴�������ʷ��\n");
  if(ob->query("shili/name")!=query("board_id")&&!wizardp(ob))
  return notify_fail("�ⲻ������������Ӣ�۰�����Ȩ������鿴��\n");
 
 if(arg=="-r"){
  file=read_file("/log/org/"+query("board_id"));
  if(!stringp(file))
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰû��ʲô��ʷ��¼��\n");
  msg=explode(file,"\n");
  if(sizeof(msg)==0)
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰû��ʲô��ʷ��¼��\n");
  result=ORG_D->get_board_shili(query("board_id"))+"��¼\n\n";
  for(i=0;i<sizeof(msg);i++){
    result +=msg[i]+"\n";}
  ob->start_more(result);
  return 1;
 }else{
  file=read_file("/log/org/"+query("board_id")+"_bangzhu");
  if(!stringp(file))
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰ�����컹������ҡ�\n");
  msg=explode(file,"\n");
  if(sizeof(msg)==0)
  return notify_fail(ORG_D->get_board_shili(query("board_id"))+"Ŀǰ�����컹������ҡ�\n");
  result=ORG_D->get_board_shili(query("board_id"))+"�������������\n\n";
  for(i=0;i<sizeof(msg);i++){
    result +=msg[i]+"\n";}
  ob->start_more(result);
  return 1;
}  
 
}
  
  
int do_jiemeng(string arg)
{
  string name;
  object ob;
  
  ob=this_player();
  
  if(!arg||
     (sscanf(arg,"-y %s",name)!=1
      &&sscanf(arg,"-n %s",name)!=1
      &&arg!="-f")
    )
  return notify_fail("��ʹ�� jiemeng -y ������� ��ĳ������\n"+
                     "       jiemeng -n ������� ��ĳ������\n"+
                     "       jiemeng -f �г���ǰ���˵İ�����ơ�\n");
  
  if(!ob->query("shili"))
  return notify_fail("����С���һ�ߴ���ȥ��\n");
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("�ⲻ����ĵ��̡�\n");
  
  if(arg=="-f") return ORG_D->list_friend_org(ob);
  
  if(!ob->query("shili/leader"))
  return notify_fail("�㲻��"+ORG_D->get_board_shili(query("board_id"))+"���죬���ܽ���/���ˡ�\n");
  if(name==ob->query("shili/name"))
  return notify_fail("�Լ����Լ����ý���/������\n");    
  
  if(sscanf(arg,"-y %s",name)==1)
  return ORG_D->make_friend(ob,name);
  else
  return ORG_D->make_enemy(ob,name);
  
}

int do_deposit(string arg)
{
	int bv,amount;
	int damount;
	string type;
	object type_ob;
	
	if(!this_player()->query("shili"))
        return notify_fail("����С���һ�ߴ���ȥ��\n");
        if(this_player()->query("shili/name")!=query("board_id"))
        return notify_fail("�ⲻ����ĵ��̡�\n");
  
        if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܴ�Ǯ��\n");
        if( !arg || sscanf(arg, "%d %s", amount, type)!=2 )
                return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	if( amount <= 0)
		return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	type_ob = present(type + "_money", this_player());
        if( !type_ob)          return notify_fail("������û�����ֻ��ҡ�\n");
        if( (int)type_ob->query_amount() < amount )
                return notify_fail("������û�������" + type_ob->query("name") + "��\n");
        bv = type_ob->query("base_value");
        if( !bv ) return notify_fail("���ֶ�����ֵǮ��\n");
	damount =query("money");
	damount += amount * bv;
	set("money", damount);
	type_ob->add_amount(-amount);
	message_vision(sprintf("$N������%s%s%s��\n",
	chinese_number(amount), type_ob->query("base_unit"), type_ob->query("name")), this_player());
	this_player()->start_busy(1);
	return 1;

}

/* ������ ����ս������ */



int do_zhubing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<300000)
   return notify_fail("ֻ�о���ﵽ�� 300��000 �ſ��Խ���פ����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
   
  if( (!ob->query("shili/power")||ob->query("shili/power")>4)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+ORG_D->get_shili(ob)+NOR+"פ����\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||(arg!=LEV1)
   )
  return notify_fail("��ʹ�� zhubing "+LEV1+"��\n");
  
    if(sboard->query("money")<LEV1_MONEY)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��פ����\n");
    
    if(query("guard_person")>=query("person"))
    return notify_fail("Ŀǰ�Ѿ��ﵽ"+HIY+ORG_D->get_shili(ob)+NOR+"���˿������ˣ�\n");
        
    if(query("do_zhubing")>=5)
    return notify_fail("����һ��פ��̫���������һ��ɣ�\n");
    
    add("do_zhubing",1);
    
    tell_object(ob,"�������"+HIY+ORG_D->get_shili(ob)+NOR+"פ��һЩ������\n");
    
    call_out("start_zhubing",180,ob->name(),ob->query("shili/name"),sboard);
            
    sboard->save();
  return 1;
  
}

void start_zhubing(string name,string org_name,object sboard)
{
  
  sboard->set("shili/name",org_name);
  CHANNEL_D->do_channel(sboard,"banghui",name+"��"+ORG_D->get_board_shili(query("board_id"))+"פ����һЩ"+LEV1+"��\n");
  
  sboard->add("money",-LEV1_MONEY);
  add("lev1_guard",1);
  add("guard_person",LEV1_SUPPLY);
  add("do_zhubing",-1);
  
  sboard->save();
  
}


int do_chebing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ��г�����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
 
  if( (!ob->query("shili/power")||ob->query("shili/power")>3)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+ORG_D->get_shili(ob)+NOR+"������\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||
   (arg!=LEV1&&arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
   )
  return notify_fail("��ʹ�� chebing "+LEV1+"/"+LEV2+"/"+LEV3+"/"+LEV4+"/"+LEV5+"��\n");
  
  if(arg==LEV1){
    
    if(query("lev1_guard")<=0)
    return notify_fail( ORG_D->get_shili(ob)+"û��פ��"+LEV1+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"������һЩ"+LEV1+"��\n");
    sboard->add("money",LEV1_MONEY/3);
    add("lev1_guard",-1);
    add("guard_person",-LEV1_SUPPLY);
    save();
    
  }
  if(arg==LEV2){
    if(query("lev2_guard")<=0)
    return notify_fail( ORG_D->get_shili(ob)+"û��פ��"+LEV2+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"������һЩ"+LEV2+"��\n");
    sboard->add("money",LEV2_MONEY/3);
    add("lev2_guard",-1);
    add("guard_person",-LEV2_SUPPLY);
    save();
    
  }
  if(arg==LEV3){
    if(query("lev3_guard")<=0)
    return notify_fail( ORG_D->get_shili(ob)+"û��פ��"+LEV3+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"������һЩ"+LEV3+"��\n");
    sboard->add("money",LEV3_MONEY/3);
    add("lev3_guard",-1);
    add("guard_person",-LEV3_SUPPLY);
    save();
    
  }
  if(arg==LEV4){
    if(query("lev4_guard")<=0)
    return notify_fail( ORG_D->get_shili(ob)+"û��פ��"+LEV4+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"������һЩ"+LEV4+"��\n");
    sboard->add("money",LEV4_MONEY/3);
    add("lev4_guard",-1);
    add("guard_person",-LEV4_SUPPLY);
    save();
    
  }
  if(arg==LEV5){
    if(query("lev5_guard")<=0)
    return notify_fail( ORG_D->get_shili(ob)+"û��פ��"+LEV5+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"������һЩ"+LEV5+"��\n");
    sboard->add("money",LEV5_MONEY/3);
    add("lev5_guard",-1);
    add("guard_person",-LEV5_SUPPLY);
    save();
    
  }
  sboard->save();
  return 1;
  
}


int do_train(string arg)
{
  object ob;
  object sboard;
  int num;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ���������\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
  
  if(!ob->query_skill("qianjun-shu",1))
   return notify_fail("�����ѧ�ᡸǧ�������ſ�����ϰʿ����\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+ORG_D->get_shili(ob)+NOR+"ѵ�����ӣ�\n");
  
  if(ob->query("vocation")!="ɱ��")
  return notify_fail("ֻ��ɱ�ֿ���ѵ��ʿ����\n");
  
  if(query("do_train")>=5)
   return notify_fail("�Ѿ���̫���������������������ɣ�\n");
  
  if(ob->query_temp("start_do_train"))
  return notify_fail("������ѵ��ʿ����\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||
     (arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
    )
  return notify_fail("��Ҫѵ����һ��ʿ����"+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"��\n");    
    
  if(arg==LEV2){
    if(!query("lev1_guard"))
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV2_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV2+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV2,1,environment(ob),LEV2_TRAIN);
     return 1;
  }
  else
  if(arg==LEV3){
    if(!query("lev1_guard"))
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV3_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV3+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV3,1,environment(ob),LEV3_TRAIN);
     return 1;
  }
  else
  if(arg==LEV4){
    if(!query("lev1_guard"))
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV4_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV4+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV4,1,environment(ob),LEV4_TRAIN);
     return 1;
  }
  else
  if(arg==LEV5){
    if(!query("lev1_guard"))
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV5_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV5+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV5,1,environment(ob),LEV5_TRAIN);
     return 1;
  }
  
  return 1;
 
}

void start_train(object ob,object sboard,string level,int times,object where,int cost)
{
   if(!ob){
     add("do_train",-1);
     return;
   }
   if(query("lev1_guard")<=0){
   		tell_object(ob,"�������̫�٣��Ѿ��޷������ӱ����ˣ���ֹͣ��������\n");
   		ob->delete_temp("start_do_train");
     	add("do_train",-1);
     	return;
   }		
   if(environment(ob)!=where){
     tell_object(ob,"�������������\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(times>=30){
     tell_object(ob,"\n����ʿ����ͣ��������Ϣһ�¡�\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(!objectp(sboard))
     sboard=load_object(BOARD_PATH+ob->query("shili/name"));
   
   if(!objectp(sboard)){
      tell_object(ob,"������������뱨����ʦ��\n");
      return;
   }
   
   if(sboard->query("money")<cost){
     tell_object(ob,HIY"\n���ǰ��Ĵ��������ˣ�\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(ob->query("gin")<=50){
    tell_object(ob,HIR"\n���ƣ����������ͣ������Ϣһ�¡�\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   ob->receive_damage("gin",50);
   
   if(level==LEV2){
     add("lev2_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev2_guard_trains")>=3000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV2_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+ORG_D->get_shili(ob)+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev2_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev2_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+ORG_D->get_shili(ob)+"��"+level+"��ǿ�ˣ�\n");
     add("lev2_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV2_SUPPLY);
     set("lev2_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
  
  if(level==LEV3){
     add("lev3_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev3_guard_trains")>=3000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV3_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+ORG_D->get_shili(ob)+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev3_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev3_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+ORG_D->get_shili(ob)+"��"+level+"��ǿ�ˣ�\n");
     add("lev3_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV3_SUPPLY);
     set("lev3_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
 
 if(level==LEV4){
     add("lev4_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev4_guard_trains")>=3000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV4_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+ORG_D->get_shili(ob)+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev4_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev4_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+ORG_D->get_shili(ob)+"��"+level+"��ǿ�ˣ�\n");
     add("lev4_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV4_SUPPLY);
     set("lev4_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }     
  
  if(level==LEV5){
     add("lev5_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev5_guard_trains")>=3000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV5_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+ORG_D->get_shili(ob)+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev5_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev5_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+ORG_D->get_shili(ob)+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+ORG_D->get_shili(ob)+"��"+level+"��ǿ�ˣ�\n");
     add("lev5_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV5_SUPPLY);
     set("lev5_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }  
  
}


int do_wuzhuang(string arg)
{
   
  object ob,obj;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<400000)
   return notify_fail("ֻ�о���ﵽ�� 400��000 �ſ��Խ�����װ��\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
  
  if(!ob->query_skill("junxie-xue",1))
  return notify_fail("�����ѧ�ˡ���еѧ���ſ�����װ���У�\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>6)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ������װ"+HIY+ORG_D->get_shili(ob)+NOR+"�ľ��ӣ�\n");
  
  if(ob->query("vocation")!="����")
  return notify_fail("ֻ�������ſ�����װ"+HIY+ORG_D->get_shili(ob)+NOR+"�ľ��ӣ�\n");
  
  if(!arg) return notify_fail("��Ҫ��ʲô�����Ӿ��ӵ���װ��\n");
  obj=present(arg,ob);
  if(!obj) return notify_fail("������û�����������\n");
  
  if( obj->query("rumor")
    ||obj->query("no_save")
    ||obj->query("no_sell")
    ||obj->query("no_get")
    ||obj->query("no_give")
    ||obj->query("nogive_player")
    )
    return notify_fail("������������������Ӿ��ӵ���װ��\n");
  
  if(!obj->query("armor_prop")&&!obj->query("weapon_prop"))
  return notify_fail("��ֻ���á����ס��򡰱����������Ӿ��ӵ���װ��\n");
  
  add("apply/armor",(obj->query("armor_prop/armor")/15)*ob->query_skill("junxie-xue",1)/200);
  add("apply/damage",(obj->query("weapon_prop/damage")/15)*ob->query_skill("junxie-xue",1)/200);
  
  if(obj->query("equipped"))
   obj->unequip();
  
  destruct(obj);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"������"+ORG_D->get_shili(ob)+"�ľ�����װ��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;

}    


int if_do_action(object ob,string type)
{
  
  if(type=="lev1") return 1;
  
  if(ob->query_skill("war-heal",1)&&
   type=="lev2")
  return 1;
  
  if(ob->query_skill("bafang-zhenfa",1)&&
   type=="lev3")
  return 1;
  
  if(ob->query_skill("liaoyuan-tianshu",1)&&
   type=="lev4")
  return 1;
  
  if(ob->query_skill("wuxing-qishu",1)&&
   type=="lev5")
  return 1;
  
  return 0;
  
}

int do_chubing(string arg)
{
  
  object ob,guard;
  int num,cost_type;
  string type,guard_type;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ��г�����\n");
  
  if(objectp(ob->query_temp("city_war_guard")))
  return notify_fail("���Ѿ������ˡ�\n");
  
  if(ob->query("pker"))
  return notify_fail("ͨ������ʵ��ɣ�\n");
  
  if(time()>ob->query("war_guard_busy")&&time()-ob->query("war_guard_busy")<60*20)
   return notify_fail("�㲻������������\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
    
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܴ�"+HIY+ORG_D->get_shili(ob)+NOR+"������\n");
  
  if(!arg||sscanf(arg,"%d %s",num,type)!=2)
  return notify_fail("��Ҫ�� ���� ʲô���� �ı���chubing ���� ����\n");
  
  if(num<=0||num>=100)
   return notify_fail("��Ҫ���ң���\n");
  if(type!=LEV1&&type!=LEV2&&type!=LEV3&&type!=LEV4&&type!=LEV5)
  return notify_fail("��Ҫ��ʲô���͵ı���"+LEV1+" "+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"\n");
  
  if(type==LEV1) guard_type="lev1";
  else
  if(type==LEV2) guard_type="lev2";
  else
  if(type==LEV3) guard_type="lev3";
  else
  if(type==LEV4) guard_type="lev4";
  else
  if(type==LEV5) guard_type="lev5";
  
  if(type==LEV1) cost_type=LEV1_SUPPLY;
  else
  if(type==LEV2) cost_type=LEV2_SUPPLY;
  else
  if(type==LEV3) cost_type=LEV3_SUPPLY;
  else
  if(type==LEV4) cost_type=LEV4_SUPPLY;
  else
  if(type==LEV5) cost_type=LEV5_SUPPLY;
  
  if(num>query(guard_type+"_guard"))
  return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"û����ô���"+type+"��\n");
  
  if(!if_do_action(ob,guard_type))
  return notify_fail("��ѧ�ļ��ܲ���ָ�Ӵ���ʿ����\n");
  
  add(guard_type+"_guard",-num);
  add("guard_person",-num*cost_type);
  
  guard=new("/std/orgroom/npc/guard");
  guard->set_status(num,guard_type,query("apply/armor"),query("apply/damage"),query("board_id"));
  guard->set("zhongcheng_du",100);
  
  guard->add_temp("damage",ob->query_skill("bafang-zhenfa",1)/5);
  guard->add_temp("damage",ob->query_skill("liaoyuan-tianshu",1)/5);
  guard->add_temp("damage",ob->query_skill("wuxing-qishu",1)/5);
  
  guard->move(environment(ob));
  guard->check_owner(ob);
  guard->set("owner_ob",ob);
  ob->set_temp("city_war_guard",guard);
  ob->set("war_guard_busy",time());
  ob->set_temp("dtsl_job","war");
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"��"+ORG_D->get_shili(ob)+"�ɳ���"+
    chinese_number(num*cost_type)+"�˵�"+type+"��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  CHANNEL_D->do_channel(this_object(),"rumor","��˵"+ORG_D->get_shili(ob)+"�ɳ���һЩʿ����\n");
  
  return 1;
  
}  


int do_shoubing()
{
  
  object ob,guard;
  int cost_type;
  string guard_type;
  
  
  ob=this_player();
  
  if(!objectp(guard=ob->query_temp("city_war_guard")))
  return notify_fail("��û�д�����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("board_id"))
  return notify_fail("���ﲻ����İ�ᣡ\n");
 
  guard_type=guard->query("guard_type");
 
  if(guard_type=="lev1") cost_type=LEV1_SUPPLY;
  else
  if(guard_type=="lev2") cost_type=LEV2_SUPPLY;
  else
  if(guard_type=="lev3") cost_type=LEV3_SUPPLY;
  else
  if(guard_type=="lev4") cost_type=LEV4_SUPPLY;
  else
  if(guard_type=="lev5") cost_type=LEV5_SUPPLY;
  
  guard->set("number",guard->query("number")*COMBAT_D->status(guard,1)/100);
  
  if(query("guard_person")+cost_type*guard->query("number")>query("person"))
  return notify_fail("����������"+HIY+ORG_D->get_shili(ob)+NOR+"���˿ڡ�\n");
  
  add(guard_type+"_guard",guard->query("number"));
  add("guard_person",guard->query("number")*cost_type);
  
  ob->set_temp("city_war_guard",0);
  ob->delete_temp("dtsl_job");
  
  destruct(guard);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"��һЩ������ʿ���ɻ���"+ORG_D->get_shili(ob)+"��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;
  
}  




int do_checkwar()
{
  object ob;
  string msg,org_msg;
  int flag=0;
  
  ob=this_player();
  
  if(!wizardp(ob)&&ob->query("shili/name")!=query("board_id")){
    if(!ob->query_skill("zhencha-shu",1))
    return notify_fail("���ﲻ����İ�ᣡ\n");
    else
    flag=1;
  }
       
  org_msg=ORG_D->get_board_shili(query("board_id"));
  
  msg=HIY+org_msg+"Ŀǰ���������\n"NOR;
  msg+=HIY"����������������������������������������������������������\n"NOR;
  msg+="�˿����ޣ�"+chinese_number(query("max_person"))+"��\n";
  
  if(!flag)
  msg+="Ŀǰ�˿ڣ�"+chinese_number(query("person"))+"��\n";
  else
  msg+="Ŀǰ�˿ڣ�"+chinese_number(query("person")+random(200-ob->query_skill("zhencha-shu",1)))+"��\n";
  
  if(!flag)
  msg+="ʿ���˿ڣ�"+chinese_number(query("guard_person"))+"��\n";
  else
  msg+="ʿ���˿ڣ�"+chinese_number(query("guard_person")+random(200-ob->query_skill("zhencha-shu",1)))+"��\n";
    
  msg+=HIR"������\n"NOR;
  if(!flag)
  msg+=LEV1+"��"+chinese_number(query("lev1_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV1_SUPPLY)+"��\n";
  else
  msg+=LEV1+"��"+chinese_number(query("lev1_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV1_SUPPLY)+"��\n";

  if(!flag)
  msg+=LEV2+"��"+chinese_number(query("lev2_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV2_SUPPLY)+"��\n";
  else
  msg+=LEV2+"��"+chinese_number(query("lev2_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV2_SUPPLY)+"��\n";  
  
  if(!flag)
  msg+=LEV3+"��"+chinese_number(query("lev3_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV3_SUPPLY)+"��\n";
  else
  msg+=LEV3+"��"+chinese_number(query("lev3_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV3_SUPPLY)+"��\n";
  
  if(!flag)
  msg+=LEV4+"��"+chinese_number(query("lev4_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV4_SUPPLY)+"��\n";
  else
  msg+=LEV4+"��"+chinese_number(query("lev4_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV4_SUPPLY)+"��\n";
  
  if(!flag)
  msg+=LEV5+"��"+chinese_number(query("lev5_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV5_SUPPLY)+"��\n";
  else
    msg+=LEV5+"��"+chinese_number(query("lev5_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
    "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV5_SUPPLY)+"��\n";
 
  
  msg+=HIR"\n��װ��\n"NOR;
  
  if(!flag)
  msg+="װ�ף�"+chinese_number(query("apply/armor"))+"\n";
  else
  msg+="װ�ף�"+chinese_number(query("apply/armor")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  if(!flag)
msg+="������"+chinese_number(query("apply/damage"))+"\n";
  else
msg+="������"+chinese_number(query("apply/damage")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  msg+=HIY"����������������������������������������������������������\n"NOR;
  
  ob->start_more(msg);
  
  return 1;
}
