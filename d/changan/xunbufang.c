
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ѳ����");
  set ("long", @LONG
�����ǳ�����Ѳ������ÿ���кܶ෸�˶���ץ�������������ս
�ң����鷸�Ƶ��¸������ŷ�������������Ĳ�ͷ�������Ǻ�æ��
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie1",
      ]));
  set("objects",([
    "/d/job/butoujob/butou":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

