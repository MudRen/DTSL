
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","˿���");
  set ("long", @LONG
������˿֯�������£����С� ��ɽ������֯��ߡ� ֮������
˿����ר�����Բ��ӷ�ӡ�����Ƶľ����֯�������������ͬ���ƣ�
Ⱦӡʱ���ƴ����ܽӴ�Ⱦ�ϣ�Ⱦɫ�󣬽�ȥ�߽ᣬ���ƿɱ���ԭɫ����
�Ի��ɡ� 
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie3",
         ]));
  set("objects",([
         __DIR__"npc/huoji3":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
