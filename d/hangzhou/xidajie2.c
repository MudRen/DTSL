
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵ�����֡����߾��Ǻ��ݵ�����ʤ�������Ķ����ˡ���
����һ����ͤ���кܶ����������̸Ц���������������������ľ�ɫ��
�ϱ���һ�ұ����꣬���洫����ƹ���ô��������������������˺ܶ࣬
���ַǷ���
LONG);

  set("exits", ([ 
 "north":__DIR__"liangting",
  "west":__DIR__"dongan1",
  "east":__DIR__"xidajie1",
  "south":__DIR__"bingqidian",
         ]));
  set("objects",([
    "/d/clone/npc/lingzhigao":1,
    ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

