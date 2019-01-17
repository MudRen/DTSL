// inventory.c
// Created by Gmm@Jianghu 1999-8-21
// Copyright by Jianghu Wizard Group(1998-1999)
//modify by yanyan@dt

#ifndef BASE_WEIGHT
#define BASE_WEIGHT 40000
#endif

#include <ansi.h>
inherit F_CLEAN_UP;
string inventory_name(object ob);
string inventory_type(object ob);
string inventory_value(object ob);
string inventory_weight(object ob);
string left(string str,int long);
string center(string str,int long);
string tribar_graphfw(int val, int eff, int max, string color);
string bar_string = "����������������������������������������������������������������";
string blank_string = "����������������������������������������������������������������";
string over_string = "����������������������������������������������������������������";

int main(object me, string arg)
{
	int i;
	object *inv, ob;
	string line;
	string *inv_name,*inv_type,*inv_value,*inv_weight;
	seteuid(getuid(me));
	if(!arg) ob = me;
	else if(wizardp(me))
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("�Ҳ���ָ����һ�NPC��\n");
	}
	else return notify_fail("ֻ����ʦ�ܲ쿴���˵���Ʒ��\n");
	inv = all_inventory(ob);
	
	if(!ob->query_weight()) //update player weight.
          ob->set_weight(BASE_WEIGHT + (ob->query("str")-10) *2000);
	
	if(!sizeof(inv))
	{
             line="\n";
              line+="��������Ʒ�����������������������������ש����������ש����������ש�����������""\n";
		line+="��";
		line+=center(HIY"��������������"NOR,52)+"��"+center(HIG"�ࡡ��"NOR,26)+"��"+center(HIC"�ۡ�ֵ"NOR,26)+"��"+center(HIM"�ء���"NOR,26)+"��""\n";
		line+="�ǩ������������������������������������ߩ����������ߩ����������ߩ�����������""\n";
		line+="��"HIW"�����ء�"+ blank_string +HIW"��"NOR"\n";
		line+="����������������������������������������������������������������������������""\n";
		write(line);
		return 1;
	}
	line ="��������Ʒ�����������������������������ש����������ש����������ש�����������""\n";
	line+="��";
	line+=center(HIY"��������������"NOR,52)+"��"+center(HIG"�ࡡ��"NOR,26)+"��"+center(HIC"�ۡ�ֵ"NOR,26)+"��"+center(HIM"�ء���"NOR,26)+"��""\n";
	line+="�ǩ������������������������������������贈���������贈���������贈����������""\n";
	inv_name = map_array(inv,"inventory_name",this_object());
	inv_type = map_array(inv,"inventory_type",this_object());
	inv_value = map_array(inv,"inventory_value",this_object());
	inv_weight = map_array(inv,"inventory_weight",this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		line+=NOR"��"NOR+left(inv_name[i],36)+NOR"��"NOR;
		line+=center(inv_type[i],17)+NOR"��"NOR;
		line+=center(inv_value[i],17)+NOR"��"NOR;
		line+=center(inv_weight[i],17)+NOR"��"NOR"\n";
	}
	line+="�ǩ������������������������������������ߩ����������ߩ����������ߩ�����������""\n";
	line+="��";
	if (ob->over_encumbranced()) line+=HIR"�����ء�"+ over_string;
	else line+="�����ء�"+left(tribar_graphfw(ob->query_encumbrance(), ob->query_max_encumbrance(), ob->query_max_encumbrance(), HIW),64);
        line+="��"NOR"\n";
	line+="����������������������������������������������������������������������������""\n";
	write(line);
	return 1;
}

