inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǻ������ˣ�����λ������֮���ϣ����֮���������ܭ��
����֮�ƣ��Թ�Ϊ���ұ���֮�أ��������´��ң�Ⱥ�۲�������Ҳ��
�����֣�������˭�����ﶼ�����ر�������Ϊ�����Ǿ����صأ����Զ�
�����������̲��ʮ���ϸ�	
LONG );

	set("exits", ([
               "west"      : __DIR__"jinyong-cheng",
               "northwest"      : __DIR__"tulu4",
               "south"      : __DIR__"tulu5",		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



