
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ǰ����");
  set ("long", @long
�����������Ҫ�����Ķ࣬�㹻һ����Ů�������裬�Լ�����ʮ��
�����ˣ��Ա���¥�ݿ��Ե�¥�ϵ����������������������������緢
�������飬���ƣ���Ů������˵���˼��ɾ���
long);

  set("exits", ([ 
 "south":__DIR__"huafang",
 "up":__DIR__"2chuancang1",
 "north":__DIR__"chuancang1",
 
        ]));
 set("objects",([
	 __DIR__"npc/wunv":4,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

