
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǻ�ɳ��ķ������ɳ��ÿ����һ�����⣬���ۼ��������
�ߡ�����ͨ���ǻ������죬��Ҳ�з��߲������������µ�ʱ��
LONG);

 set("no_fight",1);
set("no_exert",1);
  set("exits", ([ 

  "north":__DIR__"xiaolu3",
       ]));
  /*
  set("objects",([
    "/d/job/haishajob/cai":1,
    ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

