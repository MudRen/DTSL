
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�鷿"NOR);
  set ("long", @LONG
��������������鷿����ƽʱ������칫���м��������ػ����鷿
�ſڣ�һ����֪�������е����ָ��֡�������˺ܶ��鼮����Ȼ������
��һ��˧�ţ���������Ͷ�����ĺ���Ҳ�ǲ��١�
LONG);

  set("exits", ([ 

  "south":__DIR__"zoulang1",
      ]));
  set("objects",([
	  __DIR__"npc/wangshi-chong":1,
	  ]));
  set("victory","luoyang");

  
  set("valid_startroom", 1);
  setup();
 
}



