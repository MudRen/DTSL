
#include <ansi.h>
inherit ROOM;
int do_pa(string arg);
void create ()
{
  set ("short",HIB"ɽ�µ�"NOR);
  set ("long", @LONG
������ɽ�µĵײ��������Ӳݴ�������ʱ��ɫ�ʰ�쵵�С��
����Ľ��滬����ֻ��Զ���ƺ���Ұ�Ǻ��е��������������Ǹ�
������ȥ�ĺá����������ķ����ƺ����ϡ�up������left����
�ҡ�right����
LONG);
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
 
}
void init()
{
   add_action("do_pa","climb");
}
int do_pa(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="up"&&arg!="left"&&arg!="right"))
  return notify_fail("��ֻ������[up]����[left],��[right]����\n");
  ob->set_temp("climb_trace1",arg);
  if(ob->is_busy())
  return notify_fail("����æ���ء�\n");
  message_vision(YEL"$N���������µı�Ե��������ȥ��\n"NOR,ob);
  ob->move(__DIR__"yadi2");
  return 1;
}
