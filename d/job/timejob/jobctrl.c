
inherit F_CLEAN_UP;
inherit F_DBASE;

#include <ansi.h>
#include <job_money.h>

#define TOTAL_TASK 25

string *dirs=({
"/d/huashan","/d/hengshan","/d/emeishan","/d/dabashan",
"/d/wuyishan","/d/taishan","/d/changan","/d/tuyuhun",
"/d/gaoli","/d/xiangyang"
});

string *maps;

mapping *jobs;

nosave int busy_time=0;
nosave int tasks=0;

int start_job();

void create()
{
  set("name","���������������");
  set("id","jobctrl.c");
  seteuid(getuid());

}

void control_job()
{

   remove_call_out("reset_job");
   call_out("reset_job",30);
   return;
}

void reset_job()
{

  if(!start_job())
  return;
  call_out("reset_job",30);
  return;
}

void set_job()
{
  int i,j,k,count;
  object where;
  mapping job;
  string map;


  for(j=0;j<TOTAL_TASK;j++){

 for(count=0;count<20;count++){
  map=get_random_place(dirs);

  if(!maps) maps=({map});
  else{

  if(member_array(map,maps)!=-1)
   continue;
  maps +=({map});

  }
    where=load_object(map);
    if(!where) continue;
    break;
  }

    job=allocate_mapping(4);
   i=random(sizeof(maps));
    job["local"]=map;
    job["name"]=MISC_D->find_place(where);
    job["over"]=0;
    if(!sizeof(jobs)) jobs=({job});
    else jobs=jobs+({job});
   }
    maps=0;
    busy_time=time();
    return;
}

int start_job()
{
  object where;

  if(time()-busy_time<0){
  busy_time=time();
  }
  if(time()-busy_time<3600)
  return 0;
  jobs=0;;
  tasks=0;;
  set_job();
  message("vision",HIG"\n\n���������ء�������:��˵������������˺ܶ౦�������ұ���ģ���\n"+
                   "���ݵĹص������������ҵ�����󽻸���������(lingshang)!\n\n"NOR,users());

  control_job();

  return 1;
}

string do_list()
{
  int i;string job_msg="";
  start_job();
  if(sizeof(jobs)==0)
  return "error";
  job_msg=YEL"��ǰ�������Ѱ������ص�:\n\n"NOR;
  for(i=0;i<sizeof(jobs);i++){
   job_msg +=jobs[i]["name"];
   if(jobs[i]["over"]==1)
    job_msg +=HIY" �����.\n"NOR;
   else job_msg +="\n";}

    return job_msg;
}

mapping *get_jobs()
{
   return jobs;
}

void add_tasks(int i)
{
  tasks +=i;
}

void set_jobs(mapping *job)
{
  jobs=job;
}
