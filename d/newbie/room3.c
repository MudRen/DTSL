
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
���ｫ���ܴ�������Ϊ�Ž�ĵط����������������Ҫ����ͬһ
��֯���˹��ܶ���Ϊ�����ǵľ���ͽ�ǮŬ�����������õ��˽����ݣ�
��ʹ�� help banghui ���鿴��һ�������˰�ᣬ��Ҳ�;�����Ѫ�ȵ�
����֮�У��ɲ�Ҫ������������������ KILL ����
LONG);

  set("exits", ([ 
 "east":__DIR__"room1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

