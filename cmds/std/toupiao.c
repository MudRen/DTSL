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

//#define NO_MSG "只有巫师可以进行这个操作！"
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
   	return notify_fail("只有年龄达到"+HIG+chinese_number(MIN_AGE)+"岁"+NOR+"，才可以进行投票。\n");   
   
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
    return notify_fail("已经存在这个投票项目了。\n");
   
   new_vote["vote_name"]=vote_name;
   new_vote["vote_type"]=([ ]);
   
   votes=votes+({ new_vote });
   
   tell_object(me,HIG"\n创建新的投票项目 "+HIY+vote_name+HIG+"成功！\n"NOR);
   
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
    return notify_fail("目前还没有这个投票项目。\n");
   
   votes=votes-({ votes[i] });
      
   tell_object(me,HIR"\n删除投票项目 "+HIY+vote_name+HIR+"成功！\n"NOR);
   
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
    return notify_fail(HIG"请先创建"+HIY+vote_name+HIG+"这个投票项目。\n"NOR);
   
   if(exist_votetype(vote_name,vote_type)!=-1)
    return notify_fail(HIY+vote_name+HIG+"投票中已经有了"+HIM+vote_type+HIG+"这个类型。\n"NOR);
   
   votes[i]["vote_type"]+=([ vote_type:0 ]);
   
   tell_object(me,HIG"在"HIY+vote_name+HIG+"投票项目中增加"+HIM+vote_type+HIG+"投票类型成功！\n"NOR);
   
   save();
   
   do_log(me,"add a vote type “"+vote_type+"” into "+vote_name+".");
   
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
    return notify_fail(HIG"请先创建"+HIY+vote_name+HIG+"这个投票项目。\n"NOR);
   
   if(exist_votetype(vote_name,vote_type)==-1)
    return notify_fail(HIG+HIY+vote_name+HIG+"投票中没有"+HIM+vote_type+HIG+"这个类型。\n"NOR);
   
   map_delete(votes[i]["vote_type"],vote_type);
   
   tell_object(me,HIG"在"HIY+vote_name+HIG+"投票项目中删除"+HIM+vote_type+HIG+"投票类型成功！\n"NOR);
   
   save();
   
   do_log(me,"delete a vote type“"+vote_type+"”from "+vote_name+".");
   
   return 1;
   
}

