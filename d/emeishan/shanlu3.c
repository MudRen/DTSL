
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һ����ͤ��������һ��ˮ̶���ϱ��Ƕ�ü
ɽ���۽�̨���������������˱���ĵط�����ʱ�����˺��ȴ򶷵�������
������������ı̷�Ͽ�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"liangting",
 "west":__DIR__"bifengxia",
 "north":__DIR__"shuitan",
 "southup":__DIR__"lunjiantai",
 "northup":__DIR__"jietuopo",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
   if(dir=="southup"&&ob->query("pker"))
    return notify_fail("ͨ�����ϲ�ȥ��̨��\n");
   return ::valid_leave(ob,dir);
}

