#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "�����书���ۿ��������٣�����ӣ�������wlq��lying�����ˡ�",
        "liying��������е�ڳԵ�Ŷ... ...",
        "�����У���Ϊ�࿼��Ա�Ŀڳ԰��������С�ĵ���Ѱ����",
        "ͻȻ�ط����и������ڿ�С����",
        "��������ָ�����׿���˵���㡭�㡭�㡭�㡭�㡭�㡭�㡭�㡭�㡭�������ף�������վ������",
        "��ϣ��Ÿ�����վ��������",
        "wlq����֮�°����׵�ֽ�Ŷ����˵��ϡ���",
        
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
        STORY_D->give_gift("/clone/quest/skillbook.c", 1,
                           HIM "\n�����һ��һ�����������ǰ��\n\n" NOR);
        return HIM "һ����ѧ�ؼ��ڽ��������ˡ�\n" NOR;
}
