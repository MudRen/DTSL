
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С¥");
  set ("long", @LONG
��������С¥����˵ʯ�������ס���������Χ�˻������أ���
���ǳ��Գɶ���������֮�֡����ϵı��컹�����������룬���Ӻʹ���
����һ����Ⱦ����������ÿ����Ѿ���������ɨ��
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaojing3",
     ]));
  set("valid_startroom", 1);
  setup();
 
}
