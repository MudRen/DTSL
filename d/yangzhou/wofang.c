
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Է�");
  set ("long", @LONG
�����ǿ�ջ���Է��ˣ�����������˵����˺ܶ��ˡ����������
������Щ���ˡ�
LONG);

  set("exits", ([ 
 "down":__DIR__"kezhan",
 
        ]));
  set("sleep_room",1); 
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}
