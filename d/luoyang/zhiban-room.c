
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��Ϣ��"NOR);
  set ("long", @LONG
�����ǻʹ�������Ϣ�ĵط�������ǳ�����һ�����ļ���������
��һ�𣬹��ڷ��˴��ССʮ���Ŵ��������ӵĵط������˼������ӡ�
���ӣ��м���������������Ȳ衢���졣
LONG);

  set("exits", ([ 
  "west":__DIR__"qingshilu3",
         ]));
   set("objects",([
	   __DIR__"npc/guanbing":2,
	   __DIR__"obj/changjian":2,
	   ]));
   set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

