
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
����һ�����͵ĳɳ��������ǲ���ȱ�١������ʹ�� help job ��
�鿴Ŀǰ�����񡣶���һ�����ˣ������ѡ������ɾ��������ȽϽ���
����ȥ����Ժ�ĳ������������Զ���������Լ������ɵĳ�������á�
LONG);

  set("exits", ([ 
 "west":__DIR__"room13",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

