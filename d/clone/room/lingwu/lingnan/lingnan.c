
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIG"�����"NOR);
  set ("long", @LONG
�����������μұ�������á���ǰ����һ�Ѵ󵶣�����������
�������⣬�������ˡ����������������lingwu���μұ�����
���ķ�--���������
LONG);

  set("exits", ([ 
 "out":__DIR__"baihutang",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","tiangang-sanjue");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
