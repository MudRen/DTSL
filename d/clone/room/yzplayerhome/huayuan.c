
inherit ROOM;
void create()	
{
	set("short","��԰");
	set("long", @LONG
������һ��С�͵Ļ�԰�����ﻨ�ݷ��࣬���������Ʒ�֡�
��Ϊ���������ļ��紺���������������ʻ�ʢ������ʱ��������
�´������߹���
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie4",
	        "north":__DIR__"asc/xsl",
	       
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
