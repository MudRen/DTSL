
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",YEL"����"NOR);
  set ("long", @LONG
����һƬ���֣�Լ�м��̷�Բ��С�����ֻ���ïʢ����ס�����ϵ�
���գ����˸е�ʮ����ˬ���������հ�����ͣ��ƺ��������������е�
���ա��м�λ��������������������;�ɫ��
LONG);

  set("exits", ([ 
	  "northup":__DIR__"baishiguangchang",
	  "southeast":__DIR__"pudutang",
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

