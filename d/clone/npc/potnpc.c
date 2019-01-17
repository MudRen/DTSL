#include <ansi.h>
inherit NPC;

#define SCORE_D "/adm/daemons/scored.c"

int check_pot();
int give_test_reward();

void create()
{
        set_name("���ø�ɮ",({ "gao seng","gao","seng"}) );
        set("gender", "����" );
        set("class","bonze");
        set("long","����λ���ø�ɮ����˵����������\n");
        set("age", 32);
        set("inquiry",([       
        "Ǳ��":(:check_pot:),
        "���Խ���":(:give_test_reward:),
        ]));
        
        set("target_id","####");
        
    setup();
    carry_object("/obj/cloth/seng-cloth")->wear();
  
}

void init()
{
  add_action("do_save_pot","savepot");
  add_action("do_get_pot","getpot");
}

int do_save_pot(string arg)
{
  object ob;
  int pot;
  
  ob=this_player();
  
  if(is_busy()){
    command("say ���һ��... ...");
    return 1;
  } 
  
  if(!arg){
    command("say ����Ҫ�������Ǳ�ܣ�\n");
    return 1;
  }
  
  
  pot=atoi(arg);
  if(pot<10||pot>100){
   command("say һ�����ٱ��� 10 ��Ǳ�ܣ���ౣ�� 100 ��Ǳ�ܡ�");
   return 1;
  }
  if(pot>ob->query("potential")){
   command("say ������û����ô��Ǳ�ܣ�");
   return 1;
  }
  if(ob->query("office_number")<(pot+ob->query("save_potential"))/20){
   command("say 1 �㹦�����Ա��� 20 ��Ǳ�ܡ������ڵĹ���̫���ˣ�\n");
   return 1;
  }
  
  ob->add("potential",-pot);
  ob->add("save_potential",pot);
  
  start_busy(2);
  
  command("say �ã����Ѿ����㱣����"+HIY+chinese_number(pot)+NOR+CYN+"��Ǳ�ܣ�\n");
  return 1;
  
  
}

int do_get_pot(string arg)
{
  object ob;
  int pot;
  
  ob=this_player();
  
  if(is_busy()){
    command("say ���һ��... ...");
    return 1;
  } 
  
  if(!arg){
    command("say ����Ҫ�ͷŶ���Ǳ�ܣ�\n");
    return 1;
  }
  
  
  pot=atoi(arg);
  if(pot<=0||pot>100){
   command("say ���ҵĹ�����ÿ��ֻ�ܸ����ͷ�һ�ٵ�Ǳ�ܣ�");
   return 1;
  }
  if(pot>ob->query("save_potential")){
   command("say ������û�б�����ô��Ǳ�ܣ�");
   return 1;
  }
 
  ob->add("save_potential",-pot);
  ob->add("potential",pot);
  
  start_busy(2);
  
  command("say �ã����Ѿ������ͷ���"+HIY+chinese_number(pot)+NOR+CYN+"��Ǳ�ܣ�\n");
  return 1;
  
  
}

int check_pot()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("save_potential")){
   command("say ���Ѿ�����洢��"+HIY+chinese_number(ob->query("save_potential"))+
     NOR+CYN+"��Ǳ�ܣ�");
   return 1;
  }
  
  command("say ʹ��savepot������Ǳ�ܣ�ʹ��getpot���ͷ�Ǳ�ܡ�\n"+
          "ÿ�δ洢Ǳ����Ҫһ�������Ĺ�����\n");
  return 1;
  
}

/*
һ�� ���⹱�׽�����xuer 
����ԭ���ҳ��������˺ܶ���Ҫ��BUG�����ҷ����˶�ƪ����DT����ıȽϺõĽ��顣 

���� �߼����׽����� 
llklhxxc leo caimi winner tott zhch miccire 

���� �м����׽��� 
hide issac forget ylei gest trsk sister hope yihe kitty lanse sjsega yuki mercuri over stopgab love zxmly yatina tiexue 

�ġ� �������׽��� 
pound xhx wish anything zax huanle lklk yuhe tianyi none miclon denis xing lazylong sea shashou strong anan zyf xuedao 

*/

string *reward_one=({
"xuer","leo"});

string *reward_two=({
"yuki","caimi","winner","tott","zhch","anan"});

string *reward_three=({
"hide","forget","ylei","gest","trsk","sister","hope","yihe","kitty","lanse", 
"sjsega","mercuri","over","stopgab","love","zxmly","yatina","tiexue","dagon", 
"jerry","tely","lklk","leon","tly","zxy","bakal","langyan"});

string *reward_four=({
"pound","xhx","wish","anything","zax","huanle","yuhe","tianyi","none","miclon",
"denis","xing","lazylong","sea","strong","zyf","xuedao","ddyy","aojian"});

void give_reward(object ob,int pot,int office_number,int point)
{
    ob->add("potential",pot);
    ob->add("office_number",office_number);
    ob->add("char_lev/points",point);
    
    tell_object(ob,"��õ��ˣ�\n"+
    chinese_number(pot)+"��Ǳ��\n"+
    chinese_number(office_number)+"�㹦��\n"+
    chinese_number(point)+"�����ԣ�\n");
    
    tell_object(ob,"Ϊ�������Ǳ�ܲ������˷ѣ������ȴ浽"+name()+"����ȽϺã�\n");
    
    log_file("REWARD_TEST_ID",ob->query("name")+" "+ob->query("id")+"�õ����Խ���:"+
      "Ǳ��:"+chinese_number(pot)+"��;����:"+chinese_number(office_number)+
      "��;���Ե�:"+chinese_number(point)+"�㡣���ʱ�䣺"+ctime(time())+"\n");
    
}

int give_test_reward()
{
  object ob;
  string id;
  
  ob=this_player();
  id=ob->query("id");  
  
  if(!SCORE_D->RemoveOne(id)){
    command("say ʩ���ĵز��ϣ��Ժ�������߽�����\n");
    return 1;
  }
  
  
  if(member_array(id,reward_one)!=-1){
    tell_object(ob,"\n��ϲ�㣬��õ����ǡ����⹱�׽�������\n");
    command("hehe "+id);
    
    give_reward(ob,4000,20,8);
    return 1;
  }
  if(member_array(id,reward_two)!=-1){
    tell_object(ob,"\n��ϲ�㣬��õ����ǡ��߼����׽�������\n");
    command("hehe "+id);
    
    give_reward(ob,3000,15,6);
    return 1;
  }
  if(member_array(id,reward_three)!=-1){
    tell_object(ob,"\n��ϲ�㣬��õ����ǡ��й��׽�������\n");
    command("hehe "+id);
    
    give_reward(ob,2000,10,4);
    return 1;
  }
  if(member_array(id,reward_four)!=-1){
    tell_object(ob,"\n��ϲ�㣬��õ����ǡ���ͨ���Խ�������\n");
    command("hehe "+id);
    
    give_reward(ob,1000,5,2);
    return 1;
  }
  tell_object(ob,"\n��ϲ�㣬��õ����ǡ����Ե�¼��������\n");
    command("hehe "+id);
    
    give_reward(ob,500,5,1);
    return 1;
  
  
  return 1;
  
}
  
  
  
