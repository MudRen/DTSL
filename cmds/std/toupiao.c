//vote cmds.
//written by yanyan@dt. 2002/10/8.E-Mail:realyanyan@sohu.com
//Maybe some bugs,if you find,please fix it,and add
//a "change log" in this file.
/*
*
*the base vote data type:
*
*votes=({
* ([
*   "vote_name":"string",
*   "vote_type":([
*                   "type1":integer,
*                   ...
*               ]),
*   "create_time":time(),
* ]),
* 
*});
*
*vote_users=([
*     "player1_id":({ "vote_name>>vote_type>>create_time",.....}),*
*
*]);
*
* Every options can be logged. The log file at "/log/TOUPIAO_LOG"
*/



inherit F_CLEAN_UP;
inherit F_SAVE;

#include <ansi.h>

//#define NO_MSG "ֻ����ʦ���Խ������������"
#define LOG_FLAG 1  // if you don't need log file,please don't define LOG_FLAG
#define MIN_AGE  13 // the min age that can use this command.

mapping *votes=({ });

mapping vote_users=([ ]);


int help(object me);
int show_all_votes(object);
int clear_all_votes(object me);
int close_all_votes(object me);
int open_all_votes(object me);
int create_vote(object,string,string);
int clear_vote(object,string);
int add_vote(object me,string vote_name,string vote_type);
int del_vote(object me,string vote_name,string vote_type);
int do_vote(object me,int vote_name,int vote_type);
int close_vote(object me,string vote_name);
int open_vote(object me,string vote_name);

string query_save_file()
{
   return "/data/toupiao";
   
}

void create()
{
   restore();
   
}

int main(object me,string arg)
{
   string type,vote_name,vote_type,msg;
   int num;
   int vote_name_num,vote_type_num;
      
   if(!arg||arg=="all")
    return show_all_votes(me);
   
   if(me->query("age")<MIN_AGE)
   	return notify_fail("ֻ������ﵽ"+HIG+chinese_number(MIN_AGE)+"��"+NOR+"���ſ��Խ���ͶƱ��\n");   
   
   if(arg=="clearall")
    return clear_all_votes(me);
   
   if(arg=="closeall")
    return close_all_votes(me);
   
   if(arg=="openall")
    return open_all_votes(me);
   
   if(sscanf(arg,"%s %s %s",type,vote_name,msg)==3
     &&type=="create")  	
     return create_vote(me,vote_name,msg);   
   
   if(sscanf(arg,"%s %s",type,vote_name)==2
     &&type=="clear")
     return clear_vote(me,vote_name);
   
   if(sscanf(arg,"%s %s",type,vote_name)==2
     &&type=="close")
     return close_vote(me,vote_name);
   
   if(sscanf(arg,"%s %s",type,vote_name)==2
     &&type=="open")
     return open_vote(me,vote_name);
   
   if(sscanf(arg,"%s %s %s",type,vote_name,vote_type)==3
     &&type=="add")
     return add_vote(me,vote_name,vote_type);
   
   if(sscanf(arg,"%s %s %s",type,vote_name,vote_type)==3
     &&type=="del")
     return del_vote(me,vote_name,vote_type);   
   
   if(sscanf(arg,"%d %d",vote_name_num,vote_type_num)==2)   
     return do_vote(me,vote_name_num,vote_type_num);
     
   return help(me);
}

void do_log(object me,string msg)
{
  
#ifdef LOG_FLAG
  log_file("TOUPIAO_LOG",me->name()+"("+me->query("id")+")  "+msg+"  Time: "+ctime(time())+"\n");
#endif
  
}

int existvote(string vote_name)
{
   int i;
   
   if(sizeof(votes)==0)
    return -1;
   
   for(i=0;i<sizeof(votes);i++)
    if(votes[i]["vote_name"]==vote_name)
     return i;
   
   return -1;
   
}

int exist_votetype(string vote_name,string vote_type)
{
   int i,j;
   string *types;
   
   if(sizeof(votes)==0)
    return -1;
   
   for(i=0;i<sizeof(votes);i++)
    if(votes[i]["vote_name"]==vote_name){
     types=keys( votes[i]["vote_type"] );
     for(j=0;j<sizeof(types);j++)
     	if(types[j]==vote_type)
     	 return j;
    }
   
   return -1;
   
}

int is_valid(object me)
{
#ifdef NO_MSG  
  if(!wizardp(me))
    return notify_fail("\n"+NO_MSG+"\n");
#else
   if(!wizardp(me))
    return 0;  
#endif 
  
  return 1;
}

