
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������ͷ");
  set ("long", @long
�����ͷλ�ڻʹ��������ǵ�������Ѳ��ʱ����ģ�ר�Ź���
�ʵ�ʹ�á����������Ѿ��Ǹ�������ͷ���������ٸ��ƹܡ�
long);

  set("exits", ([ 
      "north":__DIR__"xiangwangjie3",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

