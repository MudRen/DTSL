// look.c
//modify by yanyan.2001.  

#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 ((time())*60)
#define MAX_LIGHT_TIME 1200

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string unique_long(object obj);
string unique_armor_long(object obj);

string power_level(int power);
string query_equip(object obj);

string *power_level_desc = ({
	BLU "����һ��" NOR,	BLU "����ҳ�" NOR,	BLU "��ѧէ��" NOR,
	BLU "�Կ��ž�" NOR,	BLU "��ͨƤë" NOR,	BLU "ƽƽ����" NOR,
	HIB "����ͨͨ" NOR,	HIB "������" NOR,	HIB "����С��" NOR,
	HIB "��������" NOR,	HIB "�������" NOR,	HIB "����С��" NOR,
	CYN "�������" NOR,	CYN "��Ȼ���" NOR,	CYN "���д��" NOR,
	CYN "�����뻯" NOR,	CYN "��Ȼ��ͨ" NOR,	CYN "���д��" NOR,
	HIC "��������" NOR,	HIC "��������" NOR,	HIC "¯����" NOR,
	HIC "�����޵�" NOR,	HIC "�Ƿ��켫" NOR,	HIC "һ����ʦ" NOR,
	HIR "������" NOR,	HIR "��ɲ�" NOR,	HIR "���˺�һ" NOR,
});

string *clr_msg=({"RED","GRN","YEL","BLU","MAG","CYN","WHT",
		"HIR","HIG","HIY","HIB","HIM","HIC","HIW","BLK"		
});
string *clr=({RED,GRN,YEL,BLU,MAG,CYN,WHT,
		HIR,HIG,HIY,HIB,HIM,HIC,HIW,BLK		
});
string *per_msg_male1 = ({
	CYN "����ΰ��Ӣͦ������֮�䣬��ɷ��\n" NOR,
	CYN "����Ӣΰ������������ȷʵ���������\n" NOR,
});
string *per_msg_male2 = ({
	CYN "Ӣ��������������档\n" NOR,
	CYN "��ò���ڣ���Ŀ���ʡ�\n" NOR,
	CYN "��ò���棬���˷��ס�\n" NOR,
});
string *per_msg_male3 = ({
	CYN "��òƽƽ��ûʲô�ÿ��ġ�\n" NOR,
	CYN "��ٶ�����\n" NOR,
});
string *per_msg_male4 = ({
	CYN "��ò�׶��������⡣\n" NOR,
	CYN "�������ۣ��������硣\n" NOR,
});
string *per_msg_male5 = ({
	CYN "����һ�����Ѳ��ۣ��˾˲�����ģ����\n" NOR,
	CYN "��������ģ�һ���޾���ɵ�ģ���� \n" NOR, 
	CYN "������֣���ͷ������������˽�ı��ҡ� \n" NOR, 
});
string *per_msg_female1 = ({
	CYN "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� \n" NOR,
	CYN "������������Ŀ���飬����һЦ������������Ȼ�Ķ��� \n" NOR,
	CYN "�������֣��������ˣ��������Ҽ������� \n" NOR, 
	CYN "��ۼ���ף������˼����ӣ�\n" NOR,
});
string *per_msg_female2 = ({
	CYN "������������ɫ���������˶��ˡ� \n" NOR,
	CYN "���潿�ݻ���¶������ϸ�������̡� \n" NOR,
	CYN "����κ죬�ۺ��ﲨ������Ͷ��֮�䣬ȷ��һ�����ϡ� \n" NOR,
	CYN "�г�������֮��,�����߻�֮ò��\n" NOR,
});
string *per_msg_female3 = ({
	CYN "���㲻�Ͼ������ˣ�Ҳ���м�����ɫ�� \n" NOR,
	CYN "���û��������м�����ɫ��\n" NOR,
});
string *per_msg_female4 = ({
	CYN "��òƽƽ,�����ù�ȥ��\n" NOR,
});
string *per_msg_female5 = ({
	CYN "���ñȽ��ѿ��� \n" NOR,
	CYN "���á���������\n" NOR,
});
string *per_msg_kid1 = ({
	CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
	CYN "������ã���̬�Ƿ���\n" NOR,
	CYN "�������£�ɫ��������\n" NOR,
});
string *per_msg_kid2 = ({
	CYN "¡����ۣ���ɫ����\n" NOR,
	CYN "�����ལ�����ϲ����\n" NOR,
	CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});
string *per_msg_kid3 = ({
	CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
	CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
});
string *per_msg_kid4 = ({
	CYN "����󰫣�ɵ��ɵ����\n" NOR,
	CYN "��ٲ�������֫���ࡣ\n" NOR,
});
string *per_msg_kid5 = ({
	CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
	CYN "����ľ�������в�ɫ��\n" NOR,
});

