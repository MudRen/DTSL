
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������Ķ���֡�������ս����������Ժ��������ڽ����й䣬
�Ե��������塣ֻ�м�����ͷ�����������߹�������ش�����·�ߵ�С����
������һ��С���������Ʀ��å�ľ۵㡣
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie2",
 "west":__DIR__"guangchang",
 "north":__DIR__"xiaoxiang1",
        ]));
        set("objects",([
        __DIR__"npc/qianduguan":1,
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

