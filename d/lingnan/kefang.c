
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ͷ�");
  set ("long", @LONG
�������μұ��Ŀͷ������ϵı�������������룬ƽʱ���μұ���
Ѿ���������ɨ���䣬����������ʰ�úܸɾ������Ӻʹ�����һ����Ⱦ��
���������ӣ�����ܾ�û����ס���ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaojing1",
      ]));
  set("sleep_room",1);
 
  setup();
 
}

