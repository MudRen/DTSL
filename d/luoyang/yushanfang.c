
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"���ŷ�"NOR);
  set ("long", @LONG
�����������ʹ������ŷ������﹩Ӧÿ��ʹ��ķ��ˡ�����������
���ŵ�æµ�ţ�һ�����˲��ϵ���������ʲô����������������������
�㡱����ѩ����÷���������ϵȵĺòˡ��������������������������
��ˮ��
LONG);

  set("exits", ([ 
  
  "north":__DIR__"shijie3",
  "south":__DIR__"dongdian",
         ]));

  set("objects",([
   __DIR__"npc/chuzi1":2,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

