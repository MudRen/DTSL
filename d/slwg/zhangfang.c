
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�˷�");
	set("long", @LONG
������ʯ����ݵ��˷���ƽʱ���˷�������������Ǯ����������
��ѧϰ���յĵ��Ӷ�Ҫ�����ｻѧ�ѵġ�ͬʱÿ������������Ҳ������
ȡ�Լ��Ĵ�
LONG
);


	set("exits", ([
		"west" :__DIR__"zoulang1",
     ]));
	set("objects",([
	    __DIR__"npc/zhangfang_xiansheng":1,
	    ]));
       set("no_fight",1);
      setup();
}
