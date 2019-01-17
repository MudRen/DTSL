inherit F_DBASE;

#define F_OWNERS 10
#define LEST_F_COUNTS 80
object *f_owner;
int start_fight_job=30;

string *wheres=({
"/d/yangzhou/guangchang","/d/jiujiang/center","/d/xiangyang/guangchang",
"/d/changan/guangchang","/d/gaoli/qinglong-1","/d/dingxiang/guangchang",
"/d/baling/center","/d/shanhaiguan/guangchang","/d/chengdu/center",
"d/hefei/center"});

void create()
{
  seteuid(getuid());

  set("name","������ϵͳ");
  set("channel_id","������ϵͳ");
  set("id","jobsys.c");
  
  start_fight_job=30;
  remove_call_out("check_fight_job");
  call_out("check_fight_job",10);
  
}

void check_fight_job()
{
   int i,j;
   start_fight_job++;
   if(start_fight_job<30){
   call_out("check_fight_job",60);
   return;
   }
      
   f_owner=children("/obj/npc/qixia");
   for(i=0,j=0;i<sizeof(f_owner);i++){
     if(objectp(f_owner[i])){
        message_vision("$N�Ҵ����ˣ�\n",f_owner[i]);
        destruct(f_owner[i]);
        j++;
     }
   }
   f_owner=children("/d/job/fightjob/xiyusengren");
   for(i=0;i<sizeof(f_owner);i++){
     if(objectp(f_owner[i])){
        message_vision("$N�Ҵ����ˣ�\n",f_owner[i]);
        destruct(f_owner[i]);
        j++;
     }
   }
   
   CHANNEL_D->do_channel(this_object(),"sys","Fight ����������ۻ�����"+j+"����\n");
   
   CHANNEL_D->do_channel(this_object(),"sys","Fight ����ʼ�����ۻ�����ص������ ...\n");
   
   remove_call_out("do_start_job");
   call_out("do_start_job",4);
   
}

void do_start_job()
{
   int counts,reduce,i,j;
   string *jobwheres,*oldwheres,where_msg;
   object target;
   
     
   counts=LEST_F_COUNTS;
   
   oldwheres=wheres;
   jobwheres=({});
   where_msg="";
   for(i=0;i<7;i++){
     j=random(sizeof(oldwheres));
     jobwheres=jobwheres+({oldwheres[j]});
     oldwheres=oldwheres-({oldwheres[j]});
   }
   jobwheres=jobwheres-({});
   
   for(i=0;i<7;i++){
     if(i==6)
     target=new("/obj/npc/qixia");
     else
     target=new("/d/job/fightjob/xiyusengren");
    if(i!=5&&i!=6){
     reduce=random(counts);
     if(reduce<counts/7) reduce=counts/7;
     if(reduce>counts/5) reduce=counts/6;
     counts -=reduce;
    }else
    if(i<6)
     reduce=counts;
    else
     reduce=0;
      target->set("fighter_counts",reduce);
     target->move(jobwheres[i]);
     if(i!=6)
     where_msg+=jobwheres[i]+"  ��������:"+reduce+"\n";
     else
     where_msg+=jobwheres[i]+"  Я���������������ڵ�:1\n";
     
   }
   CHANNEL_D->do_channel(this_object(),"sys","Fight �������ص�\n"+where_msg);
   start_fight_job=0;
   call_out("check_fight_job",60);
   return;
}