
#include <ansi.h>
inherit ROOM;


void create ()
{
 set ("short","��¶��");
  set ("long", @LONG
��¶��ƽ��������Σ������������Ϊ���䣬������ȣ���ש�̵أ�
�ݶ�Ϊ�����Ľ��ܼ⣬���渲��ɫ�����ߣ���Ϊ̥ͭ�̽𱦶���������
���ţ�������������������ʮ���ȣ��������������昆���Ÿ����ȣ���
ǰʯ�׶�����һ�����ϱ����������м�Ϊ������������·��̤�塢����
ǳ�̾���ơ����������������
LONG);

  set("exits", ([ 
 "north":__DIR__"yanjiadian",
 "south":__DIR__"liangyidian",
 "eastdown":__DIR__"dongyuchi",
 "westdown":__DIR__"xiyuchi",
        ]));
set("objects",([
	  "/d/changan/npc/wangtong":1,
	  ]));
 
  set("valid_startroom", 1);
  setup();
 
}

