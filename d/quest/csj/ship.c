inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY"ս��"NOR);
	set("long", @LONG
����һ�Ҿ޴��ս���������кܶ�ٱ��ڵ����߶���ս����Φ����
Ʈ��һ��޴�����ӣ�����д�š����ġ��������֣����Ʈ��ò���
�硣
LONG);
	set("outdoors","������");
        set("objects",([
           __DIR__"npc/yuwen-huaji":1,
           ]));
        set("exits",([
          "out":"/d/job/sjbjob/dongan",
          ]));
	setup();      
}
