#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "ĳ�գ�rzy �ڼ���������ȥ��",
        "��������˭�߸����Ų��ܾ��������Ŀ�أ�������",
        "���������ˡ�",
        "������¥��rzy ���ڴ��� fhq�� ",
        "rzy ����������������ӣ�ֻҪ����ʾ�ˣ��Ͱ����ҵĴ�æ������",
        "fhq������˵��˵���ȣ��ȣ��� ",
        "�ƹ���Ѳ�����˹���ζ���� ",
        "rzy��������������������ӡ�����",
        "fhq���������ʣ�����ǩ����ǩ����û���⡣��",
        "˵��fhq�ӹ��������ɷ���ǩ���������֡�",
        "rzy��ϲ���û�����һ���������������֡������þơ���",
        "��ž����һ����rzy ���۾����ڵ��ϵ����ˡ�",
        
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
        STORY_D->give_gift("/clone/quest/jingpian.c", 1,
                           HIM "\n��ž����һ��һ����Ƭ��������ǰ��\n\n" NOR);
        return HIM "һ�����صľ�Ƭ�ڽ��������ˡ�\n" NOR;
}
