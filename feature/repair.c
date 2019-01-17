
#include <dbase.h>
#include <ansi.h>

string result_strong(int i);
int get_value(object weapon);

string *msg=({
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
});

int do_repair(string arg)
{
	object ob,weapon;
	int strong,max_strong,value,i;
	string weapon_name;
	string j="";
	
	ob=this_player();
	
	if(this_object()->is_busy()){
		return notify_fail(query("name")+"˵��������æ�ţ����Եȡ�\n");
	}
	
	if(ob->is_busy())
	 return notify_fail("����æ���أ�\n");
	
	if(!arg)
		return notify_fail(query("name")+"˵������ʹ�� xiu ������\n");
	
	weapon_name=arg;
	
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail(query("name")+"˵���������ϲ�û���������!\n");
	
	if(!weapon->query("skill_type"))
		return notify_fail(query("name")+"˵������ֻ����������\n");
     
         strong=(int)weapon->query("strong",1);
	 max_strong=(int)weapon->query("max_strong",1);
	 if(!max_strong)
	  max_strong=strong+100;
	 i=strong*100/max_strong;

	 if(i==100)
		 return notify_fail(query("name")+"˵������ı���û���𻵣������޲�!\n");
	 j=result_strong(i);
	 tell_object(ob,query("name")+"˵������ı����Ѿ�"+j+"��\n");
     value=get_value(weapon);
	 
	 tell_object(ob,query("name")+"˵�������ı���������Ҫ"+MONEY_D->money_str(value)+"��\n");
	 
	 switch( MONEY_D->player_pay(this_player(), value) ){
	 	case 0:
		 return notify_fail(query("name")+"˵���������ϴ���Ǯ������!\n");break;
	    case 2:
		 return notify_fail(query("name")+"˵����������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	 }
	if(!weapon->move(this_object()))
		return notify_fail(query("name")+"˵������ı���̫���ˣ����ò�����\n");
	
	weapon->set("no_steal",1);
	weapon->set("no_get",1);
	
	message_vision(HIG"$N"+HIG+"�ó�һ���ʯ��������������������\n"NOR,this_object());

		
	this_object()->start_busy(3);	
	ob->start_busy(3);
		
	call_out("do_msg",3,this_object(),ob,weapon,0);		
	
	return 1;
	
	
}

void do_msg(object tiejiang,object ob,object weapon,int times)
{
	
	if(!tiejiang||!ob||!weapon||environment(weapon)!=tiejiang)
		return;
	
	if(times>=sizeof(msg)){
		message_vision("$N���˲����������޺���"+weapon->query("name")+"!\n",tiejiang);
		if(weapon->query("strong",1)<=0)
		weapon->set("name",weapon->query("org_name"));
	    weapon->set("strong",weapon->query("max_strong"));
	    weapon->set("flag",0);
	    
	    weapon->set("no_steal",0);
	    weapon->set("no_get",0);
	    
	    if(environment(ob)!=environment(tiejiang)){
	     weapon->move(environment(tiejiang));
	    }
	    else
	    if(!weapon->move(ob)){
		 tell_object(ob,query("name")+"˵���������϶���̫���ˣ��ò����������Ҹ���ŵ������ˡ�\n");
		 weapon->move(environment(ob));
	    }
		return;
    }
    message_vision(msg[times]+"\n",tiejiang);
    tiejiang->start_busy(3);
    ob->start_busy(3);
    
    call_out("do_msg",3,tiejiang,ob,weapon,times+1);
    
}
  
string result_strong(int i)
{
	if(i>=100)
	   return HIG"�������"NOR;
	if(i>=90)
		return HIG"��΢��"NOR;
	else if(i>=80) return HIG"�����"NOR;
	else if(i>=70) return GRN"������"NOR;
	else if(i>=60) return GRN"���˽ϴ�"NOR;
	else if(i>=50) return CYN"��ð뻵"NOR;
	else if(i>=40) return CYN"������"NOR;
	else if(i>=30) return BLU"�����۶�"NOR;
	else if(i>=20) return BLU"���Ʋ���"NOR;
	else if(i>=10) return RED"���ò���"NOR;
	else return RED"����֮��"NOR;
}

int get_value(object weapon)
{
	int value;
	
	value=weapon->query("weapon_prop/damage");
    value+=weapon->query("weapon_prop/min_damage");
    value+=weapon->query("weapon_prop/enhance_min_damage")*5;
    value+=weapon->query("weapon_prop/intelligence")*5;
    value+=weapon->query("weapon_prop/dodge")*5;
    value+=weapon->query("weapon_prop/karma")*5;
    value+=weapon->query("weapon_prop/dodgeaction")*5;
    value+=weapon->query("weapon_prop/constitution")*5;
    value+=weapon->query("weapon_prop/personality")*5;
    value+=weapon->query("weapon_prop/armor")*5;
    value+=weapon->query("weapon_prop/strength")*5;
   
    value=value*10;
    
    return value;
}

   
