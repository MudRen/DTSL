
inherit ROOM;
 void create()
{
       set("short", "ͥԺ");
       set("long", @LONG
������������ҵ�ͥԺ��������ֲ�˸��ֻ��ݡ����������������
�ң������Ǹ��񷿡�
LONG);
       set("outdoors", "�ɶ�");

       set("exits", ([
               "out" : __DIR__"door",
			   "east":__DIR__"woshi",
			   "west":__DIR__"chaifang",
                         
       ]));
	
       setup(); 
      
}

