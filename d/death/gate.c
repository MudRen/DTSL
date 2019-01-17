// gate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB "���Ź�" NOR);
	set("long", "�����������Ĺ��Ź��ˡ�ֻ�������кܶ����Ŷӳ�������
ȥ������谵�޹⣬��ɭ�ֲ���\n");
	set("exits", ([
		"enter" : __DIR__"gateway",
	]) );
    set("no_fight", 1);
    set("no_quit",1);
	setup();
}
void init()
{
  object ob;
  ob=previous_object();
  if(!ob) return;
  call_out("run",5,ob);
}
void run(object ob)
{
  
   if( !ob || !present(ob) ) return;
   
  ob->set("gin",ob->query("max_gin"));
  ob->set("kee",ob->query("max_kee"));
  ob->set("sen",ob->query("max_sen"));
  ob->set("eff_gin",ob->query("eff_gin"));
  ob->set("eff_kee",ob->query("max_kee"));
  ob->set("eff_sen",ob->query("max_sen"));
  
    tell_object(ob, HIW"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n"NOR);
    tell_object(ob,HIB"ͻȻһ�ɾ޴�������������˽�ȥ��\n"NOR);
    ob->move(__DIR__"gateway");
    return;
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "enter") 
	     return notify_fail(HIB"ֻ��ǰ��Ĺ��ع�ͷ����ҵؽе����������㻹��·�𣡣�\n"NOR);

	else return 1;
}
