
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short",HIG"�۽�̨"NOR);
  set ("long", @LONG
������Ƕ�üɽ��[�۽�̨]�ˡ����������ʿΪ�˹�ƽ����������
������б��䡣ֻ������ɢ�ҵط��˺ܶ�������������ָոս�����һ
�����䡣���Ҫ���۽�̨���������(jump down)��ȥ��
LONG);

  set("no_death",1);
  set("outdoors","emeishan");
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
   if(!arg||arg!="down")
   return notify_fail("��Ҫ����������\n");
   if(ob->is_busy()||ob->is_fighting())
   return notify_fail("����æ���أ�\n");
   message_vision("$N�����۽�̨����ȥ��\n",ob);
   tell_room(__DIR__"shanlu3",ob->name()+"���۽�̨������������\n");
   ob->move(__DIR__"shanlu3");
   return 1;
}
