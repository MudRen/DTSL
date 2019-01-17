
#include <ansi.h>
#include <org.h>

inherit F_SAVE;
inherit ROOM;

#define LEV1 "���"
#define LEV2 "��ر�"
#define LEV3 "����"
#define LEV4 "��ʿ��"
#define LEV5 "���"

#define LEV1_MONEY 100
#define LEV2_MONEY 200
#define LEV3_MONEY 200
#define LEV4_MONEY 200
#define LEV5_MONEY 200

#define LEV1_TRAIN 50
#define LEV2_TRAIN 50
#define LEV3_TRAIN 50
#define LEV4_TRAIN 50
#define LEV5_TRAIN 50

#define LEV1_SUPPLY 10
#define LEV2_SUPPLY 50
#define LEV3_SUPPLY 50
#define LEV4_SUPPLY 50
#define LEV5_SUPPLY 50

#define SMALL_CITY_TAX  15000
#define MIDDLE_CITY_TAX 20000
#define BIG_CITY_TAX    40000

string *zainan=({
"��������","��������","����ˮ��","�ֻȳ�","�����ɺ�","��������","��������",
});

string *goods=({
"����","��ѩ�׷���",
});

string query_save_file()
{
  return "/data/orgroom/"+query("city_id");
}

int is_city_war_room()
{
  return 1;
  
}

void setup()
{
  set("guard_person",query("lev1_guard")*LEV1_SUPPLY+query("lev2_guard")*LEV2_SUPPLY+
   query("lev3_guard")*LEV3_SUPPLY+query("lev4_guard")*LEV4_SUPPLY+
   query("lev5_guard")*LEV5_SUPPLY);
  
  if(query("owner")=="wizard"){
   set("lev1_guard",5);
   set("lev2_guard",5);
   set("lev3_guard",5);
   set("lev4_guard",5);
   set("lev5_guard",5);
  }
  
  ::setup();
  
}


void reset()
{
  
  int g_num;
  int deposit,tax;
  int no_reward=0;
  int extra_reward;  
  string msg="";
  object sboard;
  
  if(query("city_time")>=80&&query("owner")!="wizard"){
    set("city_time",0);
    g_num=query("guard_person");
    
    if(query("city_type")=="С"){
      add("deposit",-1-random(g_num/100));
    }
    else
    if(query("city_type")=="�е�"){
      add("deposit",-4-random(g_num/100));
    }
    else{
     add("deposit",-8-random(g_num/100));
    }
    
    if(query("deposit")<0)
     set("deposit",0);
     
    deposit=query("deposit");
    tax=query("tax")-query("zhili_tax");
    
    if(deposit>300) deposit=300;
    if(random(deposit+tax)>deposit){
     if(query("person")>0){
       add("person",-30-random(10));
        if(query("person")<0)
        set("person",0);
       msg=query("city_name")+"��Ϊ˰�ʹ��ߣ��˿ڼ����ˣ�\n";
     }
     no_reward=1;
    }
    else{
     add("person",30+random(10));
      if(query("person")>query("max_person"))
        set("person",query("max_person"));
      add("zhongcheng_du",30+random(10));
     msg=query("city_name")+"��˰�ʺ������յ���������ʣ�ʿ�����ҳ϶�����ˡ�\n";
    }         
        
    if((g_num>0&&(query("deposit")<g_num/5))||query("deposit")<=0){
      if(query("lev1_guard")>0){      	
       add("lev1_guard",-1);
       add("guard_person",-LEV1_SUPPLY);
      }
      else
      if(query("lev2_guard")>0){      	
       add("lev2_guard",-1);
       add("guard_person",-LEV2_SUPPLY);
      }
      else
      if(query("lev3_guard")>0){      	
       add("lev3_guard",-1);
       add("guard_person",-LEV3_SUPPLY);
      }
      else
      if(query("lev4_guard")>0){      	
       add("lev4_guard",-1);
       add("guard_person",-LEV4_SUPPLY);
      }
     else
     if(query("lev5_guard")>0){      	
       add("lev5_guard",-1);
       add("guard_person",-LEV5_SUPPLY);
     }
      
      no_reward=1;
      msg +="��Ϊ"+query("city_name")+"��ʳ��ȱ�������в���ʿ����ʼ�����ˣ�";
      
    }
   
   if(!no_reward){
     sboard=load_object(BOARD_PATH+query("owner"));
     if(sboard){
       if(query("city_type")=="С"){
        sboard->add("money",tax*SMALL_CITY_TAX);
        sboard->add("exp",query("lev1_guard")*50);
       }
       else
       if(query("city_type")=="�е�"){
        sboard->add("deposit",tax*MIDDLE_CITY_TAX);
        sboard->add("exp",query("lev1_guard")*100);
       }
       else{
        sboard->add("deposit",tax*BIG_CITY_TAX);
        sboard->add("exp",query("lev1_guard")*200);
       }
       sboard->save();
     }
   }
   
   CHANNEL_D->do_channel(this_object(),"rumor",msg);
   
  }
  else
  if(query("city_time")==60&&query("owner")!="wizard"){
    
    if(query("city_type")=="С"){
        extra_reward=90;
    }
    else
    if(query("city_type")=="�е�"){
     extra_reward=75;
    }
    else{
     extra_reward=65;
    }
    if(random(extra_reward)>=60){
      msg=query("city_name")+"�ջ��ز���ȫ��һƬ���ڣ�\n";
      sboard=load_object(BOARD_PATH+query("owner"));
      if(sboard){
      	sboard->add("money",(100-extra_reward)*query("person")*10);
      	sboard->save();
      }
      CHANNEL_D->do_channel(this_object(),"rumor",msg);
    }
  }
  else
  if(query("city_time")==40&&query("owner")!="wizard"&&random(100)>0){
   
   if(random(100)>=40){ 
    msg=query("city_name")+zainan[random(sizeof(zainan))]+"��";
    switch(random(2)){
     case 0:
      add("person",-80-random(80));
      if(query("person")<0)
        set("person",0);
      msg+="�����˿ڽ����ˣ�\n";
      break;
    case 1:
     add("deposit",-8-random(8));
      if(query("deposit")<0)
        set("deposit",0);
      msg+="������ʳ���������ˣ�\n";
    }
    CHANNEL_D->do_channel(this_object(),"rumor",msg);
   }
   else{
    msg=query("city_name")+goods[random(sizeof(goods))]+"��";
    switch(random(2)){
     case 0:
      add("person",80+random(80));
      if(query("person")>query("max_person"))
        set("person",query("max_person"));
      msg+="�����˿�����ˣ�\n";
      break;
    case 1:
     add("deposit",8+random(8));     
      msg+="������ʳ��������ˣ�\n";
    }
    CHANNEL_D->do_channel(this_object(),"rumor",msg);
   }
  }  	
    
    
  
  add("city_time",1);
  
  save();
  ::reset();
  
}

