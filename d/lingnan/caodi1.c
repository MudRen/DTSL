
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء������Ѿ��������ˡ�ӭ�����һ����ֱ�������
���������������������Ʈ��ϱ�����ԼԼ���Կ���һ���Ǳ��ƵĽ�
���
LONG);

  set("exits", ([ 

  "northwest":"/d/xiangyang/caodi1",
  "southeast":__DIR__"dalu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

