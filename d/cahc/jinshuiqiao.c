
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ˮ��");
  set ("long", @LONG
�����ڳ����Ľ�ˮ���ϡ���������������ۣ�����ù��񹦣�
���ư��磬ʹ������һ�򵱹����Ī�еĸо���������һ���峺���ס���
�ѵش�����С�ӣ���ˮ��ʱײ��ʯ�ϣ��������ȵ���ˮ�����ö���������
�߾�����ҵ������ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"wangfu",
 "south":__DIR__"beijie3",
        ]));
 /*        set("objects",([
         "/d/job/banghuijob/lifa":1,
          ]));*/
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
"/obj/board/lifa_b.c"->foo();
}