void init()
{
  add_action("do_victory",({"victory","zhanling"}));
  add_action("do_zhubing","zhubing");
  add_action("do_check",({"check","chakan"}));
  add_action("do_deposit","deposit");
  add_action("do_chebing","chebing");
  add_action("do_train",({"train","lianbing"}));
  add_action("do_move_guard","diaobing");
  add_action("do_tax","zhishui");
  add_action("do_help","helpcity");
  add_action("do_wuzhuang","wuzhuang");
  add_action("do_chubing","chubing");
  add_action("do_shoubing","shoubing");

}

void rid_no_report()
{
  delete("no_report");
  save();
}

void check_victory()
{
   object *ob;
   int i;
   
   delete("check_victory");
   message("vision",HIR"�������ơ���ս���硣�"+query("city_name")+"��ս����ͣ������˫�������ձ���\n"NOR,users());
   
   ob=all_inventory(this_object());
   
   for(i=0;i<sizeof(ob);i++)
    if(ob[i]){
      if(!userp(ob[i]))
       destruct(ob[i]);
      else
       ob[i]->remove_all_killer();
    }
   
   set("war_busy",time());
   save();
   
   return;
}

int do_victory()
{
   object ob;
   object guard1,guard2,guard3,guard4,*guards;
   int i,flag=0;
   
   ob=this_player();
   
if(ob->query("combat_exp")<500000)
return notify_fail("ֻ�о���ﵽ 500K ����ܹ������!\n");
   if(time()-query("war_busy")<3600*5)
   return notify_fail("������ٹ�һ��ſ��Թ���"+query("city_name")+"��\n");
   
   if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
   if(query("owner")==ob->query("shili/name"))
   return notify_fail("�����Ѿ���"+HIY+ORG_D->get_shili(ob)+NOR+"���ˣ�\n");
   
   if(ORG_D->is_friend_org(ob,this_object()))
   return notify_fail("�㲻�ܽ������ѵĳ��У�\n");
   
   remove_call_out("start_zhubing");
   
   if(!query("no_report")){    
    message("vision",HIR"�������ơ�������ս����ȼ��"NOR+HIY+ORG_D->get_shili(ob)+HIR+"��ʼ����"+query("city_name")+"�ˣ�\n"NOR,users());
    remove_call_out("rid_no_report");
    set("no_report",1);
    save();
    call_out("rid_no_report",30);
   }
   else{
    delete("no_report");
    tell_object(this_object(),HIY+ORG_D->get_shili(ob)+NOR+"��ʼ����"+query("city_name")+"�ˣ�\n");
    save();
   }
   
   if(!query("check_victory")){
      set("check_victory",1);
      remove_call_out("check_victory");
      call_out("check_victory",300);
   
       
    if(query("lev1_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev1_guard",-1);
     guard1->set_status(1,"lev1",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev2_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev2_guard",-1);
     guard1->set_status(1,"lev2",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev3_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev3_guard",-1);
     guard1->set_status(1,"lev3",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev4_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev4_guard",-1);
     guard1->set_status(1,"lev4",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev5_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev5_guard",-1);
     guard1->set_status(1,"lev5",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
   }
   guards=all_inventory(this_object());
   
   for(i=0;i<sizeof(guards);i++)
    if(guards[i]&&guards[i]->query("shili/name")==query("owner")
     &&guards[i]->query("age")>=13){
    	flag=1;
    	break;
    }
    
  
   if(flag)
    return notify_fail("�㻹�Ȱѵ���ɱ��ɣ�\n");
   
   remove_call_out("check_victory");
   
   message("vision",HIR"�������ơ���һ��ս��ƽϢ��"NOR+HIY+ORG_D->get_shili(ob)+HIR+"�Ѿ�ռ����"+query("city_name")+"��\n"NOR,users());
   
   set("owner",ob->query("shili/name"));
   set("shili/name",ob->query("shili/name"));
   delete("check_victory");
   delete("no_report");
   delete("lev1_guard");
   delete("lev2_guard");
   delete("lev3_guard");
   delete("lev4_guard");
   delete("lev5_guard");
   delete("city_time");
   delete("money");
   delete("lev1_guard_trains");
   delete("lev2_guard_trains");
   delete("lev3_guard_trains");
   delete("lev4_guard_trains");
   delete("lev5_guard_trains");
   add("person",-query("person")/50);
   delete("guard_person");
   set("war_busy",time());
   save();
   
   return 1;
   
}

int do_zhubing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<300000)
   return notify_fail("ֻ�о���ﵽ�� 300��000 �ſ��Խ���פ����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>4)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+query("city_name")+NOR+"פ����\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||(arg!=LEV1)
   )
  return notify_fail("��ʹ�� zhubing "+LEV1+"��\n");
  
    if(sboard->query("money")<LEV1_MONEY)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��פ����\n");
    
    if(query("guard_person")>=query("person"))
    return notify_fail("�����������"+HIY+query("city_name")+NOR+"���˿ڣ������޷�פ����\n");
    
    if(query("do_zhubing")>=5)
    return notify_fail("���в���һ��פ��̫���������һ��ɣ�\n");
    
    add("do_zhubing",1);
    
    tell_object(ob,"�������"+HIY+query("city_name")+NOR+"פ��һЩ������\n");
    
    call_out("start_zhubing",180,ob->name(),ob->query("shili/name"),sboard);
        
    save();
    sboard->save();
  return 1;
  
}

void start_zhubing(string name,string org_name,object sboard)
{
  
  sboard->set("shili/name",org_name);
  CHANNEL_D->do_channel(sboard,"banghui",name+"��"+query("city_name")+"פ����һЩ"+LEV1+"��\n");
  
  sboard->add("money",-LEV1_MONEY);
  add("lev1_guard",1);
  add("guard_person",LEV1_SUPPLY);
  add("do_zhubing",-1);
  
  save();
  sboard->save();
  
}


int do_deposit(string arg)
{
  object ob;
  object sboard;
  int num;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<300000)
   return notify_fail("ֻ�о���ﵽ�� 300��000 �ſ��Խ��жڻ���ʳ��\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>4)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+query("city_name")+NOR+"�ڻ���ʳ��\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||sscanf(arg,"%d",num)!=1)
   return notify_fail("��Ҫ�ڻ����ٶ���ʳ��һ���ƽ�/����ʳ\n");
  
  if(num<=0)
   return notify_fail("��Ҫ���ң�\n");
  
  if(sboard->query("money")<num*10000)
   return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ���ڻ���ʳ��\n");
  
  sboard->set("shili/name",ob->query("shili/name"));
  CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"�ڻ���"+
     chinese_number(num)+"����ʳ��\n");
  sboard->delete("shili/name");
  
  sboard->add("money",-num*10000);
  sboard->save();
  add("deposit",num);
  save();
  
  return 1;
}

int do_train(string arg)
{
  object ob;
  object sboard;
  int num;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ���������\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
  
  if(!ob->query_skill("qianjun-shu",1))
   return notify_fail("�����ѧ�ᡸǧ�������ſ�����ϰʿ����\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+query("city_name")+NOR+"ѵ�����ӣ�\n");
  
  if(ob->query("vocation")!="ɱ��")
  return notify_fail("ֻ��ɱ�ֿ���ѵ��ʿ����\n");
  
  if(query("do_train")>=5)
   return notify_fail("�Ѿ���̫���������������������ɣ�\n");
  
  if(ob->query_temp("start_do_train"))
  return notify_fail("������ѵ��ʿ����\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||
     (arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
    )
  return notify_fail("��Ҫѵ����һ��ʿ����"+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"��\n");    
    
  if(arg==LEV2){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV2_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV2+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV2,1,environment(ob),LEV2_TRAIN);
     return 1;
  }
  else
  if(arg==LEV3){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV3_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV3+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV3,1,environment(ob),LEV3_TRAIN);
     return 1;
  }
  else
  if(arg==LEV4){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV4_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV4+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV4,1,environment(ob),LEV4_TRAIN);
     return 1;
  }
  else
  if(arg==LEV5){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"��û��פ��"+LEV1+"��\n");
    if(sboard->query("money")<LEV5_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"����û����ô��Ǯ��ѵ��"+LEV5+"��\n");
     
     tell_object(ob,"\n�㿪ʼѵ��ʿ����\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV5,1,environment(ob),LEV5_TRAIN);
     return 1;
  }
  
  return 1;
 
}

void start_train(object ob,object sboard,string level,int times,object where,int cost)
{
   if(!ob){
     add("do_train",-1);
     return;
   }
   if(environment(ob)!=where){
     tell_object(ob,"�������������\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(times>=30){
     tell_object(ob,"\n����ʿ����ͣ��������Ϣһ�¡�\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(sboard->query("money")<cost){
     tell_object(ob,HIY"\n���ǰ��Ĵ��������ˣ�\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   if(ob->query("gin")<=50){
    tell_object(ob,HIR"\n���ƣ����������ͣ������Ϣһ�¡�\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     return;
   }
   
   ob->receive_damage("gin",50);
   
   if(level==LEV2){
     add("lev2_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev2_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV2_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+query("city_name")+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev2_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev2_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"��"+level+"��ǿ�ˣ�\n");
     add("lev2_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV2_SUPPLY);
     set("lev2_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
  
  if(level==LEV3){
     add("lev3_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev3_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV3_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+query("city_name")+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev3_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev3_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"��"+level+"��ǿ�ˣ�\n");
     add("lev3_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV3_SUPPLY);
     set("lev3_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
 
 if(level==LEV4){
     add("lev4_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev4_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV4_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+query("city_name")+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev4_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev4_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"��"+level+"��ǿ�ˣ�\n");
     add("lev4_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV4_SUPPLY);
     set("lev4_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }     
  
  if(level==LEV5){
     add("lev5_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     if(query("lev5_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV5_SUPPLY>query("person")){
        tell_object(ob,"��ü������"+HIY+query("city_name")+NOR+"���˿��ˣ�\n");
        return;
      }
      if(query("lev5_guard")<query("apply/armor")/3){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"��װ���ˣ�\n");
       return;
      }
      if(query("lev5_guard")<query("apply/damage")/2){
       tell_object(ob,"������"+HIY+query("city_name")+NOR+"������װ���ˣ�\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"��"+level+"��ǿ�ˣ�\n");
     add("lev5_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV5_SUPPLY);
     set("lev5_guard_trains",0);
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }  
  
}
     

int do_move_guard(string arg)
{
  object ob,guard,*guards;
  object source_city;
  string city,type,guard_type;
  int num,i,j;
  int cost_type;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ��е�����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner")
   &&!ORG_D->if_friend_org(ob,source_city))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���Ҳ�������ͬ�ˣ�\n");
  
  if(!arg||sscanf(arg,"%s %d %s",city,num,type)!=3)
  return notify_fail("��Ҫ�����������ʲô�����ʿ������������(diaobing ���� ���� ʿ��)\n");
  
  if(!type||
     (type!=LEV1&&type!=LEV2&&type!=LEV3&&type!=LEV4&&type!=LEV5)
    )
  return notify_fail("��Ҫ������һ��ʿ����"+LEV1+" "+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"��\n");
  
  if(num<=0||num>=100)
  return notify_fail("��Ҫ���ң�����\n");
  
  source_city=load_object(__DIR__+city);
  if(!source_city)
  return notify_fail("Ŀǰ�����в����������ĳ��У�\n");
  
  if(source_city==this_object())
  return notify_fail("��Ҫ���ң�����\n");
  
  if(ob->query("shili/name")!=source_city->query("owner"))
  return notify_fail(HIY+source_city->query("city_name")+NOR+"����"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=source_city->query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+source_city->query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+source_city->query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܴ�"+HIY+source_city->query("city_name")+NOR+"������\n");
  
  if(type==LEV1) guard_type="lev1";
  else
  if(type==LEV2) guard_type="lev2";
  else
  if(type==LEV3) guard_type="lev3";
  else
  if(type==LEV4) guard_type="lev4";
  else
  if(type==LEV5) guard_type="lev5";
  
  if(type==LEV1) cost_type=LEV1_SUPPLY;
  else
  if(type==LEV2) cost_type=LEV2_SUPPLY;
  else
  if(type==LEV3) cost_type=LEV3_SUPPLY;
  else
  if(type==LEV4) cost_type=LEV4_SUPPLY;
  else
  if(type==LEV5) cost_type=LEV5_SUPPLY;  
  
  if(num>source_city->query(guard_type+"_guard"))
  return notify_fail("Ŀǰ"+HIY+source_city->query("city_name")+NOR+"û����ô������͵�ʿ����\n");
  
  if(query("guard_person")+num*cost_type>query("person"))
    return notify_fail("�����������"+HIY+query("city_name")+NOR+"���˿ڣ������޷�����������\n");
      
  if(query("check_victory")){
    guard=new(__DIR__"npc/guard");
    guard->set_status(num,guard_type,source_city->query("apply/armor"),source_city->query("apply/damage"),source_city->query("owner"));
    guard->move(environment(ob));
  }
  add(guard_type+"_guard",num);  
  source_city->add(guard_type+"_guard",-num);
  add("guard_person",num*cost_type);
  source_city->add("guard_person",-num*cost_type);
  
  save();
  source_city->save();
  
  guards=all_inventory(source_city);
  
  for(i=0,j=0;i<sizeof(guards);i++){
    if(!userp(guards[i])&&guards[i]->query(guard_type)
      &&guards[i]->query("shili/name")==source_city->query("owner")){
     j++;
     destruct(guards[i]);
    }
    if(j>=num) break;
  }
  
  CHANNEL_D->do_channel(this_object(),"rumor","��˵��һ֧���Ӵ�"+source_city->query("city_name")+
   "��������"+query("city_name")+"��\n");
  
  return 1;

}
            

int do_chebing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ��г�����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>3)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+query("city_name")+NOR+"������\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("���������⣬�뱨����ʦ��\n");
  
  if(!arg||
   (arg!=LEV1&&arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
   )
  return notify_fail("��ʹ�� chebing "+LEV1+"/"+LEV2+"/"+LEV3+"/"+LEV4+"/"+LEV5+"��\n");
  
  if(arg==LEV1){
    
    if(query("lev1_guard")<=0)
    return notify_fail(query("city_name")+"û��פ��"+LEV1+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"������һЩ"+LEV1+"��\n");
    sboard->add("money",LEV1_MONEY/3);
    add("lev1_guard",-1);
    add("guard_person",-LEV1_SUPPLY);
    save();
    
  }
  if(arg==LEV2){
    if(query("lev2_guard")<=0)
    return notify_fail(query("city_name")+"û��פ��"+LEV2+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"������һЩ"+LEV2+"��\n");
    sboard->add("money",LEV2_MONEY/3);
    add("lev2_guard",-1);
    add("guard_person",-LEV2_SUPPLY);
    save();
    
  }
  if(arg==LEV3){
    if(query("lev3_guard")<=0)
    return notify_fail(query("city_name")+"û��פ��"+LEV3+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"������һЩ"+LEV3+"��\n");
    sboard->add("money",LEV3_MONEY/3);
    add("lev3_guard",-1);
    add("guard_person",-LEV3_SUPPLY);
    save();
    
  }
  if(arg==LEV4){
    if(query("lev4_guard")<=0)
    return notify_fail(query("city_name")+"û��פ��"+LEV4+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"������һЩ"+LEV4+"��\n");
    sboard->add("money",LEV4_MONEY/3);
    add("lev4_guard",-1);
    add("guard_person",-LEV4_SUPPLY);
    save();
    
  }
  if(arg==LEV5){
    if(query("lev5_guard")<=0)
    return notify_fail(query("city_name")+"û��פ��"+LEV5+"��\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"��"+query("city_name")+"������һЩ"+LEV5+"��\n");
    sboard->add("money",LEV5_MONEY/3);
    add("lev5_guard",-1);
    add("guard_person",-LEV5_SUPPLY);
    save();
    
  }
  sboard->save();
  return 1;
  
}

int do_tax(string arg)
{
  object ob;
  int tax;
  string msg;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ�����˰��\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
  
  if(!ob->query_skill("dadao-qishu",1))
   return notify_fail("�����ѧ�ᡸ������项�ſ���������У�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>3)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܸ�"+HIY+query("city_name")+NOR+"����˰�ʣ�\n");
  
  if(time()-query("tax_busy")<15*60)
  return notify_fail("Ҫ��һ���Ӻ���ſ��Լ�������˰�ʣ�\n");
  
  if(!arg||sscanf(arg,"%d",tax)!=1)
  return notify_fail("��Ҫ��ε���˰�ʣ�zhishui ˰��(0-100)\n");
  
  if(tax<0||tax>100)
  return notify_fail("��Ҫ���ң���\n");
  
  if(query("tax")<tax) msg="�����";
  else
  if(query("tax")>tax) msg="������";
  else msg="���ֲ���";
  
  CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"��˰��"+msg+"��\n");
  
  set("tax",tax);
  set("zhili_tax",tax*ob->query_skill("dadao-qishu",1)/300);
  set("tax_busy",time());
  
  save();
  
  return 1;
  
}

int do_wuzhuang(string arg)
{
   
  object ob,obj;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<400000)
   return notify_fail("ֻ�о���ﵽ�� 400��000 �ſ��Խ�����װ��\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
  
  if(!ob->query_skill("junxie-xue",1))
  return notify_fail("�����ѧ�ˡ���еѧ���ſ�����װ���У�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>6)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ������װ"+HIY+query("city_name")+NOR+"�ľ��ӣ�\n");
  
  if(ob->query("vocation")!="����")
  return notify_fail("ֻ�������ſ�����װ"+HIY+query("city_name")+NOR+"�ľ��ӣ�\n");
  
  if(!arg) return notify_fail("��Ҫ��ʲô�����Ӿ��ӵ���װ��\n");
  obj=present(arg,ob);
  if(!obj) return notify_fail("������û�����������\n");
  
  if( obj->query("rumor")
    ||obj->query("no_save")
    ||obj->query("no_sell")
    ||obj->query("no_get")
    ||obj->query("no_give")
    ||obj->query("nogive_player")
    )
    return notify_fail("������������������Ӿ��ӵ���װ��\n");
  
  if(!obj->query("armor_prop")&&!obj->query("weapon_prop"))
  return notify_fail("��ֻ���á����ס��򡰱����������Ӿ��ӵ���װ��\n");
  
  add("apply/armor",(obj->query("armor_prop/armor")/15)*ob->query_skill("junxie-xue",1)/200);
  add("apply/damage",(obj->query("weapon_prop/damage")/15)*ob->query_skill("junxie-xue",1)/200);
  
  if(obj->query("equipped"))
   obj->unequip();
  
  destruct(obj);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"������"+query("city_name")+"�ľ�����װ��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;

}

int if_do_action(object ob,string type)
{
  
  if(type=="lev1") return 1;
  
  if(ob->query_skill("war-heal",1)&&
   type=="lev2")
  return 1;
  
  if(ob->query_skill("bafang-zhenfa",1)&&
   type=="lev3")
  return 1;
  
  if(ob->query_skill("liaoyuan-tianshu",1)&&
   type=="lev4")
  return 1;
  
  if(ob->query_skill("wuxing-qishu",1)&&
   type=="lev5")
  return 1;
  
  return 0;
  
}

int do_chubing(string arg)
{
  
  object ob,guard;
  int num,cost_type;
  string type,guard_type;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("ֻ�о���ﵽ�� 500��000 �ſ��Խ��г�����\n");
  
  if(objectp(ob->query_temp("city_war_guard")))
  return notify_fail("���Ѿ������ˡ�\n");
  
  if(ob->query("pker"))
  return notify_fail("ͨ������ʵ��ɣ�\n");
  
  if(time()-ob->query("war_guard_busy")<60*20)
   return notify_fail("�㲻������������\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ���ܴ�"+HIY+query("city_name")+NOR+"������\n");
  
  if(!arg||sscanf(arg,"%d %s",num,type)!=2)
  return notify_fail("��Ҫ�� ���� ʲô���� �ı���chubing ���� ����\n");
  
  if(num<=0||num>=100)
   return notify_fail("��Ҫ���ң���\n");
  if(type!=LEV1&&type!=LEV2&&type!=LEV3&&type!=LEV4&&type!=LEV5)
  return notify_fail("��Ҫ��ʲô���͵ı���"+LEV1+" "+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"\n");
  
  if(type==LEV1) guard_type="lev1";
  else
  if(type==LEV2) guard_type="lev2";
  else
  if(type==LEV3) guard_type="lev3";
  else
  if(type==LEV4) guard_type="lev4";
  else
  if(type==LEV5) guard_type="lev5";
  
  if(type==LEV1) cost_type=LEV1_SUPPLY;
  else
  if(type==LEV2) cost_type=LEV2_SUPPLY;
  else
  if(type==LEV3) cost_type=LEV3_SUPPLY;
  else
  if(type==LEV4) cost_type=LEV4_SUPPLY;
  else
  if(type==LEV5) cost_type=LEV5_SUPPLY;
  
  if(num>query(guard_type+"_guard"))
  return notify_fail(HIY+query("city_name")+NOR+"û����ô���"+type+"��\n");
  
  if(!if_do_action(ob,guard_type))
  return notify_fail("��ѧ�ļ��ܲ���ָ�Ӵ���ʿ����\n");
  
  add(guard_type+"_guard",-num);
  add("guard_person",-num*cost_type);
  
  guard=new(__DIR__"npc/guard");
  guard->set_status(num,guard_type,query("apply/armor"),query("apply/damage"),query("owner"));
  guard->set("zhongcheng_du",query("zhongcheng_du"));
  
  guard->add_temp("damage",ob->query_skill("bafang-zhenfa",1)/5);
  guard->add_temp("damage",ob->query_skill("liaoyuan-tianshu",1)/5);
  guard->add_temp("damage",ob->query_skill("wuxing-qishu",1)/5);
  
  guard->move(environment(ob));
  guard->check_owner(ob);
  guard->set("owner_ob",ob);
  ob->set_temp("city_war_guard",guard);
  ob->set("war_guard_busy",time());
  ob->set_temp("dtsl_job","war");
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"��"+query("city_name")+"�ɳ���"+
    chinese_number(num*cost_type)+"�˵�"+type+"��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  CHANNEL_D->do_channel(this_object(),"rumor","��˵"+query("city_name")+"�ɳ���һЩʿ����\n");
  
  return 1;
  
}     
  

int do_shoubing()
{
  
  object ob,guard;
  int cost_type;
  string guard_type;
  
  
  ob=this_player();
  
  if(!objectp(guard=ob->query_temp("city_war_guard")))
  return notify_fail("��û�д�����\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("����С�������������֣�\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("����������ĳ�����"+HIY+ob->query("shili/wide")+NOR+"��������"+HIY+query("city_name")+NOR+"��\n");
    else
    return notify_fail("�㲻������"+HIY+query("city_name")+NOR+"��\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("�����Ȩ��Ŀǰ������"+HIY+query("city_name")+NOR+"�ձ���\n");
  
  
  guard_type=guard->query("guard_type");
 
  if(guard_type=="lev1") cost_type=LEV1_SUPPLY;
  else
  if(guard_type=="lev2") cost_type=LEV2_SUPPLY;
  else
  if(guard_type=="lev3") cost_type=LEV3_SUPPLY;
  else
  if(guard_type=="lev4") cost_type=LEV4_SUPPLY;
  else
  if(guard_type=="lev5") cost_type=LEV5_SUPPLY;
  
  guard->set("number",guard->query("number")*COMBAT_D->status(guard,1)/100);
  
  if(query("guard_person")+cost_type*guard->query("number")>query("person"))
  return notify_fail("����������"+HIY+query("city_name")+NOR+"���˿ڡ�\n");
  
  add(guard_type+"_guard",guard->query("number"));
  add("guard_person",guard->query("number")*cost_type);
  
  ob->set_temp("city_war_guard",0);
  ob->delete_temp("dtsl_job");
  
  destruct(guard);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"��һЩ������ʿ���ɻ���"+query("city_name")+"��\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;
  
}     
  

int do_check()
{
  object ob;
  string msg,org_msg;
  int flag=0;
  
  ob=this_player();
  
  if(!wizardp(ob)&&ob->query("shili/name")!=query("owner")){
    if(!ob->query_skill("zhencha-shu",1))
    return notify_fail("���ﲻ��"+HIY+ORG_D->get_shili(ob)+NOR+"��ռ��ĵط���\n");
    else
    flag=1;
  }
  
  if(query("owner")&&query("owner")!="wizard")
   org_msg=ORG_D->get_board_shili(query("owner"));
  else
   org_msg="��͢";
  
  msg=HIY+query("city_name")+"Ŀǰ���������\n"NOR;
  msg+=HIY"����������������������������������������������������������\n"NOR;
  msg+="��"+HIY+org_msg+NOR+"��ͳ���¡�\n\n"NOR;
  msg+="���ͣ�����"+query("city_type")+"����\n";
  msg+="�˿����ޣ�"+chinese_number(query("max_person"))+"��\n";
  
  if(!flag)
  msg+="Ŀǰ�˿ڣ�"+chinese_number(query("person"))+"��\n";
  else
  msg+="Ŀǰ�˿ڣ�"+chinese_number(query("person")+random(200-ob->query_skill("zhencha-shu",1)))+"��\n";
  
  if(!flag)
  msg+="ʿ���˿ڣ�"+chinese_number(query("guard_person"))+"��\n";
  else
  msg+="ʿ���˿ڣ�"+chinese_number(query("guard_person")+random(200-ob->query_skill("zhencha-shu",1)))+"��\n";
  
  msg+="˰�ʣ�"+query("tax")+"%\n";
  msg+="�ҳ϶ȣ�"+query("zhongcheng_du")+"\n";
  msg+=HIR"������\n"NOR;
  if(!flag)
  msg+=LEV1+"��"+chinese_number(query("lev1_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV1_SUPPLY)+"��\n";
  else
  msg+=LEV1+"��"+chinese_number(query("lev1_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV1_SUPPLY)+"��\n";

  if(!flag)
  msg+=LEV2+"��"+chinese_number(query("lev2_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV2_SUPPLY)+"��\n";
  else
  msg+=LEV2+"��"+chinese_number(query("lev2_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV2_SUPPLY)+"��\n";  
  
  if(!flag)
  msg+=LEV3+"��"+chinese_number(query("lev3_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV3_SUPPLY)+"��\n";
  else
  msg+=LEV3+"��"+chinese_number(query("lev3_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV3_SUPPLY)+"��\n";
  
  if(!flag)
  msg+=LEV4+"��"+chinese_number(query("lev4_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV4_SUPPLY)+"��\n";
  else
  msg+=LEV4+"��"+chinese_number(query("lev4_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV4_SUPPLY)+"��\n";
  
  if(!flag)
  msg+=LEV5+"��"+chinese_number(query("lev5_guard"))+"��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV5_SUPPLY)+"��\n";
  else
    msg+=LEV5+"��"+chinese_number(query("lev5_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
    "��   "+"��λ��ռ�˿ڣ�"+chinese_number(LEV5_SUPPLY)+"��\n";
 
  
  msg+=HIR"\n��װ��\n"NOR;
  
  if(!flag)
  msg+="װ�ף�"+chinese_number(query("apply/armor"))+"\n";
  else
  msg+="װ�ף�"+chinese_number(query("apply/armor")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  if(!flag)
msg+="������"+chinese_number(query("apply/damage"))+"\n";
  else
msg+="������"+chinese_number(query("apply/damage")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  msg+=WHT"��ʳ������"NOR+chinese_number(query("deposit"))+"��\n";
  msg+=HIY"����������������������������������������������������������\n"NOR;
  
  ob->start_more(msg);
  
  return 1;
}

int do_help()
{
  string msg;
  
  msg="\n�������йس��������һЩ����(��ϸ�����ݻ���μ�help war)��\n\n";
  msg+="victory/zhanling������������ռ��һ������ʱʹ�á�\n";
  msg+="zhubing�������������ڳ�����פ��������\n";
  msg+="chebing�����������ڳ����Ѿ�פ����һЩ������\n";
  msg+="chubing�����������ڳ�����������ĳ��С�\n";
  msg+="shoubing�������������ջ��Ѿ��ɳ���һЩ������\n";
  msg+="train/lianbing������������ѵ��ʿ��������ߵȼ���\n";
  msg+="deposit�����������ڶڻ���ʳ��\n";
  msg+="diaobing�����������ڵ�������֧�������еķ��ء�\n";
  msg+="zhuishui������������������е�˰�ʡ�\n";
  msg+="wuzhuang�����������ڼ�ǿ���е���װ��\n";
  msg+="check/chakan�����������ڲ鿴���е���Ϣ��\n";
  
  this_player()->start_more(msg);
  return 1;
}
