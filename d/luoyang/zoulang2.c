
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�������������������ȡ����ȵı�����һ���ɻ��أ�����ɻ�����
���ǳ�Ư������ʱ�м������������������߹������������İ�ȫ��
LONG);

  set("exits", ([ 

  "east":__DIR__"wangfu_neiting",
  "west":__DIR__"shufang2",
  //"north":"/d/job/tujuejob/luoyang_junjichu",
       ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

