
#include <ansi.h>
inherit ROOM;
int do_bo(string arg);
void create ()
{
  set ("short","����");
  set ("long", @LONG
��ͣ����һ������֮�ϡ�������������µı����������ϣ�
���ð����ס�ˡ��±߾���ɽ�µĵײ����ں����ģ�ʲôҲ����
�塣�����ĸ����Ӳݴ������ƺ����Բ���bo������
LONG);
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_bo","bo");
}
int do_bo(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="�Ӳ�")
  return notify_fail("��Ҫ��ʲô��\n");
  message_vision(YEL"$N���ֲ����Ӳݣ��Ӳݺ������ֳ�һ�����ڣ�\n"NOR,ob);
  set("exits/enter",__DIR__"dongming");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
