
inherit ROOM;

void create()	
{
	set("short", "��ǩ����");
	set("long", @LONG
���������°�������ĳ�ǩ���������������м����һ
�Ŵ����ӣ��������һ����ǩ�ĺ��ӡ��������Ի���������Գ�
ׯ�����µ����ա�
LONG);
    
 	set("exits",([
 	  "down":__DIR__"kantai1",
 	  ]));
 	set("no_death",1);
        set("leitai",1);
 	set("no_sleep",1);
 	set("no_channel","���Ǻúó�ǩ�ɣ�\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("no_fight",1);
	
      setup();
    
}
