
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ǯׯ");
  set ("long", @LONG
���������ݳǵ�Ǯׯ�����Ǯׯ���������ƾõ���ʷ����������һ
ֱ�ܺá���˵Ǯׯ�ϰ�����ݵĹٸ����й�ϵ��������Ȼ��ս�������
������Ŀǰ��ƽ�����£������кܶ����������Ǯ��
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie3",
        ]));
  set("objects",([
	  __DIR__"npc/ouyang":1,
	  ]));
  set("no_fight", 1);
  set("valid_startroom", 1);
  setup();
 
}

