//�η�laofang.c
#include <ansi.h>;
inherit ROOM;
void create()
{
set("short","�η�");
set("long",@LONG
�������η���������߻谵������ǽ�ڱ�������Ϊ��ʵ������ɢ����һ
Щ�õ��ݣ�ʪ�����ģ�ɢ����һ��������Ż�ĳ�ζ�������������ż�������
�����ӿ첻���ˣ��ű߰���һֻ���룬������Щù������ֻ˶�����޼ɵ���
�����ε���
LONG);
setup();
}
void init()
{
object me;
me=this_player();
remove_call_out("kickout");
call_out("kickout",30,me);
}
int kickout(object me)
{
message_vision(HIY"���ض�$N˵�����㲻�Ǽ�ϸ����������ˣ���\n"NOR,me);
me->move(__DIR__"showroom");
message_vision(HIY"$N��������У���ϡ�\n"NOR,me);
return 1;
}
