
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","������");
  set ("long", @LONG
���Ƕ����𣬶������ة����������£��������е�һ����������
���Դγ�ã��Լ�ð�棬�������죬�̽������ߣ�һ����ʵ������û�գ�
���������г��õ�ꭳӾ�������ͳһ������Ӧ���Ͻ�˽�ƣ��г����
�������嶨���ⶼ��������������������������
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshixijie3",
         ]));

  set("objects",([
   __DIR__"npc/zhangguan":1,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}
