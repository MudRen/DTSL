
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������λ�ڶ������ڵ�һ�������꣬ר��Ϊ�˿���������������Ʒ��
�㵽�����ڷ��������õ���Ʒ����������������������ȵȣ�������
����������Ŀ��
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshixijie5",
       ]));
  set("objects",([
         __DIR__"npc/huoji1":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

