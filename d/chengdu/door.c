
inherit ROOM;
 void create()
{
       set("short", "�������");
       set("long", @LONG
������������ҡ�������ǳɶ���һ�󸻻�������Ů�����ø���ǧ
�����ġ�ÿ��������׵��˶����ﲻ������˵������ͳɶ��Ķ��𱤹�
ϵ�ܣ�����������ڳɶ�Ҳ��ռ��һϯ֮�ء�
LONG);
       set("outdoors", "�ɶ�");

       set("exits", ([
               "north" : __DIR__"dongdajie2",
			   "enter":__DIR__"tingyuan",
                         
       ]));
	   set("objects",([
		   __DIR__"npc/jiading":1,
		   ]));

       setup(); 
      
}

int valid_leave(object me,string dir)
{
	if(objectp(present("jia ding",environment(me)))&&dir=="enter")
		return notify_fail("�Ҷ�����һ��:������ɲ��ܽ�ȥ!\n");
	return ::valid_leave(me,dir);
}

