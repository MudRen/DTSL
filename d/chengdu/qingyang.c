
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǳɶ������򹬡����ǳɶ������ĵ��ۣ����ʮ�ֶ�ʢ��ÿ��
���������ʮ�ֶࡣ�ɶ��⼸��ۼ��˺ܶ�������ʿ�����Զ�����Ȼ
Ҳ�ɳ��˺ܶ���ӳ���Ѳ�ӡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
  
	setup();
	replace_program(ROOM);
}

