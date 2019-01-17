

inherit NPC;



#include <job_money.h>

#include <ansi.h>



#define MBUG(x) (tell_object(find_player("inwind"),sprintf("%s: %O\n",__FILE__,(x))))

string give_job();

string do_abandon();

string do_quest1();

int do_quest2();

string do_mghs_quest1();

int do_answer(string arg);



string *dir1=({

"/d/huashan","/d/emeishan"

});

string *dir2=({

"/d/suiye","/d/dingxiang","/d/wuyishan"

});

string *dir3=({

"/d/hengshan","/d/taishan","/d/dabashan"

});



void create()

{

   set_name("�Ų���",({ "wen caiting","wen" }) );

   set("gender", "Ů��" );

		

   set("age", 32);

   set("long", "���������ɵ��Ų��ã�����ħ���ڽ�����Ҳ�Ƿǳ�������\n");

       

   set("combat_exp",500000);

   set("str", 25);

   set("per", 25);

   set("attitude", "peaceful");

   set_skill("unarmed",170);

   set_skill("dodge",170);

   set_skill("parry",170);

   set_skill("force",170);

   set_skill("sword",170);

   set_skill("strike",170);

   set_skill("cuff",170);

   set_skill("literate",170);

   set_skill("jiutian-huanzhang",170);

   set_skill("tianmo-dafa",170);

   set_skill("tianmo-jianfa",170);

   set_skill("tianmo-huanzong",170);

   set_skill("tianmo-dai",170);  

   set_skill("meigong-huanshu",200);

   set("gin",3000);

   set("max_gin",3000);

   set("kee",3000);

   set("max_kee",3000);

   set("sen",3000);

   set("max_sen",3000);

   set("force",3000);

   set("max_force",3000);

   create_family("������",5,"����");

   set("target_id","####");

   

   set("inquiry",([	

	   "����":(:give_job:),

            "����":(:do_abandon:),

	   "��ħ��":(:do_quest1:),

	   "Ч��":(:do_quest2:),

	   "����":(:do_mghs_quest1:),

	   ]));  

   setup();

  

}



void init()

{

   add_action("do_answer","answer");

}



string give_job()

{

	object me,letter;

	object owner;

	string *dirs,str;

	

	me=this_player();

	if(me->query_temp("zhu_sx")) return "�㻹�����������е��Ű�!\n";

	

	

        if(time()-me->query("busy_time")<=10)

		return "�㻹����ЪЪ�ɣ�\n";

	if(me->query_temp("dtsl_job"))

	return "���������������񣬻�����æ�����İɣ�\n";

	

	if(me->query("combat_exp")<200000)

	 dirs=dir1;

	else

	 if(me->query("combat_exp")<500000)

	 dirs=dir1+dir2;

	else

	 dirs=dir1+dir2+dir3;

	

	owner=new(__DIR__"owner");

	

	if(!owner->set_status(me))

	return "���ŵ�ʹ�߳������ˣ���ȥ������ʦ��\n";

	

	if(!random_place(owner,dirs))

	return "���ŵ�ʹ���������أ���������... ...\n";

	

	if(!environment(owner))

	return "���ŵ�ʹ���������أ���������... ...\n";

	

	letter=new(__DIR__"letter");

	letter->set("target",owner);

	letter->set("long","����һ���͸�"+HIC+owner->name()+NOR+"���š�\n");

	letter->set("owner",me);

	letter->move(me);

	me->set_temp("zhu_sx",1);

	me->set_temp("dtsl_job","������������");

	me->set_temp("songxin/name",owner->query("name"));

         if(me->query("combat_exp",1)>=800000)

	 me->set_temp("need_killer",1);

	else

	 me->set_temp("need_killer",0);

	if((int)me->query("combat_exp",1)>=800000)

	   {   

	   	call_out("killer_come",30+random(10),me);

            str="·�Ͽ�ҪС�ģ�\n";

	}

	else str="";

	tell_object(me,query("name")+"����һ��"+letter->query("name")+"��\n");

	return "�ðɣ��鷳����Ұ����"+letter->query("name")+CYN+"�͸�"+MISC_D->find_place(environment(owner))+

	 "��"+owner->name()+"��ǧ��Ҫ��©����Ϣ��\n"+

	       str;

	

	 

}







