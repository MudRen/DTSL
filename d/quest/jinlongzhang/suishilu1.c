
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�����������ģ���������ͷ��·���ұ���һ
��СϪ��Ϫˮ�峺���ס������һЩ������ľ��ɢ���ŵ�������
�㡣
LONG);

  set("exits", ([ 

  "southeast":"/d/xiangyang/tree1",
  "northwest":__DIR__"shijie",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

