//Cemote
//A very small bug let me expend very much time on it!
//Yanyan Fixed some small bugs.
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping emote;
        string *e;
    string result,msg;
    int i;int flag;
    flag=0;
    if( !arg )
        { 
                printf("���������ڹؼ��ֲ�ѯsemote  ���� cemote �Ϲ�\n");
        }
    else 
        {me->add("gin",-20);
         
                e = EMOTE_D->query_all_emote();
                if(sizeof(e)<=0)
                return notify_fail("����BUG[1]�ˣ���ȥ������ʦ����GOLD���ģ���\n");               
        
        result = "  ���    ����            ����\n" +
                                 "��������������������������������������������������������������������������\n";
            for(i=0;i<sizeof(e);i++)
            {
                        emote=EMOTE_D->query_emote(e[i]);
                        if(!mapp(emote)){                       
                         break;}
            msg="";
            if(stringp(emote["others_target"]))
            msg=msg+emote["others_target"];
            if(strsrch(msg, arg) >=0)
            { 
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
                        }
            msg="";
            msg=msg+emote["others_self"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
            }
            msg="";
            msg=msg+emote["others"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
            }
        }
        if(!flag) result +="û����������Ĺؼ�����ƥ���emote.";
                result += "\n��������������������������������������������������������������������������\n";
            me->start_more(result);
            return 1;
        }
    return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : cemote �ؼ���  �г�Ŀǰ���к�ָ���ؼ��ֵ�emote.

����:
        cemote ��ù
   ���    ����            ����
��������������������������������������������������������������������������
[  42] :(           : $N��ü������,һ����ù��

��������������������������������������������������������������������������

HELP
    );
    return 1;
}
