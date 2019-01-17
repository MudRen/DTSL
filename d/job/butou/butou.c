
inherit NPC;

#include <ansi.h>
#include <job_money.h>

mapping map_here=([
 "/d/dabashan/shandong1":"���ɽ��","/d/dabashan/shandong2":"���ɽ��",
 "/d/dabashan/shandong3":"���ɽ��","/d/dabashan/shanpo":"���ɽ��",
 "/d/dabashan/shanfeng":"���ɽ��","/d/dabashan/shanya":"���ɽ��",
  "/d/dabashan/shanji1":"���ɽ��", "/d/dabashan/shanji2":"���ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong1":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong2":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong3":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong4":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong5":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong6":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong7":"����ɽ��",
  "/d/changbaishan/shanlu1":"����ɽ��",
  "/d/changbaishan/shanlu2":"����ɽ��",
  "/d/changbaishan/shanlu3":"����ɽ��",
  "/d/changbaishan/shanlu4":"����ɽ��",
  "/d/changbaishan/shanlu5":"����ɽ��",
  "/d/changbaishan/shulin1":"����ɽ��",
  "/d/changbaishan/shulin2":"����ɽ��",
  "/d/changbaishan/shulin3":"����ɽ��",
  "/d/changbaishan/shulin4":"����ɽ��",
  "/d/changbaishan/shanya":"����ɽ��",
  "/d/changbaishan/shanpo":"����ɽ��",
   "/d/hangzhou/dongan1":"��������","/d/hangzhou/dongan2":"��������",
  "/d/hangzhou/dongan3":"��������","/d/hangzhou/nanan1":"��������",
  "/d/hangzhou/nanan2":"��������","/d/hangzhou/xiaolu1":"��������",
  "/d/wuyishan/shanlu1":"����ɽ��","/d/wuyishan/shanlu2":"����ɽ��",
  "/d/wuyishan/shanlu3":"����ɽ��","/d/wuyishan/shanlu4":"����ɽ��",
  "/d/wuyishan/shanlu5":"����ɽ��","/d/wuyishan/shulin1":"����ɽ��",
  "/d/wuyishan/shulin2":"����ɽ��","/d/wuyishan/shulin3":"����ɽ��",
  "/d/wuyishan/shulin4":"����ɽ��","/d/wuyishan/xiaoxi1":"����ɽ��",
  "/d/wuyishan/xiaoxi2":"����ɽ��","/d/wuyishan/doupo3":"����ɽ��",
  "/d/huashan/putidong":"��ɽɽ��","/d/huashan/houshan":"��ɽɽ��",
  "/d/huashan/shanlu1":"��ɽɽ��","/d/huashan/shanlu2":"��ɽɽ��",
  "/d/huashan/shanlu3":"��ɽɽ��","/d/huashan/shanlu4":"��ɽɽ��",
  "/d/huashan/shanlu5":"��ɽɽ��","/d/huashan/shanlu6":"��ɽɽ��",
  "/d/huashan/xiaoxi":"��ɽɽ��","/d/huashan/shulin3":"��ɽɽ��",
  "/d/emeishan/liangting":"��üɽ��","/d/emeishan/shilin":"��üɽ��",
  "/d/emeishan/shulin":"��üɽ��","/d/emeishan/xiaojing1":"��üɽ��",
  "/d/emeishan/wu":"��üɽ��","/d/taiyuan/center":"̫ԭ����",
  "/d/hengshan/beiyuedian":"��ɽ��",
  "/d/hengshan/beiyuemiao":"��ɽ��","/d/hengshan/cuiping1":"��ɽ��",
  "/d/hengshan/cuiping2":"��ɽ��","/d/hengshan/cuipinggu1":"��ɽ��",
  "/d/hengshan/cuipinggu2":"��ɽ��","/d/hengshan/daziling":"��ɽ��",
  "/d/hengshan/guolaoling":"��ɽ��","/d/hengshan/sanjiaodian":"��ɽ��",
  "/d/hengshan/xuankong1":"��ɽ��","/d/hengshan/xuangengsong":"��ɽ��",
  "/d/hengshan/kutianjing":"��ɽ��","/d/hengshan/huixiantai":"��ɽ��",
  "/d/hengshan/hufengkou":"��ɽ��",
]);


string give_job();
int do_ok(string arg);

