
#include <ansi.h>
inherit ROOM;

int do_wa();
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
����ɽ�������澲���ĵģ�����û��ʲô�ˡ�������ؿ�����һ����
ֻ��������������߻ص���
LONG);

  set("exits", ([ 

   "west":__DIR__"shanlu3",
   
          ]));
 set("objects",([
     __DIR__"npc/she":2,
     ]));
//set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int do_wa()
{
  object ob;
  object cao;
  
  ob=this_player();
  if(ob->is_busy()||
     ob->is_fighting())
  return notify_fail("����æ���أ�\n");
  if(query("no_dig"))
  return notify_fail("�������û��ʲô�����ˡ�\n");
  if(ob->query("sen")<50)
  return notify_fail("��е�����ƣ�����������Ϣһ���ˡ�\n");
  message_vision("$N�ڵ�������������\n",ob);
  ob->receive_damage("sen");
  if(random(20)>10){
  	cao=new("/d/quest/poison/obj/cao2");
  	cao->move(environment(ob));
  	message_vision("$N�ڵ���һ��"+cao->query("name")+"��\n",ob);
  	set("no_dig",1);
  	return 1;}
  ob->start_busy(2);
  return 1;
}