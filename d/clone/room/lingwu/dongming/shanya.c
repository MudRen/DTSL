
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void create ()
{
  set ("short",HIB"ɽ��"NOR);
  set ("long", @LONG
������һɽ�£���������ף�ֻ�����ƴӽ�������Ʈ����
��վ����������Ƚ�ֱ�����һ����������������㴵��
��������ȥ��
LONG);

  set("exits", ([ 
 "north":"/d/dongming/shulin2",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="cliff")
  return notify_fail("��Ҫ����������\n");
  if(ob->query("pker"))
  return notify_fail("ͨ����������ʵ��ɣ�\n");
  message_vision(YEL"$Nһ�����������±�������ȥ��\n"NOR,ob);
  if(ob->query("family_lingwu")!="dongming"||
     !ob->query("no_check_jump")){
  	ob->receive_wound("kee",2);
  	ob->move(__DIR__"yadi");
  	tell_object(ob,"��о�˫�ȷ��飬һ��Ҳ�߲����ˣ�����Ҫ��Ϣһ���ˣ�\n");
  	//ob->add("no_check_jump",1);
  	ob->start_busy(300);
  	return 1;}
  tell_object(ob,"�������֮�У���ͻȻ��һ��������ס�ˣ�\n");
  ob->move(__DIR__"songshu");
  return 1;
}
