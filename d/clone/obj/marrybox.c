
inherit ITEM;
#include <ansi.h>
string go_msg=HIY"ֻ�����������һλ���ӣ�����"+HIW+"��������"+HIY+"������λ��΢΢һЦ��\n"+
                 "���������䣬ת��Ͷ���յ�"+HIC+"����"+HIY+"֮�У�Ʈң��ȥ��\n"NOR;

int do_qu(string arg);
int do_withdraw();

void create()
{
   set_name(HIR"������"NOR,({ "box"}) );  	
   set("long", "�����͸��»�򸾵������䡣\n"+
               "����Դ�������ó�����[qu]��\n"+
               "Ҳ�����ó�100���ƽ�[withdraw]��\n");
   set_weight(10);       
   set("unit","��");
   set("rumor",1);
   set("no_sell",1);
   set("value",100000000);
   setup();
 
}

int is_get_of(object pal,object ob)
{
  return notify_fail("�������������������\n");
}
void init()
{
   add_action("do_qu","qu");
   add_action("do_withdraw","withdraw");
   
}

int do_qu(string arg)
{
  object ob;
  object weapon;
  string wp,type;
  
  ob=this_player();
  if(query("weapons")>=2)
  return notify_fail("��ֻ��ȡ����������\n");
  if(!arg||sscanf(arg,"%s %s",wp,type)!=2)
  return notify_fail("��ʹ�� qu ���������� ����,\n���ֿ��Լ�����ɫ�����ַ���\n");
  
  weapon=new("/obj/weaponclass/"+type);
	wp=replace_string(wp,"$HIR$",""HIR"");
	wp=replace_string(wp,"$HIG$",""HIG"");
	wp=replace_string(wp,"$HIY$",""HIY"");
	wp=replace_string(wp,"$HIW$",""HIW"");
	wp=replace_string(wp,"$HIB$",""HIB"");
	wp=replace_string(wp,"$HIM$",""HIM"");
	wp=replace_string(wp,"$HIC$",""HIC"");
	wp=replace_string(wp,"$GRN$",""GRN"");
	wp=replace_string(wp,"$RED$",""RED"");
	wp=replace_string(wp,"$BLK$",""BLK"");
	wp=replace_string(wp,"$YEL$",""YEL"");
	wp=replace_string(wp,"$BLU$",""BLU"");
	wp=replace_string(wp,"$MAG$",""MAG"");
	wp=replace_string(wp,"$CYN$",""CYN"");
	wp=replace_string(wp,"$WHT$",""WHT"");
	wp=wp+NOR;
	weapon->set("name",wp);
	weapon->set("long","����һ"+weapon->query("unit")+
	   ob->name()+"��"+ob->query("couple/couple_name")+"�������õ����\n");
	weapon->set("weapon_prop/damage",100);
	weapon->set("max_strong",100);
	weapon->set("strong",100);
	weapon->set("flag",0);
	weapon->move(ob);
	add("weapons",1);
	add("parents",1);
	message("vision",HIG"��������Ե����"+ob->name()+HIG+"�����������ó���һ"+weapon->query("unit")+
	        weapon->name()+"\n"NOR,users());
	if(query("parents")>=3){
	message("vision","\n\n"+go_msg,users());
	destruct(this_object());
	return 1;}
	return 1;
}

int do_withdraw()
{
  object ob,money;
  ob=this_player();
  if(query("money"))
  return notify_fail("�����Ѿ�û��Ǯ�ˡ�\n");
  money=new("/obj/money/gold");
  money->set_amount(100);
  money->move(ob);
  message("vision",HIG"��������Ե����"+ob->name()+HIG+"�����������ó���"+HIY+"һ�����ƽ�\n"NOR,users());
  add("parents",1);
  set("money",1);
  if(query("parents")>=3){
	message("vision","\n\n"+go_msg,users());
	destruct(this_object());
	return 1;}
  return 1;
}
