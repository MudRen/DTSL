
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��վ");
  set ("long", @LONG
�����ǳ�������վ���������ڵ��ż��ʼĶ���ͨ����������ɵġ�
���ڳ������ڵ��˿��ڶ࣬������վ�ڵ��˶��ڲ�ͣ��æµ�ţ�������
ʱ��ͣ����������к����Աߵ����������кܶ����ԣ���Ϊ���յĲ�ͣ
���ܶ��Ե��൱ƣ�롣
LONG);

  set("exits", ([ 
 "east":__DIR__"csdajie3",
       ]));
  set("objects",([
   __DIR__"npc/bing":1,
   "/d/clone/npc/chuzi":1,
   ]));
  
  set("resource/water",1);
  set("sleep_room",1);

  set("valid_startroom", 1);
  setup();
 
}

