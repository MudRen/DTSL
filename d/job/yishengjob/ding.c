inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("ҩ��",({"yao ding","ding"}) );
	set("long","����һ��ҩ����������á�������(helian)������ҩƷ��\n");
        set("no_get",1);
	set_weight(1000000);
	set("unit","��");
	set("value",100);
}

void init()
{
	add_action("do_helian","helian");
	
}
/*
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
*/
int do_helian(string arg)
{
object me = this_player();    
string met,met2,met3,met4,met5,name,iname,iname1,iname2,iname3,iname4,iname5,mname,mname1,mname2,mname3,mname4,mname5;
	object med,med2,med3,med4,med5,new_med;
	mapping heals,heals2,heals3,heals4,heals5;
	int lev;
	if(!arg||sscanf(arg,"%s %s %s %s %s %s",met,met2,met3,met4,met5,name)!=6)
		return notify_fail("��ʹ�� helian ԭ������1 ԭ������2 ԭ������3 ԭ������4 ԭ������5 ҩ������\n");
	if(!objectp(med=present(met,me))||!objectp(med2=present(met2,me))||!objectp(med3=present(met3,me))||!objectp(med4=present(met4,me))||!objectp(med5=present(met5,me)))
      return notify_fail("������û������ԭ��!\n");
	if(me->query("vocation")!="ҩʦ")
		return notify_fail("�㲻��ҩʦ����������ҩ!\n");
	if(!me->query("quest/final/yao"))
		return notify_fail("��û����������ҩ��Ȩ��!\n");
	lev=(int)me->query_skill("bencao-shuli",1);
	if(lev<200)
	return notify_fail("��ı�������̫���ˣ���ô��ҩ��\n");
	if(me->query_int()<30)
	return notify_fail("������Բ������޷���ҩ��\n");
	if(me->query("max_force")<2000)
		return notify_fail("�����������������ҩ��!\n");
      // add by Yanyan. ����ÿ������һ��ҩ��
      if(me->query("busy_time_lianyao",1)%2==0
      &&time()-me->query("busy_time_lianyao_time",1)<3600*24){//3600��==1Сʱ���
		return notify_fail("������һ������ҩ�����������������Ԫ������Ҫһ�κܳ�ʱ������������ơ�\n");
      }
      //add end.
	heals=med->query("heal");
	heals2=med2->query("heal");
	heals3=med3->query("heal");
	heals4=med4->query("heal");
	heals5=med5->query("heal");
     if(!heals||!heals2||!heals3||!heals4||!heals5) return notify_fail("���ֶ�������������ҩ��\n");
     if(med->query("name")==med2->query("name")||
        med->query("name")==med3->query("name")||
        med->query("name")==med4->query("name")||
        med->query("name")==med5->query("name")||
        med2->query("name")==med3->query("name")||
        med2->query("name")==med4->query("name")||
        med2->query("name")==med5->query("name")||
        med3->query("name")==med4->query("name")||
        med3->query("name")==med5->query("name")||
        med4->query("name")==med5->query("name")) 
        return notify_fail("��ͬЧ����ҩ�ķŽ�ȥ��Ч���Ͳ����ˣ�\n");
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	name=replace_string(name,"$HIR$",""HIR"");
	name=replace_string(name,"$HIG$",""HIG"");
	name=replace_string(name,"$HIY$",""HIY"");
	name=replace_string(name,"$HIW$",""HIW"");
	name=replace_string(name,"$HIB$",""HIB"");
	name=replace_string(name,"$HIM$",""HIM"");
	name=replace_string(name,"$HIC$",""HIC"");
	name=replace_string(name,"$GRN$",""GRN"");
	name=replace_string(name,"$RED$",""RED"");
	name=replace_string(name,"$BLK$",""BLK"");
	name=replace_string(name,"$YEL$",""YEL"");
	name=replace_string(name,"$BLU$",""BLU"");
	name=replace_string(name,"$MAG$",""MAG"");
	name=replace_string(name,"$CYN$",""CYN"");
	name=replace_string(name,"$WHT$",""WHT"");
	name=name+NOR;
      new_med=new("/d/job/yishengjob/dan");
	new_med->set("name",name);
/*
  mname=no_color(new_med->query("name"));
  mname1=no_color(med->query("name"));
  mname2=no_color(med2->query("name"));
  mname3=no_color(med3->query("name"));
  mname4=no_color(med4->query("name"));
  mname5=no_color(med5->query("name"));
  iname=no_color(me->query("quest/final/yao/name"));
  iname1=no_color(me->query("quest/final/yao/med"));
  iname2=no_color(me->query("quest/final/yao/med2"));
  iname3=no_color(me->query("quest/final/yao/med3"));
  iname4=no_color(me->query("quest/final/yao/med4"));
  iname5=no_color(me->query("quest/final/yao/med5"));
*/  
  mname=new_med->query("name");
  mname1=med->query("name");
  mname2=med2->query("name");
  mname3=med3->query("name");
  mname4=med4->query("name");
  mname5=med5->query("name");
  iname=me->query("quest/final/yao/name");
  iname1=me->query("quest/final/yao/med");
  iname2=me->query("quest/final/yao/med2");
  iname3=me->query("quest/final/yao/med3");
  iname4=me->query("quest/final/yao/med4");
  iname5=me->query("quest/final/yao/med5");
  if(!me->query("quest/final/yao/done")&& mname==iname && mname1==iname1 && mname2==iname2 && mname3==iname3 && mname4==iname4 && mname5==iname5) 
{
me->add_skill("bencao-shuli",20);
me->add("potential",2000);
me->add("vocation_score",10000);
// me->delete("quest/final/yao/name");
me->set("quest/final/yao/done",1);
message("shout",HIY"��"HIW"ҩʦ�л�"HIY"��"HIY"��٢(huatuo):" HIY+ me->query("name")+HIW"�ɹ����ƶ�����ҩ���ʽ�Ǳ�ܶ�ǧ�㣬ְҵ����һ��㼰���������ʮ������\n"NOR,users()); 
}


 if (mname1==iname1 && mname2==iname2 && mname3==iname3 && mname4==iname4 && mname5==iname5)
{
      message_vision("$N��"+mname1+"��"+mname2+"��"+mname3+"��"+mname4+"��"+mname5+"�Ž�ҩ���������ע���Լ�����Դ��\n\n"+name+"���ƺ��ˣ�\n",me);
      destruct(med);
      destruct(med2);
      destruct(med3);
      destruct(med4);
      destruct(med5);
	new_med->move(me);
	me->add("vocation_score",200);
	me->add("vocation_exp",200);
// 	me->improve_skill("bencao-shuli",(lev/20+heals["heals"])/4);
	me->set("gin",0);
	me->set("kee",0);
	me->set("sen",0);
	me->set("force",0);
	me->add("max_force",-20);
	//add by Yanyan. ����ÿ������һ��ҩ
	me->add("busy_time_lianyao",1);
	if(me->query("busy_time_lianyao",1)%2!=0)
	 me->set("busy_time_lianyao_time",time());
       //add end.
    return 1;
    
}
      destruct(med);
      destruct(med2);
      destruct(med3);
      destruct(med4);
      destruct(med5);
      destruct(new_med);
 return notify_fail("���õ�ҩ�Ļ�˳�򲻶�,�����������ĵ�ҩ���˷��\n");
}

