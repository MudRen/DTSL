
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��˹����");
  set ("long", @LONG
������һ��Ρ���ΰ�Ĳ�˹���£��ܶ�Ӳ�˹���Ŀ��̶�Ҫ������
�����ݣ�������״���أ�Ģ��״�Ĵ�Բ���ⶥ�����ڸ�����֮�ϣ�Զ
������һĿ��Ȼ��
LONG);

  set("exits", ([ 
 "east":__DIR__"zqdajie4",
       ]));
  set("objects",([
         __DIR__"npc/shangren2":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

