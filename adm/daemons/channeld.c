
#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/httpd.h>
#include <org.h>
inherit F_DBASE;

#define BLOCK_CHAT      0
#define BLOCK_RUMOR     0

string remove_addresses(string, int all);

mapping channels = ([

	"sys":	(["msg_speak": HIR "��ϵͳ��%s��%s\n" NOR,"wiz_only": 1,]),
	"debug":	(["msg_speak": HIW "�����ԡ�%s��%s\n" NOR,"wiz_only": 1,]),
           	"qst":	(["msg_speak": HIR "������%s��%s\n" NOR,"wiz_only": 1,]),
	"wiz":	(["msg_speak": HIY "����ʦ��%s��%s\n" NOR,
			"msg_emote": HIY "����ʦ��%s" NOR,
			"wiz_only": 1,]),
	"chat":	(["msg_speak": HIC "�����ġ�%s��%s\n" NOR,
			"msg_emote": HIC "�����ġ�%s" NOR,
			"msg_color": HIC,]),
	"sale":	(["msg_speak": HIG "��������%s��%s\n" NOR,
			"msg_emote": HIG "��������%s" NOR,
			"msg_color": HIC,]),
	"rumor":	(["msg_speak": HIM "��ҥ�ԡ�%s��%s\n" NOR,
			"msg_emote": HIM "��ҥ�ԡ�%s" NOR,
			"anonymous": "ĳ��",]),
	"gwiz":	(["msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
			"msg_emote": HIG "��������ʦ��%s" NOR,
			"wiz_only": 1,
			"intermud": GWIZ,
			"intermud_emote": 1,
			"channel": "CREATOR",
			"msg_color": HIG,
			"filter": 1,
			"omit_address": 0, 
		]),

	"dt":	([	"msg_speak": WHT "�����ơ�%s��%s\n" NOR,
			"msg_emote": WHT "�����ơ�%s" NOR,
			"msg_color": WHT,
			"intermud": GCHANNEL,
			"intermud_emote": 1,
			"channel": "dt",
			"omit_address": 0, 
//			"filter": 1,
			"filter": (: $1["VERSION"] == MUDLIB_VERSION :)
		]),


	"es":	([	"msg_speak": HIG "��������̸��%s��%s\n" NOR,
			"msg_emote": HIG "��������̸��%s" NOR,
			"msg_color": HIG,
//			"es_only": 1,
			"intermud": GCHANNEL,
			"intermud_emote": 1,
			"channel": "es",
			"filter": 1,
			"omit_address": 0, 
		]),

        "dashi": ([     "msg_speak": WHT "����    ʦ��%s��%s\n" NOR,
                        "msg_emote": WHT "����    ʦ��%s" NOR,
                        "msg_color": WHT,
                        "name"     : "��ʦ",
                        "intermud" : GCHANNEL,
                        "intermud_emote"    : 1,
                        "channel"  : "dashi",
    			"filter": (: $1["ENCODING"] == MUDLIB_ENCODING :)
                ]),
	"gbwiz":([	"msg_speak": WHT "����½��ʦ��%s��%s\n" NOR,
			"msg_emote": WHT "����½��ʦ��%s" NOR,
			"msg_color": WHT,
                        "wiz_only": 1,
			"intermud": GCHANNEL,
			"intermud_emote": 1, 
			"channel": "gbwiz",
			"omit_address": 0, 
//			"filter":1,
			"filter": (: $1["ENCODING"] == MUDLIB_ENCODING :)
		]),
	"party":([	"msg_speak": HIG "�����ɡ�%s��%s\n" NOR,
			"msg_emote": HIG "�����ɡ�%s" NOR,
			"msg_color": HIG,
			"party_only": 1 ]),
	"banghui":([	"msg_speak": YEL "����᡿%s��%s\n" NOR,
			"msg_emote": YEL "����᡿%s" NOR,
			"msg_color": YEL,
			"banghui_only": 1 ]),

]);

void create()
{
	// This is required to pass intermud access check.
	seteuid(getuid());
	set("channel_id", "Ƶ������");
}

string get_shili(object ob)
{
  return ORG_D->get_channel_shili(ob);
}

