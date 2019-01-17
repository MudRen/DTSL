#include <ansi.h>
inherit NPC;

int do_kiss(string arg);
int do_sleep(string arg);

mapping *npcnames=({
([
"name":"����",
"id1":"chun",
"id2":"feng",
]),	
([
"name":"С��",
"id1":"xiao",
"id2":"yue",
]),
([
"name":"�ٻ�",
"id1":"bai",
"id2":"hua",
]),
([
"name":"����",
"id1":"ru",
"id2":"yue",
]),
([
"name":"����",
"id1":"cui",
"id2":"ling",
]),
	
	
	
});

void create()
{
   mapping names;
   
   names = npcnames[random(sizeof(npcnames))];
   
   set_name(names["name"],({ names["id1"]+" "+names["id2"],names["id1"],names["id2"] }) );
   set("gender", "Ů��" );
   set("age", 22);
   set("long", "����һ���糾Ů�ӡ�\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("per", 28);
   set("attitude", "friendly");
   set("chat_chance",10);
   set("chat_msg",({
    query("name")+"΢΢Ц������Ǯ�Ĵ�ү���������ף�qin "+names["id1"]+"���Ұ���\n",
    query("name")+"Ц������Ǯ�Ĵ�ү���ҿ��Ժ���˯����shuijiao "+names["id1"]+"���ģ�\n",
   }));

   setup();
   
  
}

void init()
{
  add_action("do_kiss","qin");
  add_action("do_sleep","shuijiao");
}

int do_kiss(string arg)
{
  object me,ob;string str;
  int money;
  
  me=this_player();
  ob=this_object();
  money = 0;
  
  if(!arg)
  return notify_fail("��ſ�ڵ��ϣ�����"+query("name")+"�Ľ�һ�¡�\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("������������𣿣�\n");
  if(ob!=this_object())
  return notify_fail(query("name")+"�������٣����ʲô�أ���\n");
  if(me->query("gender")=="Ů��")
  return notify_fail(query("name")+"һЦ�����Ҵ�����ˣ�\n");
  if(me->query("gin")<200)
  return notify_fail(query("name")+"Ц�����������ӣ�ûʲô���񣬵Ȼ�ɣ�\n");
  if(me->is_busy())
  return notify_fail(query("name")+"һЦ���㻹��ЪЪ�ɣ�����̰�İ���\n");
  if(me->is_fighting())
  return notify_fail(query("name")+"���Ա�һ�����㻹���ȴ��̰ɣ�\n");
  if(me->query_per()<10){
  	message_vision("$N��$nһ��ü���㳤�úö��İ���Ǯ�ɵ����㣡\n",ob,me);
  	money += 5000;
  	
  }
  if(me->query_per()<20){
  	message_vision("$N��$n΢΢һ��ü��������ò��Ǯ�ɵ����㣡\n",ob,me);
  	money += 4000;
  	
  }	
  if(me->query_per()<26){
  	message_vision("$N��$n΢΢һЦ��"+RANK_D->query_respect(me)+",��û�����Ǯ�����ɣ�\n",ob,me);
  	money += 3000;
  	
  }
  if(me->query_per()<31){
  	message_vision("$N����΢΢һ�죬��$n������"+RANK_D->query_respect(me)+",�㻵���㻵��\n",ob,me);
  	money += 2000;
  }
  else{
  	message_vision("$Nһ�����Σ��ߴ��ض�$n˵������ʶ"+RANK_D->query_respect(me)+"�������ˣ����ҵĸ�����\n",ob,me);
  	money += 1000;
  } 
  switch(MONEY_D->player_pay(me, money)){
  	case 0:
  	case 2:
  		message_vision("$N��$n�����������һ�ε��ó���"+MONEY_D->money_str(money)+"��������Ʊ���յģ�\n",ob,me);
  		command("heng "+me->query("id"));
  		return 1;
  }	
  message_vision("\n$N���������$n��$N����������һ�ڡ�\n",ob,me);
  me->add("gin",-200);
  me->start_busy(2);
  return 1;
}

int do_sleep(string arg)
{
  object me,ob;string str;
  int money;
  
  me=this_player();
  ob=this_object();
  money = 0;
  
  if(!arg)
  return notify_fail("��ſ�ڵ��ϣ�����"+query("name")+"�Ľ�һ�¡�\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("������������𣿣�\n");
  if(ob!=this_object())
  return notify_fail(query("name")+"�������٣����ʲô�أ���\n");
  if(me->query("gender")=="Ů��")
  return notify_fail(query("name")+"һЦ�����Ҵ�����ˣ�\n");
  if(me->query("gin")<200||me->query("kee")<200)
  return notify_fail(query("name")+"Ц�����������ӣ�ûʲô���񣬵Ȼ�ɣ�\n");
  if(me->is_busy())
  return notify_fail(query("name")+"һЦ���㻹��ЪЪ�ɣ�����̰�İ���\n");
  if(me->is_fighting())
  return notify_fail(query("name")+"���Ա�һ�����㻹���ȴ��̰ɣ�\n");
  if(me->query_per()<10){
  	message_vision("$N��$nһ��ü���㳤�úö��İ���Ǯ�ɵ����㣡\n",ob,me);
  	money += 50000;
  	
  }
  if(me->query_per()<20){
  	message_vision("$N��$n΢΢һ��ü��������ò��Ǯ�ɵ����㣡\n",ob,me);
  	money += 40000;
  	
  }	
  if(me->query_per()<26){
  	message_vision("$N��$n΢΢һЦ��"+RANK_D->query_respect(me)+",��û�����Ǯ�����ɣ�\n",ob,me);
  	money += 30000;
  	
  }
  if(me->query_per()<31){
  	message_vision("$N����΢΢һ�죬��$n������"+RANK_D->query_respect(me)+",�㻵���㻵��\n",ob,me);
  	money += 20000;
  }
  else{
  	message_vision("$Nһ�����Σ��ߴ��ض�$n˵������ʶ"+RANK_D->query_respect(me)+"�������ˣ����ҵĸ�����\n",ob,me);
  	money += 10000;
  }
  switch(MONEY_D->player_pay(me, money)){
  	case 0:
  	case 2:
  		message_vision("$N��$n���������˯һ�ε��ó���"+MONEY_D->money_str(money)+"��������Ʊ���յģ�\n",ob,me);
  		command("heng "+me->query("id"));
  		return 1;
  }
  message_vision(CYN"$nӵ����$N������$Nһ��������ǣ�\n"+
                "$N������$n�Ļ�����к������������Ͻ������ޣ�\n"NOR,me,ob);
  call_out("step2",2,me,ob);
        return 1;
}

int step2(object me, object who)
{
        if(me->query("gender") == "����" ) 
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,me,who);
        else
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,who,me);

        call_out("remove_cloth",1,me);
        call_out("remove_cloth",1,who);
        call_out("step3",3,me,who);
        return 1;
}

int step3(object me, object who)
{
        message_vision(MAG"$N��$n�������Ҹ��ĺ������������������������\n"NOR,me,who);
        call_out("step4",2,me,who);
        return 1;
}

int step4(object me, object who)
{
        if(me->query_condition("xxx"))
                me->clear_condition("xxx");
        if(who->query_condition("xxx"))
                who->clear_condition("xxx");

        me->receive_damage("gin",me->query("max_gin")/2);
        me->receive_damage("kee",me->query("max_kee")/2);

        who->receive_damage("gin",who->query("max_gin")/2);
        who->receive_damage("kee",who->query("max_kee")/2);
       message_vision(HIW"����һ���ָֻ���ƽ����\n"NOR,me,who);
       
        return 1;
}

int remove_cloth(object me)
{
        object *inv;
        string str;
        int i;
        // remove all staff before sleepping :P
        inv = all_inventory(me);
        for(i=0; i < sizeof(inv); i++ ) {
            if( inv[i]->query("equipped") == "worn" ) {
                if( inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("remove_msg")) )
                        switch(inv[i]->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N��$n����������\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N��$n���˿ڴ�����������\n" NOR;
                                        break;
                                default:
                                        str = YEL "$Nж��$n��װ����\n" NOR;
                        }
                message_vision(str, me, inv[i]);
                }
            } else if ( inv[i]->query("equipped") == "wielded" ) {
                if(inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("unwield_msg") )) 
                        str = YEL "$N�������е�$n��\n" NOR;
                message_vision(str, me, inv[i]);
                }
            }
        }
}
