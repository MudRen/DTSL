
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�鷿"NOR);
  set ("long", @LONG
���������Ա���鷿��������Ϊ��������ļ�˲ŵĹ�����������Ŀ
ǰս��֮�л���ܺã�������Ͷ�������Ľ����������ǲ��١�ֻ������
���˼������ӣ����Ա���ͼ�λ��������̸����ʲô��
LONG);

  set("exits", ([ 

  "east":__DIR__"zoulang2",
  

       ]));
  set("objects",([
	  __DIR__"npc/li":1,
	  ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

