
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������λ�ڶ������ڵ�һ�ҽ����꣬ר��Ϊ�˿��������ֽ�����Ʒ��
�㵽�����ڷ��������õ���Ʒ���н����������������ȵȣ������
����������Ŀ��
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie5",
       ]));
  set("objects",([
         __DIR__"npc/huoji2":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