int valid_vote(string id,string vote_name,string vote_type,int create_time)
{
   string *vote_types;
   
   if(!vote_users[id]){
   	 vote_users+=([ id:({ vote_name+">>"+vote_type+">>"+create_time }) ]);
   	 return 1;
   }
   vote_types=vote_users[id];
   
   if(member_array(vote_name+">>"+vote_type+">>"+create_time,vote_types)==-1){
     vote_types+=({ vote_name+">>"+vote_type+">>"+create_time });
     vote_users[id]=vote_types;
     return 1;
   }
   
   return 0;
   
}

int create_vote(object me,string vote_name,string msg)
{
   mapping new_vote=(["vote_name":"string",
                     "vote_type":([]),
                     "create_time":time(),
                     "close_flag":0,
                     "msg":msg,
                    ]);
   
   if(!is_valid(me))
    return is_valid(me);
   
   if(existvote(vote_name)!=-1)
    return notify_fail("�Ѿ��������ͶƱ��Ŀ�ˡ�\n");
   
   new_vote["vote_name"]=vote_name;
   new_vote["vote_type"]=([ ]);
   
   votes=votes+({ new_vote });
   
   tell_object(me,HIG"\n�����µ�ͶƱ��Ŀ "+HIY+vote_name+HIG+"�ɹ���\n"NOR);
   
   save();
   
   do_log(me,"create new vote:"+vote_name+".");
   
   return 1;
   
}

int clear_vote(object me,string vote_name)
{
   int i;
   
   if(!is_valid(me))
    return is_valid(me);
   
   i=existvote(vote_name);
   if(i==-1)
    return notify_fail("Ŀǰ��û�����ͶƱ��Ŀ��\n");
   
   votes=votes-({ votes[i] });
      
   tell_object(me,HIR"\nɾ��ͶƱ��Ŀ "+HIY+vote_name+HIR+"�ɹ���\n"NOR);
   
   save();
   
   do_log(me,"clear one vote:"+vote_name+".");
   
   return 1;
   
}

int add_vote(object me,string vote_name,string vote_type)
{
    int i;
        
    if(!is_valid(me))
    return is_valid(me);
   
   i=existvote(vote_name);
   if(i==-1)
    return notify_fail(HIG"���ȴ���"+HIY+vote_name+HIG+"���ͶƱ��Ŀ��\n"NOR);
   
   if(exist_votetype(vote_name,vote_type)!=-1)
    return notify_fail(HIY+vote_name+HIG+"ͶƱ���Ѿ�����"+HIM+vote_type+HIG+"������͡�\n"NOR);
   
   votes[i]["vote_type"]+=([ vote_type:0 ]);
   
   tell_object(me,HIG"��"HIY+vote_name+HIG+"ͶƱ��Ŀ������"+HIM+vote_type+HIG+"ͶƱ���ͳɹ���\n"NOR);
   
   save();
   
   do_log(me,"add a vote type ��"+vote_type+"�� into "+vote_name+".");
   
   return 1;
   
}

int del_vote(object me,string vote_name,string vote_type)
{
    int i;
    mapping new_vote;
        
    if(!is_valid(me))
    return is_valid(me);
   
   i=existvote(vote_name);
   if(i==-1)
    return notify_fail(HIG"���ȴ���"+HIY+vote_name+HIG+"���ͶƱ��Ŀ��\n"NOR);
   
   if(exist_votetype(vote_name,vote_type)==-1)
    return notify_fail(HIG+HIY+vote_name+HIG+"ͶƱ��û��"+HIM+vote_type+HIG+"������͡�\n"NOR);
   
   map_delete(votes[i]["vote_type"],vote_type);
   
   tell_object(me,HIG"��"HIY+vote_name+HIG+"ͶƱ��Ŀ��ɾ��"+HIM+vote_type+HIG+"ͶƱ���ͳɹ���\n"NOR);
   
   save();
   
   do_log(me,"delete a vote type��"+vote_type+"��from "+vote_name+".");
   
   return 1;
   
}

int do_vote(object me,int vote_name,int vote_type)
{
     int i;
     string *vote_types;
     
     i=vote_name-1;
     
     if(vote_name>sizeof(votes))
     	return notify_fail("Ŀǰû�����ͶƱ��Ŀ��\n");
     
     if(votes[i]["close_flag"]==1)
     	return notify_fail("�Բ���Ŀǰ"+votes[i]["vote_name"]+"��ֹͶƱ��\n");
     
     vote_types=keys(votes[i]["vote_type"]);
     if(vote_type>sizeof(vote_types))
     	return notify_fail("��׼����ͶƱ��Ŀ��û�����ͶƱ���͡�\n");
     
     if(!valid_vote(me->query("id"),votes[i]["vote_name"],vote_types[vote_type-1],votes[i]["create_time"]))
      return notify_fail(HIR"�㲻��������һ����Ŀ��һ������ͶƱ��\n"NOR);
     
     votes[i]["vote_type"][vote_types[vote_type-1]]++;          
     
     tell_object(me,HIG"��Ͷ��"+HIY+votes[i]["vote_name"]+HIG+"�е�"+HIM+vote_types[vote_type-1]+HIG+"�����һƱ��\n"NOR);
     
     save();
     
     do_log(me,"vote ,vote name:"+votes[i]["vote_name"]+", vote type:"+vote_types[vote_type-1]+".");
     
     return 1;
     
}
     

