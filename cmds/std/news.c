#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit F_DBASE;

string title=HIG"
    ����������������������������������������������������
    ��                                                ��
    ��                   ����˫������                 ��
    ��                                                ��
    ����������������������������������������������������
"+HIY+"    
    ����������������������������������������������������
\n\n"NOR;

int main(object me,string arg)
{
	 object board;string msg;
        
         board=load_object("/obj/board/news_b");
	 if(!board) 
	 return notify_fail("����ϵͳ�����뱨����ʦ��\n");
	 if(arg=="all"||arg=="new"){
	   msg=board->do_list_news(me,arg);
	   msg=title+msg;
           me->start_more(msg);
           return 1;
         }
         if(arg){
	   return board->do_read_news(arg);
	 }
        else{
         msg=board->tell_news(me);
         msg=title+msg;
        tell_object(me,"\n"+msg+"\n\n"+" ��ʹ��news ���� �� news next ���Ķ����š�\n\n");}
        return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : news all/����
���ָ����������Ķ������з��������š�
ʹ��news all ���Կ������е����š�
ʹ��news new ���Կ����·���������
ʹ��news next �Ķ���һ������
ʹ��news ���� �����Ķ���������š�
HELP
        );
        return 1;
}