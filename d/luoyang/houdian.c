
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"���"NOR);
  set ("long", @LONG
������������ʹ��ĺ�һ��������ٳ�ǰ��Ҫ��������Ϣ����
�����ڻʵۻ����޶ȣ���������Ҳ��ûʲô�����ˡ���������Ե��ʵ�
���޹���
LONG);

  set("exits", ([ 
  
  "southeast":__DIR__"shijie3",
  "north":__DIR__"qingshilu3",
  "southwest":__DIR__"shijie2",
         ]));
 set("objects",([
   __DIR__"npc/guanbing":2,
   ]));
  
  set("valid_startroom", 1);
  setup();
 
}

