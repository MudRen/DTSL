
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵ�����֡������߿��Ե������������˵ĵط���������
���Ǻ��ݵ������ˡ��кܶ��οͶ�����������ȥ��������һ�Ҿ�¥����
����������㣬�ȾƳ��ֵ�����ͬʱҲ�����������ͷ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xihulou",
  "west":__DIR__"xidajie2",
  "east":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

