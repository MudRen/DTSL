// /d/gaoli/ suishixiaolu2
// Room in  ��ʯС·
// laowuwu 99/06/27
inherit ROOM;
void create()	
{
	set("short", "��ʯС·");
	set("long", @LONG
��˳��С·��ǰ�ߣ����ֲ�Զ�ĵط���һ�����ᣬ�������
�Ľ���ʦ�������֣����Ľ�С����
LONG
	);
set("outdoors", "/d/yijiange");
set("exits", ([
                "southwest" : "/d/gaoli/xiaoxi1",
                "northwest" : __DIR__"zhuangmen",  
                "northeast": __DIR__"zhulin",            
           	]));
       setup();
	replace_program(ROOM);
}	
