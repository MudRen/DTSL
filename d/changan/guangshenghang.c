

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʢ��");
  set ("long", @LONG
���ǹ�ʢ�г������ܵ꣬���̹�ģ��󣬶˲赽ˮ��������ˣ�̸
������˰�ټ��ĵ��ö��켷���ˣ����һ���ʱ���л�ƿ����ΰ�����
�����������ʽ���ѹ��ܳ�Ϊ���к��ε���Ҫ��Ӧ�̺�֮һ��
LONG);

  set("exits", ([ 
 "east":__DIR__"xishidongjie5",
  
       ]));
  set("objects",([
         __DIR__"npc/xiaoer6":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

