
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
������һ�����ң����ܺڰ���ֻ��һ֧���������ǰ������
�ϡ��Ա��м��������ţ����滹����һ��������������ּ��Ѿ�
ģ�����塣���������������lingwuͻ�ʵ��ڹ��ķ�----������
����
LONG);

  set("exits", ([ 
 "out":"/d/dingxiang/guoshifu",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","yanyang-dafa");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