string do_abandon()

{

   object ob;

   object letter;

   object owner;

   

   ob=this_player();

   

   if(!ob->query_temp("zhu_sx"))

   return "����˵ʲô���ҿ���һ��Ҳ��������\n";

   

   

   if(objectp(letter=present("letter",ob)))

{

   if(objectp(owner=letter->query("target")))

{

MBUG(owner);

    destruct(owner);

}

    destruct(letter);

}

   ob->delete_temp("zhu_sx");

   ob->delete_temp("dtsl_job");

  ob->delete_temp("songxin/ob");

  ob->delete_temp("songxin/ob");

   ob->delete_temp("need_killer");

   ob->delete_temp("need_killer_flags");

   return "��������û�е����������Ǹ��Ҷ�����\n";

}

void killer_come(object me)
{
  object killer;
   object killer2;
   object letter;
   
   if(!me)
    return;
   if(me->is_ghost())
    return;
   
   if(!me->query_temp("zhu_sx"))
    return;
    
   tell_object(me,HIB"\n�ƺ����˴���ı���Ϯ����\n\n"NOR);
   killer=new("/d/job/ygsongxin/killer");
        
        killer->set_status(me);                         
        killer->move(environment(me));
        message_vision("\n$N��Ȼ��:а��֮��������!\n\n",killer);
        me->add_temp_array("job_temp_killer",killer);
        killer->kill_ob(me);
  

  return;
}       


string do_quest1()

{

   object ob;

  

  ob=this_player();

  

  if(ob->query("dtsl_quest_yinguifinal"))

  return "ƾ��Ĺ���ѧϰ��ħ��̫��ϧ�ˣ�\n";

  

  if(ob->query_temp("tmz_quest/pass_wen"))

  return "��Ĺ������Ѿ�������ˣ���ȥ���������ϰɣ�\n";

  

  ob->set_temp("tmz_quest/wen_step1",1);

  

  return "��ѧ��ħ���ȴ������˵�ɣ�\n";

}



int surrender(object killer,object victim)

{

   if(!killer->query_temp("tmz_quest/wen_step1"))

   return 1;

   killer->delete_temp("tmz_quest/wen_step1");

   killer->set_temp("tmz_quest/wen_step2",1);

   

   message_vision(CYN"\n$N"+CYN+"��ɫһ�䣬��$n"+CYN+"����"+RANK_D->query_respect(killer)+"��Ȼ���ֲ�����\n"+

   "�����㻹Ҫ���Ұ������ſ��ԣ�\n"NOR,victim,killer);

   return 1;

}





int do_action1(object ob)

{

   string msg;

   

   msg="\n$N��$n���˸����ۣ��������������»��������㱾��һ��ɣ�\n";

   message_vision(msg,this_object(),ob);

   call_out("do_msg2",1,ob);

   return 1;

}



int do_action2(object ob)

{

    string msg;

    

    msg="\n$N��$n��Ц�����ã������ͽ�������Ի����ӣ�\n";

    message_vision(msg,this_object(),ob);

    call_out("show_msg2",1,ob);

    return 1;

}

void do_msg2(object ob)

{

  string msg;

  

  if(!ob) return;

  

  msg="\n$Nһ����ۣ���$n���˹�ȥ��\n"+

      "$nֻ���������˱ǣ���Щ���������ˣ�\n";

  message_vision(msg,this_object(),ob);

  call_out("do_msg3",1,ob);

}



void do_msg3(object ob)

{

  string msg;

  

  if(!ob) return;

  

  if(ob->query("sen")<300){

   msg="\n$Nһ���ƿ�$n��ŭ��������һ�㾫��Ҳû�У������뱾��Զ��ɣ�\n";

   message_vision(msg,this_object(),ob);

  }

  msg="\n$N��$n����������һ��$n��ȫ��ʧ�����ǡ�\n"+

      "�����ƺ��Ѿ�����Χ����������һ�ɶ�����\n"+

      "����������������������\n\n";

  message_vision(msg,this_object(),ob);

  call_out("do_msg4",1,ob);

}



