
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ְҵƪ");
  set ("long", @LONG
�����˴������벻������ְҵ�����أ��ڴ����У������ѡ������
ְҵ��������ҩʦ��ɱ�֡�
����Ľ����뵽���Ե�����ȥ�����ɣ��ڴ������ǲ���ת��ְҵ�ģ���
��ѡ��ְҵʱһ��Ҫ���ؿ��ǣ�
LONG);

  set("exits", ([ 
 "east":__DIR__"room8",
 "west":__DIR__"room9",
 "north":__DIR__"room10",
 "south":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

