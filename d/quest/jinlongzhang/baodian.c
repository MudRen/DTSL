
inherit ROOM;


void create ()
{
  set ("short","���ܱ���");
  set ("long", @LONG
������ǻ����µĴ��ܱ�����湩�����������棬�ڵ��ϻ�����
�������š�ͷ�����ϷŹ���һ���ͭ�ӡ��м���ɮ�����������̾����
LONG);

  set("exits", ([ 

  "out":__DIR__"huilongsi",
  "south":__DIR__"wu1",
     ]));

  set("objects",([
    __DIR__"zhuchi":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}


