
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵı���֡�����������Ѿ��ܶ��ˣ������������ò���
�֡��Ա���һ��С�Եֻ꣬����С����������������к������Ŀ��ˣ�
һ��������Ǳ�Ʈ������ʱҲ���������ȾƳ��ֵ�������
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "west":__DIR__"xiaochidian",
  "north":__DIR__"beimen",
         ]));
  set("objects",([
    "/d/clone/npc/tanyong":1,
    ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

