
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƿ��������ĳ��������﹩Ӧ��������ÿ��ķ�ʳ��ֻ������
�����������æ��׼����ʳ�������������磬�㲻�������˿�ˮ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"caiyuan",
    ]));
 set("objects",([
    __DIR__"obj/niurou":3,
    __DIR__"obj/mantou":3,
    ]));
 
 set("resource/water",1);

  
  set("valid_startroom", 1);
  setup();
 
}

