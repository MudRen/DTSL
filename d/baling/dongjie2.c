
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ���Ķ��֡����߾��ǰ���Ķ����ˡ�������һ��Ǯׯ��Ǯ
ׯ�Ľ����������������ҫ���������⡣���ߵĶ��Ŵ����˹ٱ�ߺ�ȵ�
������
LONG);

  set("exits", ([ 

  "north":__DIR__"qianzhuang",
  "east":__DIR__"dongmen",
  "west":__DIR__"dongjie1",
      ]));
 set("objects",([
   "/d/quest/yrs/zhuge-dewei":1,
   ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

