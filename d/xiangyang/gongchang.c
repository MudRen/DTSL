#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������������Ĺ�����������һ���ܴ������¯��һ��ǿ׳�ǳ���
�Ĵ��������ڻ������������Աߵı������ϰڷ��Ÿմ�������Ļ�ð��
�����ĸ��ֱ�����
LONG);

  set("exits", ([ 
 "west":__DIR__"tiejianggh",
       ]));
  set("objects",([
	  "/d/job/tiejiangjob/tiejiang2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

