// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "������Ȫ");
	set("long", @LONG
�����¥�����Ǹ����ɽѽ�ʮ�Ŵ�Բ���ķ��ã���¥��Ժ
�Ǹ���԰����������������Ȫ���ڲ��������Ȼ��������������
��ʱ�Ѳ��ü��ӵķ�������Ϊ�ɽ縣�ء�
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "east":__DIR__"kezhan",  
                	]));
       setup();
	replace_program(ROOM);
}
