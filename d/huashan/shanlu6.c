
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����·��᫣���ν�ǻ�ɽ���յ�֮һ������ȥ�����Կ�����ɽ
Ρ��ĳ����塣����ȥ�����Կ�����ɽ��������Ů�塣վ�����ＫĿ
Զ��������Ⱥɽ�������ϼ��������Ұ�������������һɨ���ա�
LONG);

  set("exits", ([ 
 "southdown":__DIR__"shanlu5",
 "westup":__DIR__"yunvfeng",
 "east":__DIR__"shulin1",
       ]));
       
  set("objects",([
	  "/d/clone/npc/beast/yeji":1,
	  ]));
   set("no_select",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
