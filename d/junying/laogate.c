//�η�����laogate.c
inherit ROOM;
void create()
{
set("short","�η�����");
set("long",@LONG
һ�ȳ��صĴ��Ż�Ȼ����������ǰ��������ǹ�Ѻ���˵��η����ڡ���
�����������أ�������ǽ�ϣ�����������λεĸֵ�������һ�����������
��ֱ�����ӣ��������㡣����(men)�������ǳ���ʵ�������(break)������
�����ס�
LONG);
set("exits",([
"east":__DIR__"showroom",
]));
set("objects",([
__DIR__"npc/kanshou":2,
]));
setup();
}
void init()
{
add_action("do_break","break");
}
int do_break(string arg)
{
object me;
me=this_player();
if(!arg||arg=="") return 0;
if(arg!="men")
return notify_fail("������ʲô��\n");
if(present("kan shou",this_object()))
{
write("��հڳ����ƣ�ֻ�����ش��һ�����������ʲô����\n");
message_vision("$N��������ţ�����������ֹ�ˡ�\n",me);
return 1;
}
else
{
write("����һ�����������ȥһ�ơ�\n");
message_vision("$N�����˴��š�\n",me);
set("exits/south", __DIR__"laofang");
return 1;
}
}
