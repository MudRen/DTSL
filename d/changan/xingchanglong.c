

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�˲�¡");
  set ("long", @LONG
�����˲�¡�������ܵ꣬���̹�ģ��󣬶˲赽ˮ��������ˣ�̸
������˰�ټ��ĵ��ö��켷���ˣ����һ���ʱ���л�ƿ����ΰ�����
�����������ʽ���ѹ��ܳ�Ϊ���к��ε���Ҫ��Ӧ�̺�֮һ����������
���֣���ʢ�еĲ����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshixijie1",
 //"west":"/d/clone/room/hanghui/room",
       ]));
  set("objects",([
         __DIR__"npc/shangren3":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

