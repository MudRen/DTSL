
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"��ħ��"NOR);
  set ("long", @LONG
�����������ɵ���ħ�ã����������������[lingwu]������
���ڹ��ķ�--��ħ�󷨡����ﾲ���ĵģ��Ա��м�������������
ϥ��������ɫ�������㲻�������˽Ų���
LONG);

  set("exits", ([ 
 "out":"/d/yinkui/woshi2",
        ]));
  set("no_channel","�����л��ǲ�Ҫ˵����\n");
  set("no_tell","�����л��ǲ�Ҫ˵����\n");
  set("valid_startroom", 1);
  set("force","tianmo-dafa");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