string inventory_weight(object ob)
{
	int weight=ob->weight();

	if(weight<1) return HIC"û������";
	if(weight<5) return HIC"����һǮ";
	if(weight>50000) return HIR"����ٽ�";

	if(weight/5<10) return HIG"��Լ"+chinese_number(weight/5)+"Ǯ";
	if(weight/50<10) return HIG"��Լ"+chinese_number(weight/50)+"��";
	if(weight/500<=10) return HIM"��Լ"+chinese_number(weight/500)+"��";
	if(weight/500<=20) return HIM"Լ"+chinese_number(weight/500)+"��";
	if(weight/500==30 || weight/500==40 || weight/500==50 || weight/500==60
	|| weight/500==70 || weight/500==80 || weight/500==90 || weight/500==100)
		return HIM"Լ"+chinese_number(weight/500)+"��";
	return HIM+chinese_number(weight/5000)+"ʮ����";
}

string inventory_value(object ob)
{
	int value=ob->query("value");

	if (ob->query("money_id")) return HIY"����";
	if (value<1) return HIC"һ�Ĳ�ֵ";
	if (value>=10000000) return HIR"�޼�֮��";
	if (value>=1000000) return HIR"��ֵ����";
	if (value>=100000) return HIM"ϡ����Ʒ";
	if (value>=10000) return HIY+chinese_number(value/10000)+"���ƽ�";
	if (value>=100) return HIW+chinese_number(value/100)+"������";
	return HIC+chinese_number(value)+"��ͭ��";
}

string inventory_name(object ob)
{
	string short=ob->short();
	
	return (ob->query("equipped")) ? HIC+"��"+NOR+short : short;
}

string inventory_type(object ob)
{
	switch(ob->query("skill_type"))
	{
		case "sword":return HIR"����(����)";
		break;
		case "hammer":return HIR"����(����)";
		break;
		case "axe":return HIR"����(����)";
		break;
		case "blade":return HIR"����(����)";
		break;
		case "dagger":return HIR"����(ذ��)";
		break;
		case "fork":return HIR"����(����)";
		break;
		case "staff":return HIR"����(����)";
		break;
		case "whip":return HIR"����(����)";
		break;
		case "throwing":return HIR"����(����)";
		break;
		case "ring":return HIR"����(����)";
		break;
		case "spear":return HIR"����(ì��)";
		break;
                case "sweeper":return HIR"����(����)";
                break;
	}
	switch(ob->query("armor_type"))
	{
		case "cloth":return HIM"�·�";
		break;
		case "armor":return HIG"����(����)";
		break;
		case "head":return HIG"����(ͷ��)";
		break;
		case "neck":return HIG"����(����)";
		break;
		case "waist":return HIG"����(����)";
		break;
		case "wrists":return HIG"����(����)";
		break;
		case "shield":return HIG"����(����)";
		break;
		case "finger":return HIG"����(��ָ)";
		break;
		case "hands":return HIG"����(����)";
		break;
		case "boots":return HIG"����(ѥ��)";
		break;
		case "bandage":return HIM"����";
		break;
	}
	if (ob->query("food_supply")) return HIC"ʳ��Ʒ";
	else if (ob->query("liquid")) return HIC"����Ʒ";
	else if (ob->query("money_id")) return HIW"����";
	else if (ob->query("cargo_id")) return HIW"����";
	else if (ob->query("skill")) return HIW"��ѧϰ";
	else if (ob->is_corpse()) return HIY"ʬ��";
	else if (userp(ob)) return HIY"����";
	else return HIY"δ֪";
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

string center(string str,int long)
{
	int space,len,i;
	string s,s2;
	s="";s2="";
	len=strlen(str);
	space=(long-len)/2;
	for(i=0;i<space;i++) s+=" ";
	for(i=0;i<long-len-space;i++) s2+=" ";
	return sprintf("%s%s%s",s,str,s2);
}



string tribar_graphfw(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*32/max)*2-1] + ((eff > val) ? blank_string[(val*32/max)*2..(eff*32/max)*2-1] : "") +NOR;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: inventory

�г���Ŀǰ������Я����������Ʒ�Լ���Ʒ���͡���ֵ�������ȵȡ�
ע����ָ������� i ���档

HELP
);
        return 1;
}
