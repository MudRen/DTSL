#include <ansi.h>
inherit ROOM;
 void create()
{
       set("short", "��");
       set("long", @LONG
������������ҵĲ񷿡����Ϸ��źܶ�����õ�ľ��ͼ��Ѳ񵶡�
ƽʱ����������ɻ������������������ǳ����ǡ�
LONG);
    
       set("exits", ([
               "east" : __DIR__"tingyuan",
			            
       ]));
	
       setup(); 
      
}

