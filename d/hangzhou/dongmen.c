
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ��ݵĶ��š�����������ʤ�أ�����������Ȼ��ս��ʱ�֣�
����Ȼ�ڸǲ������ﷱ���ľ���ͬ������ȣ������й����޲�������
����������˺ܶࡣ�����������ٱ����ڼ�������������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"dongdajie2",
  "east":__DIR__"guandao1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