varargs int do_channel(object me, string verb, string arg, int emote,int remote)
{
	object *ob;
        string *tuned_ch, who;
	string arg_bk,self_emote;
	string party,shili;
	self_emote=arg;

	// Check if this is a channel emote.
	if( sizeof(verb) > 2 ) {
		if( verb[sizeof(verb)-1] == '*' ) {
			emote = 1;
			verb = verb[0..<2];
			}
	}
        // Check if this is a channel messsage.
	if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;
        if(!objectp(me)) return 0;
	// check if this channel support emote message. by ken at 98-3-30
	if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
		write("�Բ������Ƶ����֧�� emote ��\n");
		return 1;
	}
	//now we can be sure it's indeed a channel message:
	if (!stringp(arg) || arg == "" || arg == " ") arg = "...";
	if(remote) arg_bk = arg;

	// add by ken for filter channel not define intermud at 1998/06/24
	if( !userp(me) ) {
		if( sprintf("/%O", previous_object()) == GCHANNEL
			&& channels[verb]["intermud"] != GCHANNEL ) {

			log_file("channel",
				sprintf("\nfrom: %O \n"
					"who: %s\n"
					"channel: %s\n"
					"message: %s\n"
					"error: remote host want use gchannel send local channel message.\n"
					"time: %s\n",
					previous_object(),
					me->query("channel_id"),
					verb, arg, ctime(time()) ) );
			return 1;
			}
	}


	// check if one can write to channels
	// only block rumor or chat...
	if ( me->query("chblk_on") ) {
		me->set("chblk_rumor", 1);
		me->set("chblk_chat", 1);
	}

	// player broadcasting need consume jing
	if(me&&environment(me)&&
	  userp(me)&&!wizardp(me)&&environment(me)->query("no_channel"))
	   if(stringp(environment(me)->query("no_channel")))
	     return notify_fail(environment(me)->query("no_channel"));
	   else return notify_fail("���ﲻ��ʹ��Ƶ����\n");
	if( userp(me) && !wizardp(me) && verb == "rumor" )
		if(me->query("gin") > 50) me->add("gin", 0-random(36));
			else
		return notify_fail("���Ѿ�û����ɢ��ҥ���ˣ�\n");


	// check if rumor or chat is blocked
	if ((me->query("chblk_rumor") && (verb == "rumor"))||
		((verb == "rumor") && BLOCK_RUMOR))
	return notify_fail("���ҥ��Ƶ�����ر��ˣ�\n");
        
	if ((me->query("chblk_chat") && (verb == "chat" || verb == "es"|| verb == "dt" ))||
		((verb == "chat" || verb == "dt" ) && BLOCK_CHAT))
		return notify_fail("�������Ƶ�����ر��ˣ�\n");
                
        
	if( userp(me) ) {
		if( channels[verb]["wiz_only"] && !wizardp(me)) return 0;
	}
	//this is the party channel.
	if(channels[verb]["party_only"] && !me->query("family/family_name"))
		return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

	if (channels[verb]["party_only"]) {
		party = me->query("family/family_name");
		channels[verb]["msg_speak"] = HIG "��"+party+"��%s��%s\n" NOR;
		channels[verb]["msg_emote"] = HIG "��"+party+"��%s" NOR;
	}
     //this is the party channel.
     //this is the banghui channel.
       if(channels[verb]["banghui_only"] && !me->query("shili"))
		return notify_fail("�㻹���ȼ���һ����ᣨ��������˵�ɡ�\n");

	if (channels[verb]["banghui_only"]) {
		shili =get_shili(me);
		channels[verb]["msg_speak"] = YEL "��"+shili+"��%s��%s\n" NOR;
		channels[verb]["msg_emote"] = YEL "��"+shili+"��%s" NOR;
	}
  //this is the banghui channel.
	// check if same channel message but not wizard
	if( !wizardp(me)&&userp(me))
		if( arg==(string)me->query_temp("last_channel_msg") )
	return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");
	//��ֹflood,add by yanyan.
	if(me->query("no_channel_cnt")){
	  if(time()-me->query("no_channel_time")<60*me->query("no_channel_cnt"))
	 return notify_fail(HIR"��Ϊ��Ƶ��������Ϣ���Ѿ����ͷ���"+chinese_number(me->query("no_channel_cnt"))+
	  "���ӡ�����ʹ��Ƶ��������\n"HIR);
	  else{
	   me->delete("no_channel_cnt");
	   me->delete("no_channel_time");
	  }
	}
	
    	if(!wizardp(me)&&userp(me)) {
		me->set_temp("last_channel_msg", arg);
		me->add_temp("channel_msg_cnt", 1);
		if(time()-me->query_temp("channel_msg_time")<=2)
		 me->add_temp("channel_flood_times",1);
		else
		 me->set_temp("channel_flood_times",0);
		
		if(me->query_temp("channel_flood_times")>=10){
		  tell_object(me,HIR"\n��Ϊ��Ƶ��������Ϣ�������ͷ�����ʮ���ӡ�����ʹ��Ƶ��������\n"HIR);
		  me->set("no_channel_time",time());
		  me->set("no_channel_cnt",20);
		  message("vision",HIG"��Ƶ��������Ϊ"+me->name()+HIG+"��������Ϣ�������Ӿ��棬�����ͷ�����ʮ���ӡ�����ʹ��Ƶ��������\n",users());
		  return 0;
		}
		else
		if(me->query_temp("channel_flood_times")>=5)
		 tell_object(me,HIR"\n�������Ƶ��˵�����㽫���ͷ�����ʮ���ӡ�����ʹ��Ƶ��������\n"HIR);
		
		me->set_temp("channel_msg_time",time());
	
		
	}

	// If we speaks something in this channel, then must tune it in.
	tuned_ch = me->query("channels");
	if( !pointerp(tuned_ch) )
		me->set("channels", ({ verb }) );
	else if( member_array(verb, tuned_ch)==-1 )
		me->set("channels", tuned_ch + ({ verb }) );
