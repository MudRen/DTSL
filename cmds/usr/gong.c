// gong.c

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	//str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}

int main(object me, string arg)
{
          object ob;
          string *offices;
          mapping job_office;
          int i;
          string msg;
          
          seteuid(getuid(me));
	  if(!arg) ob = me;
	  else if (wizardp(me))
	{
	   	ob = present(arg, environment(me));
        	if (!ob) ob = find_player(arg);
	        if (!ob) ob = find_living(arg);
        	if (!ob) return notify_fail("��Ҫ�쿴˭�Ĺ�����\n");
	}
	else return notify_fail("ֻ����ʦ�ܲ쿴���˵Ĺ�����\n");
      
                if(ob==me)
                write("\n�����ڵ��ܹ����� " +HIY+ (int)ob->query("office_number")+NOR
                        + "�㡣\n\n");
                else
                write("\n"+ob->name()+"���ڵ��ܹ����� " +HIY+ (int)ob->query("office_number")+NOR
                        + "�㡣\n\n");
                        
                job_office=ob->query("job_office_number");
                if(!mapp(job_office))
                return 1;
                offices=keys(job_office);
                msg="����ÿ������Ĺ���Ϊ��\n\n";
                for(i=0;i<sizeof(offices);i++){
                
                if(job_office[offices[i]]<0)
                 job_office[offices[i]]=0;
                msg +=left(offices[i],30);
                msg +=HIY+job_office[offices[i]]+NOR"��\n";
                
                }
                
                me->start_more(msg);
                return 1;
     
}

int help(object me)
{
        write(@HELP


���ָ������֪���㵱ǰ�Ĺ�����
HELP
        );
        return 1;
}

