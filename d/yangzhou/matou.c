
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"matou"
#define TO __DIR__"huafang"
#include "/std/shiproom.c";
void create ()
{
  set ("short","��ͷ");
  set ("long", @LONG
����������������ͷ���кܶ��ͽ����������ȥ����Ѱ������
һ����������������ʲô�ö�����
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guangchang1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","yangzhou");
  setup();
 
}


int valid_leave(object me,string dir)
{
	if(dir=="northeast")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}