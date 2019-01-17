
inherit NPC;
#include <job_money.h>
#include <ansi.h>
string give_job();

mapping maps=([
"/d/clone/room/lingwu/jingzhai/wolong2":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong3":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong4":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong5":"����ɽ��",
  "/d/clone/room/lingwu/jingzhai/wolong6":"����ɽ��",
  "/d/changbaishan/shulin1":"����ɽ��",
  "/d/changbaishan/shulin2":"����ɽ��",
  "/d/changbaishan/shulin3":"����ɽ��",
  "/d/changbaishan/shulin4":"����ɽ��",
  "/d/hangzhou/dongan1":"��������","/d/hangzhou/dongan2":"��������",
  "/d/hangzhou/dongan3":"��������","/d/hangzhou/nanan1":"��������",
  "/d/hangzhou/nanan2":"��������","/d/hangzhou/xiaolu1":"��������",
  "/d/wuyishan/shanlu5":"����ɽ��","/d/wuyishan/shulin1":"����ɽ��",
  "/d/wuyishan/shulin2":"����ɽ��","/d/wuyishan/shulin3":"����ɽ��",
  "/d/wuyishan/shulin4":"����ɽ��","/d/wuyishan/xiaoxi1":"����ɽ��",
  "/d/changan/nanjie2":"��������","/d/changan/nanjie3":"��������",
  "/d/changan/nanjie4":"��������","/d/changan/nanjie5":"��������",
  "/d/changan/beijie0":"��������","/d/changan/beijie1":"��������",
  "/d/changan/beijie2":"��������","/d/changan/beijie3":"��������",
  "/d/huashan/putidong":"��ɽɽ��","/d/huashan/houshan":"��ɽɽ��",
  "/d/huashan/shanlu1":"��ɽɽ��","/d/huashan/shanlu2":"��ɽɽ��",
  "/d/huashan/shanlu3":"��ɽɽ��","/d/huashan/shanlu4":"��ɽɽ��",
 ]);
void create()
{
   set_name("����",({ "shang zhen","shang","zhen" }) );
        set("gender", "����" );
        set("age", 50);
   set("long", "�����Ƿ��������Ĵ�ܼң��Ӳ�����ȥ��\n"+
               "Ӧ����ʮ���£�����ƽֱ���ϴ��Ļ�����\n"+
               "�ߺ���΢���̵��´��ľ���������ʾ����\n"+
               "�к�ǿ�ĸ��Ժ����š�\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("tao",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("babu-ganchan",170);
   set("hand",({"liu","liang","tao"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "��ͽ":(:give_job:),
	   ]));
   setup();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N����غ���һ��.\n",ob2);break;
	case 1: message_vision("$N�����۴�����$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
string give_job()
{
   object me;object paper;
   string *map;
   string here;
   int i;
   
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "�㻹���Ȱ���ͽɱ����˵��!\n";

   if(!me->query_temp("zhaoxiang_killer")){
      if(time()-me->query("busy_time")<100)
         return "�㻹����ЪЪ�ɣ�\n";}
   else{
      if(time()-me->query("busy_time")<20)
         return "�㻹��ЪЪ�ɣ�\n";}
   if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   if(!valid_do_job(me,"feimajob"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
   me->set_temp("dtsl_job","��������ɱ��ͽ����");
   me->delete_temp("zhaoxiang_killer");
   map=keys(maps);
   i=random(sizeof(map));
   here=map[i];
   me->set_temp("shang_kill_pantu/where",map[i]);
   paper=new(__DIR__"paper");
   paper->move(me);
   message_vision("$N����$nһ��"+paper->query("name")+"��\n",
                  this_object(),me);
   return "�ðɣ��鷳��ȥ"+HIG+maps[here]+NOR+CYN+"�����Ƿ�����������ͽɱ����\n"+
          "�����˰������׼��û������ҡ�\n";

}



int accept_object(object me,object ob)
{
	int exp,sil,pot,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return notify_fail("�ҿɲ����Ҫ���˵Ķ�����\n");
	if((string)ob->query("dead_id")!="tao shusheng")
		return notify_fail("��ɱ�����˰ɣ�\n");
	if(ob->query("killed_by")!=me->query("id"))
	return notify_fail("�ߣ�������ɱ���ˣ�����ð���𣿣�\n");
	me->delete_temp("shang_kill_pantu");
	me->delete_temp("dtsl_job");
        exp=250+random(20);
        if(me->query("combat_exp")<1000000)
        pot=me->query("max_pot")/3;
        else pot=120+random(10);
	me->add("combat_exp",exp);
	pot=50+random(10);
	me->set("busy_time",time());
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot")*3/2)
	me->set("potential",me->query("max_pot")*3/2);
    me->add("deposit",100);
    add_shili(me,exp/3,50);
	tell_object(me,HIW"\n�㱻������"+exp+"�㾭��ֵ "+pot+"��Ǳ��"+sil/100+"������\n"NOR);
	tell_object(me,HIW"лл��,Ϊ���Ƿ�������������ô��ĺ���!\n"NOR);
	tell_object(me,"���Ǯׯ��������ˣ�\n");
	remove_call_out("cancel_shang_kill_pantu");
	return 1;
}

