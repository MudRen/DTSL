// /d/yazhang/nandajie1.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��ʯ�̳ɵĵ�·��ƽ̹�����������洫��һ��ҩζԭ����һ������
�ŵ�ҩ�̣�����������Ψһ�Ҵ��ջ���˵صĿ��̴��������ס�ޡ�
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
                 "south" : __DIR__"beidajie2",  
                  "north" : __DIR__"huanggong",  
                  "east" : __DIR__"kezhan",  
                  "west" : __DIR__"yaopu",    
	]));
       setup();
	replace_program(ROOM);
}	
