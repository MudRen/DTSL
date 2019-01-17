//���ơ�
/*ÿ�µİ������ʤ������
  ��õ����ơ�
*/
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
string OWNER;
string query_save_file()
{
	string id;

	if( !stringp(id = this_object()->query("save_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id;
}
int do_set_owner(string arg);
void create()
{
	set_name(HIR"����" NOR, ({ "ling pai", "ling","pai" }));
       	set("long", "����һ�����ƣ�����д�š����µ�һ���\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("no_sell",1);		
		set("material", "ǧ������");
		set("save_id","lingpai_save_file");
		
	}
	setup();
	
}	
int query_autoload()
{
	restore();
	return 1;
}

void init()
{
  object ob;
  add_action("do_set_owner","setowner");
  ob=environment(this_object());
  if(!interactive(ob)||ob->is_corpse()){
  delete("no_give");
  delete("no_drop");}
  if(!wizardp(ob)){
  set("no_give",1);
  set("no_drop",1);}
  else{
  delete("no_give");
  delete("no_drop");}
  restore();
}

int is_get_of(object me,object ob)
{
  if(me->query("shili/leader")==OWNER)
  return 1;
  return notify_fail("ֻ��"+query("only")+"������ſ��Լ���"+query("name")+"\n");
}
string get_name(string arg)
{
  switch(arg){
   
   case "��߸�":return "lifa_b";
   case "��ɳ��":return "haisha_b";
   case "����":return "dajiang_b";
   case "����":return "duzun_b";
   case "�μұ�":return "songjia_b";
   case "��������":return "feima_b";
   default:return "error";}
}

int help()
{
  write("
  ��ʹ�� setowner ������� ��ʽ��
  ������ƿ�����:
  ��߸�
  ��ɳ��
  ����
  ����
  �μұ�
  ��������
  \n");
  return 1;
}

int do_set_owner(string arg)
{
  object ob;
  ob=this_player();
  if(!wizardp(ob)) return 0;
  if(!arg) return (int)help();
  if(get_name(arg)=="error") return (int)help();
  OWNER=get_name(arg);
  set("long",query("long")+"\n"+NATURE_D->game_time()+" �����Ϊ���µ�һ�����"+HIW+arg+NOR+"\n");
  set("only",arg);
  tell_object(ob,"����ӵ�д����Ƶİ��Ϊ"+arg+"\n");
  save();
  return 1;
}

int clean_up()
{
  return 0;
}