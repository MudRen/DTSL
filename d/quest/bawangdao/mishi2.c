
#include <room.h>

inherit ROOM;
string do_look1();
string do_look2();
int do_nothing(string arg);
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ҡ�������һ���صء�����û�����⣬ֻ�����涴��©
�µ�˿˿���ߡ������и�ˮ̶���Ա߻��м���ƻ����������������Ϣ��
�ط���
LONG
	);


	set("exits", ([
		"east" :__DIR__"mishi",
	]));
	set("resource/water",1);
	set("sleep_room",1);
	set("objects",([
	__DIR__"pingguo":3,
	]));
	set("no_channel","�㻹��ר�������ɣ�\n");
 	setup();
}
  
