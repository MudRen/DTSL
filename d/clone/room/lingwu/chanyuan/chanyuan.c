
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",MAG"����Ժ"NOR);
  set ("long", @LONG
�����Ǿ�����Ժ�Ŀ���Ժ�������������[lingwu]��Ժ����
���ķ�--�տ���������ɮ�������������Ĭ����㲻������
�˽Ų���
LONG);

  set("exits", ([ 
 "out":__DIR__"room",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","bikouchan");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
