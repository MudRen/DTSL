
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
�����Ǻ��ϱ������ɵ���������������ռž�������û��ʲ
ô���裬ֻ��һ������������ǽ�ϻ���һЩ���ɵıڻ�����Ȼ����
�������������ڲ�ס��������ա�
LONG);
  set("exits",([
	  "south":__DIR__"zhengdian",
	  "northeast":__DIR__"zhulin",
	  "northwest":__DIR__"caodi",
	  ]));
//set("objects",(["/d/job/ygsongxin/wencai-ting":1,])); move to �Ž���

  set("valid_startroom", 1);
  setup();
 
}

