inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵĶ���֡������Ǻ��ݵĶ����ˡ�������һ��԰�֣���
�ܶ����˳�������ȥ��ֻ���������м���������ʫ���ԣ���Ȼ���ʱ��
���ң������ݵ������ƺ����⼸����������ս�ҵ�Σ����
LONG);

  set("exits", ([ 

  "east":__DIR__"dongmen",
 "south":__DIR__"dangpu",
   "west":__DIR__"dongdajie1",
   "north":__DIR__"yuanlin",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