void create()
{
   set_name("��ͷ",({ "bu tou","bu","tou" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǳ����Ĳ�ͷ���������ǵ��ΰ���\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   set("inquiry",([
	   "����":(:give_job:),
	   ]));
   setup();
   
}

void init()
{
	add_action("do_ok","guian");
}

string give_job()
{
	object me,ob;object *t;int i;
	object paper;
	string *here;
	int j;
	string str;
	me=this_player();ob=this_object();
	//return "�Բ�������������޸��С�\n";
	t=me->query_team();
	if(sizeof(t)==0){
		return "����������Լ�����̫Σ���ˣ����Ǻͱ������һ�����ɣ�\n";}
	if(!me->is_team_leader())
		return "�㲻�Ƕ�������죬�����ǵ��������ɣ�\n";
        if(time()-me->query("busy_time")<160+random(60))
		return "���ûʲô���������һ���������ɣ�\n";
	if(sizeof(t)>2) 
	 return "��ô�򵥵�����Ҫ��ô���ˣ�����ɣ�\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return "��Ķ�Ա��û���룬�ȵȰɣ�\n";
	for(i=0;i<sizeof(t);i++)
	 if(t[i])
	  if(t[i]->query("combat_exp")<200000)
	   return t[i]->name()+"�ľ���̫�ͣ���̫Σ���ˣ�\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(me->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(me->query("combat_exp")-t[i]->query("combat_exp")>100000)
				  return "���ǵľ������̫�����Σ�գ�\n";}
		  else{ if(t[i]->query("combat_exp")-me->query("combat_exp")>100000)
			      return "���ǵľ������̫�����Σ�գ�\n";}
	if(me->query_temp("butou_job"))
		return "���Ǹ���������ȥ��������ô����ȥ��\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
	    t[i]->set_temp("butou_job",1);
	me->set_temp("butou_job",1);
	paper=new("/u/yanyan/paper");
	here=keys(map_here);
	j=random(sizeof(here));
	paper->set("where",here[j]);
	paper->move(me);
	tell_object(me,query("name")+"������һ��"+paper->query("name")+"��\n");
	return "�ðɣ�������������"+paper->query("name")+"ȥ"+map_here[here[j]]+"��ɱ������Ȼ����������ɣ�\n";
	
}

int do_ok(string arg)
{
	object me,ob,*t;int i;object money;
	int exp,pot,sil,famous;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ��˭�鰸��\n");
	if(!me->query_temp("butou_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",�⻰�Ӻ�˵��\n");
	if(!me->query_temp("butou_job_ok"))
        return notify_fail(""+RANK_D->query_respect(me)+",���ǵ�����С������ƭ�𣿣�\n");
	t=me->query_team();
	if(sizeof(t)==0)
		return notify_fail("��û����������ӣ��ҾͲ��������������ô��޵�����\n");
    for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return notify_fail("��Ķ�Ա��û���룬�ȵȰɣ�\n");
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(!t[i]->query_temp("butou_job"))
			  return notify_fail("���ǵĶ����л���������ˣ����������ߣ�����ν������ǣ�\n");
    for(i=0;i<sizeof(t);i++)
		if(objectp(t[i])){
		if(t[i]->query("combat_exp")<300000)
		  exp=220+random(10);
		else if(t[i]->query("combat_exp")<500000)
                  exp=220+random(20);
		else if(t[i]->query("combat_exp")<800000)
                  exp=220+random(30);
		else if(t[i]->query("combat_exp")<1000000)
                  exp=220+random(40);
                else exp=220+random(50);
          if(t[i]->query("combat_exp")<1000000)
          pot=t[i]->query("max_pot")/4;
          else pot=115+random(10);
             sil=BUTOU_JOB+t[i]->query("max_pot")-100;
	      t[i]->add("deposit",sil);
		  t[i]->add("combat_exp",exp);
		  t[i]->add("potential",pot);
		  if(t[i]->query("potential")>t[i]->query("max_pot")*3/2)
	t[i]->set("potential",t[i]->query("max_pot")*3/2);
		  add_shili(t[i],exp/2,sil/2);
		  t[i]->delete_temp("butou_job");
		  t[i]->delete_temp("butou_job_ok");
		  t[i]->delete_temp("butou_job_flag");
		  t[i]->set("busy_time",time());
		  tell_object(t[i],"��ͷЦ�����ðɣ������鷳"+RANK_D->query_respect(t[i])+"�ˣ�\n");
		  tell_object(t[i],"������ж��У�������"+""HIW""+chinese_number(exp)+""NOR""+"��ʵս���顣\n");
          tell_object(t[i],"                      "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�ܡ�\n");
		  tell_object(t[i],"��ͷ������"+MONEY_D->money_str(sil)+"��Ϊ������\n");
		  tell_object(t[i],"��Ǯׯ�Ĵ�������ˣ�\n");}
	return 1;
}
