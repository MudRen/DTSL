
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�����������������ש��������������ġ�����û
��ʲô�ˡ��ϱ��������ɵ����¹㳡�����߾��������ɵ����������
���������������ش�����ĵط���������һ��������С·��
LONG);
  set("exits",([
	  "north":__DIR__"zhengdian",
	  "south":__DIR__"qingshilu1",
	  "east":__DIR__"xiaolu",
	  "westdown":__DIR__"shiwu",
	  ]));
	  
  set("objects",([
    __DIR__"npc/xiazhanglao":1,
    ]));
    
set("outdoors","yinkui");

  
  set("valid_startroom", 1);
  setup();
 
}

