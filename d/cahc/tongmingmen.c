
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨ����");
  set ("long", @LONG
ͨ�����ǻʹ���̫����ͨ��Ҵͥ����Ҫ�ţ������������ӣ�������
����������Ȼͬ���ʹ������������������Ȼ��ɭ�ϣ��ųʳ����Σ���
��ʯΪ������שΪǽ����Ϊ��̡�
LONG);

  set("exits", ([ 
 "westup":__DIR__"houdian",
 "east":__DIR__"xiyuchi",
        ]));
  set("objects",([
          "/d/cahc/npc/chengmo":1,
          ]));
  

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

