//����̨watchroom.c
inherit ROOM;
void create()
{
set("short","����̨");
set("long",@LONG
������Ϲ���̨��˳��������ȥ�����̱�̨���������塣ʿ����ʿ��
��磬һ��һ�ˣ��а����ۣ�ɱ�����춯�ء�����̨����һ�ˣ��������ǻ�
ͤ�ؽ���������䵱��ȫ��̫��ˮ�����������������������˹���̨��ü
ͷһ�壬�������㣬�۹��������ƺ�Ҫ��������ġ�
LONG);
set("exits",([
"down":__DIR__"showroom",
]));
set("objects",([
__DIR__"npc/zhangtian":1,
__DIR__"npc/wujiang":1,
]));
setup();
}
