#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������������ó���õķ��������˵�Ȩ�ߵ�ע�⣬�������ھͳ���
�������Ӵ���г��������к������У����±���ר�Ź�����Щ�г���
��Ļ�����ͳһ����ȫ������ó���
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie3",
 "west":__DIR__"shunyimen",
   ]));
  set("valid_startroom", 1);
  setup();
 
}