void do_msg4(object ob)

{

  string msg;

  

  if(!ob) return;

  

  msg="\n$n��Щ����ʧ���վ��������\n"+

      "$N¶�������Ц�ݣ�������$n�����ա�\n"+

      "$N����������Ŀ����Ѿ�ͨ���ˣ�����ȥ�����������ϵ�����ɣ�\n";

  message_vision(msg,this_object(),ob);

  ob->set_temp("tmz_quest/pass_wen",1);

  return;

}



void show_msg2(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N���Ƶ�$n��ߣ�������$n˵�š��Ĺ��������ľ��ϡ�\n"+

       "$n���ţ������ɵú��ˡ�\n";

   message_vision(msg,this_object(),ob);

   call_out("show_msg3",1,ob);

}



void show_msg3(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N��Ц�Ŷ�$n˵��ʲô�����İ�����$n�ı��ϡ�\n"+

       "$n��ͷ����һ�ᣬ�ƺ��ԡ��Ĺ�����������һЩ����\n";

   message_vision(msg,this_object(),ob);

   call_out("show_msg4",1,ob);

}



void show_msg4(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N��$nһЦ���ú�ѧϰ���Ĺ����������Ժ����µ����ӾͶ���\n"+

       "�������֮���ˣ�\n"+

       "$N����������Ŀ����Ѿ�ͨ���ˣ�����ȥ�����������ϵ�����ɣ�\n";   

   message_vision(msg,this_object(),ob);

   ob->improve_skill("meigong-huanshu",1000);

   ob->set_temp("tmz_quest/pass_wen",1);

}



int do_quest2()

{

  object ob;

  

  ob=this_player();

  

  if(!ob->query_temp("tmz_quest/wen_step2")){

    command("xixi");

    command("say ����Ϊ��Ч��ʲô����");

    return 1;

  }

  

  ob->delete_temp("tmz_quest/wen_step2");

  if(ob->query("gender")=="����")

   return do_action1(ob);

  else

   return do_action2(ob);

}



string do_mghs_quest1()

{

   object ob;

   

   ob=this_player();

   

   if(ob->query("dtsl_quest_meigong-huanshu"))

   return "���Լ����Ĺ�����ȥ�Ի�ɣ�����������ʲô��\n";

   

   if(ob->query("gender")=="����")

   return "���뵱�����������뵱���˵������˵����ô֪�����밡��... ...\n";

   if(ob->query_per()<29)

   return "���㳤��������ӣ��ĸ����˻ᱻ���Ի󣿣�\n";

   

   if(ob->query("couple"))

   return "����Ů�ӻ���������⣿������һ���������\n";

   

   if(ob->query("age")>60)

   return "�������Ҳ̫����˰ɣ�������������ˣ��ϲ�������İ���\n";

   

   if(ob->query("class")=="bonze"){

     command("kao1");

     return "�����Ҳ��������ʲô��������... ...\n";

   }

   

   ob->set_temp("do_mghs_quest1",1);

   return RANK_D->query_respect(ob)+"���Ķ��ˣ�Ҫ�����װ�������һ���Ĺ���ѧ��ѧ����\n";

}



int is_apprentice_of(object ob)

{

   return 1;

}



int recognize_apprentice(object ob)

{

   return 1;

}



int prevent_learn(object me, string skill)

{

    if(skill!="meigong-huanshu")

    return 1;

    if(!me->query("dtsl_quest_meigong-huanshu"))

    return 1;

    if(me->query_skill("meigong-huanshu",1)>me->query_per()*6)

    return 1;

    

    return 0;

}



int do_answer(string arg)

{

   object ob;

   

   ob=this_player();

   

   if(!ob->query_temp("do_mghs_quest1")){

     return 0;

   }

   if(arg!="ѧ"){

     command("say �㵽����˵ʲô����");

     return 1;

   }

   

   ob->set("dtsl_quest_meigong-huanshu",1);

   command("say �ã��Ժ���ͺ���ѧϰ���Ĺ����������Ժ����µ����Ӷ����������֮�У�");

   return 1;

}

