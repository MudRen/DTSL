
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������ǳ���ɽ���������ˣ����������Ҫ�����߶���ͻ�����ʯ
�ͱڣ���·�����Ǳ�ѩ��һ��С�ľͿ��ܻ��䵽ɽ��֮�С�·���Ա���
��һ����ʯ����������ּ��Ѿ�ģ�����壬ֻ����Լ����������������
�֡�
LONG);

  set("exits", ([ 
 "westup":"/d/changbaishan/tiyun-feng",
 "eastup":__DIR__"wolong2",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

