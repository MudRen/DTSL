
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ��");
  set ("long", @LONG
�����ǳ��������������Ҫ����סլ�������ǹ��ƿ��Ĵ�լԺ��
Ժ�����أ�ӵ���쾮���á������ڵ������Ϊ�߶���ǽ�����㹹���г�
��������š�լ�Ŷ���װ�޽�������ľ�ţ���ǽ��Ժ������������
�ֵĴ����Ȼ���죬������͡�
LONG);

  set("exits", ([ 
   "east":__DIR__"hgdajie1",
        ]));
  set("objects",([
         __DIR__"npc/baixing":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

