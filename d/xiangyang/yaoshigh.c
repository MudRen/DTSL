#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩʦ����");
  set ("long", @LONG
����ҩʦ�ǵĹ��ᣬ����ҩʦ�Ĵ�С���鶼�����ﴦ���������
���ָ����ҽѧ�鼮��һ��ҩʦ����ָ��������ѧͽѧϰ��Щ��������
����һ��ͨ��ҩ�������ȡ�
LONG);

  set("exits", ([ 
 "out":__DIR__"yaodian",
 "east":__DIR__"yaofang",
       ]));
  set("objects",([
	  "/d/job/yishengjob/yisheng1":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

