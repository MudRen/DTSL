#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "yanyan������ʦ��ȥҰ�⽼�Ρ�",
        "����������̣�������֦��yanyan��������һ�����⣬�����ʵ���",
        "�����֪�����ʶ������𣿡�",
        "����֪������yanziһ�߻ش�һ�ߴӴӵ��ϼ���һƬ��Ҷ�������ȥ��",
        "����һƬ����������һ�ף��������Ǳ�Ʈ������֪�����𡣡�",
        "���ţ��ܺá���yanyan����������ǻ���˭Ը���ٸ����ʾ��һ�£��������ڹε���ʲô�磿��",
        "���ҡ���fhq�Ը�������˳����������һ�����ƽ��������ȥ����",
        "�����棬���ڹε������·磡�� ��������",
        
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
        STORY_D->give_gift("/clone/money/gold.c", 1,
                           HIM "\n�����һ��һ�����ƽ��������ǰ��\n\n" NOR);
        return HIM "һ�����ƽ��ڽ��������ˡ�\n" NOR;
}