string ride_suffix(object me)
{
	string ridemsg=0;
	object ridee;
	if (ridee = me->ride()) { 
		if (environment(ridee) != environment(me) ||
		!living(ridee) || !living(me)) {
			me->delete_temp("ridee");
			ridee->delete_temp("rider");
			ridee=0;
		}else ridemsg = ridee->query("ride/msg")+"��"+ridee->name()+"��";
	}
	if (! ridee) {
	me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
	me->set_temp("ride/dodge",0);
	}
	return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;
	string str;

	if(environment(me)&&stringp(str=environment(me)->query("no_look_msg"))
	   &&!wizardp(me) ) return notify_fail(str);

	if(!arg) result = look_room(me, environment(me));
	else if((obj = present(arg, me)) || (obj = present(arg, environment(me))) ){
			if(obj->is_character() && !obj->query("carrier") ) 
				result = look_living(me, obj);
			else result = look_item(me, obj);
		}
		else if(wizardp(me)&& (obj = find_player(arg)) ) 
			result = look_living(me, obj);
		else result = look_room_item(me, arg);
	return result;
}
int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str,str1="",str2,*dirs,long,color,ridemsg = "";
	object room;

	if(!env){
		write(HIY"������ܻ����ɵ�һƬ��ʲôҲ��������\n"NOR);
		me->move(VOID_OB);
		return 1;
	}

	if (NATURE_D->is_look_night(me,env)) 
			long=HIB"���ܹ��ߺܰ����������һƬ��ʲôҲ�����������̧ͷ������
