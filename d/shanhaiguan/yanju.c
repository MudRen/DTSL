
#include <ansi.h>
inherit ROOM;

#define JOBNAME "ɽ����"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
������ɽ���ص��ξ֣��ܹ�ɽ���ص����ˡ���������ս�ң���䷷
��˽�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һ
Щ���������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷�
���������е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ��
�˴������������γ�������ȥ��
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie",
       ]));
  set("objects",([
	  "/d/job/yunyanjob/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

