
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵİ����¡����������ս�ң���������ݷ���˲���
�ܶ��ˣ�ֻ�м���ɮ��������������е����������Ȼ�����ޱߣ���
����ȴ�޷�������˵�ʹ�ࡣ
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie1",
        ]));
  set("objects",([
          "/d/job/jj/heshang2":1,
          __DIR__"npc/shami":1,
          ]));
set("no_fight",1);set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

