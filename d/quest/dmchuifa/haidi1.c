
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","����");
  set ("long", @LONG
������ǳ���ĵײ�����������������������ߴ�ͷ��ֱ����������
�׽�ʯ�������У������������ƺ���������ʲô�󷨡�����СϺ����
������������ȥ������һ����Ȥ��
LONG);

  set("exits", ([ 

  "east":__DIR__"haidi1",
  "west":__DIR__"haidi2",
  "north":__DIR__"haidi3",
  "south":__DIR__"haidi2",
  "up":__DIR__"haitan",
      ]));

  set("valid_startroom", 1);
  setup();
 
}
