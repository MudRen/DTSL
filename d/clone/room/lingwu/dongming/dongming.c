
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"�̺��ɶ�"NOR);
  set ("long", @LONG
�����Ƕ����ɵı̺��á�����������ɽ��֮�л�����ô���
�ĵط����������������ұ�ʯ���������һ���޼ʵĴ󺣡�һ
��紵���������ĺ�����棬��ʱ����������ˡ������Ƕ�����
��������lingwu�����ڹ��ķ�--�����ķ��ĵط���
LONG);

  set("exits", ([ 
 "up":__DIR__"shanya",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","bihai-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
