
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIW"��˼��"NOR);
  set ("long", @LONG
�����ǴȺ���ի�ľ�˼�á�����û��ʲô���裬ֻ�м�����
���š�������һ�����������񣬻��м����ո��Ϻõ��㡣��
��������������[lingwu]�Ⱥ���ի���ڹ��ķ�--�������ƾ���
LONG);

  set("exits", ([ 
 "out":__DIR__"mishi2",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","qingxin-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"