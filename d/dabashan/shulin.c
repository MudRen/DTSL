
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǵ��ɽ��Ƭ���֡���ľ����ʮ��ïʢ�������Ŵ��ɽ�վ���
���Σ�����һ������
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu2",
           ]));

 set("objects",([ "/d/clone/npc/beast/she":1,]));
set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

