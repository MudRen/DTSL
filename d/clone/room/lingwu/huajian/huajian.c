
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
������һ�����ң����ܺ�����ġ�ǽ����Լ���Կ����м���
�֡������������lingwu��������ڹ��ķ�--�ɻ���ˮ������
�ǳ��ž���������н���ƽ�������ˡ�
LONG);

  set("exits", ([ 
 "out":"/d/changan/didao3",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","flower-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
