
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ø߾��¸ڣ�����Σ�£������ľ���������ľ��������Ŀ���ġ�
��˵��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬�ֹ��������֡���ɽ��
���ڴ˷���ϴ�ģ���ɽ���ɻ���Ϊ�ģ�����ƽ����
LONG);

  set("exits", ([ 
 "westdown":__DIR__"jietuopo",
      ]));
  set("objects",([
     __DIR__"npc/xiangke":1,
     ]));
 set("valid_startroom", 1);
  setup();
 
}

