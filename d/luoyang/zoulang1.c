
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
���������������ȡ����ܷǳ��ž�����ʱ��Ѿ�ߴ������߹���ǽ��
���кܶ�ڻ�������ɽˮ�羰���ֱʲ���������Ѳ�ߵ����������ϵ���
��������������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"wangfu_neiting",
  "north":__DIR__"shufang",
  "east":__DIR__"caizheng_ting",
       ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

