
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������µ������ˡ����ҿ����������ࡣ���ϵı����������
���롣�������Ʒ�ڷŵĺ����룬��������Ů�����˱Ƕ��������ҵ���
�������һ�Ŵ����ӣ����ӷ���һ��û�п�����顣�����ڵİ��費��
�ܺ�������ÿһ����Ʒ���Ƕ��߽��ģ���һ�������֮Ʒ��
LONG);

  set("exits", ([ 

  "west":__DIR__"caodi2",
    ]));
  set("objects",([
        __DIR__"npc/songyuzhi":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

