
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
����һ��Сɽ������Ȼ�������ѩ�أ�������ȴ��ů�紺��ֻ����
������һ��Сʯ��������д�ţ������ƶ��������֡����������һ��ʯ
���Ӻͼ���ʯ���ӣ�ͬ�����������ȣ��������Ǳ��ж��졣
LONG);

  set("exits", ([ 
 "out":__DIR__"songshu",
 "west":__DIR__"mishi2",
        ]));
  set("objects",([
     __DIR__"fan":1,
     ]));
  
  set("valid_startroom", 1);
  setup();
 
}