//	}

	// Support of channel emote
	if( emote && me->is_character() && !remote) {
	string vb, emote_arg, id, mud;

	if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
		vb = arg;
		emote_arg = "";
		}
    if( channels[verb]["intermud_emote"]
		&& sscanf(emote_arg, "%s@%s", id, mud)==2 ) {
		REMOTE_Q->send_remote_q(mud, verb, me->query("id"), id, vb);
		write("��·ѶϢ���ͳ������Ժ�\n");
		return 1;
		}

	if( channels[verb]["intermud_emote"] ){
	        if(verb=="dt")
		  arg = EMOTE_D->do_emote(me, vb, emote_arg,8);
		else if(verb=="es")
		 arg = EMOTE_D->do_emote(me, vb, emote_arg,9);
		else arg = EMOTE_D->do_emote(me, vb, emote_arg,8);}
	else if( verb == "rumor" )
		arg = EMOTE_D->do_emote(me, vb, emote_arg, 2, 
			random(100)>10?channels[verb]["anonymous"]:
			me->name()+HIM+"(" + capitalize(me->query("id")) + ")"
		);
	else 	
	arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
       
	if (!arg && emote) {

		// we should only allow chinese emote.
		if( vb[0] < 128 ) return notify_fail("�Բ���û����� emote��\n");

		arg = sprintf("%s(%s@%s)%s\n",me->name(),me->query("id"),Mud_name(),vb);
		if( verb == "rumor" ) {
			if( userp(me) )
				arg = sprintf("%s%s\n",random(100)>10 ? 
					channels[verb]["anonymous"]:me->name() + "(" +
					capitalize(me->query("id")) + ")",vb);
			else
				arg = sprintf("%s%s\n",channels[verb]["anonymous"],vb);
		}
	}

	if( !arg ) {
		if( channels[verb]["anonymous"] ) 
			arg = channels[verb]["anonymous"]+vb+" "+emote_arg+"\n"; 
		else if( channels[verb]["intermud_emote"] )
			arg = sprintf("%s(%s@%s)%s %s\n", me->name(),
				capitalize(me->query("id")), INTERMUD_MUD_NAME, vb, emote_arg);
		else	arg = me->name()+vb+" "+emote_arg+"\n"; 
		}
	}
	
	// Make the identity of speaker.
	
	if( channels[verb]["anonymous"] ) {
		if (userp(me)) {
			who = random(100) > 10 ? channels[verb]["anonymous"]:me->name()+HIM
				+"(" + capitalize(me->query("id")) + ")";
			message("system",HIR+"��ϵͳ��Ƶ�����飺"+me->query("name")+HIR+"("+me->query("id")+")"+
			 "������ҥ��Ƶ��������Ϣ��\n",filter_array(users(),"filter_wiz",this_object()));
									
		}
		else	who = channels[verb]["anonymous"];
	}

	else if(!userp(me)){
		who=me->query("channel_id");
		if(!who) who=me->name();
		if(!who) who="δ֪";
		}
	else if(userp(me)) //changed by Yanyan for name with color
	     if(channels[verb]["party_only"])
	     who = me->name() +HIG+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(channels[verb]["banghui_only"])
	     who = me->name() +YEL+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(channels[verb]["wiz_only"])
	     who = me->name() +HIY+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(verb=="sys")
	     who = me->name() +HIR+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(verb=="rumor")
	     who = me->name() +HIM+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(verb=="dt")
	     who = me->name() +WHT+ "(" + capitalize(me->query("id")) + ")";
	     else
	     if(verb=="es")
	     who = me->name() +HIG+ "(" + capitalize(me->query("id")) + ")";
	     else
	     who = me->name() +HIC+ "(" + capitalize(me->query("id")) + ")";
	     
             //changed by Yanyan for name with color
             
