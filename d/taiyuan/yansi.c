
#include <ansi.h>
inherit ROOM;

#define JOBNAME "̫ԭ"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
������̫ԭ���ξ֣��ܹ�̫ԭ�����ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
       ]));
  set("objects",([
	  "/d/job/yunyanjob/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

