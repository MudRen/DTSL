
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����԰");
  set ("long", @LONG
����԰�ò�ʯ��·�����ӱ��¡�԰���·���Բ�ͬ��ɫ����ʯ����
�������ɣ���ɾŰ������ͬ��ͼ������������ܡ����Ϸ�硢��
�ʵȣ���·���ͣ���Ȥ���԰����ʯ�޲�����ľ���ף���Ű����ܣ�
�������������԰��׺����Ȥ��Ȼ�� 

LONG);

  set("exits", ([ 
 "north":__DIR__"xuanwumen",
 "southup":__DIR__"yanjiadian",
 "west":__DIR__"jiashan",
 "east":"/d/job/liyuanjob/guanyuting",
        ]));
  set("objects",([
          "/d/cahc/npc/pinfei":1,
          "/d/cahc/npc/shinv":3,
          ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

