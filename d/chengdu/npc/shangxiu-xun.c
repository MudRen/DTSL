#include <ansi.h>
#include <job_money.h>
inherit NPC;
inherit F_SAVE;
string give_job();
string query_save_file()
{

	string id2;

	if( !stringp(id2 = query("npc_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id2;
}
void create()
{
   set_name("���㫑",({ "shang xiuxun","shang"}) );
        set("gender", "Ů��" );
		
        set("age", 25);
   set("long", "�����Ƿ�����.��̬��ǧ���ں�Ư�����㷢������С�ٲ�����к����������
����紦���������Ѱ��������Ը����������ľ���Ů�ɣ����������������ǵĴ���û�а�˿
���졣���ŵ�װ����ͻ���������ڵ����Ӻ�ɹ�ù�ͭɫ���������Ľ��ۼ�����ɢ�������ȵ��ഺ
���������۵Ľ�����Ϣ�����Ƕ����������Ѳ⣬Ũ�ܵ��۽�ë��Ϊ����˫���������������
��ķ�Ŀ�������������ظС�\n");
       
   set("combat_exp",600000);
   set("str", 24);
   set("per", 27);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("sword",170);
   set_skill("qingxuan-jianfa",170);

   set_skill("babu-ganchan",170);
   set("sword",({"qingxuan-jianfa"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "��ͽ":(:give_job:),
	   ]));
   set("shili",([
       "name":"feima_b",
       "leader":"feima_b",
       ]));
   set("npc_id","shangxiuxun");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
   restore();
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
	case 0: message_vision("$N˵��:˭���������,��ȥ!\n",ob2);break;
	case 1: message_vision("$Ņͷ���˿�$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

string give_job()
{
   object me;object ob;
   ob=this_object();
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "�㻹���Ȱ���ͽɱ����˵��!\n";
   if(ob->query("job_time"))
	   if(time()-ob->query("job_time")<=120)
		   return "��..���,�Ѿ����˰�æ��,���ȵȻ��!\n";
   
   ob->set("job_time",time());
   call_out("cancel_shang_kill_pantu",300,me);
   switch(random(3))
   {
   case 0: me->set_temp("shang_kill_pantu/1",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵�������ݵ�һ��������԰�������!\n";break;
   case 1: me->set_temp("shang_kill_pantu/2",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵���ڳɶ���һ������֮�Ҳ���!\n";break;
   case 2: me->set_temp("shang_kill_pantu/3",1);return "�ð�,��ȥ�ѷ�����������ͽɱ��,�������û������׼�!\n��˵����������������Ľ�ͷС����!\n";break;
   }
   
}

void cancel_shang_kill_pantu(object me)
{
	if(!objectp(me)) {remove_call_out("cancel_shang_kill_pantu");return;}
	if(me->query_temp("shang_kill_pantu"))
	{
		tell_object(me,HIW"������̫����,�������ȡ����!\n"NOR);
		me->delete_temp("shang_kill_pantu");
		remove_call_out("cancel_shang_kill_pantu");
		return;
	}
	remove_call_out("cancel_shang_kill_pantu");
}

int accept_object(object me,object ob)
{
	int exp,sil,pot,famous,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return 0;
	if((string)ob->query("dead_id")!="tao shusheng")
		return 0;
	me->delete_temp("shang_kill_pantu");
        exp=me->query("max_pot");
        famous=exp/2;
        pot=me->query("max_pot")/4;
	me->add("combat_exp",exp);
	sil=FEIMA_JOB;
	pot=50+random(10);
	me->add("potential",pot);
	me->add("deposit",FEIMA_JOB);
	add_shili(me,exp/3,FEIMA_JOB/2);
	tell_object(me,HIW"\n�㱻������"+exp+"�㾭��ֵ "+famous+"�㽭������"+pot+"��Ǳ��"+sil/100+"������\n"NOR);
	tell_object(me,HIW"лл��,Ϊ���Ƿ�������������ô��ĺ���!\n"NOR);
	tell_object(me,"���Ǯׯ��������ˣ�\n");
	return 1;
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("���Ƿ��������ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("������������������������֣�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ���Ƿ������������֣�\n",ob,me);
	tell_object(me,"��ȥ���������񴦴� join �����������ˣ�\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s�����˷���������\n",me->name()));
	return 1;
}