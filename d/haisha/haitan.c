
#include <ansi.h>
inherit ROOM;
int do_yell(string arg);
int do_wa();
void create ()
{
  set ("short","��̲");
  set ("long", @LONG
���������ľ�ͷ�ˣ�������һ���޼ʵĴ󺣣����������򰶱ߡ�
���紵��������һ����ɬ����Ϣ��
LONG);

  set("exits", ([ 
  "west":__DIR__"xiaolu3",
  "northwest":"/d/clone/room/orgsaferoom/haisha/longhutang",
         ]));
  set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_yell","yell");
   add_action("do_wa","wa");
}

int do_yell(string arg)
{
    object me;
    me=this_player();
    if(!arg||(arg!="boat"&&arg!="����"))
    return notify_fail("��Ҫ����ʲô��\n");
    message_vision("$N���������к��������ҡ�����������������\n",me);
    tell_object(environment(me),"Զ�����˺���������˭���ں�ɳ��ͣ��������ʡʡ�ɡ�����\n");
    return 1;
    
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
  	cao=new("/d/quest/poison/obj/cao1");
  	cao->move(environment(ob));
  	message_vision("$N�ڵ���һ��"+cao->query("name")+"��\n",ob);
  	set("no_dig",1);
  	return 1;}
  ob->start_busy(2);
  return 1;
}