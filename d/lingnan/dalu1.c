
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĵ�·��ӭ�����һ����ֱ�������������������
���������Ʈ��ϱ�����ԼԼ���Կ���һ���Ǳ��ƵĽ����
LONG);

  set("exits", ([ 

  "northwest":__DIR__"caodi1",
  "south":__DIR__"dalu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