�գ����������ҹ���з�����˸�����Ӻ���һ������㻮�����һ��
������¸߹������֮�С�\n"NOR;
		else long=env->query("long");

	color=NATURE_D->outdoor_room_outcolor();
	for(i=0; i<sizeof(clr_msg); i++)
		if(color==clr_msg[i]){color=clr[i];i=20;}
	if(i!=21) color="";

	str=sprintf( "%s - %s\n����%s"+color+"%s"+NOR,
		env->query("short"),wizardp(me)? file_name(env):"",long,
		env->query("outdoors")? NATURE_D->outdoor_room_description():"");

	if(mapp(exits = env->query("exits"))) 
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if((int)env->query_door(dirs[i],"status") & DOOR_CLOSED) dirs[i] = 0;
		dirs -= ({ 0 });
		if(sizeof(dirs)==0) 
			str+="��������û���κ����Եĳ�·��\n";
		else 
		if( sizeof(dirs)==1 ){ 
			//str+="��������Ψһ�ĳ����� "HIY+dirs[0]+HIW"��\n"NOR;
			room = load_object(exits[dirs[0]]);
			if(objectp(room)&&room->valid_leave(me,dirs[0]))
			str+="��������Ψһ�ĳ����� "HIY+dirs[0]+NOR+"("+HIG+room->query("short")+NOR+")��\n"NOR;
		}
		else {
			//changed by Yanyan 2004.9.24
			/*str += sprintf("�����������Եĳ����� "HIY"%s"HIW" �� "HIY"%s"HIW"��\n"NOR,
				implode(dirs[0..sizeof(dirs)-2], HIW"��"HIY), dirs[sizeof(dirs)-1]);*/
			str += "�����������Եĳ�����";
			for(i=0;i<sizeof(dirs);i++){
				room = load_object(exits[dirs[i]]);				
                if(objectp(room)){
					str += HIY+dirs[i]+NOR+"("+HIG+room->query("short")+NOR+")";
					if(i>0&&i<sizeof(dirs)-1&&(i+1)%2==0)
						str += "\n"+"����                ";
					else
					if(i<sizeof(dirs)-1)
						str += "��";
                }
			}
			str += "\n";
		}
		
	}

	inv = all_inventory(env);
	i=sizeof(inv);
	if(NATURE_D->is_look_night(me,env)){
			while(i--){
			if( !me->visible(inv[i]) ) continue;
			if( inv[i]==me ) continue;
			if( inv[i]->query("no_shown")&& (!wizardp(me) || !me->query("env/shown"))) continue;
			
			if (ridemsg = ride_suffix(inv[i]))
				str1 = "  һ�����ʵ���Ӱ�����������˭ <"+ridemsg+">\n"+str1;
			else if(inv[i]->is_character() && (inv[i]->query("race")=="����"
				|| inv[i]->query("race")=="��ħ") )
				str1= "  һ�����ʵ���Ӱ�����������˭��\n"+str1;
			else if( inv[i]->is_character() && inv[i]->query("race")=="Ұ��" )
				str1 = "  "+inv[i]->short()+"\n"+str1;
			else str1="  һ��ģģ�����Ķ�����\n"+str1;
		}
        }
	else while(i--){
		if( !me->visible(inv[i]) ) continue;
		if( inv[i]==me ) continue;
		if( inv[i]->query("no_shown")&& (!wizardp(me) || !me->query("env/shown"))) continue;
		if(ridemsg=ride_suffix(inv[i])) str2="��"+inv[i]->short()+" <"+ridemsg+">";
		else{ 
		if(inv[i]->query("teams")) str2=" "+"һȺ"+inv[i]->short(); //add by yanyan.
		else str2="��" + inv[i]->short();
		}
		if(wizardp(me)) str1=str2+"  "+base_name(inv[i])+"\n"+str1;
		else str1=str2+"\n"+str1;
	}
        write(str+str1);
        return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;
	string position,look_msg,carrier;

	if(obj->query("no_show_cont")) return 1;
	
	if(obj->query("skill_type")||obj->query("armor_prop"))
	 me->start_more(unique_long(obj));
	else
	me->start_more(obj->long());
	
	inv = all_inventory(obj);
	if(sizeof(inv)){
		inv = map_array(inv, "inventory_look", this_object());
		carrier=obj->query("carrier");
		if(!carrier || carrier==""){
			carrier="��";
			message("vision", sprintf(carrier+"����װ�ţ�\n%s\n",
				implode(inv, "\n") ), me);
		}
		else if(look_msg=obj->query("look_msg")){
		message("vision", sprintf("%s\n%s\n", look_msg,
			implode(inv, "\n") ), me);
		}else{
		position=obj->query("position");
		if(!position || position=="") position="��";
		message("vision", sprintf("%s���У�\n%s\n", position,
			implode(inv, "\n") ), me);
		}
	}
        return 1;
}
string per_status_msg(int age, int per, string gender)
{
	if (age < 14) {
		if ( per>=25 )
			return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
		else if ( per>=20 )
			return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
		else if ( per>=15 )
			return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
		else if ( per>=10 )
			return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
		else return ( per_msg_kid5[random(sizeof(per_msg_kid5))]);
		}
		
	if ( gender == "����" ) {
		if ( per>=25 )
			return ( per_msg_male1[random(sizeof(per_msg_male1))]);
		else if ( per>=20 )
			return ( per_msg_male2[random(sizeof(per_msg_male2))]);
		else if ( per>=15 )
			return ( per_msg_male3[random(sizeof(per_msg_male3))]);
		else if ( per>=10 )
			return ( per_msg_male4[random(sizeof(per_msg_male4))]);
		else return ( per_msg_male5[random(sizeof(per_msg_male5))]);
		}
		
	if ( gender == "Ů��" ) {
		if ( per>=25 )
			return ( per_msg_female1[random(sizeof(per_msg_female1))]);
		else if ( per>=20 )
			return ( per_msg_female2[random(sizeof(per_msg_female2))]);
		else if ( per>=15 )
			return ( per_msg_female3[random(sizeof(per_msg_female3))]);
		else if ( per>=10 )
			return ( per_msg_female4[random(sizeof(per_msg_female4))]);
		else return ( per_msg_female5[random(sizeof(per_msg_female5))]);
		}
	else return "";
}
string query_power(object me)
{
	mapping action;
	string skill_name;
	int attack_points;
	
	if(!me->query("actionp")){
  	skill_name=me->reset_action(me->query_temp("weapon"));
    action=me->query("actions");
  }
  else{
  	action=me->query("actionp");
    skill_name=action["skill_name"];
  }


	attack_points = COMBAT_D->get_damage(me,0,me->query_temp("weapon"),action,0,skill_name);

	return  power_level(attack_points*15);
}
string power_level(int power)
{

	int lvl;
	int rawlvl;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl);
                        if( lvl >= sizeof(power_level_desc) )
                                lvl = sizeof(power_level_desc)-1;
                        return power_level_desc[((int)lvl)];
}

string apply_msg(int p)
{
  if(p==0)
   return "����ɱ��";
  else
  if(p<3)
   return CYN"�Դ�ɱ��"NOR;
  else
  if(p<7)
   return HIR"ɱ��΢��"NOR;
  else
  if(p<10)
   return HIR"ɱ����Ũ"NOR;
  else return RED"ɱ��Ũ��"NOR;
}
  

