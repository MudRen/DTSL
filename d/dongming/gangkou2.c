
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"gangkou2"
#define TO __DIR__"gangkou"
int do_yell(string arg);
void create ()
{
  set ("short","�ۿ�");
  set ("long", @LONG
��������ԭ���Ϸ���һ���ۿڡ���ǰ��һ���޼ʵĴ󺣡������м�
�Ҵ�ͣ����������ϵ�ˮ����æµ�ţ������๤�����Ա�ߺ���ţ���
ͣ��ָ�ֻ��š�
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu1",
  "west":__DIR__"chuan",
         ]));
  set("objects",([
	  __DIR__"npc/shang":1,
	  __DIR__"npc/dizi2":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","gangkou");
  setup();
 
}

void init()
{   
	add_action("do_yell","yell");
	add_action("do_shout","han");
	
}

int do_yell(string arg)
{
	object ship,here,me;int force;
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
	me=this_player();
	here=environment(me);
	force=me->query("force");
	if(!arg||(arg!="boat"&&arg!="����")) return notify_fail("��Ҫ����ʲô?\n");
	if(force<=500) message_vision("$Nʹ������������:���ҡ�����!\n",me);
	else if(force<=1000) message_vision("$N��������:���ҡ�����!����ԶԶ���˳�ȥ.\n",me);
	else if(force<=2000) message_vision("$N����������������:���ҡ�����!����ԶԶ���˳�ȥ.\n",me);
	else message_vision("$N��������:���ҡ�����!��������,���ò�Ϣ.\n",me);
	
	if(me->query("family/family_name")=="������"){
	   message_vision("\n���ҳ�$N���˸�Ҿ��ԭ���Ƕ����ɵ��ӣ������ҳ�����С��ȥ������\n",me);
	   message_vision("\nֻ��һ��С��ʻ�˹�����$N����һԾ��������С���У�\n",me);
	   tell_object(me,"\nֻ��С��Ѹ�ٵĻ�����ת���ѵ��˶����ɵĺ�����\n");
	   me->move(TO);
	   message_vision("$N��С��������������\n",me);
	   return 1;}
	   
	if(ship->query("yell"))
		if(ship->query("exits/out")==FROM)
			return notify_fail("��������,�����ϾͿ���!\n");
	else return notify_fail("��������:�ȵȰ�������һ������ˡ�����\n");
	ship->set("yell",1);
	ship->set("exits/out",FROM);
	here->set("exits/enter",SHIPDIR);
	tell_object(here,"����˵��:�͹�,�����õ���,�����ϴ���!\n");
	call_out("on_board",10,me,ship,here);
	return 1;
}

void on_board(object me,object ship,object here)
{
   tell_object(ship,"��������:��λ�͹�����,�����ˡ�����\n");
   tell_object(here,"��������:��λ�͹�����,�����ˡ�����\n");
	ship->delete("exits");
   here->delete("exits/enter");
   call_out("leave_ship",30,me,ship);
   remove_call_out("on_board");
}

void leave_ship(object me,object ship)
{
	object here;
	ship->set("exits/out",TO);
    here=load_object(TO);
	here->set("exits/enter",SHIPDIR);
	tell_object(ship,"����˵��:�͹�,������,�´���!\n");
	call_out("no_ship",1,ship,here);
	remove_call_out("leave_ship");
}

void no_ship(object ship,object here)
{
   object *ob;int i;
   ob=all_inventory(ship);
   for(i=0;i<sizeof(ob);i++)
   {
	   if(living(ob[i]))
		   ob[i]->move(here);
	   else
	   {
		   tell_object(ship,"����һ�Ű�"+ob[i]->name()+"���´�!\n");
		   tell_object(here,"����һ�Ű�"+ob[i]->name()+"���´�!\n");
		   ob[i]->move(here);
	   }
   }
   ship->delete("exits");
   ship->delete("yell");
   here->delete("exits/enter");
   remove_call_out("no_ship");
}

int do_shout(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("bai_dongming/action3"))
  return 0;
  if(!arg)
  return notify_fail("��Ҫ��ʲô��\n");
  if(arg!="��ɳ�������������ѣ���ɳ�﹥�䲻����")
  return notify_fail("��Ϲ����ʲô����\n");
  
  tell_object(ob,"\nֻ���������˵�����л���ţ��������ɣ�\n"+
                 "һ��˿����������˴��ϡ�\n\n"+
                 "��Ѹ��ʻ�����ۣ�������ʻȥ��\n\n"+
                 "�ܿ죬�󴬿��˰�����������˵����������Ƕ������ж���\n"+
                 "���Ը��Ļ�������Ͷ�뵽�Ƕ��������¡�\n");
  ob->delete_temp("bai_dongming/action3");
  ob->set_temp("bai_dongming/action4",1);
  ob->move(__DIR__"gangkou");
  return 1;
}