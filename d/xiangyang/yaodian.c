
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩ��");
  set ("long", @LONG
������һ��ҩ�ꡣ����ս�����꣬�������������ܺá������ҩ
��������ȫ�������������кܸߵ��������ϰ��������ѧͽ������ҩʦ
һʱ��������������ְҵ������ѧ������ѧϰҩ���ϰ�����ҩ��ķ�����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie3",
 "enter":__DIR__"yaoshigh",
        ]));
 set("objects",([
	 __DIR__"npc/shangguan":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}
/*
int valid_leave(object me,string dir)
{
        if(me->query("vocation")!="ҩʦ" && dir=="enter")
                return notify_fail("�㲻��ҩʦ�����ܽ���ҩʦ����!\n");
                return ::valid_leave(me,dir);
                return 1;
}
*/
