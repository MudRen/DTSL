
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̫����");
  set ("long", @LONG
̫���±��ƹܳ�͢�������ǣ��淶���շ�͡��������ƽ���������
���Ļ���չѸ�٣�ʫ�ʸ���Խ��Խʢ�У��������֣��赸�ȹ�����
��Ҳ����̫���¡�
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie4",
        ]));
   
  
  set("valid_startroom", 1);
  setup();
 
}

