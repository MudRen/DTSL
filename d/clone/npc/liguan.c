#include <ansi.h>
inherit NPC;

#define YEAR 2002
#define ZQJ 0
#define SDJ 0
#define YD 1
#define CJ 0

string give_skill();
//string give_buchang();
//string give_pot();
//string do_change_skill();
string give_box();

string give_present_zqj();
string give_present_sdj();
string give_present_yd();
string give_present_cj();
int change_age();

void create()
{
   set_name(HIR"礼官"NOR,({ "li guan","li","guan"}) );
        set("gender", "男性" );
        set("long","这位是大唐双龙的礼官，用来给新来的客人发礼物。\n"+
                   "你可以用 ask li about 大唐双龙 来要礼物。\n");
        set("age", 32);
        set("inquiry",([
        "大唐双龙":(:give_skill:),
        "中秋节":(:give_present_zqj:),
        "圣诞节":(:give_present_sdj:),
//        "元旦":(:give_present_yd:),
        "春节":(:give_present_cj:),
        "盒子":(:give_box:),
        "行囊":(:give_box:),
//        "年龄问题":(:change_age:),
       
        ]));
        set("no_get",1);
        set("target_id","####");
        set("accept_kill",1);
    setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
  
}
string give_skill()
{
  object ob;
  ob=this_player();
  if(ob->query("combat_exp")>6000)
  return "你的经验已经很高，还是自己去闯荡江湖吧！\n";
  if(ob->query("gived_gift"))
  return "我已经给你礼物了，不要这么贪心。\n";
  
  if(is_busy())
   return "请稍等... ...\n";
  
  ob->set("combat_exp",6000);
  ob->set_skill("parry",40);
  ob->set_skill("force",40);
  ob->set_skill("dodge",40);
  ob->set_skill("unarmed",40);
  ob->set("max_sen",200);
  ob->set("eff_sen",200);
  ob->set("max_sen_add",100);
  ob->set("sen",200);
  ob->set("max_force",200);
  ob->set("force",200);
  ob->set("gived_gift",1);
  
  start_busy(2);
  
  message_vision(YEL"$N缓缓举起双掌，将自己的部分功力注入到了$n体内！\n"NOR,this_object(),ob);
  return NOR+CYN+"我只能帮你这么多，希望你以后在这里有所作为！\n"NOR;
}

int accept_fight(object ob)
{
  return notify_fail("礼官一笑：我可是从来不和别人打仗的！\n");
}
int accept_kill(object killer,object victim)
{
  message_vision(MAG"$N突然大声一喊，一股内力朝$n喷射而去！\n"NOR,victim,killer);
  killer->unconcious();
  return notify_fail("礼官嘿嘿笑了几声... ...\n"); 
}
void die()
{
  object ob;
  ob=this_object()->query("last_damage_from");
  this_object()->remove_all_enemy();
  if(objectp(ob))
  ob->remove_all_enemy();
  set("max_kee",1000);
  set("eff_kee",1000);
  set("kee",1000);
  set("max_sen",1000);
  set("eff_sen",1000);
  set("sen",1000);
  message_vision("$N呵呵一笑：我死了，怎么给客人发礼物呢？\n",this_object());
  return;
}
string give_present_zqj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!ZQJ)
   return "今天不是中秋节啊！";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"你的经验不足"+HIY+"200,000"+NOR+CYN+",我无法给你礼物，但还是祝你中秋节快乐！\n";
  if(ob->query("feast/zhongqiujie"+YEAR))
  return NOR+CYN"月饼我已经给你了，赶快和亲人一起吃吧！\n"NOR;
  ob->set("feast/zhongqiujie"+YEAR,1);
  thing=new(__DIR__"obj/yuebing");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"礼官给了你一块月饼。\n"NOR);
  return HIC"祝你中秋节快乐，合家团圆！\n"NOR;
}

string give_present_sdj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!SDJ)
   return "今天不是圣诞节啊！";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"你的经验不足"+HIY+"200,000"+NOR+CYN+",我无法给你礼物，但还是祝你中秋节快乐！\n";
  if(ob->query("feast/shengdanjie"+YEAR))
  return NOR+CYN"圣诞节礼物我已经给你了，别太贪心了。\n"NOR;
  ob->set("feast/shengdanjie"+YEAR,1);
  thing=new(__DIR__"obj/wazi");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"礼官给了你一双袜子。\n"NOR);
  return HIC"祝你圣诞节快乐！\n"NOR;
}

