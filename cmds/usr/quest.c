// by Yanyan.

#include <ansi.h>
#define QUEST_DIR "/doc/quest/"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	
	if(!arg){
	 cat(QUEST_DIR+"topic");
	 return 1;}
	file=QUEST_DIR+arg;
	if(file_size(file)<=0)
	return notify_fail("û����������˵���ļ���\n");
	me->start_more(read_file(file));
        write("\n");
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quest
 
���ָ�������ʾ������˫��Ŀǰ���ŵ����⡣
HELP
        );
        return 1;
}
