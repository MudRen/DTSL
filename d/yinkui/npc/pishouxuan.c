
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_quest1();
int do_tell(string arg);

void create()
{
   int i;
   object *ob;
   
   set_name("������",({ "pi shouxuan","pi","shouxuan" }) );
        set("gender", "����" );
	set("nickname","����˫��");
        set("age",46);
   set("long", "����������Ԫ�ϼ��ĸ��֡�\n");
       
   set("combat_exp",1000000);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",400);
   set_skill("strike",400);
   set_skill("qianbian-tongxiao",400);
   set_skill("sword",400);
   set_skill("literate",400);
   set_skill("tianmo-dafa",400);
   set_skill("tianmo-jue",400);
   set_skill("tianmo-huanzong",400);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   set("perform_quest/wanhuan",1);
   create_family("������",3,"����");
   set("inquiry",([
       "������":(:do_quest1:),
      
      ]));
   setup();
   
   ob=children(__DIR__"obj/tongxiao");
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
   carry_object(__DIR__"obj/tongxiao")->wield();
  
}

void init()
{
   add_action("do_tell","gaosu");
}
void attempt_apprentice(object ob)
{
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	if(ob->query("gender")=="Ů��"){
	
	command("say �Ҳ���Ů���ӵģ����������Ͷ�뱾�ɣ�ȥ�ҵ�÷�ɣ�\n");
	return;
        }
        if(ob->query_skill("tianmo-dafa",1)<150){
        command("say �����ħ����Ϊ������������ȥ��ϰһ���ٰ���Ϊʦ�ɣ�\n");
        return;
        }
               
        if(ob->query("office_number")<50){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        if(ob->query("bellicosity")<1000){
        command("say ���ɱ��̫���ˣ�\n");
        return;
        }
        
        lev=ob->query_skill("strike",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("sword",lev);
        tell_object(ob,HIY"��ӻ����Ʒ������Ե��˻���������\n"NOR);
        
	command("say �ã�ϣ���㽫����һͳħ��������������������\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin3");
}

int accept_ansuan(object me,int flag)
{
    if(flag==2)
     set("ansuan_ob",me);
    if(flag==1)
     set("ansuan_ob_ok",me);
    return 1;
}

int do_quest1()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(query("ansuan_ob")==ob){
     msg="$N��$n�ȵ���"+RANK_D->query_rude(ob)+"����ոհ����ң����ڻ�������\n"+
         "�����ɣ���\n";
     message_vision(msg,this_object(),ob);
     kill_ob(ob);
     return 1;
   }
   if(query("ansuan_ob_ok")!=ob){
     command("say �ղ��ұ����˰����ˣ����ǵ�ù��");
     return 1;
   }
   if(ob->query_skill("qianbian-tongxiao",1)<160){
     command("say ������������ʲô�����ʲô��");
     return 1;
   }
   ob->set_temp("wanhuan_quest1",1);
   command("say ʦ���ղű��˰��㣬��Ҫ���С������кк��\n������ʱ�������һ����");
   return 1;
}

int do_tell(string arg)
{
   object ob,target,obj;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("wanhuan_quest1"))
   return notify_fail("�������������������߿���\n");
   if(!arg)
   return notify_fail("������������Ҫ˵ʲô�Ϳ�㣡\n");
   if(arg!="����������")
   return notify_fail("������������������ֻ�������㣬����ʲô�����ܣ�\n");
   if(!objectp(target=present("you qiuyan",environment(ob))))
   return notify_fail("���������������������أ�\n");
   
   msg="\n$N¶��Ц�ݣ�����$t���ֳ�������ȥ��$t��ͷ����$nһ�ۡ�\n";
   msg +="\n����һ�ᣬ$t�������߳�����������Щ���ң���æ����$nһ���ţ�"+
         "Ȼ��ת�����ˡ�\n\n";
   msg=replace_string(msg,"$t",target->name());
   message_vision(msg,this_object(),ob);
   destruct(target);
   obj=new(__DIR__"obj/letter");
   obj->move(ob);
   ob->delete_temp("wanhuan_quest1");
   return 1;
}

int accept_object(object ob,object obj)
{
   string msg;
   
   if(!obj->query("wanhuan_quest"))
   return 0;
   
   msg="$N¶���־�ı��飬��$n̾���������ǳ���������ǰ�ˣ�\n"+
       RANK_D->query_respect(ob)+"�ܲ��ܷ���һ�Σ�\n\n";
   msg +="$N��$n������������������Ĺ���ѧ����ô���ˣ�\n\n";
   message_vision(msg,this_object(),ob);
   ob->set_temp("wanhuan_quest2",1);
   fight_ob(ob);
   return 1;
}

int end_fight(object killer,object victim)
{
    if(!victim->query_temp("wanhuan_quest2"))
    return 1;
    message_vision("$N��$n��Цһ������֪��������̫���ˣ������ɣ�\n",
          killer,victim);
    kill_ob(victim);
    return 1;
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("wanhuan_quest2"))
    return 1;
   message_vision("$N��$n��̾һ�������ˣ����ˣ����Ҿʹ��ڸ���ǧ��ͭ���ľ�ѧ�ɣ�\n",
                victim,killer);
   if(killer->query("perform_quest/lingxiao")){
     command("say ���Ѿ��������ħն�ľ��ϣ��޷������ǧ��ͭ���ľ����ˣ�");
     return 1;
   }
   if(killer->query("perform_quest/yulong")){
     command("say ���Ѿ��������ħ���ľ��ϣ��޷������ǧ��ͭ���ľ����ˣ�");
     return 1;
   }
   if(killer->query_skill("tianmo-zhen",1)){
     command("say ��ѧ����ħ���޷���ѧϰǧ��ͭ���ľ����ˣ�");
     return 1;
   }
   message_vision("$N���յ�Ц��Ц������������ǧ��ͭ���ľ�ѧ��\n",killer);
   killer->set("perform_quest/wanhuan",1);
   killer->save();
   return 1;
}