int look_living(object me, object obj)
{
	string str,limb_status,ridemsg,pro,ogender,orace;
	mixed *inv;
	mapping my_fam,fam,ofamily;
	int oage;
 
	ofamily=obj->query("family");
	ogender=obj->query("gender");
	orace=obj->query("race");
	oage=obj->query("age");

	if(obj->query("fake_age") ) oage=obj->query("fake_age");

	if( me!=obj )
	      if(me->query("id")==obj->query("couple/couple_id"))
	        if(me->query("gender")=="����")
	        message("vision", "����ɷ�"+me->name() + "������ؿ����㡣\n", obj);
	        else message("vision", "�������"+me->name() + "������ؿ����㡣\n", obj);
	     else if(me->query("id")==obj->query("home/mother_id"))
	        message("vision","���ĸ��"+me->name()+"������������㡣\n",obj);
	      else if(me->query("id")==obj->query("home/father_id"))
	        message("vision","��ĸ���"+me->name()+"������������㡣\n",obj);
	     else if(me->query("home/father_id")==obj->query("id")||
	            me->query("home/monther_id")==obj->query("id"))
	          message("vision","��ĺ���"+me->name()+"�������㡣\n",obj);
	        else message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);
        
	str = obj->long();
    if(obj->query("teams")) {write(str);return 1;} //add by yanyan.
	str = replace_string(str, "$n", me->name());
	str = replace_string(str, "$N", obj->name());
str = replace_string(str, "$C", RANK_D->query_respect(obj));
	str = replace_string(str, "$c", RANK_D->query_rude(obj));
	str = replace_string(str, "$R", RANK_D->query_respect(me));
	str = replace_string(str, "$r", RANK_D->query_rude(me));


	pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

	ridemsg = ride_suffix(obj);
	if (ridemsg) str+=pro+"��"+ridemsg+"��\n";

	if( orace=="����" && intp(oage) )
		if(oage<10) str+=sprintf("%s��������Ȼ������ʮ�ꡣ\n", pro);
		else str+=sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(oage/10*10));

	if(obj->query("id")==me->query("couple/couple_id") ) {
		if( (string)me->query("gender")=="Ů��" ){
		str += sprintf("%s������ɷ�\n", pro);
		}
		else{
	str += sprintf("%s��������ӡ�\n", pro);
		}
	}
	if(obj->query("home/mother_id")==me->query("id")||
	   obj->query("home/father_id")==me->query("id")){
	   if(obj->query("gender")=="Ů��")
	     str+=sprintf("%s�����Ů��.\n",pro);
	   else str+=sprintf("%s����Ķ���.\n",pro);}
	if(me->query("home/mother_id")==obj->query("id")||
	   me->query("home/father_id")==obj->query("id")){
	   if(obj->query("gender")=="Ů��")
	     str+=sprintf("%s�����ĸ��.\n",pro);
	   else str+=sprintf("%s����ĸ���.\n",pro);}
	if(me->query("id")==obj->query("couple/couple_id"))
          if(obj->query("gender")=="Ů��")
           if(obj->query("makelove_times")&&obj->query("makelove_times")<4) str+=sprintf("���Ѿ��������ˡ�\n");
           else if(obj->query("makelove_times")&&obj->query("makelove_times")<40) str+=sprintf("���Ѿ�����"+chinese_number(obj->query("makelove_times")/4)+
                      "�������ˡ�\n");     
	if( obj!=me && mapp(fam = ofamily) && mapp(my_fam = me->query("family")) 
	&& fam["family_name"] == my_fam["family_name"] ) {
		if( fam["generation"]==my_fam["generation"] ) {
			if( ogender == "����" ) str += sprintf( pro + "�����%s%s��\n",
				my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
				my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else str += sprintf( pro + "�����%s%s��\n",
				my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
				my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		}else
		if( fam["generation"] < my_fam["generation"] ) {
			if(member_array(my_fam["master_id"],obj->parse_command_id_list())>-1)
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else str += pro + "�����ʦ�塣\n";
		}else{
		if( fam["generation"] - my_fam["generation"] > 1 )
			str += pro + "�����ͬ������\n";
		else if( fam["master_id"] == me->query("id") )
			str += pro + "����ĵ��ӡ�\n";
		else str += pro + "�����ʦֶ��\n";
		
		}
	}

	if( obj->query("max_kee") )
		str+=pro+COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

	if( obj->query("looking") ){
		str += pro + (string)obj->query("looking") + "\n";
	} else {
		string looking= per_status_msg((int)obj->query("age"),(int)obj->query_per(), ogender);
		if( orace!="����" || base_name(obj)==CORPSE_OB ) looking="";
		if( strlen(looking)>1) str += pro + looking;
	}
	if(me->query("combat_exp")+200000>obj->query("combat_exp")||me==obj)
	{str+=pro+sprintf("�书����������");
	str+=query_power(obj)+"��\n";}
	else  if(obj->query("race")=="����")
	      if(obj->query("gender")=="����")str+="�����书��������ǳ��\n";
	      else str+="�����书��������ǳ��\n";
        if(me->query("shili")&&obj->query("shili")&&
        me->query("shili/name")==obj->query("shili/name")&&me!=obj)
		     str +=pro +"�Ǻ���ͬһ�������ˡ�\n";
	if(userp(obj) && ((int)(obj->query("food")*10/obj->max_food_capacity())<3
		||(int)(obj->query("water")*10/obj->max_water_capacity())<3) )
		str+=pro+"������"MAG"��������"NOR"��\n";
	if(userp(obj) && (int)obj->query_encumbrance()* 10/(int)obj->query_max_encumbrance()>6)
		str+=pro+"������"MAG"�ж�����"NOR"��\n";
	if(obj->query("bellicosity")>40000) str+=pro+"������"MAG"ɱ������"NOR"��\n";
        
       // str +=pro+"������"+apply_msg(obj->query("apply_points"))+"��\n";
        if(obj->query_temp("bsy_skill_damage")
        &&time()-obj->query_temp("bsy_damage_time")<obj->query_temp("bsy_skill_damage")/7)
        str +=pro+"�������Ѿ����˲���ӡ�����ˡ�\n";
        
        if(obj->query_temp("csj_skill_damage")
        &&time()-obj->query_temp("csj_damage_time")<obj->query_temp("csj_skill_damage")/7)
        str +=pro+"�������Ѿ����˳����������ˡ�\n";
        
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
	str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ��ţ�\n%s\n",
	pro, implode(inv, "\n") );
	}
	
	me->start_more(str);

	if( obj!=me && living(obj)
		&&!environment(obj)->query("no_fight")
		&&!environment(obj)->query("sleep_room")
		&& obj->query("bellicosity")-1000 > (int)me->query("bellicosity")
	   &&me->query("id")!=obj->query("couple/couple_id")&&
	   me->query("home/mother_id")!=obj->query("id")&&me->query("home/father_id")!=obj->query("id")
	   &&obj->query("home/mother_id")!=me->query("id")&&obj->query("home/father_id")!=me->query("id")
	   &&!obj->is_busy()){
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str=obj->short();
	if( obj->query("equipped") ) str = HIM"��"NOR+ query_equip(obj);
	else if( !flag ) str = "  " + str;
	else return 0;
	return str;
}

