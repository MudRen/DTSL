#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "��˵ subzero �ò�֮��tott��valkyrieȥ���� subzero�� ",
        "��tott��subzero�������ʱ��valkyrie�������ģ�����������һ�뻨����",
        "valkyrie�Ĳ�������ë�����Ϳ�ʼ�Ի�����",
        "��tott��subzero�����subzero��ǡ�",
        "valkyrie��subzero˵����л��Ļ����� ",
        "subzero������лѽ����������ã���ֻ�ܰ�������ɿ����������Ļ�����ҧ������",
        "valkyrie��...... ",
       
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
        STORY_D->give_gift("/clone/quest/huasheng.c", 1,
                           HIM "\n��ž����һ����һ���������������ǰ��\n\n" NOR);
        return HIM "һ�������ڽ��������ˡ�\n" NOR;
}
