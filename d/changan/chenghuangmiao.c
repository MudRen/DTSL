

#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ǳ����ĳ�������������Ĺ�ģ�ܴ󣬼������Ժ����ݵĳ�
������������ÿ�����������㹩��������ﲻ�������﹩��һ�����ɣ�
�߸����ϣ��溬΢Ц��
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie5",
 
        ]));
  set("objects",([
   "/d/clone/npc/potnpc":1,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}
