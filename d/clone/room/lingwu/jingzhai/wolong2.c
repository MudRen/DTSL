
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
��������������ϵ�����ǡ����������խ������һ�����������ǡ�
��������Կ���ɽ�µİ�����ѩ��һ�󺮷紵�������������ѩ������
�����ͱڶ��£�һ��С�ľͻỬ����ȥ��
LONG);

  set("exits", ([ 
 "westdown":__DIR__"wolong1",
 "northup":__DIR__"wolong3",
 "eastup":__DIR__"wolong5",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

