
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨѵ��");
  set ("long", @LONG
ͨѵ���ǻʹ���̫����ͨ��������Ҫ�ţ������������ӣ������Ͼ���
������Ȼͬ���ʹ������������������Ȼ��ɭ�ϣ��ųʳ����Σ�����ʯ
Ϊ������שΪǽ����Ϊ��̡�
LONG);

  set("exits", ([ 
 "eastup":__DIR__"chengendian",
 "west":__DIR__"dongyuchi",
        ]));
  set("objects",([
          "/d/cahc/npc/liaonan":1,
          ]));
  

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