string query_equip(object obj)
{
        string str,units;

        units =obj->query("unit");
        str = obj->name();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "��һ"+ units + str;
                        break;
                case "boots":
                        str = "���ϴ���һ" + units + str;
                        break;
                case "head":
                case "neck":
                case "wrists":
                case "finger":
                case "hands":
                        str ="����һ"+ units + str;
                        break;
                case "waist":
                        str = "��������һ"+units+str;
                        break;
                default:
                        str = "װ����"+str; 
                        }
        else
        if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="���ϴ���"+str;
                else
                str ="�ֳ�һ" + units + str;
        return str;     
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !env = environment(me) ){
		write(HIY"������ܻ����ɵ�һƬ��ʲôҲ��������\n"NOR);
		me->move(VOID_OB);
		return 1;
	}
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ){
		if( stringp(item[arg]) ) write(item[arg]);
		else if( functionp(item[arg]) ) write((string)(*item[arg])(me));
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = load_object(exits[arg])) ) look_room(me, env);
		else return notify_fail("�Ǳߺ���û��ʲô��\n");
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

string *wdamage=({
BLU"Ѱ������"NOR,BLU"΢������"NOR,HIB"��΢����"NOR,HIB"�ľ�����"NOR,CYN"�ϴ�����"NOR,
CYN"�޴�����"NOR,GRN"��ͬ����"NOR,GRN"�����ױ�"NOR,HIC"�޿�ƥ��"NOR,HIC"��������"NOR,
HIY"���亱��"NOR,HIY"������˫"NOR,HIG"��������"NOR,HIG"��ǰ����"NOR,HIW"�����"NOR,
HIW"�������"NOR,HIR"��ɽ�Ϻ�"NOR,HIR"���춯��"NOR,RED"�������"NOR,RED"�����޾�"NOR,
});

string *wstrong=({
BLU"��΢"NOR,BLU"����"NOR,HIB"����"NOR,CYN"�ϴ�"NOR,GRN"�ܴ�"NOR,HIC"��ͬ����"NOR,
HIY"�����ױ�"NOR,HIG"�޿�ƥ��"NOR,HIW"���亱��"NOR,HIR"������˫"NOR,
});

string *strongs=({BLU"����һ��"NOR,BLU"�����ʵ"NOR,HIB"�ȽϽ�ʵ"NOR,GRN"�ǳ���ʵ"NOR,
GRN"����쳣"NOR,HIG"�᲻�ɴ�"NOR,HIR"�޿�ƥ��"NOR,});

string *supers=({
"��΢��Щ����","΢��һЩ����","��Щ����","�ȽϷ���","�ǳ�����",
"�쳣����","���д�ë�Ϸ���ķ���","�������������ķ���",
"��ɽնʯ��ķ���",
});

