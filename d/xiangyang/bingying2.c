
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ӫ");
  set ("long", @LONG
�����������ı�Ӫ��ƽʱ�����кܶ��ʿ�����ϰ��ո��ǲ�������
�ֻ�������ٱ����ڱ�Ӫ���ſڴ�������Ϻ������˵ط��Ÿ��ֱ�
�����м�ƥ�����ڱ�Ӫ��Χ�߶�����Ϊû������ϸι�����Ѿ��ݵò���
�����ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie4",
        ]));
  set("outdoors","xiangyang");
 set("valid_startroom", 1);
  setup();
 
}

