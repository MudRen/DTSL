
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǻ�ɳ��ľ����������һ��������(pai) ������д��һ��
�ʺ��[��]�֡�����ׯ�����£�����������˶���С������
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shalu",
         ]));
  set("objects",([
	  __DIR__"npc/bangzhu":1,
	  ]));
set("no_clean_up",1);
  set("item_desc",([
     "pai":HIR"    ��\n\n\n"NOR,
                ]));                               
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/haisha_b.c"->foo();
 
}

