#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "һ�գ�rzy ȥ�ƹݺȾƣ�����һ�������ͷ����������� ",
        "������˵������İ�Ǯ�����ˣ�",
        "���˻ش���ģ���ƭ�㡣",
        "���������Ǻã���ȥ���ſڶ��°ɡ� ",
        "�������͵��ſڶ���������˭֪������һ�žͰѿ������˳�ȥ��",
        "rzy ����������Ҫ��һ��XO������ȥ������������ι����Ҳû�д�Ǯ��",
       
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/quest/zuihan.c", 1,
                           HIM "\nһ����ҡҡ�λε����˹�����\n\n" NOR);
        return HIM "һ�����ڽ��������ˡ�\n" NOR;
}