int show_all_votes(object me)
{
   string msg;
   string m_msg;
   string *vote_types;
   int j,k=0;
   int i;
   
   if(sizeof(votes)==0)
    return notify_fail("Ŀǰû�н����κ�ͶƱ��Ŀ��\n");
   
   i=sizeof(votes);
   msg=HIG"\nĿǰ���е�ͶƱ��Ŀ�У�\n\n"NOR;
   for(i=0;i<sizeof(votes);i++){
   	k=0;
   	if(votes[i]["close_flag"]!=1)
   	msg+=sprintf(HIG"����Ŀ��š�"+(i+1)+"��\n��Ŀ���ƣ�%-20s\n"NOR,votes[i]["vote_name"]);
   	else
   	msg+=sprintf(HIR"������"HIG"��Ŀ��š�"+(i+1)+"��\n��Ŀ���ƣ�%-20s\n"NOR,votes[i]["vote_name"]);
   	
   	vote_types=keys(votes[i]["vote_type"]);
   	
   	for(j=0;j<sizeof(vote_types);j++)
   	 msg+=sprintf(HIY+"%10s%3d%2s"+HIM+"%-60s"+HIG+" %5dƱ\n"NOR,"��",(j+1),"��",vote_types[j],votes[i]["vote_type"][vote_types[j]]);
   	   
   	msg+="��Ŀ˵����\n";
   	m_msg=votes[i]["msg"];
   	for(j=0;j<sizeof(m_msg);j+=1){
   	 msg+=sprintf("%c",m_msg[j]);
   	 k++;
   	 if(k==40){
   	 	msg+="\n";
   	 	k=0;
   	 }
   	 
   	}
   	msg+="\n\n";
   }
   
   me->start_more(msg);
   
   return 1;
   
}

int clear_all_votes(object me)
{
   if(!is_valid(me))
    return is_valid(me);
    
   votes=({ });
   vote_users=([ ]);
   
   tell_object(me,HIR"ɾ��ȫ��ͶƱ��Ŀ�ɹ�!\n"NOR);
   
   save();
   
   do_log(me,"clear all votes");
   
   return 1;
   
}

int close_vote(object me,string vote_name)
{
	int i;
	
	if(!is_valid(me))
    return is_valid(me);
    
    i=existvote(vote_name);
    if(i==-1)
     return notify_fail(HIG"���ȴ���"+HIY+vote_name+HIG+"���ͶƱ��Ŀ��\n"NOR);
    
    votes[i]["close_flag"]=1;
    save();
    tell_object(me,"�㶳����"+votes[i]["vote_name"]+"ͶƱ��Ŀ��\n");
    
    do_log(me,"close vote,vote_name="+votes[i]["vote_name"]);
    
    return 1;
    
}

int open_vote(object me,string vote_name)
{
	int i;
	
	if(!is_valid(me))
    return is_valid(me);
    
    i=existvote(vote_name);
    if(i==-1)
     return notify_fail(HIG"���ȴ���"+HIY+vote_name+HIG+"���ͶƱ��Ŀ��\n"NOR);
    
    votes[i]["close_flag"]=0;
    save();
    tell_object(me,"�㿪����"+votes[i]["vote_name"]+"ͶƱ��Ŀ��\n");
    
    do_log(me,"open vote,vote_name="+votes[i]["vote_name"]);
    
    return 1;
    
}

int close_all_votes(object me)
{
	int i;
	
	if(!is_valid(me))
    return is_valid(me);
    
    for(i=0;i<sizeof(votes);i++)
     votes[i]["close_flag"]=1;
    
    save();
    do_log(me,"close all vote");
    tell_object(me,"�㶳�������е�ͶƱ��Ŀ��\n");
    
    return 1;
    
}

int open_all_votes(object me)
{
	int i;
	
	if(!is_valid(me))
    return is_valid(me);
    
    for(i=0;i<sizeof(votes);i++)
     votes[i]["close_flag"]=0;
    
    save();
    do_log(me,"open all vote");
    tell_object(me,"�㿪�������е�ͶƱ��Ŀ��\n");
    
    return 1;
    
}

// this function is used for test.
//you can use 'call' use it.
mapping *query_all_votes()
{
   return votes;
   
}

// this function is used for test.
//you can use 'call' use it.
mapping query_vote_users()
{
   return vote_users;
   
}

