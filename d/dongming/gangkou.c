
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"gangkou"
#define TO __DIR__"gangkou2"
int do_yell(string arg);
void create ()
{
  set ("short","�ۿ�");
  set ("long", @LONG
�����Ƕ����ɱ���Ψһ�ĸۿڡ���ǰ��һ���޼ʵĴ󺣡�������
�Ĵ��ڰ��ߣ������������������м��Ҵ�ͣ���������������׼����
��Զ���ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"haitan1",
         ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","gangkou");
  setup();
 
}

void init()
{
	add_action("do_yell","yell");
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