
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ǻʳǵı����ţ����������ĸ���ʴ��֡��������š���Ϧ��
���ڻ��߹�����������ϣ���ڻԻͣ�����ĿΪ֮�š������������ϣ�
����ƽ�����ո������ýӽ���
LONG);

  set("exits", ([ 
 "north":"/d/changan/tydajie4",
 "south":__DIR__"xineiyuan",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":4,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

