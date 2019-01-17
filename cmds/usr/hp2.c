
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
//string combat_desc(int combat);
int get_pot(object ob);
/*
void same_length(string l1,string l2,string l3);
string line_g;
string line_s,line_k,line_f;
string line_b,line_a;
*/
int main(object me, string arg)
{
   object ob;
   mapping my;
   int exp,i;

   seteuid(getuid(me));
 
   if(!arg)
     ob = me;
   else if (wizardp(me)) {
     ob = present(arg, environment(me));
     if (!ob) ob = find_player(arg);
     if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
   } else
     return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
   
   exp=ob->query("combat_exp");
    for(i=0;i*i*i<exp*10;i++);
    ob->set("max_pot",i+100);
  
  //ob->add("max_pot",ob->query_skill("jiuxuan-dafa",1)/2);
  for(i=0;i*i*i<exp*3;i++);
    ob->set("max_apply_points",i);
 
   my = ob->query_entire_dbase();
   if(ob->query("force")<0)
    ob->set("force",0);
   write(sprintf("\n   ��Ѫ��%s%5d/%5d%s(%3d%%)"+NOR+"   ����%s%4d/%4d%s(%3d%%) \n"NOR,
	   status_color(my["gin"],my["eff_gin"]),my["gin"],my["eff_gin"],
	   status_color(my["eff_gin"],my["max_gin"]),my["eff_gin"]*100/my["max_gin"],
	   status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],
	   status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]));
  
   write(sprintf("   ��Ѫ��%s%5d/%5d%s(%3d%%)"+NOR+"   ������%s%4d/%4d%s(+%d%%)\n"NOR,
	   status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],
	   status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"],
	   status_color(my["force"],my["max_force"]),my["force"],my["max_force"],
	   status_color(my["force"],my["max_force"]),ob->query_skill("force",1)?my["jiali"]*100/ob->query_skill("force",1):0));
   write(sprintf("   ���ƣ�%s%6d/%4d"+NOR+"         �������ޣ�%s%d\n"NOR,
                 HIG,ob->query("apply_points"),ob->query("max_apply_points"),
                 HIG,ob->query_skill("force",1)*63/4));
  
   printf("   ʳ�  %s%4d/%4d"NOR"         Ǳ�ܣ� "HIY"%d"NOR"/"HIY"%d"NOR"\n",
	   status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
		ob->query("potential"),(int)ob->query("max_pot",1));
   printf("   ��ˮ��  %s%4d/%4d"NOR"         ���飺 "HIY"%d\n"NOR,
	       status_color(my["water"], ob->max_water_capacity()),
           my["water"], ob->max_water_capacity(),
                   ob->query("combat_exp"));
	   
 
  return 1;
}
 
string status_color(int current, int max)
{
   int percent;
 
   if( max>0 ) percent = current * 100 / max;
   else percent = 100;
   if( percent > 100 ) return HIC;
   if( percent >= 90 ) return HIG;
   if( percent >= 60 ) return HIY;
   if( percent >= 30 ) return HIY;
   if( percent >= 10 ) return HIR;
   return HIR;
}
 
string combat_desc(int combat)
{
	int i;int j,exp; 
   
	string *desc=({
BLU "��ֵһ��" NOR,BLU "΢�����" NOR,BLU "����ҳ�" NOR,BLU "��¶��â" NOR,HIB "�����ž�" NOR,
HIB "���г���" NOR,HIB "����ǿǿ" NOR,HIB "���䲻��" NOR,HIB "��Σ����" NOR,HIB "������" NOR,
HIB "���г���" NOR,HIB "�շ�����" NOR,HIB "��Σ����" NOR,HIB "����С��" NOR,HIB "�������" NOR,
CYN "�����ͨ" NOR,CYN "��Ȼ���" NOR,CYN "���д��" NOR,CYN "���д��" NOR,CYN "��Ȼ��ͨ" NOR,
CYN "�������" NOR,CYN "�޿�ƥ��" NOR,CYN "����Ⱥ��" NOR,CYN "�������" NOR,CYN "�����뻯" NOR,
CYN "�����һ" NOR,HIC "�Ƿ��켫" NOR,HIC "��������" NOR,HIC "һ����ʦ" NOR,HIC "�񹦸���" NOR,
HIC "������˫" NOR,HIC "��������" NOR,HIC "������" NOR,HIC "����֮��" NOR,HIR "��ɲ�" NOR
});
    i=0;j=0;
    exp=combat;
	if(combat==0||exp<3000) return desc[0];
	
    while(exp>=10){
		exp=exp/10;j++;}
	if(j<=3)
		if(exp>5) return desc[4];
		  else return desc[exp];
	if(j<=4)
		if(exp>5) return desc[9];
		 else return desc[4+exp];
	if(j<=5)
		return desc[9+exp];
	return desc[18+exp];
}

int get_pot(object ob)
{
int exp,i;
	exp=ob->query("combat_exp");
    for(i=0;i*i*i<exp*10;i++);
    ob->set("max_pot",i+100);
  
 // ob->add("max_pot",ob->query_skill("jiuxuan-dafa",1)/2);
  return ob->query("potential");
}
/*
void same_length(string l1,string l2,string l3)
{
	if(40>strlen(l2)){
	while(40>strlen(l2))
		l2+=sprintf(" ");
	} 
	if(strlen(l1)<40){
	while(strlen(l1)<40)
		l1+=sprintf(" ");
	}
	if(strlen(l3)<40){
	while(strlen(l3)<40)
		l3+=sprintf(" ");
	}
	write(l1);write(line_s);
	write(l2);write(line_f);
	write(l3);write(line_a);
	return;
}
*/
int help(object me)
{
   write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ���ָ������ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}
