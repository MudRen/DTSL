
inherit NPC;

#include <ansi.h>
#include <job_money.h>

#define TIME_TICK1 time()*60
string *list=({

"killer",

	});
int work_me();
int cancel_me();
int delete_ask(object me);
int do_kill(string arg);

string do_quest1();
void create()
{
   int i;
   object *ob;
   
   set_name("������",({ "yang xuyan","yang" }) );
   set("gender", "����" );
   set("nickname","Ӱ�Ӵ̿�");
   set("age", 32);
   set("long", "�����������������Ӱ�Ӵ̿͡�\n");
       
   set("combat_exp", 1000000);
   set("str",30);
   set("per", 22);
   set("dex",30);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   set_skill("force",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("sword",200);
   
   set_skill("yingzi-jianfa",200);
   set_skill("huanmo-shenfa",200);
   set_skill("wanshi-jue",200);
 
   set("inquiry",([
//	  "ɱ��": "�ðɣ����� cisha ����id  ��������ɱ˭��!\n",
//        "��ɱ": "�ðɣ����� cisha ����id  ��������ɱ˭��!\n",
//	  "��ɱ": "�ðɣ����� cisha ����id  ��������ɱ˭��!\n",
          "kill": (: work_me :),
	  "ɱ��": (: work_me :),
	  "����": (: cancel_me :),
	  "�嶾��":(:do_quest1:),
	   ]));
   set("vocation","ɱ��");
   set_temp("apply/armor",100);
   setup();
   ob=children(__DIR__"obj/qingfeng-jian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/qingfeng-jian")->wield();
  
}

void init()
{
	//add_action("do_kill","cisha");
	add_action("do_teach","qingjiao");
}

int do_kill(string arg)
{
	object *usr;object me,ob;int i,j;object victim;
	int vexp,gol;int money;
	me=this_player();
	ob=this_object();
	usr=users();
	if(!arg) return notify_fail("������ȥɱ˭����˵����!\n");
	j=0;
	if(me->query("id")==arg) return notify_fail("ɱ���Լ�������Ц�ɣ���\n");
	for(i=0;i<sizeof(usr);i++)
	{
		if(usr[i]->query("id")==arg)
		{ j=1;victim=usr[i];break;}
	}
	if(j==0) return notify_fail("�������ڵĽ�������������𣿺úÿ���!\n");
	if(victim->is_ghost())
	return notify_fail("������Ѿ����ˣ��㻹�ǻ������°ɣ�\n");
	vexp=victim->query("combat_exp");
	gol=vexp/1000+random(vexp/1000);
	if(gol<=0) return notify_fail("�ߣ��书��ô��΢����Ҳֵ������ɱ?\n");
	tell_object(me,"����ж�Ҫ������"+chinese_number(gol)+"���ƽ�!\n");
	money=gol*10000;
	switch(MONEY_D->player_pay(this_player(), money))
	{
	case 0: return notify_fail("�ߣ���ô��Ǯ��Ҳ�������ң�\n");
	case 2: return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
	tell_object(me,"�����ӵ��ͷ����������Ǯ�ƣ��������֣�����ź��ˣ�\n");
	if(victim->query("combat_exp")>500000)
	ob->set("combat_exp",victim->query("combat_exp"));
	if(!objectp(victim)) return notify_fail("��ѽ�������ͻȻ���ˣ��´ΰ�!\n");
	victim->start_busy(2);
	message_vision("$N����һ�Σ��ټ�����!\n",ob);
	ob->move(environment(victim));
	message_vision(HIR"$N����$n�е������˹�����ɱ�㣬����������!\n"NOR,ob,victim);
	ob->kill_ob(victim);
log_file("killer_kill",sprintf("%s let yang kill %s\n",me->query("id"),victim->query("id")));
	call_out("yang_go",180,ob);
	return 1;
	}
	return 1;
}

void yang_go(object ob)
{
	string *dir=({"/d/luoyang/shanlu1","/d/xiangyang/tulu2","/d/chengdu/shulin1"});
	if(!objectp(ob))
	{ remove_call_out("yang_go");return;}
	message_vision("$N���¿��˿�������һ�Σ��ټ�����!\n",ob);
	ob->move(dir[random(sizeof(dir))]);
	remove_call_out("yang_go");return;
}

int prevent_learn(object me,string skill)
{
   
   if(me->query("vocation")==query("vocation")){
   	if(skill!=query("vocation_skill")&&skill!="wanshi-jue"){
          command("say ��ֻ����"+to_chinese(query("vocation_skill"))+
             "��"+query("vocation_skill")+"����"+
             to_chinese("wanshi-jue")+"��wanshi-jue����");
          
          return 1;
        }
       return 0;
   } 
   else if(skill!="wanshi-jue")
        return 1;
   
   return 0;
}

int is_apprentice_of(object ob)
{
	return 1;
}
int recognize_apprentice(object ob)
{
         return 1;
}

int cancel_me()
{	
	
	object me=this_player();

           if(!me->query_temp("cisha/name"))
	   
	{
	   command("bite");
	   command("say ��������ɱ�𣿣�����ʲô���֣�\n");
	   return 1;
       }
        
        // ��������
        JOBSYS_D->do_cancel_job("killerjob",me,this_object());
	
	command("shrug");
	command("say ���Ȼ���ܰ���ɱ�ˣ�Ҳֻ�����ˡ�\n");	
	return 1;
}
 
int work_me()
{
	object me;
	me=this_player();
	
	if(me->query("vocation")!="ɱ��"){
	 command("say ֻ��ɱ�ֿ������������\n");
	 return 1;}
	
	if(me->query("combat_exp")<100000){
	command("say ��ı���̫���ˣ��޷����������ġ�\n");
	return 1;
	}
	
	   if(me->query_temp("cisha/name"))
	   {
		command("heng");
		command(
 		  "say �Ҳ����Ѿ�����ȥ��ɱ"+me->query_temp("cisha/name")
		  +"�𣿻����ţ���ȥ����\n");
		return 1;
	    }
	   
	   if(time()-me->query("busy_time")<30){
	   	
		command("heng");
		command(
 		  "say ���������ⲻ�����еģ��Ȼ�ɣ�\n");
		return 1;
	    }
	   
	   if(me->query_temp("dtsl_job")){
	   command("heng");
		command(
 		  "say �����������������æ��ȥ�ɣ�\n");
		return 1;
	    }
	    
	    if(me->is_busy()){
	     command("say ����æ���أ�\n");
	     return 1;}
	   
	    
	me->set_temp("cisha");
	me->set_temp("dtsl_job","ɱ������");
	me->set("busy_time",time()-20);
	me->start_busy(1);
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	
	string where;
	object killer;
	int lvl;

	if(environment(me)!=environment()) return 1;
	
	lvl=me->query_temp("cisha_job/level");
	
        killer = new("/d/job/killerjob/"+list[random(sizeof(list))]);
        where=killer->invocation(me,lvl);
	
	message_vision("$N����ߵ����¶����˼��䣡\n",this_object());
        message_vision("$N��"HIR"$n"NOR"˵����ĳ��ί�д�ɱ��"+where+"�����ˣ�"
		+"����Ͼ������ȥ���Ұ���ɱ�˰ɣ�\n"
		,this_object(),me);

	me->set_temp("cisha/name",killer->query("name"));
	//�˴�����һ�� job_temp_killer ����������� quit �� ���������ʱ
	// jobsysd.c �������������
	me->add_temp_array("job_temp_killer",killer);
	return 1;
}

//�ϳ��ݺ����Ť Ϊ��Ҫ����Ʒ��
string do_quest1()
{
  object ob;
  string str1,str2;
  
  ob=this_player();
  if(ob->query("vocation")!="ҩʦ")
  return "��ֻ����ҩʦ�������\n";
  if(ob->query("dtsl_quest_poison_ok"))
  return "�����Ѵ��ڸ��㶾���Ļ�Ҫ���㻹����ʲô��\n";
  ob->add_temp("ask_times",1);
  if(ob->query_temp("ask_times")>40)
  ob->set_temp("ask_times",random(10));
  str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)]||
   ob->query_temp("ask_times")!=ob->query("kar"))
  return "�ҿ����������ѣ�����ʱ�в��Ǵ�����˶�����ʱ����\n";
  ob->set("dtsl_quest_poison_ok",1);
  return "���������Ķ�ҩ��Ҫ������Ʒ�����ܲ��ܰ�����һ�£�\n";
}

int accept_object(object who,object ob)
{
    object book;
    
    if(!who->query("dtsl_quest_poison_ok"))
    return 0;
    if(ob->query("quest_poison")&&
    !who->query_temp(ob->query("poison_id"))&&
     who->query_temp("poison_find")<2){
    who->add_temp("poison_find",1);
    if(who->query_temp("poison_find")==2){
    	book=new(__DIR__"obj/book");
    	book->move(who);
    	tell_object(who,query("name")+"������һ��"+book->query("name")+"��\n");
    	return 1;}
    return 1;}
   return 0;
}
    
