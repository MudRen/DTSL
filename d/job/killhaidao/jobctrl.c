
inherit F_CLEAN_UP;
inherit F_DBASE;
#include <job_money.h>
#define OUT "/d/job/killhaidao/out/"
#define LEV1 "/d/job/killhaidao/lev1/"
#define LEV2 "/d/job/killhaidao/lev2/"
#define LEV3 "/d/job/killhaidao/lev3/"

string *where=({OUT+"out_0_4",
OUT+"out_2_4",OUT+"out_4_4",OUT+"out_6_0",OUT+"out_6_10",
OUT+"out_6_2",OUT+"out_6_4",OUT+"out_6_6",OUT+"out_6_8",
LEV1+"ship_0_0",LEV1+"ship_0_2",LEV1+"ship_0_4",LEV1+"ship_0_6",
LEV1+"ship_0_8",LEV1+"ship_2_0",LEV1+"ship_2_2",LEV1+"ship_2_4",
LEV1+"ship_2_6",LEV1+"ship_2_8",LEV1+"ship_4_2",LEV1+"ship_4_6",
LEV1+"ship_4_8",
LEV2+"ship_0_0",LEV2+"ship_0_2",LEV2+"ship_0_4",LEV2+"ship_0_6",
LEV2+"ship_0_8",LEV2+"ship_2_0",LEV2+"ship_2_2",LEV2+"ship_2_4",
LEV2+"ship_2_6",LEV2+"ship_2_8",LEV2+"ship_4_0",LEV2+"ship_4_2",
LEV2+"ship_4_8",
LEV3+"ship_0_0",LEV3+"ship_0_2",LEV3+"ship_0_4",LEV3+"ship_0_6",
LEV3+"ship_0_8",LEV3+"ship_2_0",LEV3+"ship_2_2",LEV3+"ship_2_4",
LEV3+"ship_2_6",LEV3+"ship_2_8",LEV3+"ship_4_0",LEV3+"ship_4_2",
LEV3+"ship_4_4",LEV3+"ship_4_8",

});

void start_job(object ob,int i)
{
	object killer,boss;
   	object boss2,boss3;
   	string room;
   	if(query("start_job"))
   		return;
   	while(i--){
     	room=where[random(sizeof(where))];
     	killer=new(__DIR__"killer");
     	killer->set_status(ob);
     	killer->move(room);
    }
  boss=new(__DIR__"boss");
  boss->set_status(ob);
  
  boss2=new(__DIR__"boss");
  boss3=new(__DIR__"boss");
  copy_object(boss2,boss);
  copy_object(boss3,boss);
  boss2->set_name("��",({"da fu","fu"}));
  boss2->set("long","�������Ҵ��Ĵ󸱡�\n");
  boss3->set_name("����",({"er fu","fu"}));
  boss3->set("long","�������Ҵ��Ķ�����\n");
  boss2->set("fu",1);
  boss3->set("fu",1);
  boss->move("/d/job/killhaidao/lev3/ship_2_8");
  boss2->move("/d/job/killhaidao/lev3/ship_2_8");
  boss3->move("/d/job/killhaidao/lev1/ship_2_8");
  set("start_job",1);
  call_out("haidao_job_clear",900);
  return;
}


void clear_job()
{
   object *ob,*target;
   string room;
   object here;
   int k,j;
   
   for(k=0;k<sizeof(where);k++){
   room=where[k];
   here=load_object(room);
     ob=all_inventory(here);
     for(j=0;j<sizeof(ob);j++){
       if(ob[j]->is_character()&&userp(ob[j])){
       	tell_object(ob[j],"\n\n�㿴��Զ��ʻ���˼���ս�����Ͻ��ܻ��˸ۿڣ�\n\n");
        ob[j]->move(__DIR__"gangkou");}
       else if(ob[j]->is_character()) destruct(ob[j]);}}
   delete("start_job");
   target=children(__DIR__"han");
   for(j=0;j<sizeof(children(__DIR__"han"));j++)
   target[j]->delete("have_job");
   return;
}

void haidao_job_clear()
{
  clear_job();
  return;
}

int clean_up()
{
  return 0;
}