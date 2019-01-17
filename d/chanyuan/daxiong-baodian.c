
#include <ansi.h>
inherit ROOM;

int do_ketou();
void create ()
{
  set ("short",HIY"���۱���"NOR);
  set ("long", @LONG
�����Ǿ�����Ժ�Ĵ��۱�������빩�����������飬����޴�
�������Ž�ɫ�Ĺ�â������������������޺�����̬���졣��������
���ƣ�����һ�ؾ��׵ĸо����Ա��м���ɮ����������м���������
�ݷ�
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie3",
	  "eastdown":__DIR__"shilu3",
	  "northup":__DIR__"changlang2",
          "south":__DIR__"changlang4",
         ]));
  set("objects",([
    __DIR__"npc/foxiang":1,
    ]));
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_ketou","ketou");
}

int do_ketou()
{
    object me;
    me=this_player();
    if(me->is_fighting())
    return notify_fail("���ȴ�������˵�ɣ�\n");
    if(me->is_busy())
    return notify_fail("����æ���أ�\n");
    message_vision("$N���ŷ��񣬿��������дʣ�������ȥ������һ��ͷ��\n",me);
    me->add("bellicosity",-20);
    if(me->query("bellicosity")<0)
    me->set("bellicosity",0);
    me->add("sen",-10-random(10));
    me->start_busy(2);
    return 1;
}
