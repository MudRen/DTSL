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
   set_name(HIR"���"NOR,({ "li guan","li","guan"}) );
        set("gender", "����" );
        set("long","��λ�Ǵ���˫������٣������������Ŀ��˷����\n"+
                   "������� ask li about ����˫�� ��Ҫ���\n");
        set("age", 32);
        set("inquiry",([
        "����˫��":(:give_skill:),
        "�����":(:give_present_zqj:),
        "ʥ����":(:give_present_sdj:),
//        "Ԫ��":(:give_present_yd:),
        "����":(:give_present_cj:),
        "����":(:give_box:),
        "����":(:give_box:),
//        "��������":(:change_age:),
       
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
  return "��ľ����Ѿ��ܸߣ������Լ�ȥ���������ɣ�\n";
  if(ob->query("gived_gift"))
  return "���Ѿ����������ˣ���Ҫ��ô̰�ġ�\n";
  
  if(is_busy())
   return "���Ե�... ...\n";
  
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
  
  message_vision(YEL"$N��������˫�ƣ����Լ��Ĳ��ֹ���ע�뵽��$n���ڣ�\n"NOR,this_object(),ob);
  return NOR+CYN+"��ֻ�ܰ�����ô�࣬ϣ�����Ժ�������������Ϊ��\n"NOR;
}

int accept_fight(object ob)
{
  return notify_fail("���һЦ���ҿ��Ǵ������ͱ��˴��̵ģ�\n");
}
int accept_kill(object killer,object victim)
{
  message_vision(MAG"$NͻȻ����һ����һ��������$n�����ȥ��\n"NOR,victim,killer);
  killer->unconcious();
  return notify_fail("��ٺٺ�Ц�˼���... ...\n"); 
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
  message_vision("$N�Ǻ�һЦ�������ˣ���ô�����˷������أ�\n",this_object());
  return;
}
string give_present_zqj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!ZQJ)
   return "���첻������ڰ���";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"��ľ��鲻��"+HIY+"200,000"+NOR+CYN+",���޷��������������ף������ڿ��֣�\n";
  if(ob->query("feast/zhongqiujie"+YEAR))
  return NOR+CYN"�±����Ѿ������ˣ��Ͽ������һ��԰ɣ�\n"NOR;
  ob->set("feast/zhongqiujie"+YEAR,1);
  thing=new(__DIR__"obj/yuebing");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"��ٸ�����һ���±���\n"NOR);
  return HIC"ף������ڿ��֣��ϼ���Բ��\n"NOR;
}

string give_present_sdj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!SDJ)
   return "���첻��ʥ���ڰ���";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"��ľ��鲻��"+HIY+"200,000"+NOR+CYN+",���޷��������������ף������ڿ��֣�\n";
  if(ob->query("feast/shengdanjie"+YEAR))
  return NOR+CYN"ʥ�����������Ѿ������ˣ���̫̰���ˡ�\n"NOR;
  ob->set("feast/shengdanjie"+YEAR,1);
  thing=new(__DIR__"obj/wazi");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"��ٸ�����һ˫���ӡ�\n"NOR);
  return HIC"ף��ʥ���ڿ��֣�\n"NOR;
}

string give_present_yd()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!YD)
   return "���첻��Ԫ������";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"��ľ��鲻��"+HIY+"200,000"+NOR+CYN+",���޷��������������ף������ڿ��֣�\n";
  if(ob->query("feast/yuandan"+YEAR))
  return NOR+CYN"Ԫ���������Ѿ������ˣ���̫̰���ˡ�\n"NOR;
  ob->set("feast/yuandan"+YEAR,1);
  thing=new(__DIR__"obj/libao");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"��ٸ�����һ�������\n"NOR);
  return HIC"ף��Ԫ�����֣�\n"NOR;
}

string give_present_cj()
{
  object ob;
  object thing;
  
  ob=this_player();
  
  if(!CJ)
   return "���첻�Ǵ��ڰ���";
  
  //if(ob->query("combat_exp")<200000)  
  //return NOR+CYN"��ľ��鲻��"+HIY+"200,000"+NOR+CYN+",���޷��������������ף������ڿ��֣�\n";
  if(ob->query("feast/chunjie"+YEAR))
  return NOR+CYN"�����������Ѿ������ˣ���̫̰���ˡ�\n"NOR;
  ob->set("feast/chunjie"+YEAR,1);
  thing=new(__DIR__"obj/bianpao");
  thing->set("owner_ob",ob);
  thing->move(ob);
  tell_object(ob,YEL"��ٸ�����һ�����ڡ�\n"NOR);
  return HIC"ף�㴺�ڿ��֣�\n"NOR;
}

int change_age()
{
	object ob;
	
	ob=this_player();
	if(ob->query("age")<=15||ob->query("change_age")){
	  tell_object(ob,"�����䲻�õ����ˡ�\n");
	  return 1;
	}
	ob->set("change_age",1);
	ob->set("mud_age",522000);
	tell_object(ob,"�����µ�¼��Ϸ�������ָ�������\n");
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
   return "�Բ�����ֻ�����ܵ�����ʧ����ҡ�\n";
   if(ob->query("gived_buchang"))
   return "��ֻ�ܸ�ÿ����һ�β����Ļ��ᡣ\n";
   ob->add("combat_exp",100000);
   skl=ob->query_skills();
   if(mapp(skl)){
  skills=keys(skl);
 for(i=0;i<sizeof(skills);i++){
  ob->set_skill(skills[i],ob->query_skill(skills[i],1)+5);}
}
  ob->set("gived_buchang",1);
  return CYN+"�ܱ�Ǹ�����ڱ��ε�����������ʧ��\n"+
         "�صز�����100000�㾭�飬ÿ�������弶��ϣ���ڴ���˫����Ŀ��ģ�\n";
}
*/
/*
string give_pot()
{
   object ob;
   
   ob=this_player();
   if(ob->query("age")<11)
   return "������̫С�ˣ����ڲ�����Χ֮�ڡ�\n";
   if(ob->query("gived_buchang_pot"))
   return "��ֻ��һ�β����ġ�\n";
   ob->add("potential",2000);
   ob->set("gived_buchang_pot",1);
   return CYN"���Ƿǳ���Ǹ�����صز������ǧ��Ǳ�ܣ�\n";
}
*/
/*
string do_change_skill()
{
    object ob;
    int skill;
    
    ob=this_player();
    if(ob->query("family/family_name")!="������"&&
    ob->query("family/family_name")!="������")
    return CYN"��ûʲô����ɻ��ǲ�Ҫ�������ˣ�\n";
    if(ob->query("family/family_name")=="������"&&
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
    return CYN"����ת����ϣ������鷳���ˣ�\n";
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
     return "���Ӳ��Ǹ���ģ���ֻ��������ʿ���ҡ�\n���Ѿ��������ң�����ô̰���ˡ�\n";
   box=new("/d/clone/obj/elite/box");
   if(!box->move(ob))
     return "�����ϵĶ���̫���ˣ�\n";
   message_vision("$N����$nһ�����ҡ�\n",this_object(),ob);
   return "һ��������ʿ��ʲô���ӣ�����һ�����Ұɣ�\n������ҿ��Դ�������Ʒ����С�ı��ܣ�\n";
}

