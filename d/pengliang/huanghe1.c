inherit ROOM;

void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӵĵİ��ߡ���վ�ڰ��ߵĴ���ϣ���ǰ�ƺӹ���������
���ˡ��޷綼�������ˣ���ˮ������ɳ������������о���̺�����
�𶯡�
LONG );

	set("exits", ([
              "west"      : __DIR__"edao7",
               "east"      : __DIR__"huanghe2",
		
	]));


 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



