
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵĶ���֡���������˽϶࣬������һ��������԰�ӣ�
��˵���澭���ֹ�����ƽʱ����û����ȥ��������������ݵĶ���
�����Կ����м����ٱ������������
LONG);

  set("exits", ([ 
 "east":__DIR__"dongmen",
 "west":__DIR__"dongdajie2",
 "north":__DIR__"feiyuan",

        ]));
  set("objects",([
    "/d/clone/npc/zhangshihe":1,
    ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