int help(object me)
{
    
if(!wizardp(me))
write(@HELP

ָ���ʽ��toupiao all|toupiao
          toupiao ��Ŀ���� ͶƱ��Ŀ

ͨ�����ָ������Խ��ж�ĳһ��ͶƱ��Ŀ����ͶƱ��
toupiao all�����Բ鿴Ŀǰ���е�ͶƱ��Ŀ��
�磺
��һ��toupiao all|toupiao

Ŀǰ���е�ͶƱ��Ŀ�У�

����Ŀ��š�1��
��Ŀ���ƣ�������kill����ʦ��  
��Ŀ������
˵��������ɱ����ʦ���Ǻ�
                ��1��subzero             100Ʊ
                ��2��rzy                 100Ʊ

������toupiao ��Ŀ��� ͶƱ��Ŀ
��ĳһ��ͶƱ��Ŀ����ͶƱ��
�磺
toupiao 1 1

ͶƱ����
����ÿһ��ͶƱ��Ŀ����ֻ�ܶ�����һ��ͶƱ����ͶһƱ��
�磺���� ��������kill����ʦ�ǡ� ���ͶƱ��Ŀ��������е���Ŀ
��rzy��ֻ��ͶһƱ���ԡ�subzero��Ҳֻ��ͶһƱ��
�����ͶƱ��Ŀ����ʦ�������������¼���Ͷ����Ŀ��Ʊ��
���⣬Ϊ�˷�ֹ����ͶƱ���涨ֻ������ﵽʮ����ʱ�ſ���ͶƱ��

ע�⣺
ֻ����ʦ�ſ��Դ����µ�ͶƱ��Ŀ��
HELP);
else
write(@HELP

ָ���ʽ��toupiao all|toupiao
          toupiao ��Ŀ���� ͶƱ��Ŀ

ͨ�����ָ������Խ��ж�ĳһ��ͶƱ��Ŀ����ͶƱ��
toupiao all�����Բ鿴Ŀǰ���е�ͶƱ��Ŀ��
�磺
��һ��toupiao all|toupiao

Ŀǰ���е�ͶƱ��Ŀ�У�

����Ŀ��š�1��
��Ŀ���ƣ�������kill����ʦ��  
��Ŀ������
˵��������ɱ����ʦ���Ǻ�
                ��1��subzero             100Ʊ
                ��2��rzy                 100Ʊ

������toupiao ��Ŀ��� ͶƱ��Ŀ
��ĳһ��ͶƱ��Ŀ����ͶƱ��
�磺
toupiao 1 1

ͶƱ����
����ÿһ��ͶƱ��Ŀ����ֻ�ܶ�����һ��ͶƱ����ͶһƱ��
�磺���� ��������kill����ʦ�ǡ� ���ͶƱ��Ŀ��������е���Ŀ
��rzy��ֻ��ͶһƱ���ԡ�subzero��Ҳֻ��ͶһƱ��
�����ͶƱ��Ŀ����ʦ�������������¼���Ͷ����Ŀ��Ʊ��
���⣬Ϊ�˷�ֹ����ͶƱ���涨ֻ������ﵽʮ����ʱ�ſ���ͶƱ��

ע�⣺
ֻ����ʦ�ſ��Դ����µ�ͶƱ��Ŀ��

��������ʦ�ſ��Կ����İ�����
1)toupiao create ͶƱ��Ŀ �����������µ�ͶƱ��Ŀ��
�磺toupiao create ������kill����ʦ�� ���ѡһ����һ�����֡�
��������Ǻ��֣�������ȫ�ǡ���ʾʱÿ����ʾ 40 �С�

2)toupiao add ͶƱ��Ŀ ͶƱ���ͣ����Ѿ����ڵ�ͶƱ��Ŀ����ӽ�
��ͶƱ�����͡�
�磺
toupiao add ������kill����ʦ�� subzero
toupiao add ������kill����ʦ�� rzy

3)toupiao del ͶƱ��Ŀ ͶƱ���ͣ����Ѿ����ڵ�ͶƱ��Ŀ��ɾ����
��ͶƱ�����͡�
�磺
toupiao del ������kill����ʦ�� subzero
toupiao del ������kill����ʦ�� rzy

4)toupiao clear ͶƱ��Ŀ��ɾ���Ѿ����ڵ�ͶƱ��Ŀ��
�磺
toupiao clear ������kill����ʦ��

5)toupiao clearall��ɾ��ȫ����ͶƱ��Ŀ��
�磺
toupiao clearall

6)toupiao close ͶƱ��Ŀ���ر�ĳһ��ͶƱ��Ŀ

7)toupiao closeall:�ر�ȫ��ͶƱ��Ŀ

8)toupiao open ͶƱ��Ŀ����ĳһ��ͶƱ��Ŀ

9)toupiao openall:��ȫ��ͶƱ��Ŀ

ͶƱ�ļ�¼�ļ��� /log/TOUPIAO_LOG

HELP);
    return 1;
}
