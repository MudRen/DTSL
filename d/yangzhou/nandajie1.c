
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
���������ݳǵ��ϴ�֡����������ݵ������ˡ�ԶԶ������������
�������������������������ļ�Ժ--����¥���кܶ����վ���ſ��к�
���������ˡ����ȵ���ѬѬ�Ľ������������Ǳ���ȥ��
LONG);

  set("exits", ([ 
 "east":__DIR__"chunfenglou",
 "northwest":__DIR__"nanhudi2",
 "south":__DIR__"nandajie2",
        ]));
  set("objects",([
     "/d/clone/npc/dugu-xiong":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

