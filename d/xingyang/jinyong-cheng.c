inherit ROOM;

void create()
{
	set("short", "��ܭ");
	set("long", @LONG
������ǽ�ܭ���ˣ���ܭλ������֮���ϣ����֮�������������
����֮�ƣ��Թ�Ϊ���ұ���֮�أ��������´��ң�Ⱥ�۲�������Ҳ��
�����֣�������˭�����ﶼ�����ر�������Ϊ�����Ǿ����صأ����Զ�
�����������̲��ʮ���ϸ�	
LONG );

	set("exits", ([
               "east"      : __DIR__"heyang",
               "north"      : __DIR__"tulu4",

	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



