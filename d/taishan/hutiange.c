
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
������̩ɽ�ĺ�������ﾰɫ�ǳ�Ư������ɽ����ȥ��һƬ���̣�
��紵�����������֮�����кܶ�������������Ϣ��̸���ź�ʱ�����ʵ�
̩ɽ�Ķ��ˡ�
LONG);

  set("exits", ([ 

   "eastup":__DIR__"zhongtianmen",
   "southdown":__DIR__"doumugong",
          ]));
  set("objects",([
     __DIR__"npc/shangren":1,
     ]));
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

