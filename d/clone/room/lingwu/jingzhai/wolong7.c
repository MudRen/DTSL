
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��β��");
  set ("long", @LONG
��������������ϵİ�β�壬�����������塣����������������
������������Ҫƽ̹�öࡣ������һƬï�ܵ������֡��ϱ����߶���
���͵������ͱڡ�һ��紵������ѩ���������
LONG);

  set("exits", ([ 
 "westup":__DIR__"wolong6",
 "east":__DIR__"shulin",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

