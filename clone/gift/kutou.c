#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "һ��fire�������������һ����ͣ���Ů���������������Ҳ����",
        "fire������˼������ͷ����������ֻ�Ǽ��˸���ͷ���ѡ���",
        "ǡ��lying��һ���߹���һ��������˵���������ͷҲҪ��������",
        "fire����ʦ��������ȥ���ߵ�¥�£�������fhq����������˵�������Ҽ���һ����ͷ��",
        "��¥������yanyan���ͷ��˵���ҵĿ�ͷ���������ҵĿ�ͷ������������",
       
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
        STORY_D->give_gift("/clone/quest/kutou.c", 1,
                           HIM "\n�����һ��һ����ͷ��������ǰ��\n\n" NOR);
        return HIM "һ����ͷ�ڽ��������ˡ�\n" NOR;
}
