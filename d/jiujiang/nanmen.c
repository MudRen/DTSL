
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǾŽ������š���������˺ܶࡣ����ս����������Ž�����
�ܷ�������ʱ��������������������������ٱ�ҫ��������վ�����
��������������ˡ�
LONG);

  set("exits", ([ 

 "north":__DIR__"nandajie2",
 "south":"/d/dongming/guanlu2",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

