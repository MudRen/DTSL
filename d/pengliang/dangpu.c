inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���߽����̣�����������һ�����̨������Ҫ�䵱�Ķ�������Ҫ��
��̨�Ĵ����͹�ȥ��������ͷ�Ĺ�����й��ۡ�
LONG
	);
set("exits", ([
                "north"  :__DIR__"xidajie",
	]));
         set("objects", ([
		 __DIR__"npc/gongfeng" : 1
	]));
       setup();
	replace_program(ROOM);
}	
