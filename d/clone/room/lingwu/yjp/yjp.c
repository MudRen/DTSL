
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"ʯ��"NOR);
  set ("long", @LONG
������һ��ʯ�ң��Ա���һ��ʯ�������ܻ��м���ʯ���ӡ�
ǽ���Ͽ���д���֣��Ѿ�ģ�������ˡ�����������������Ľ���
���ڹ��ķ�--�����󷨡�
LONG);

  set("exits", ([ 
 "out":"/d/yjp/yijiange",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","jiuxuan-dafa");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