//	the channel "adm" modify by ken at 1998-06-19
	if( verb == "adm" ) {
		who = sprintf("��%s��", me->rank());
		who = replace_string(who," ","");
		who = replace_string(who,NOR,"");
		who += sprintf("%s(%s)", me->name(),capitalize(me->query("id")));
	}

	// Ok, now send the message to those people listening us.
	ob = filter_array( users(), "filter_listener", this_object(), channels[verb],party,me->query("shili/name") );

	if( !arg || arg == "" || arg == " " ) arg = "...";
	if(verb=="rumor"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIM);
	else 
	if(verb=="sys"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIR);
	else
	if(verb=="wiz"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIY);
	else
	if(verb=="gwiz"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIG);
	else
	if(verb=="chat"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIC);
	else
	if(verb=="sale"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIC);
	else
	if(verb=="dt"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+WHT);
	else
	if(verb=="es"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIG);  //There add by Yanyan for color name
	else
	if(verb=="chat"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIC);
	else
	if(verb=="party"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+HIG);
	else
	if(verb=="banghui"&&stringp(arg))
	arg=replace_string(arg,NOR,NOR+YEL);
	else
	if(stringp(arg))
	arg=replace_string(arg,NOR,NOR+CYN);
	if(stringp(arg))
	arg +=NOR;
  //      if(wizardp(me)) arg=BGRN+HIW+arg+NOR; modify by Yanyan
//        if(wizardp(me)) arg= HIW+arg+NOR;         // zpqs modify
	if( emote ) {
		string localmsg;
		string ecol=channels[verb]["msg_color"];
		if(remote) {
			arg=arg_bk;
		}

		if (!stringp(arg) || arg == "0" ) return 0;

		localmsg = arg;

		if ( channels[verb]["msg_emote"] )
			localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

		if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
		else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);

		if( !stringp(localmsg) ) return 0;
			message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],
				sprintf(localmsg,ecol,ecol,ecol)+"\n"), ob );
	}
	else	message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg ), ob );

	//if(verb == "chat" || verb == "rumor" || verb == "dt")
          //      WWW_CHANNEL->init_msg_base(sprintf( channels[verb]["msg_speak"], who, arg ),ob);

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
		}
        
	if( !undefinedp(channels[verb]["intermud"]) && me->is_character()) {
		channels[verb]["intermud"]->send_msg(
		channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
		channels[verb]["filter"] );
	}

	return 1;
}

int filter_listener(object ppl, mapping ch,string party,string shili)
{
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;

	if( ch["arch_only"])
		if( userp(ppl) )
			if( wiz_level(ppl) < wiz_level("(adept)") )
				return 0;

	if( ch["wiz_only"] ) 
		if( userp(ppl) )	
			return wizardp(ppl);

	if( ch["es_only"] ) {
		if( wiz_level(ppl) > 0 ) return 1;
//                if( ppl->query("age") > 23 ) return 1;
                     return 1;
	}
	if (ch["party_only"])
		return (wizardp(ppl)
		&& (!ppl->query("env/party") || ppl->query("env/party")==party))
		|| party == ppl->query("family/family_name");
	if (ch["banghui_only"])
		return (wizardp(ppl)
		&& (!ppl->query("env/party") || ppl->query("env/party")==party))
		|| shili == ppl->query("shili/name");
	
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;
	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
	if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
	channels[channel]["extra_listener"] += ({ ob });
	}
	else  channels[channel]["extra_listener"] = ({ ob });
}

string remove_addresses(string msg, int all)
{
	int i;
	mixed tmp;
	string pattern;

	if(!stringp(msg)) return msg;
	if( all )
		pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
	else
		pattern = "[(][A-Za-z]+@"+Mud_name()+"[)]";

	tmp = reg_assoc(msg, ({pattern}), ({1}));

	if(!arrayp(tmp)) return msg;
	msg = "";
	for(i=0; i< sizeof(tmp[0]); i++)
		if( tmp[1][i] == 0 ) msg += tmp[0][i];
	return msg;
}
int filter_wiz(object ob)
{
  if(wizardp(ob)) return 1;
  return 0;
}
