
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIR"ִ����"NOR);
  set ("long", @LONG
�����Ǻ�ɳ���ִ���ã�����ڷ��˸����̾ߡ��м�����ɱ������
���������̣��������졣
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xiaolu3",
       ]));
       /*
  set("objects",([
  "/d/job/banghuijob/haisha":1,
  ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

