#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "�¶����䣬�����ǿա�ҹɫ��������",
        "Chris��Forever����������ҹɫ�У����¡�",
        "�������ǣ�����һ������... ... ...",
        "�����ϣ��и���Ů�˵ļһҲ�ڿ������ǡ�",
        "�������˭�ء�����Ȼ���Ǹ���а�Ůװ��Yanzi�ˣ�",
        "Yanzi����������͵���϶���ǹ���",
        "������Yanzi�������������ǹ��Ҷ���",
        "�����ҵ������¶����Rain��Rain���һ��ˡ�",
        
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
        STORY_D->give_gift("/clone/quest/tangguo.c", 1,
                           HIM "\n�����һ��һ���ǹ���������ǰ��\n\n" NOR);
        return HIM "һ�����ص��ǹ��ڽ��������ˡ�\n" NOR;
}
