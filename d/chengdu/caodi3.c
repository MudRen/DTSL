
inherit ROOM;

 void create()
{
       set("short", "�ݵ�");
       set("long", @LONG
������һƬ��ݵأ��Ա���һ��СϪ�����߿������в��ٵ���ľ��
����Ⱥ���������������ǳ��վ���
LONG);
       set("exits", ([
               "east":__DIR__"caodi2",
               "westup":__DIR__"shijie1",
                  ]));
 if(sizeof(children(__DIR__"obj/xuantie"))<5)
       set("objects",([
       __DIR__"obj/xuantie":1,
       ]));
       setup(); 
      
}

