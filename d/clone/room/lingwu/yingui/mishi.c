
#include <ansi.h>
inherit ROOM;
int do_clear(string arg);
void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
������һ�����ң��������Ѿ��ܾ�û���������ˡ�ǰ�����
һ�Ŵ���������˺���һ�㳾�����Ա߻���һ��ɨ�㣬������
����ɨ�����ġ�
LONG);

 set("exits",([ "out":"/d/yinkui/woshi2",]));
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_clear","sao");
}
int do_clear(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="��")
  return notify_fail("��Ҫɨʲô��\n");
  message_vision(YEL"$N��ϸ��ɨ��������\n"NOR,ob);
  tell_object(ob,"ͻȻ���ı�������һ�ǣ����ֳ�һ���ڶ�����\n");
  set("exits/enter",__DIR__"yingui");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
