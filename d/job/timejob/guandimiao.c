
#include <ansi.h>
inherit ROOM;
int do_jiangli(string arg);

void create ()
{
  set ("short",HIR"�ص���"NOR);
  set ("long", @LONG
���������ݵĹص���ÿ����������ƽ�����˺ܶࡣ�����ֱ�����
�ң��������Ǹ�Ը�����������ƽ������������һ���ع�����������
����һ���������µ����������ݡ�
LONG);

  set("exits", ([ 
 "south":"/d/yangzhou/xidajie1",
        ]));
  set("valid_startroom", 1);
  set("target",([
     "name":"",
     "level":"",
     ]));
  set("objects",([
     __DIR__"timerobot":1,
     ]));
  setup();
 
}