string *levs=({
BLU"����"NOR,HIB"����"NOR,CYN"����"NOR,GRN"Щ��"NOR,HIC"����"NOR,
HIY"�϶�"NOR,HIG"�ܶ�"NOR,HIW"����"NOR,HIR"����"NOR,RED"����"NOR,
});

string unique_long(object obj)
{
   string longs;
   
   int min_damage,max_damage;
   int super=0;
   int dodge=0,parry=0,armor=0,enhance_min_damage=0,enhance_max_damage=0,double_damage=0;
   int intl=0,con=0,dex=0,str=0,kar=0,per=0;
   int flag=0;
   int wield_str,wield_con,wield_dex,wield_int;
   int wield_force,wield_maxforce;
   int line1_flag=0,line2_flag=0,line3_flag=0,line4_flag=0,line5_flag=0,need_flag=0;
   
   int no_need_force=0,no_need_maxforce=0,no_need_sx=0;
   int reduce_force=0,reduce_maxforce=0,reduce_sx=0;
   
   int weapon_or_armor;
   string obj_type,equip_type;
   
   if(obj->query("weapon_prop")){
    obj_type="weapon_prop";
    equip_type="wield";
    weapon_or_armor=1;
   }
   else{
    obj_type="armor_prop";
    equip_type="wear";
    weapon_or_armor=0;
   }
    
   min_damage=obj->query(obj_type+"/min_damage")+obj->query("user_skill")/10;
   max_damage=obj->query(obj_type+"/damage")+obj->query("user_skill")/10;
   super=obj->query("super");
   
   dodge=obj->query(obj_type+"/dodge");
   if(dodge<0) dodge=0;
   
   if(weapon_or_armor)
    parry=obj->query("weapon_prop/armor");
   else{
    armor=obj->query("armor_prop/armor");
    if(armor<0) armor=0;
    parry=obj->query("armor_prop/parry");
   }
   
   enhance_min_damage=obj->query(obj_type+"/enhance_min_damage");
   enhance_max_damage=obj->query(obj_type+"/enhance_max_damage");
   double_damage=obj->query(obj_type+"/double_damage");
   intl=obj->query(obj_type+"/intelligence");
   con=obj->query(obj_type+"/constitution");
   dex=obj->query(obj_type+"/dodgeaction");
   str=obj->query(obj_type+"/strength");
   kar=obj->query(obj_type+"/karma");
   per=obj->query(obj_type+"/personality");
   
   wield_str=obj->query(equip_type+"_str");
   wield_dex=obj->query(equip_type+"_dex");
   wield_con=obj->query(equip_type+"_con");
   wield_int=obj->query(equip_type+"_int");
   wield_force=obj->query(equip_type+"_force");
   wield_maxforce=obj->query(equip_type+"_maxforce");
   
   no_need_force=obj->query("no_need_force");
   no_need_maxforce=obj->query("no_need_maxforce");
   no_need_sx=obj->query("no_need_sx");
   
   reduce_force=obj->query("reduce_force");
   reduce_maxforce=obj->query("reduce_maxforce");
   reduce_sx=obj->query("reduce_sx");
   
   if(!obj->query("long"))
    obj->set("long",obj->short()+"\n");
   longs=obj->query("long");
   
   if(weapon_or_armor)
   longs+="�����پ��С�"+wdamage[min_damage/25>sizeof(wdamage)-1?sizeof(wdamage)-1:min_damage/25]+"�������������ɴﵽ"+
              "��"+wdamage[max_damage/25>sizeof(wdamage)-1?sizeof(wdamage)-1:max_damage/25]+"����������\n";
   else
   longs+="�����С�"+wstrong[armor/25>sizeof(wstrong)-1?sizeof(wstrong)-1:armor/25]+"���ķ�����\n";
   
   if(dodge>0){
	  longs+="���ĸ�������Ϊ��\n��"+levs[dodge/10>sizeof(levs)-1?sizeof(levs)-1:dodge/10]+"����";
	  line1_flag=1;	  
	}
	if(parry>0){
	  if(!line1_flag){
	   longs+="���ĸ�������Ϊ��\n��"+levs[parry/10>sizeof(levs)-1?sizeof(levs)-1:parry/10]+"����";
	   line1_flag=1;	   
	  }
	  else{
	   longs+="��"+levs[parry/10>sizeof(levs)-1?sizeof(levs)-1:parry/10]+"����";
	   
	  }
	}
	if(enhance_min_damage>0){
	  if(!line1_flag){
	   longs+="���ĸ�������Ϊ��\n��"+levs[enhance_min_damage/5>sizeof(levs)-1?sizeof(levs)-1:enhance_min_damage/5]+"�˺�";
	   line1_flag=1;	   
	  }
	  else{
	    longs+="��"+levs[enhance_min_damage/5>sizeof(levs)-1?sizeof(levs)-1:enhance_min_damage/5]+"�˺�";
	   
	  }
	}	
	if(enhance_max_damage>0){
	  if(!line1_flag){
	   longs+="���ĸ�������Ϊ��\n��"+levs[enhance_max_damage/5>sizeof(levs)-1?sizeof(levs)-1:enhance_max_damage/5]+"����";
	   line1_flag=1;	   
	  }
	  else{
	    longs+="��"+levs[enhance_max_damage/5>sizeof(levs)-1?sizeof(levs)-1:enhance_max_damage/5]+"����";
	   
	  }
	}	
	if(double_damage>0){
	  if(!line1_flag){
	   longs+="���ĸ�������Ϊ��\n��"+levs[double_damage/5>sizeof(levs)-1?sizeof(levs)-1:double_damage/5]+"��������";
	   line1_flag=1;	   
	  }
	  else{
	    longs+="��"+levs[double_damage/5>sizeof(levs)-1?sizeof(levs)-1:double_damage/5]+"��������";
	   
	  }
	}
	if(intl>0){
	  if(!line2_flag){
	   if(!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[intl>sizeof(levs)-1?sizeof(levs)-1:intl]+"����";
	   else
	   longs+="��\n��"+levs[intl>sizeof(levs)-1?sizeof(levs)-1:intl]+"����";
	   line2_flag=1;
	  }
	  else{
	  
	    longs+="��\n��"+levs[intl>sizeof(levs)-1?sizeof(levs)-1:intl]+"����";
	  
	  }
	}
	if(con>0){
	  if(!line2_flag){
	   if(!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[con>sizeof(levs)-1?sizeof(levs)-1:con]+"����";
	   else
	   longs+="��\n��"+levs[con>sizeof(levs)-1?sizeof(levs)-1:con]+"����";
	   line2_flag=1;
	  }
	  else{
	   
	    longs+="��"+levs[con>sizeof(levs)-1?sizeof(levs)-1:con]+"����";
	   
	  }
	}
	if(dex>0){
	  if(!line2_flag){
	   if(!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[dex>sizeof(levs)-1?sizeof(levs)-1:dex]+"��";
	   else
	   longs+="��\n��"+levs[dex>sizeof(levs)-1?sizeof(levs)-1:dex]+"��";
	   line2_flag=1;
	  }
	  else{
	  
	    longs+="��"+levs[dex>sizeof(levs)-1?sizeof(levs)-1:dex]+"��";
	  
	  }
	}
	if(str>0){
	  if(!line2_flag){
	   if(!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[str>sizeof(levs)-1?sizeof(levs)-1:str]+"����";
	   else
	   longs+="��\n��"+levs[str>sizeof(levs)-1?sizeof(levs)-1:str]+"����";
	   line2_flag=1;
	  }
	  else{
	   
	    longs+="��"+levs[str>sizeof(levs)-1?sizeof(levs)-1:str]+"����";
	   
	  }
	}	
	if(kar>0){
	  if(!line3_flag){
	   if(!line2_flag&&!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[kar>sizeof(levs)-1?sizeof(levs)-1:kar]+"����";
	   else
	   longs+="��\n��"+levs[kar>sizeof(levs)-1?sizeof(levs)-1:kar]+"����";
	   line3_flag=1;
	  }
	  else{
	   
	    longs+="��\n��"+levs[kar>sizeof(levs)-1?sizeof(levs)-1:kar]+"����";
	   
	  }
	}
	if(per>0){
	  if(!line3_flag){
	   if(!line2_flag&&!line1_flag)
	   longs+="���ĸ�������Ϊ��\n��"+levs[per>sizeof(levs)-1?sizeof(levs)-1:per]+"��ò";
	   else
	   longs+="��\n��"+levs[per>sizeof(levs)-1?sizeof(levs)-1:per]+"��ò";
	   line3_flag=1;
	  }
	  else{
	   
	    longs+="��"+levs[per>sizeof(levs)-1?sizeof(levs)-1:per]+"��ò";
	   
	  }
	}
   if(no_need_force>0){
   	 if(!line4_flag){
   	  if(!line3_flag&&!line2_flag&&!line1_flag)
   	   longs+="���ĸ�������Ϊ��\n��������Ҫ��";
   	  else
   	   longs+="��\n��������Ҫ��";
   	  line4_flag=1;
   	 }
   	 else{
   	   longs+="��������Ҫ��";
   	 }
   }
  if(no_need_maxforce>0){
   	 if(!line4_flag){
   	  if(!line3_flag&&!line2_flag&&!line1_flag)
   	   longs+="���ĸ�������Ϊ��\n�����������Ҫ��";
   	  else
   	   longs+="��\n�����������Ҫ��";
   	  line4_flag=1;
   	 }
   	 else{
   	   longs+="�����������Ҫ��";
   	 }
   }
    if(no_need_sx>0){
   	 if(!line4_flag){
   	  if(!line3_flag&&!line2_flag&&!line1_flag)
   	   longs+="���ĸ�������Ϊ��\n��������Ҫ��";
   	  else
   	   longs+="��\n��������Ҫ��";
   	  line4_flag=1;
   	 }
   	 else{
   	   longs+="��������Ҫ��";
   	 }
   }
    if(reduce_force>0){
     if(!line5_flag){
      if(!line4_flag&&!line3_flag&&!line2_flag&&!line1_flag)
       longs+="���ĸ�������Ϊ��\n����������Ҫ��"+chinese_number(reduce_force)+"��";
      else
       longs+="��\n����������Ҫ��"+chinese_number(reduce_force)+"��";
      line5_flag=1;
     }
     else{
      longs+="����������Ҫ��"+chinese_number(reduce_force)+"��";
     }
   }
   
   if(reduce_maxforce>0){
     if(!line5_flag){
      if(!line4_flag&&!line3_flag&&!line2_flag&&!line1_flag)
       longs+="���ĸ�������Ϊ��\n��������������Ҫ��"+chinese_number(reduce_maxforce)+"��";
      else
       longs+="��\n��������������Ҫ��"+chinese_number(reduce_maxforce)+"��";
      line5_flag=1;
     }
     else{
      longs+="��������������Ҫ��"+chinese_number(reduce_maxforce)+"��";
     }
   }
   
   if(reduce_sx>0){
     if(!line5_flag){
      if(!line4_flag&&!line3_flag&&!line2_flag&&!line1_flag)
       longs+="���ĸ�������Ϊ��\n����������Ҫ��"+chinese_number(reduce_sx)+"��";
      else
       longs+="��\n����������Ҫ��"+chinese_number(reduce_sx)+"��";
      line5_flag=1;
     }
     else{
      longs+="����������Ҫ��"+chinese_number(reduce_sx)+"��";
     }
   }
   	   
	if(line1_flag||line2_flag||line3_flag||line4_flag||line5_flag)
	longs+="��\n";
	
	if(!no_need_sx&&wield_str-reduce_sx>0){
          longs+="װ�����󣺡�"+chinese_number(wield_str-reduce_sx)+"���ı�����";
	  need_flag=1;
	}
	else
	if(!no_need_sx&&wield_int-reduce_sx>0){
          longs+="װ�����󣺡�"+chinese_number(wield_int-reduce_sx)+"�������ԣ�";
	  need_flag=1;
	}
	else
	if(!no_need_sx&&wield_con-reduce_sx>0){
          longs+="װ�����󣺡�"+chinese_number(wield_con-reduce_sx)+"���ĸ��ǣ�";
	  need_flag=1;
	}
	else
	if(!no_need_sx&&wield_dex-reduce_sx>0){
          longs+="װ�����󣺡�"+chinese_number(wield_dex-reduce_sx)+"��������";
	  need_flag=1;
	}
	
	if(!no_need_force&&wield_force-reduce_force>0){
	 if(!need_flag)
           longs+="װ�����󣺡�"+chinese_number(wield_force-reduce_force)+"����������";
	 else
	   longs+="��"+chinese_number(wield_force-reduce_force)+"����������";
	 need_flag=1;
	}
        if(!no_need_maxforce&&wield_maxforce-reduce_maxforce>0){
	  if(!need_flag)
            longs+="װ�����󣺡�"+chinese_number(wield_maxforce-reduce_maxforce)+"�����������ޡ�\n";
	  else
            longs+="��"+chinese_number(wield_maxforce-reduce_maxforce)+"�����������ޡ�\n";
	}
	if(obj->query("poison_flag"))
	longs+="����������ͿĨЩ��ҩ��\n";
	
	if(weapon_or_armor){
	 if(!obj->query("max_strong"))
	  obj->set("max_strong",obj->query("strong"));
         longs+="�����С�"+strongs[obj->query("max_strong")/200>sizeof(strongs)-1?sizeof(strongs)-1:obj->query("max_strong")/200]+"���ļ�̶̳ȣ�";
         longs+="������"+"/feature/repair.c"->result_strong(obj->query("strong")*100/obj->query("max_strong"))+"";
	 if(super>0)
      longs+="��"+supers[super-1]+"��\n";
     else
      longs+="��\n";
	
    if(obj->query("user")!="") {
      if(obj->query("imbued"))
        longs+="���������ǡ�"+obj->query("saved")+"����\n";
      else
	longs+="���������ǡ�"+obj->query("user")+"����\n";
    } else
	longs+="����û�����ˡ�\n";
    }
    
	return longs;
	
}   


int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
