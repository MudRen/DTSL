
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��¹��Ժ");
  set ("long", @LONG
���������������İ�¹��Ժ��ר�Ÿ���Ϊ��͢�����˲ţ���ϧ����
ս��Ƶ��������֮���ʢ���Ѿ�������������������ι�֮���ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"nanjie1",
       ]));
  set("valid_startroom", 1);
  setup();
 
}

