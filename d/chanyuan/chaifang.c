
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��");
  set ("long", @LONG
��������Ժ�Ĳ񷿡�ƽʱ�к�������������������ɢ�ҵط���һЩ
���ӡ���ͷ�ȶ�����ǽ�Ż�����һЩ��ľ��������Ҳ����Ժ�������е�
�ط���
LONG);

  set("exits", ([ 
	  "southwest":__DIR__"xiaolu7",
      ]));

  
  set("valid_startroom", 1);
  setup();
 
}

