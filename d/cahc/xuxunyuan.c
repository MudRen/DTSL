
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ѤСԺ");
  set ("long", @LONG
������Ҵͥ���ڵ�һ��С԰���ʷ�軨ʢ���ļ��ڣ�԰�еĲ軨��
�涷�ޣ����࿪�š�԰����һ��С�أ��������㾧Ө��͸��������һ��
��ɽ��һ����ϸ��ע����У���һ��ɽˮ��԰ͼ��
LONG);

  set("exits", ([ 
 "east":__DIR__"chengqingmen",
         ]));
  set("valid_startroom", 1);
  setup();
 
}

