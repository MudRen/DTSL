inherit NPC;
#include <ansi.h>
int item_player();
mapping yaoname2=([
RED"������"NOR:"jinyinhua",
YEL"����"NOR:"chuanwu",
HIY"��Ƭ"NOR:"bingpian",
GRN"�춬"NOR:"tiandong",
HIC"Ѫ��"NOR:"xuejie",
BLU"���"NOR:"dahuang",
MAG"�Ͷ�"NOR:"badou",
]);

mapping yaoname3=([
RED"����"NOR:"fuling",
YEL"��֥"NOR:"lingzhi",
HIY"ûҩ"NOR:"moyao",
GRN"����"NOR:"dilong",
HIC"��β"NOR:"guiwei",
BLU"�ư�"NOR:"huangpo",
MAG"����"NOR:"hupo",
]);

mapping yaoname4=([
RED"�׶���"NOR:"hedinghong",
YEL"�ϻ�"NOR:"zihua",
HIY"�ʲ�"NOR:"gancao",
GRN"����"NOR:"changpu",
HIC"����"NOR:"jiuzi",
BLU"����"NOR:"lanhua",
MAG"����"NOR:"fuzi",
]);

mapping yaoname5=([
RED"¹��"NOR:"lurong",
YEL"ţ��"NOR:"niuhuang",
HIY"�ܵ�"NOR:"xiongdan",
GRN"���"NOR:"zhansu",
HIC"���"NOR:"xiafen",
BLU"����"NOR:"hugu",
MAG"��ɽ�׿�"NOR:"chuanshanjiake",
]);

mapping yaoname=([
RED"�컨"NOR:"honghua",
YEL"��Ƥ"NOR:"chenpi",
HIY"�˲�"NOR:"renshen",
GRN"����"NOR:"danggui",
HIC"ѩ��"NOR:"xuelian",
BLU"����"NOR:"shengdi",
MAG"������"NOR:"heshouwu",
]);

mapping itemname=([
RED"����������"NOR:"dan",
HIM"��ת���굤"NOR:"dan",
HIW"����ͨ����"NOR:"dan",
MAG"���ŷ��赤"NOR:"dan",
BLU"�߱����׵�"NOR:"dan",
]);

void create()
{
  set_name("��٢", ({"huatuo"}));
  set("age", 60);
  set("gender", "����");
  set("long", "������ǿ��ҩʦ������������йء�ҩʦ��ְҵ�����⡣\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 80);
 set("inquiry", ([
        "ҩʦ":   (: item_player:),
      ]));
  setup();

}
int item_player()
{
  object me = this_object();
  object who = this_player();
  object yaofang;
  string *itemn;
  int itemz;
  string *n,*n2,*n3,*n4,*n5;
  int z;
  int z2;
  int z3;
  int z4;
  int z5;
  if(who->query("vocation") != "ҩʦ"){
	   	
		command("kok");
		command(
		  "say �㻹����ȥ���Լ����ҩʦ�ɣ�\n");
		return 1;
	    }
  if (who->query("quest/final/yao"))
  {
    message_vision ("$N��$n˵�����Ҳ����Ѿ���ҩ����������\n",me,who);
    return 1;
 } 
 

  n=keys(yaoname);
  z=random(sizeof(n));  

  n2=keys(yaoname2);
  z2=random(sizeof(n2));  
  n3=keys(yaoname3);
  z3=random(sizeof(n3));  
  n4=keys(yaoname4);
  z4=random(sizeof(n4));  
  n5=keys(yaoname5);
  z5=random(sizeof(n5));  
  itemn=keys(itemname);
  itemz=random(sizeof(itemn));  
//  itemid1=itemname[itemn[itemz]];
  who->set("quest/final/yao/name", itemn[itemz]);
  who->set("quest/final/yao/med", n[z]);
  who->set("quest/final/yao/med2", n2[z2]);
  who->set("quest/final/yao/med3", n3[z3]);
  who->set("quest/final/yao/med4", n4[z4]);
  who->set("quest/final/yao/med5", n5[z5]);
  yaofang=new("/d/job/yishengjob/yaofang");
  yaofang->move(who);
  message_vision ("������һ��ҩ�������ҵ�����д��ҩ�ĺ���ȥ������,�ǵ�Ҫ��˳��!\n",me,who);
  return 1;
}

