
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ӭ����");
  set ("long", @LONG
�˶��ơ���������ӭ�����������������������ں��������Ԫ��
�񣬶�����¶�����⣬������н��������С�ʯ�顱�������кܶ�����
���й䣬�������Ƚ����֡�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu5",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
