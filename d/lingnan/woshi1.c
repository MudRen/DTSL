
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǡ��쵶����ȱ�����ҡ����ҿ����������ࡣ���ϵı������
�������롣���ҵ����������һ�Ŵ����ӣ������ϵı�ī�ŵú����룬
����һ������ŷ������档�����ڵİ��費�Ǻܺ�����������������
��Ҳ�ǲ����ˣ�ÿһ����Ʒ�޲��ǹŶ�������������Ʒ��
LONG);

  set("exits", ([ 

      "north":__DIR__"huayuan2",
    ]));
  set("objects",([
	  __DIR__"npc/songque":1,
	  ]));
  set("valid_startroom", 1);
 
  setup();
 
}