int do_vote(object me,int vote_name,int vote_type)
{
     int i;
     string *vote_types;
     
     i=vote_name-1;
     
     if(vote_name>sizeof(votes))
     	return notify_fail("目前没有这个投票项目！\n");
     
     if(votes[i]["close_flag"]==1)
     	return notify_fail("对不起，目前"+votes[i]["vote_name"]+"禁止投票！\n");
     
     vote_types=keys(votes[i]["vote_type"]);
     if(vote_type>sizeof(vote_types))
     	return notify_fail("你准备的投票项目中没有这个投票类型。\n");
     
     if(!valid_vote(me->query("id"),votes[i]["vote_name"],vote_types[vote_type-1],votes[i]["create_time"]))
      return notify_fail(HIR"你不能连续对一个项目的一个类型投票！\n"NOR);
     
     votes[i]["vote_type"][vote_types[vote_type-1]]++;          
     
     tell_object(me,HIG"你投了"+HIY+votes[i]["vote_name"]+HIG+"中的"+HIM+vote_types[vote_type-1]+HIG+"宝贵的一票！\n"NOR);
     
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
    return notify_fail("目前没有进行任何投票项目。\n");
   
   i=sizeof(votes);
   msg=HIG"\n目前进行的投票项目有：\n\n"NOR;
   for(i=0;i<sizeof(votes);i++){
   	k=0;
   	if(votes[i]["close_flag"]!=1)
   	msg+=sprintf(HIG"◆项目编号【"+(i+1)+"】\n项目名称：%-20s\n"NOR,votes[i]["vote_name"]);
   	else
   	msg+=sprintf(HIR"【禁】"HIG"项目编号【"+(i+1)+"】\n项目名称：%-20s\n"NOR,votes[i]["vote_name"]);
   	
   	vote_types=keys(votes[i]["vote_type"]);
   	
   	for(j=0;j<sizeof(vote_types);j++)
   	 msg+=sprintf(HIY+"%10s%3d%2s"+HIM+"%-60s"+HIG+" %5d票\n"NOR,"〖",(j+1),"〗",vote_types[j],votes[i]["vote_type"][vote_types[j]]);
   	   
   	msg+="项目说明：\n";
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
   
   tell_object(me,HIR"删除全部投票项目成功!\n"NOR);
   
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
     return notify_fail(HIG"请先创建"+HIY+vote_name+HIG+"这个投票项目。\n"NOR);
    
    votes[i]["close_flag"]=1;
    save();
    tell_object(me,"你冻结了"+votes[i]["vote_name"]+"投票项目！\n");
    
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
     return notify_fail(HIG"请先创建"+HIY+vote_name+HIG+"这个投票项目。\n"NOR);
    
    votes[i]["close_flag"]=0;
    save();
    tell_object(me,"你开启了"+votes[i]["vote_name"]+"投票项目！\n");
    
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
    tell_object(me,"你冻结了所有的投票项目！\n");
    
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
    tell_object(me,"你开启了所有的投票项目！\n");
    
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

指令格式：toupiao all|toupiao
          toupiao 项目名称 投票项目

通过这个指令你可以进行对某一个投票项目进行投票。
toupiao all：可以查看目前所有的投票项目。
如：
（一）toupiao all|toupiao

目前进行的投票项目有：

◆项目编号【1】
项目名称：你最想kill的巫师是  
项目描述：
说出你最想杀的巫师，呵呵
                〖1〗subzero             100票
                〖2〗rzy                 100票

（二）toupiao 项目编号 投票项目
对某一个投票项目进行投票。
如：
toupiao 1 1

投票规则：
对于每一个投票项目，你只能对其中一个投票类型投一票。
如：对于 “你最想kill的巫师是” 这个投票项目，你对其中的项目
“rzy”只能投一票，对“subzero”也只能投一票。
如果此投票项目被巫师清除，则可以重新继续投此项目的票。
另外，为了防止胡乱投票，规定只有年龄达到十三岁时才可以投票。

注意：
只有巫师才可以创建新的投票项目。
HELP);
else
write(@HELP

指令格式：toupiao all|toupiao
          toupiao 项目名称 投票项目

通过这个指令你可以进行对某一个投票项目进行投票。
toupiao all：可以查看目前所有的投票项目。
如：
（一）toupiao all|toupiao

目前进行的投票项目有：

◆项目编号【1】
项目名称：你最想kill的巫师是  
项目描述：
说出你最想杀的巫师，呵呵
                〖1〗subzero             100票
                〖2〗rzy                 100票

（二）toupiao 项目编号 投票项目
对某一个投票项目进行投票。
如：
toupiao 1 1

投票规则：
对于每一个投票项目，你只能对其中一个投票类型投一票。
如：对于 “你最想kill的巫师是” 这个投票项目，你对其中的项目
“rzy”只能投一票，对“subzero”也只能投一票。
如果此投票项目被巫师清除，则可以重新继续投此项目的票。
另外，为了防止胡乱投票，规定只有年龄达到十三岁时才可以投票。

注意：
只有巫师才可以创建新的投票项目。

以下是巫师才可以看到的帮助：
1)toupiao create 投票项目 描述：创建新的投票项目。
如：toupiao create 你最想kill的巫师是 大家选一个，一起娱乐。
描述如果是汉字，必须是全角。显示时每行显示 40 列。

2)toupiao add 投票项目 投票类型：在已经存在的投票项目中添加进
行投票的类型。
如：
toupiao add 你最想kill的巫师是 subzero
toupiao add 你最想kill的巫师是 rzy

3)toupiao del 投票项目 投票类型：在已经存在的投票项目中删除进
行投票的类型。
如：
toupiao del 你最想kill的巫师是 subzero
toupiao del 你最想kill的巫师是 rzy

4)toupiao clear 投票项目：删除已经存在的投票项目。
如：
toupiao clear 你最想kill的巫师是

5)toupiao clearall：删除全部的投票项目。
如：
toupiao clearall

6)toupiao close 投票项目：关闭某一个投票项目

7)toupiao closeall:关闭全部投票项目

8)toupiao open 投票项目：打开某一个投票项目

9)toupiao openall:打开全部投票项目

投票的记录文件在 /log/TOUPIAO_LOG

HELP);
    return 1;
}
