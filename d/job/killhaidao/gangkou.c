#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ۿ�");
        set("long", @LONG
�����Ǹ����ĸۿڣ�����ǳ����֣�ͣ���Ÿ��ִ�ֻ���л�
�����̴��ȵȡ��ܶ��ÿʹ���������ۿڣ��д���ԭ���ģ�Ҳ��
�������ط����ġ����С�������������
LONG
);
        set("exits",([
	"west" : "/d/gaoli/gangkou",
        ]));
        set("objects",([
          __DIR__"han":1,
          ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
