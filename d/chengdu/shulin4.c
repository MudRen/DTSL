
inherit ROOM;
int do_zuan(string arg);
 void create()
{
       set("short", "�ȴ�����");
       set("long", @LONG
����һƬ�ȴ����֡����Ѿ��������ֵ��ڲ����㲻��С����������
˵���Ǻ��������ȴ���������·�ġ�����ϸ���˿������������һ������
LONG);
       set("exits", ([
               "northeast" : __DIR__"shulin3",
                  ]));
       set("item_desc",([
		   "hole":"����һ����,���ƺ��������ȥ\n",
	   ]));
       setup(); 
      
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{   
    object me;
	me=this_player();
	if(!arg||arg!="��") return notify_fail("��Ҫ��ʲô?\n");
    message_vision("$N���˿�,Ȼ�󳯶�����ȥ\n",me);
	me->move(__DIR__"caodi2");
	return 1;
}
