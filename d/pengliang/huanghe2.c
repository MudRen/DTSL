inherit ROOM;

void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӵĵİ��ߡ���վ�ڰ��ߵĴ���ϣ���ǰ�ƺӹ���������
���ˡ��޷綼�������ˣ���ˮ������ɳ������������о���̺�����
�𶯡���ı�����һ�涸�͵�ɽ�£�һֱ�������쵽�������ϸ��
����ż���������������� �������Ľ���������������ɽ���ϸߺ���
LONG );

	set("exits", ([
              "west"      : __DIR__"huanghe1",
               "east"      : __DIR__"huanghe3",
		
	]));


 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



