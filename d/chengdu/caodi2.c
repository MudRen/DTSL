
inherit ROOM;

 void create()
{
       set("short", "�ݵ�");
       set("long", @LONG
��ͻȻ�����ȴ������л�����ô�����ĵط����Ա���һ��СϪ����
��������һƬ��ݵ��ϡ�����������ºͣ��������£������˼���ɾ�
һ�㡣
LONG);
       set("exits", ([
               "west" : __DIR__"caodi3",
			   "out":__DIR__"shulin4",
                  ]));
	   
       setup(); 
      
}

