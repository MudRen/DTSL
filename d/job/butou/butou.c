
inherit NPC;

#include <ansi.h>
#include <job_money.h>

mapping map_here=([
 "/d/dabashan/shandong1":"大巴山上","/d/dabashan/shandong2":"大巴山上",
 "/d/dabashan/shandong3":"大巴山上","/d/dabashan/shanpo":"大巴山上",
 "/d/dabashan/shanfeng":"大巴山上","/d/dabashan/shanya":"大巴山上",
  "/d/dabashan/shanji1":"大巴山上", "/d/dabashan/shanji2":"大巴山上",
  "/d/clone/room/lingwu/jingzhai/wolong1":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong2":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong3":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong4":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong5":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong6":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong7":"长白山上",
  "/d/changbaishan/shanlu1":"长白山上",
  "/d/changbaishan/shanlu2":"长白山上",
  "/d/changbaishan/shanlu3":"长白山上",
  "/d/changbaishan/shanlu4":"长白山上",
  "/d/changbaishan/shanlu5":"长白山上",
  "/d/changbaishan/shulin1":"长白山上",
  "/d/changbaishan/shulin2":"长白山上",
  "/d/changbaishan/shulin3":"长白山上",
  "/d/changbaishan/shulin4":"长白山上",
  "/d/changbaishan/shanya":"长白山上",
  "/d/changbaishan/shanpo":"长白山上",
   "/d/hangzhou/dongan1":"杭州西郊","/d/hangzhou/dongan2":"杭州西郊",
  "/d/hangzhou/dongan3":"杭州西郊","/d/hangzhou/nanan1":"杭州西郊",
  "/d/hangzhou/nanan2":"杭州西郊","/d/hangzhou/xiaolu1":"杭州西郊",
  "/d/wuyishan/shanlu1":"武夷山上","/d/wuyishan/shanlu2":"武夷山上",
  "/d/wuyishan/shanlu3":"武夷山上","/d/wuyishan/shanlu4":"武夷山上",
  "/d/wuyishan/shanlu5":"武夷山上","/d/wuyishan/shulin1":"武夷山上",
  "/d/wuyishan/shulin2":"武夷山上","/d/wuyishan/shulin3":"武夷山上",
  "/d/wuyishan/shulin4":"武夷山上","/d/wuyishan/xiaoxi1":"武夷山上",
  "/d/wuyishan/xiaoxi2":"武夷山上","/d/wuyishan/doupo3":"武夷山上",
  "/d/huashan/putidong":"华山山内","/d/huashan/houshan":"华山山内",
  "/d/huashan/shanlu1":"华山山内","/d/huashan/shanlu2":"华山山内",
  "/d/huashan/shanlu3":"华山山内","/d/huashan/shanlu4":"华山山内",
  "/d/huashan/shanlu5":"华山山内","/d/huashan/shanlu6":"华山山内",
  "/d/huashan/xiaoxi":"华山山内","/d/huashan/shulin3":"华山山内",
  "/d/emeishan/liangting":"峨眉山中","/d/emeishan/shilin":"峨眉山中",
  "/d/emeishan/shulin":"峨眉山中","/d/emeishan/xiaojing1":"峨眉山中",
  "/d/emeishan/wu":"峨眉山中","/d/taiyuan/center":"太原城内",
  "/d/hengshan/beiyuedian":"恒山内",
  "/d/hengshan/beiyuemiao":"恒山内","/d/hengshan/cuiping1":"恒山内",
  "/d/hengshan/cuiping2":"恒山内","/d/hengshan/cuipinggu1":"恒山内",
  "/d/hengshan/cuipinggu2":"恒山内","/d/hengshan/daziling":"恒山内",
  "/d/hengshan/guolaoling":"恒山内","/d/hengshan/sanjiaodian":"恒山内",
  "/d/hengshan/xuankong1":"恒山内","/d/hengshan/xuangengsong":"恒山内",
  "/d/hengshan/kutianjing":"恒山内","/d/hengshan/huixiantai":"恒山内",
  "/d/hengshan/hufengkou":"恒山内",
]);


string give_job();
int do_ok(string arg);

void create()
{
   set_name("捕头",({ "bu tou","bu","tou" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是长安的捕头，管理长安城的治安。\n");
       
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
	   "盗贼":(:give_job:),
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
	//return "对不起，这个任务还在修改中。\n";
	t=me->query_team();
	if(sizeof(t)==0){
		return "这个任务你自己来做太危险了，还是和别人组队一起做吧！\n";}
	if(!me->is_team_leader())
		return "你不是队伍的首领，让你们的首领来吧！\n";
        if(time()-me->query("busy_time")<160+random(60))
		return "最近没什么盗贼，你过一阵子再来吧！\n";
	if(sizeof(t)>2) 
	 return "这么简单的任务还要这么多人？不会吧？\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return "你的队员还没到齐，等等吧！\n";
	for(i=0;i<sizeof(t);i++)
	 if(t[i])
	  if(t[i]->query("combat_exp")<200000)
	   return t[i]->name()+"的经验太低，这太危险了！\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(me->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(me->query("combat_exp")-t[i]->query("combat_exp")>100000)
				  return "你们的经验相差太大，这很危险！\n";}
		  else{ if(t[i]->query("combat_exp")-me->query("combat_exp")>100000)
			      return "你们的经验相差太大，这很危险！\n";}
	if(me->query_temp("butou_job"))
		return "不是告诉让你们去做了吗？怎么还不去？\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
	    t[i]->set_temp("butou_job",1);
	me->set_temp("butou_job",1);
	paper=new("/u/yanyan/paper");
	here=keys(map_here);
	j=random(sizeof(here));
	paper->set("where",here[j]);
	paper->move(me);
	tell_object(me,query("name")+"给了你一张"+paper->query("name")+"。\n");
	return "好吧，你们拿着这张"+paper->query("name")+"去"+map_here[here[j]]+"缉杀盗贼，然后回来复命吧！\n";
	
}

int do_ok(string arg)
{
	object me,ob,*t;int i;object money;
	int exp,pot,sil,famous;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("你要向谁归案？\n");
	if(!me->query_temp("butou_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",这话从何说起？\n");
	if(!me->query_temp("butou_job_ok"))
        return notify_fail(""+RANK_D->query_respect(me)+",你们当我是小孩子来骗吗？！\n");
	t=me->query_team();
	if(sizeof(t)==0)
		return notify_fail("你没和其他人组队，我就不信你会独自完成这么艰巨的任务！\n");
    for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return notify_fail("你的队员还没到齐，等等吧！\n");
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(!t[i]->query_temp("butou_job"))
			  return notify_fail("你们的队伍中混进了其他人，不把他赶走，我如何奖励你们？\n");
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
		  tell_object(t[i],"捕头笑道：好吧，真是麻烦"+RANK_D->query_respect(t[i])+"了！\n");
		  tell_object(t[i],"在这次行动中，你获得了"+""HIW""+chinese_number(exp)+""NOR""+"点实战经验。\n");
          tell_object(t[i],"                      "+""HIW""+chinese_number(pot)+""NOR""+"点潜能。\n");
		  tell_object(t[i],"捕头给了你"+MONEY_D->money_str(sil)+"作为奖励。\n");
		  tell_object(t[i],"你钱庄的存款增加了！\n");}
	return 1;
}