string give_present_yd()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!YD)
   return "今天不是元旦啊！";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"你的经验不足"+HIY+"200,000"+NOR+CYN+",我无法给你礼物，但还是祝你中秋节快乐！\n";
  if(ob->query("feast/yuandan"+YEAR))
  return NOR+CYN"元旦礼物我已经给你了，别太贪心了。\n"NOR;
  ob->set("feast/yuandan"+YEAR,1);
  thing=new(__DIR__"obj/libao");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"礼官给了你一个礼包。\n"NOR);
  return HIC"祝你元旦快乐！\n"NOR;
}

string give_present_cj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!CJ)
   return "今天不是春节啊！";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"你的经验不足"+HIY+"200,000"+NOR+CYN+",我无法给你礼物，但还是祝你中秋节快乐！\n";
  if(ob->query("feast/chunjie"+YEAR))
  return NOR+CYN"春节礼物我已经给你了，别太贪心了。\n"NOR;
  ob->set("feast/chunjie"+YEAR,1);
  thing=new(__DIR__"obj/bianpao");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"礼官给了你一个鞭炮。\n"NOR);
  return HIC"祝你春节快乐！\n"NOR;
}

int change_age()
{
	object ob;
	
	ob=this_player();
	if(ob->query("age")<=15||ob->query("change_age")){
	  tell_object(ob,"你年龄不用调节了。\n");
	  return 1;
	}
	ob->set("change_age",1);
	ob->set("mud_age",522000);
	tell_object(ob,"请重新登录游戏，年龄会恢复正常。\n");
	return 1;
	
}

/*
string give_buchang()
{
   object ob;
   mapping skl;
   string *skills;
   int i;
   
   ob=this_player();
   if(ob->query("age")<16)
   return "对不起，我只补偿受当机损失的玩家。\n";
   if(ob->query("gived_buchang"))
   return "我只能给每个人一次补偿的机会。\n";
   ob->add("combat_exp",100000);
   skl=ob->query_skills();
   if(mapp(skl)){
  skills=keys(skl);
 for(i=0;i<sizeof(skills);i++){
  ob->set_skill(skills[i],ob->query_skill(skills[i],1)+5);}
}
  ob->set("gived_buchang",1);
  return CYN+"很抱歉让你在本次当机中遭受损失，\n"+
         "特地补偿你100000点经验，每项技能提高五级，希望在大唐双龙玩的开心！\n";
}
*/
/*
string give_pot()
{
   object ob;
   
   ob=this_player();
   if(ob->query("age")<11)
   return "你年龄太小了，不在补偿范围之内。\n";
   if(ob->query("gived_buchang_pot"))
   return "我只给一次补偿的。\n";
   ob->add("potential",2000);
   ob->set("gived_buchang_pot",1);
   return CYN"真是非常抱歉！！特地补偿你二千点潜能！\n";
}
*/
/*
string do_change_skill()
{
    object ob;
    int skill;
    
    ob=this_player();
    if(ob->query("family/family_name")!="阴癸派"&&
    ob->query("family/family_name")!="东溟派")
    return CYN"你没什么事情干还是不要来捣乱了！\n";
    if(ob->query("family/family_name")=="阴癸派"&&
       ob->query_skill("tianmo-dai",1)){
      skill=ob->query_skill("tianmo-dai",1);
      ob->delete_skill("tianmo-dai");
      ob->set_skill("tianmo-dai",skill);}
    else
      if(ob->query_skill("shuiyun-xiufa",1)){
      skill=ob->query_skill("shuiyun-xiufa",1);
      ob->delete_skill("shuiyun-xiufa");
      ob->set_skill("shuiyun-xiufa",skill);}
    if(ob->query_skill("unarmed",1)){
    skill=ob->query_skill("unarmed",1);
    ob->set_skill("whip",skill);}
    return CYN"技能转换完毕，真是麻烦你了！\n";
}
*/
string give_box()
{
   object ob,box;
   object *inv;
   int i;
   
   ob=this_player();
   
   inv=all_inventory(ob);
   for(i=0;i<sizeof(inv);i++)
    if(inv[i]->query("save_box"))
     return "盒子不是给你的，我只给武林侠士行囊。\n你已经拿了行囊，别这么贪心了。\n";
   box=new("/d/clone/obj/elite/box");
   if(!box->move(ob))
     return "你身上的东西太多了！\n";
   message_vision("$N给了$n一个行囊。\n",this_object(),ob);
   return "一个武林人士拿什么盒子？给你一个行囊吧！\n这个行囊可以存放五件物品，请小心保管！\n";
}

