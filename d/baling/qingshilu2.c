
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�������ǰ���ı��š���������˺ܶ࣬���ϱ���
�Ϳ��Ե�����������ˡ����ڽ���������Ᵽ����������Է�����
��Ϊְҵ�����԰���Ľ�ͷ�ټ�����Ů���ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"qingshilu1",
 "east":"/d/clone/room/cityroom/baling",
  "north":__DIR__"beimen",
       ]));
 set("objects",([
	 __DIR__"npc/boy":1,
	 ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

