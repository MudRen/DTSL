

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ˮ����");
  set ("long", @LONG
���ǳ����ǵ�һ��ˮ���ꡣ�����������һ���ŵ���𣬿����и�
ʽ������ˮ���������ˮ��Ϊ�˱������ʣ�����ÿ��ӳ���Ĺ�԰�ÿ�
�������ġ�ˮ����Ů�ϰ���ɩ��������к��ſ��ˡ�
LONG);

  set("exits", ([ 

 "west":__DIR__"xishidongjie5",
        ]));
  set("objects",([
	  __DIR__"npc/zhao":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

