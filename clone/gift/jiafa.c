#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "˵���ƿ�����֮��Ū�úܶ��˶���ˬ�����������밵ɱ��Щ��ʦ... ...",
        "lying ���˾��ر��£���æȥ������Ժ�������ݡ�",
        "������ʱ���Ѿ����һ��������Ů�ˣ�",
        "���ڽ��ϣ�����һ��Ҫ������̫̫... ...",
        "�͸�����100��Ǯ��������֪������˭��",
        "��̫̫���˿�����˵ lying��",
        "�������Ż��ˣ���æ��ȥ������Ժ���ڶ��γ������������Ǹ���̫̫��",
        "���ֹ�ȥ����ͬ�������⣬�����̫̫����Ҳû������˵lying��",
        "��ë�ˣ�����ô�ϳ��ҵģ���̫̫��æ˵���꣬С���㣬���� yanyan...",
        "һ���ٷ���lying��ͷ�Ϸ����ˣ���",
              
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
        STORY_D->give_gift("/clone/quest/jiafa.c", 1,
                           HIM "\n�����һ��һ���ٷ���������ǰ��\n\n" NOR);
        return HIM "һ���ٷ��ڽ��������ˡ�\n" NOR;
}
