
inherit F_DBASE;

#include <ansi.h>

#define BASE_EXP 100
#define BASE_POT 70
#define BASE_OFFICE_NUMBER 1
#define BASE_FAMOUS 1

#define CHUJICHANYUAN_JOB "������Ժ��������"
#define SJBZAHUO_JOB "�μұ���������"
#define WAKUANG_JOB "�ڿ�����"
#define DMCHUJI_JOB "�����������"
#define GAOLIXUNLUO_JOB "����Ѳ������"
#define CHCHUJI_JOB "�Ⱥ���ի��������"
#define TJCHUJI_JOB "ͻ�ʳ�������"

#define CHANYUAN_JOB "������Ժ�ᾭ������"
#define BUTOU_JOB "������ͷ����"
#define GAOLI_JOB "����ɱ��������"
#define SJBKILLPANTU_JOB "�μұ�ɱ��ͽ����"
#define TUJUEJY_JOB "ͻ�ʽ�Ӧ����"
#define FANMAI_JOB "�����˿�����"
#define YGSONGXIN "��������������"
#define YUNYAN_JOB "��������"
#define FUWEN_JOB "��������"
#define DMSHOUZHANG_JOB "������������"
#define HAIDAO_JOB "��������"
#define RANDOM_JOB "����������"
#define TRADE_JOB "��������"
#define KILLER_JOB "ɱ������"
#define TIEJIANG_JOB "��������"
#define YAOSHI_JOB "ҩʦ����"
#define MAZEI_JOB "�����������"


void create()
{
  seteuid(getuid());

  set("name","������ϵͳ");
  set("channel_id","����ϵͳ");
  set("id","jobsys.c");
  
}

int if_thesame_job(object ob,string jobname)
{
return ob->query("last_job_name")==jobname;             
        
}

// �޸��˹��������ԡ�
//ÿ��������ÿ������Ĺ����㣬����һ���ܵĹ���������
// ����Ϊ job_office_number/
//��������������� ���񹦼��� 1�����ܹ����㲻�ۡ�

//����ǽ�����ᴢ���ġ��� /include/job_money.h ���Ƶ��������ˡ�
void add_shili(object me,int exp,int money)
{
   object sboard;
   if(!me->query("shili/name")) return;
   sboard=load_object(BOARD_PATH+me->query("shili/name"));
   if(!sboard) return;
 if(!me->query_temp("bhjob"))
   sboard->add("exp",exp/10);
 else sboard->add("exp",exp);
 if(!me->query_temp("bhjob"))
   sboard->add("money",money/8);
 else sboard->add("money",money);
   sboard->save();
   tell_object(me,"��İ������������ˣ�\n");
   return;
}

//���������ʱ���ֵ�һ��clone������ɱ�֡���Ӧ�����NPC:
int clear_job_npc(object ob)
{
   object *targets;
   int i,j;
   
   targets=ob->query_temp("job_temp_killer");
        
        if(arrayp(targets)){
        
        for(i=0,j=0;i<sizeof(targets);i++)
         if(objectp(targets[i])){
           if(living(targets[i]))
           message_vision("$N�Ҵҵ����ˡ�\n",targets[i]);
           if(!targets[i]->is_character())
           targets[i]->unequip();                  
          destruct(targets[i]);
          j++;
           }
        }
    return j;
}

//�������к������õĹ��к�����
//������һЩ���к����������£��� ��������ȣ�
void do_action(object ob,int flag)
{
   if(flag)
   clear_job_npc(ob);
   ob->set("busy_time",time()+5+random(15));
   return;
}

int job_reward_flag(object ob,int num)
{
  int i;
  int exp;
  
  exp=ob->query("combat_exp");
  
  for(i=0;i*i*i*i<exp*num;i++);
  
  return i;
  
}

int job_reward(object ob,int num)
{
  int i;
  int exp;
  
  exp=ob->query("combat_exp");
  
  for(i=0;i*i*i<exp*num;i++);
  
 if(i<25) i=25;
  return i;
  
}

//ͻ�ʳ�����������

void give_reward_tjchujijob(object ob)
{
   int exp,pot,silver;
   
   exp=job_reward(ob,job_reward_flag(ob,1)/6)+random(10);
   pot=exp/2;
   silver=50+random(50);
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
   ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",silver);
   add_shili(ob,exp/5,silver/5);
   tell_object(ob,"���˽�������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                  "            "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�"+
                  MONEY_D->money_str(silver)+"\n");
  ob->add("famous",1);
  ob->add_temp("tjchuji_job_times",1);
   
   if(ob->query_temp("tjchuji_job_times")>=10){
     ob->delete_temp("tjchuji_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+TJCHUJI_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
    
    do_action(ob,0);
}
//�Ⱥ���ի������������

void give_reward_chchujijob(object ob)
{
    int exp,pot,sil;
    
  exp=job_reward(ob,job_reward_flag(ob,1)/6)+random(ob->query_skill("wuwang-jing",1)/5);
  pot=exp/2;
  sil=90+random(10);
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  ob->add("deposit",sil);
  if(ob->query("potential")>ob->query("max_pot"))
  ob->set("potential",ob->query("max_pot"));    
  tell_object(ob,"������Ц�����ã�ֻҪ���Ŭ�����У���һ���ܳ�Ϊһ�����Ƶ�Ů����\n");
  tell_object(ob,HIC"\n��������������"+HIW+chinese_number(exp)+HIC+"�㾭��ֵ��"+
                 HIY+chinese_number(pot)+HIC+"��Ǳ�ܣ�"+NOR+CYN+chinese_number(sil)+HIC+"��ͭǮ��\n\n"NOR);
        tell_object(ob,"���Ǯׯ��������ˣ�\n");                 
  ob->add("famous",1);
  ob->add_temp("chchuji_job_times",1);
   
   if(ob->query_temp("chchuji_job_times")>=10){
     ob->delete_temp("chchuji_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+CHCHUJI_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
    
    do_action(ob,0);
}
//����Ѳ����������

void give_reward_xunluojob(object me)
{
   int exp,pot,sil;
   
   exp=job_reward(me,job_reward_flag(me,1)/6);
   pot=exp/2;
   sil=90+random(10);
   me->add("combat_exp",exp);
   me->add("potential",pot);
   if(me->query("potential")>me->query("max_pot"))
   me->set("potential",me->query("max_pot"));
   me->add("deposit",sil);
   
   add_shili(me,exp/5,sil/5);
   tell_object(me,"�㱻������"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIW""+chinese_number(pot)+""NOR""+"��Ǳ�� "+""HIW""+chinese_number(sil)+""NOR""+"��ͭǮ\n");
   tell_object(me,"���Ǯׯ��������ˣ�\n");
   
   me->add("famous",1);
   me->add_temp("gaolixunluo_job_times",1);
   
   if(me->query_temp("gaolixunluo_job_times")>=10){
     me->delete_temp("gaolixunluo_job_times");
     me->add("office_number",1);
     me->add("job_office_number/"+GAOLIXUNLUO_JOB,1);
     tell_object(me,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(me,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
    do_action(me,1);
}
//��Ժ������������

void give_reward_chanyuanjob(object me)
{
     int exp,sil,pot;
     
     exp=job_reward(me,job_reward_flag(me,1)/6);
     pot=exp/2;
     sil=90+random(10);
     me->add("combat_exp",exp);
     me->add("potential",pot);
     if(me->query("potential")>me->query("max_pot"))
     me->set("potential",me->query("max_pot"));
     me->add("deposit",sil);
     
     add_shili(me,exp/5,sil/5);
     tell_object(me,"\n���߳���Ц����Сʩ���ܾ��ľ��������ֻ����һ��������Ϊ��\n");
     tell_object(me,HIC"\n�㱻������"+HIW+chinese_number(exp)+HIC+"�㾭��ֵ "+HIY+chinese_number(pot)+HIC+"��Ǳ�� "+NOR+CYN+chinese_number(sil)+HIC+"��ͭǮ��\n\n"NOR);
     tell_object(me,"���Ǯׯ��������ˣ�\n");
     
     me->add("famous",1);
     me->add_temp("chanyuan_chujijob_times",1);
   
   if(me->query_temp("chanyuan_chujijob_times")>=10){
     me->delete_temp("chanyuan_chujijob_times");
     me->add("office_number",1);
     me->add("job_office_number/"+CHUJICHANYUAN_JOB,1);
     tell_object(me,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(me,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
   
   do_action(me,1);  
}

//�μұ�������������

void give_reward_sjbzahuo(object ob)
{
    int exp,pot,silver;
   
   exp=job_reward(ob,job_reward_flag(ob,1)/6);
   pot=exp/2;
   silver=50+random(50);
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",silver);
   add_shili(ob,exp/5,silver/5);
   tell_object(ob,"�����Ž�������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                  "              "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�"+
                  MONEY_D->money_str(silver)+"\n");
   ob->add("famous",1);
   ob->add_temp("sjb_zahuojob_times",1);
   
   if(ob->query_temp("sjb_zahuojob_times")>=10){
     ob->delete_temp("sjb_zahuojob_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+SJBZAHUO_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
    
    do_action(ob,0);
}

//���������������
void give_reward_dmchujijob(object ob)
{
        int exp,sil,pot;
        
  exp=job_reward(ob,job_reward_flag(ob,1)/6);
        pot=exp/2;
        sil=60+random(30);
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
        ob->add("deposit",sil);
        add_shili(ob,exp/5,sil/5);
        tell_object(ob,HIW"�㱻������"+chinese_number(exp)+"�㾭��ֵ "+chinese_number(sil)+"��ͭǮ "+chinese_number(pot)+"��Ǳ��\n"NOR);
        tell_object(ob,"��Ǯׯ�Ĵ�������ˣ�\n");
        ob->add("famous",1);
        ob->add_temp("dmchuji_job_times",1);
   
   if(ob->query_temp("dmchuji_job_times")>=10){
     ob->delete_temp("dmchuji_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+DMCHUJI_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
   
   do_action(ob,1);
}
//��Ժ�ᾭ����������
void give_reward_jj(object ob)
{
  int exp,pot,sil;
  
  exp=150+random(20);
  pot=60+random(20);
  sil=ob->query("max_pot")/2+ob->query("job_office_number/"+CHANYUAN_JOB)*3/2;
  

  ob->set("last_job_name",CHANYUAN_JOB);
    
    ob->add("combat_exp",exp);
    ob->add("potential",pot);
    if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   
   add_shili(ob,exp/10,sil/10);
   
   tell_object(ob,"����ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
      HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n"+
      MONEY_D->money_str(sil)+"��\n");
   
   ob->add("famous",1);
   ob->add_temp("chanyuan_job_times",1);
   
   if(ob->query_temp("chanyuan_job_times")>=10){
     ob->delete_temp("chanyuan_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+CHANYUAN_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
   
   do_action(ob,1);   
   return;
}

//������ͷ��������
void give_reward_butoujob(object ob,object target,int lev)
{
   
   int exp,pot,silver;
   
   if(target->query("combat_exp")<=300000){
        exp=90+random(20);
        pot=70+random(20);}
        else
        if(target->query("combat_exp")<=500000){
        exp=100+random(20);
        pot=90+random(20);}
        else
        if(target->query("combat_exp")<=800000){
        exp=150+random(10);
        pot=100+random(20);}
        else
        if(target->query("combat_exp")<=1500000){
        exp=180+random(10);
        pot=100+random(20);}
        else
        if(target->query("combat_exp")<=2500000){
        exp=220+random(10);
        pot=110+random(20);}
        else{
        exp=240+random(10);
        pot=120+random(20);}
        
        silver=ob->query("max_pot");
        exp=exp*lev;
        pot=pot*lev;
        silver=silver*lev+ob->query("job_office_number/"+BUTOU_JOB)*3/2;
        
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
        ob->add("deposit",silver);
        
        tell_object(ob,"��õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
        HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n"+
        MONEY_D->money_str(silver)+"��\n");
        
        add_shili(ob,exp/10,silver/10);
        
        ob->add("famous",2*lev);
   ob->add_temp("butou_job_times",1);
   
   if(ob->query_temp("butou_job_times")>=10){
     ob->delete_temp("butou_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+BUTOU_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
  do_action(ob,0);
  return;
}

//��ҩ��������

void give_reward_caiyao(object ob)
{
   int v_score;
   
   v_score=ob->query_int()*ob->query("max_pot");
   
   ob->improve_skill("bencao-shuli",v_score);
   tell_object(ob,"��ı����������˽�һ������ߣ�\n");
   
   return;
}

//����ɱ������������

void give_reward_gaolijob(object ob)
{
   int exp,pot,money;
   
   exp=200+random(30);
  pot=60+random(20);  
  money=ob->query("max_pot")/2+ob->query("job_office_number/"+GAOLI_JOB)*3/2;
  
  ob->set("last_job_name",GAOLI_JOB);
  
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
  ob->add("deposit",money);
  
  tell_object(ob,"��õ���"+HIW+chinese_number(exp)+NOR+"�㾭��\n"+
                 "       "+HIY+chinese_number(pot)+NOR+"��Ǳ��\n"+
                 "       "+MONEY_D->money_str(money)+"\n");
                 
  add_shili(ob,exp/10,money/10);
  
  ob->add("famous",1);
   ob->add_temp("gaoli_job_times",1);
   
   if(ob->query_temp("gaoli_job_times")>=10){
     ob->delete_temp("gaoli_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+GAOLI_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
  do_action(ob,0);
  return;
}

//�μұ�ɱ��ͽ��������

void give_reward_sjbkillpantu(object ob)
{
   int exp,pot,sil;
   
  exp=30+random(10);
  pot=220+random(30);
  sil=200+random(100)+ob->query("job_office_number/"+SJBKILLPANTU_JOB)*3/2;
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot")*2)
  ob->set("potential",ob->query("max_pot")*2);
  ob->add("deposit",sil);
   tell_object(ob,HIC"\n����˰Ѻ�������ж���õ���"+HIW+chinese_number(exp)+HIC+"�㾭�飬"+
                                              HIY+chinese_number(pot)+HIC+"��Ǳ�ܣ�"+
                                              HIW+chinese_number(sil/100)+HIC+"��������\n"NOR+
                                              "���Ǯׯ��������ˣ�\n");
    add_shili(ob,exp,sil/100);
    
    ob->add("famous",1);
   ob->add_temp("sjbkillpt_job_times",1);
   
   if(ob->query_temp("sjbkillpt_job_times")>=10){
     ob->delete_temp("sjbkillpt_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+SJBKILLPANTU_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
    do_action(ob,0);
    return;
}

//ͻ�ʽ�Ӧ��̽��������

void give_reward_tujuejy(object ob)
{
   int exp,pot,sil;
   
   if(ob->query_temp("come_killer")){
        if(ob->query("combat_exp")>500000){
         exp=400+random(50);        
         pot=exp*2/5;
        }
        else{
         exp=190+random(40);
         pot=90+random(20);
        }
   }
   else
   {
        exp=50+random(10);
        pot=20+random(10);
   }
        
    sil=ob->query("max_pot")+ob->query("job_office_number/"+TUJUEJY_JOB)*3/2;
    
        ob->set("last_job_name",TUJUEJY_JOB);
    
        ob->add("deposit",sil);
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
        
        tell_object(ob,"������ж�����õ���"+
                ""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ��"+
                ""HIY""+chinese_number(pot)+""NOR""+"��Ǳ�ܡ�\n"+
                "�ž��ٸ�����"+MONEY_D->money_str(sil)+"��\n");
        add_shili(ob,exp/10,sil/10);
        
         ob->add("famous",2);
   ob->add_temp("tujuejy_job_times",1);
   
   if(ob->query_temp("tujuejy_job_times")>=10){
     ob->delete_temp("tujuejy_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+TUJUEJY_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
   do_action(ob,1);     
   return;
}

//����ɽ�����˿���������

void give_reward_xiangfanmai(object me)
{
   int exp,pot,sil;
      
      if(me->query("combat_exp")<500000){
        exp=170+random(30);
        exp +=20*me->query("dtsl_job_xiang_jobtimes")/(me->query("dtsl_job_xiang_jobtimes")+200);
        
        if(exp>230)
        exp=230;
        
        pot=70+random(20);
        pot +=10*me->query("dtsl_job_xiang_jobtimes")/(me->query("dtsl_job_xiang_jobtimes")+300);
      }else{
        exp=290+random(20);
        pot=exp*3/5;
      }                         
        sil=500+me->query("max_pot")/5+me->query("job_office_number/"+FANMAI_JOB);
        

        me->set("last_job_name",FANMAI_JOB);
        
        me->add("deposit",sil);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        if(me->query("potential")>me->query("max_pot")*3/2)
        me->set("potential",me->query("max_pot")*3/2);
        
        me->add("dtsl_job_xiang_jobtimes",1);//����������ۻ������ô���Խ�࣬����Խ�ࡣ
        
        tell_object(me,"������ж�����õ���"+
                ""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ��"+
                ""HIY""+chinese_number(pot)+""NOR""+"��Ǳ�ܡ�\n"+
                "����ɽ������"+MONEY_D->money_str(sil)+"��\n");
       
       add_shili(me,exp/10,sil/10);
       
        me->add("famous",3);
   me->add_temp("fanmai_job_times",1);
   
   if(me->query_temp("fanmai_job_times")>=10){
     me->delete_temp("fanmai_job_times");
     me->add("office_number",1);
     me->add("job_office_number/"+FANMAI_JOB,1);
     tell_object(me,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(me,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
       do_action(me,0);
       return;
}

//������������������

void give_reward_songxin(object who)
{
   int exp,sil,pot;
   
   if(who->query("combat_exp")<100000){
        exp=50+random(20);
    pot=23+random(5);
        sil=who->query("max_pot")/2;
   }
   else
   if(who->query_temp("need_killer")<=who->query_temp("need_killer_flags")){
        exp=140+random(10);
        pot=60+random(20);
                sil=who->query("max_pot")/2+who->query("job_office_number/"+YGSONGXIN)*3/2;
         }
        else{
         exp=10+random(10);
         pot=5+random(5);
         sil=2+random(2);}
        
        
        who->set("last_job_name",YGSONGXIN);
        
        who->add("combat_exp",exp);
        who->add("potential",pot);
        if(who->query("potential")>who->query("max_pot"))
        who->set("potential",who->query("max_pot"));
        who->add("deposit",sil);
        tell_object(who,HIC"\n������ж�����õ���"+HIW+chinese_number(exp)+HIC+"�㾭��ֵ��"+HIY+chinese_number(pot)+HIC+"��Ǳ�ܣ�"+MONEY_D->money_str(sil)+"��\n"NOR);
        tell_object(who,"���Ǯׯ��������ˣ�\n");
        add_shili(who,exp/10,sil/10);
                
        who->add("famous",1);
  who->add_temp("songxin_job_times",1);
   
   if(who->query_temp("songxin_job_times")>=10){
     who->delete_temp("songxin_job_times");
     who->add("office_number",1);
     who->add("job_office_number/"+YGSONGXIN,1);
     tell_object(who,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
    do_action(who,1);
    return;
}

//����������:
void give_reward_yunyanjob(object me,int i)
{
   int exp,pot,sil;
   
   if(me->query("combat_exp")<100000){
         exp=55+random(15);
         pot=23+random(5);
         sil=me->query("max_pot")/2;
   }
   else
   if(me->query_temp("need_killer")<=me->query_temp("need_killer_flags")){
        exp=140+i*12;
        pot=90+i*5;
        sil=me->query("max_pot")/2+me->query("job_office_number/"+YUNYAN_JOB)*3/2;
   }
   else{
        exp=10+random(10);
         pot=5+random(5);
         sil=2+random(2);
        }
        
        me->set("last_job_name",YUNYAN_JOB);
        
        me->add("combat_exp",exp);
        me->add("potential",pot);
        if(me->query("potential")>me->query("max_pot"))
        me->set("potential",me->query("max_pot"));
        me->add("deposit",sil);
        
        tell_object(me,HIC"������ж��У���õ��ˣ�"
                           +HIW+chinese_number(exp)+HIC+"��ľ���ֵ��"
               +HIY+chinese_number(pot)+HIC+"���Ǳ�ܣ�"
               +MONEY_D->money_str(sil)+"��\n"NOR);
  tell_object(me,"���Ǯׯ��������ˣ�\n");     
        add_shili(me,exp/10,sil/10);
        
        me->add("famous",1);
        me->add_temp("yunyan_job_times",1);
   
   if(me->query_temp("yunyan_job_times")>=10){
     me->delete_temp("yunyan_job_times");
     me->add("office_number",1);
     me->add("job_office_number/"+YUNYAN_JOB,1);
     tell_object(me,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(me,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
    
      do_action(me,1);
      return;
}

//������������

void give_reward_questjob(object ob,object target)
{
   int exp,pot,silver;
   
   exp=190+target->query("reward_exp");
   pot=100+target->query("reward_pot");
   silver=ob->query("max_pot");
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",silver);
   add_shili(ob,exp/10,silver/10);
   tell_object(ob,"������ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                  "                    "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�"+
                  MONEY_D->money_str(silver)+"��\n");
   
   ob->add("famous",1);
   ob->add_temp("fuwen_job_times",1);
   
   if(ob->query_temp("fuwen_job_times")>=10){
     ob->delete_temp("fuwen_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+FUWEN_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
   do_action(ob,0);                
   return;
}

//����������������

void give_reward_dmshouzhang(object ob)
{
   int exp,pot,sil;
  
  if(ob->query("combat_exp")<200000) {
  exp=100+random(10);
  pot=60+random(20);
  sil=50+random(50);
  }
  else
  if(ob->query("combat_exp")<600000) {
  exp=140+random(30);
  pot=80+random(20);
  sil=300+random(50)+ob->query("job_office_number/"+DMSHOUZHANG_JOB);
  }
  else{
  exp=220+random(50);
  pot=90+random(20);
  sil=500+random(50)+ob->query("job_office_number/"+DMSHOUZHANG_JOB);
  }
  
        
  ob->set("last_job_name",DMSHOUZHANG_JOB);
         
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
  ob->add("deposit",sil);
  
  
  tell_object(ob,
  "����ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭��\n"+
  "                  "+HIY+chinese_number(pot)+NOR+"��Ǳ��\n"+
  "                  "+MONEY_D->money_str(sil)+"\n");

  add_shili(ob,exp/10,sil/10);
  
   ob->add("famous",1);
   ob->add_temp("shouzhang_job_times",1);
   
   if(ob->query_temp("shouzhang_job_times")>=10){
     ob->delete_temp("shouzhang_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+DMSHOUZHANG_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }
  do_action(ob,1);  
  return;
}

//������������

void give_reward_haidaojob(object ob,int lev)
{
  
  object *member;
   int i;
   int exp,pot,sil;
   
   member=ob->query_team();
   for(i=0;i<sizeof(member);i++){
     if(member[i]&&environment(member[i])==environment(ob)){
        exp=ob->query("combat_exp")-member[i]->query("combat_exp");
        exp=exp/2000000;
        exp=70+random(10)+lev*10-exp;
        if(exp<=0)
        exp=5+random(5);
        
        pot=ob->query("combat_exp")-member[i]->query("combat_exp");
        pot=pot/2000000;
        pot=40+random(10)+lev*5-pot;
        if(pot<=0)
        pot=5+random(5);
        
        sil=member[i]->query("max_pot")+member[i]->query("job_office_number/"+HAIDAO_JOB)*3/2;
        
        member[i]->add("combat_exp",exp);
        member[i]->add("potential",pot);
        if(member[i]->query("potential")>member[i]->query("max_pot")*5)
        member[i]->set("potential",member[i]->query("max_pot")*5);
        member[i]->add("deposit",sil);
        
        tell_object(member[i],"����ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
                              HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n"+
                              MONEY_D->money_str(sil)+"��\n");
        
         add_shili(member[i],exp/10,sil/10);
         
         member[i]->add("famous",5);
         member[i]->add_temp("haidao_job_times",1);
   
         if(member[i]->query_temp("haidao_job_times")>=10){
             member[i]->delete_temp("haidao_job_times");
             member[i]->add("office_number",4);
             member[i]->add("job_office_number/"+HAIDAO_JOB,1);
             tell_object(member[i],HIG"\n��õ����ĵ㹦����\n"NOR);
             tell_object(member[i],HIG"\n��õ���һ�������Ĺ�����\n"NOR);
            }
          do_action(member[i],0);  
           
        }}
               
     return;
}

//��������������

void give_reward_feiyunzi(object ob)
{
   int exp,pot,coin;
   object thing;
   
  if(ob->query("combat_exp")<200000){
  
  exp=160+random(20);
  pot=90+random(20);
  }
  else{
  exp=350+random(50);
  pot=120+random(20);
  }
  coin=ob->query("max_pot")/2+ob->query("job_office_number/"+RANDOM_JOB)*3/2;
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot"))
        ob->set("potential",ob->query("max_pot"));
  ob->add("deposit",coin);
  add_shili(ob,exp/2,coin/2);
  tell_object(ob,"�����ӽ�������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��,"+MONEY_D->money_str(coin)+"��\n");
    
    if(ob->query("combat_exp")>=200000)
    ob->add("famous",2);
    else
    ob->add("famous",1);
    
   ob->add_temp("feiyunzi_job_times",1);
   
   if(ob->query_temp("feiyunzi_job_times")>=10){
     ob->delete_temp("feiyunzi_job_times");
     ob->add("office_number",2);
     /*
     if(!present("fuwen",ob)){
     thing=new("/d/job/questjob/questmaster");
     thing->set_status();
     thing->move(ob);
      tell_object(ob,"\n�����Ӹ�����һ����ġ�\n");
     }
     */
     ob->add("job_office_number/"+RANDOM_JOB,1);
     tell_object(ob,HIG"\n��õ������㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    
    }
  do_action(ob,1);  
  return;
}

//������������

void give_reward_tradejob(object who)
{
    int exp,sil,pot;
    
    if(who->query_temp("need_killer")<=who->query_temp("need_killer_flags")){
        exp=100+random(30);
        pot=50+random(20);
        sil=who->query("max_pot")/2;}
        else{
         exp=10+random(10);
         pot=5+random(5);
         sil=2+random(2);}
   
        who->add("combat_exp",exp);
        who->add("potential",pot);
        if(who->query("potential")>who->query("max_pot"))
        who->set("potential",who->query("max_pot"));
        who->add("deposit",sil);
        who->improve_skill("trade",who->query_int()*who->query("max_pot")*2/3);
        add_shili(who,exp/10,sil/10);
        
        tell_object(who,"������ж�����õ���"+""HIW""+chinese_number(exp)+""NOR""+"�㾭��ֵ "+""HIY""+chinese_number(pot)+""NOR""+"��Ǳ�� "+MONEY_D->money_str(sil)+"\n");
        tell_object(who,"���Ǯׯ��������ˣ�\n");
        
   who->add("famous",1);
   who->add_temp("tradejob_job_times",1);
   
   if(who->query_temp("tradejob_job_times")>=10){
     who->delete_temp("tradejob_job_times");
     who->add("office_number",1);
     who->add("job_office_number/"+TRADE_JOB,1);
     tell_object(who,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
    do_action(who,1);  
    return;
}

//�������еĽ������ܣ�
string give_reward(object me) {
  mapping skill=me->query_skills();
  string *skillnames;
  string selected,msg;
  int level, inc=0;

  if (!skill) return "none";

  skillnames=keys(skill);
  selected=skillnames[random(sizeof(skillnames))];

  // mon 3/25/99
  level=skill[selected];
  if(level<80) {
      inc=1;
  } else if(level<160) {
      inc=random(2)==0;
  } else if(level<240) {
      inc=random(3)==0;
  } else {
      inc=random(4)==0;
  }

  if(inc==1) {
   // me->set_skill(selected,level+1);
   me->improve_skill(selected,level*2);
    tell_object(me,"���"+ to_chinese(selected) + "����ˡ�\n");
    return selected;
  }

  return "none";
}

void give_reward_killerjob(object ob)
{
     string skill;
     int exp,pot,lev,sil;
    
    lev=ob->query_temp("cisha_job/level");
                    
    exp=170+random(30)+lev*10;
    pot=90+random(20)+lev*3;
    sil=ob->query("max_pot")+ob->query("job_office_number/"+KILLER_JOB)*3/2;//��Ǯ��
                    
    ob->add("combat_exp",exp);
    ob->add("potential",pot);               
    if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
    ob->add("deposit",sil);
    
    ob->add_temp("cisha_job/level",1);//�ۼ�����һ���������
    ob->add("famous",1);
    
    if(ob->query_temp("cisha_job/level")>=10) {
       // ֻ�о�����ڵ��� 200K �ſ��ܽ������ܡ�
        if(ob->query("combat_exp")>=200000)
          skill=give_reward(ob);
        else skill="none";
          ob->add("office_number",1);
          ob->add("job_office_number/"+KILLER_JOB,1);
          ob->delete_temp("cisha_job/level");
          tell_object(ob, HIG"��õ���һ�㹦����\n"NOR);
          tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
        if (skill != "none"){
           message("shout",HIY"��"HIW"ɱ�ֹ���"HIY"��"HIY"������(yang xuyan):" HIR+ ob->query("name")+HIM"���Ҵ�ɱҪ���й����ʽ���"HIY+ to_chinese(skill)+HIM"���ܣ�\n"NOR,users()); 
        }



    }

                
         tell_object(ob, "��õ���"HIR+chinese_number(exp)
                            +"��"NOR"�����"HIY+chinese_number(pot)+
                            "��"NOR"Ǳ�ܣ�\n"+
                            MONEY_D->money_str(sil)+"\n");
        
        add_shili(ob,exp/10,sil/10);//��ᴢ��������
        
       do_action(ob,0);

}

//������������Ľ�����

void give_reward_tiejiangjob1(object ob)
{
  int exp,pot,coin;  
   
  exp=100+random(20);
  pot=random(20)+60;
  coin=ob->query("max_pot");
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot"))
  ob->set("potential",ob->query("max_pot"));
  ob->add("deposit",coin);
  add_shili(ob,exp/10,coin/10);
  tell_object(ob,"������������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��,"+MONEY_D->money_str(coin)+"��\n");
  tell_object(ob,"��Ĵ�������ˣ�\n");
  
         ob->add_temp("tiejob/level",1);//�ۼ�����һ�����������
         ob->add("famous",1);
         if(ob->query_temp("tiejob/level")>=10) {                 
          ob->add("office_number",1);
          ob->add("job_office_number/"+TIEJIANG_JOB,1);
          ob->delete_temp("tiejob/level");
          tell_object(ob, HIG"��õ���һ�㹦����\n"NOR);
          tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
        }
  
  do_action(ob,1); 

}

//�����߼���������
void give_reward_tiejiangjob2(object who)
{
   int exp,pot,coin,lev;  
   string skill;
if (who->query("combat_exp") >=200000)
{
  lev=who->query_temp("tiejob/level");
  exp=170+random(30)+lev*10;
  pot=90+random(20)+lev*3;
  coin=who->query("max_pot")+lev*12+who->query("job_office_number/"+TIEJIANG_JOB)*3/2;
  who->add("combat_exp",exp);
  who->add("potential",pot);
  if(who->query("potential")>who->query("max_pot"))
  who->set("potential",who->query("max_pot"));
  who->add("deposit",coin);
  
  who->add_temp("tiejob/level",1);//�ۼ�����һ�����������
if(random(100)>65){
 who->improve_skill("duanzao-jishu",who->query("max_pot"));
 tell_object(who,"\n��Ķ��켼������ˣ�\n\n");
}
  who->add("famous",1);
       if (who->query_temp("tiejob/level")>=10) {
          
          if(who->query("combat_exp")>=200000)
          skill=give_reward(who);
          else skill="none";
          who->add("office_number",1);
          who->add("job_office_number/"+TIEJIANG_JOB,1);
          who->delete_temp("tiejob/level");
          tell_object(who, HIG"��õ���һ�㹦����\n"NOR);
          tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
        if (skill != "none"){
    message("shout",HIY"��"HIW"�����л�"HIY"��"HIY"������(datie gong):" HIR+ who->query("name")+HIM"����������������й����ʽ���"HIY+ to_chinese(skill)+HIM"���ܣ�\n"NOR,users()); 
    }
   }
}
else
{ exp=170+random(30);
  pot=90+random(20);
  coin=who->query("max_pot");
  who->add("combat_exp",exp);
  who->add("potential",pot);
  if(who->query("potential")>who->query("max_pot"))
  who->set("potential",who->query("max_pot"));
  who->add("deposit",coin);

  who->add_temp("tiejob/level",1);
  who->add("famous",1);
       if (who->query_temp("tiejob/level")>=10) {
          who->add("office_number",1);
          who->add("job_office_number/"+TIEJIANG_JOB,1);
          who->delete_temp("tiejob/level");
          tell_object(who, HIG"��õ���һ�㹦����\n"NOR);
          tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);      
       } 
}
  add_shili(who,exp/10,coin/10);
  tell_object(who,"��������������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��,"+MONEY_D->money_str(coin)+"��\n");
  tell_object(who,"��Ĵ�������ˣ�\n");
  do_action(who,1);
}

//ҩʦ������������

void give_reward_yishengjob1(object who)
{
    int exp,pot,coin;
    
  exp=100+random(20);
  pot=60+random(20);
  coin=who->query("max_pot");
  who->add("combat_exp",exp);
  who->add("potential",pot);
  if(who->query("potential")>who->query("max_pot"))
  who->set("potential",who->query("max_pot"));
  who->add("deposit",coin);
   
  add_shili(who,exp/10,coin/10);
  tell_object(who,"��ҩ�˽�������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��,"+MONEY_D->money_str(coin)+"��\n");
  tell_object(who,"��Ĵ�������ˣ�\n");
  
          who->add_temp("yaojob/level",1);//�ۼ�����һ�����������
          who->add("famous",1);
       if(who->query_temp("yaojob/level")>=10) {
          who->add("office_number",1);
          who->add("job_office_number/"+YAOSHI_JOB,1);
          who->delete_temp("yaojob/level");
          tell_object(who,HIG"\n��õ���һ�㹦����\n"NOR);
          tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
          }
  
  do_action(who,1); 

}

//ҩʦ�߼���������
void give_reward_yishengjob2(object who)
{
  int exp,pot,coin,lev;  
  string skill;
  
if (who->query("combat_exp") >=200000)
{
 lev=who->query_temp("yaojob/level");
  exp=170+random(30)+lev*10;
  pot=90+random(20)+lev*3;
  coin=who->query("max_pot")+lev*12+who->query("job_office_number/"+YAOSHI_JOB)*3/2;
  who->add("combat_exp",exp);
  who->add("potential",pot);
  if(who->query("potential")>who->query("max_pot"))
  who->set("potential",who->query("max_pot"));
  who->add("deposit",coin);
  
  who->add_temp("yaojob/level",1);//�ۼ�����һ�����������
 if(random(100)>35){
   who->improve_skill("bencao-shuli",who->query("max_pot"));
  tell_object(who,"\n��ı�����������ˣ�\n\n");
}
  who->add("famous",1);
       if (who->query_temp("yaojob/level")>=10) {
          if(who->query("combat_exp")>=200000)
          skill=give_reward(who);
          else skill="none";
          who->add("office_number",1);
          who->add("job_office_number/"+YAOSHI_JOB,1);
          who->delete_temp("yaojob/level");
          tell_object(who,HIG"\n��õ���һ�㹦����\n"NOR);
          tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
        if (skill != "none"){
    message("shout",HIY"��"HIW"ҩʦ�л�"HIY"��"HIY"ҩʦ(yao shi):" HIR+ who->query("name")+HIM"�����������Ƶ�ҩ�й����ʽ���"HIY+ to_chinese(skill)+HIM"���ܣ�\n"NOR,users()); 
    }
   }
}
else
{ exp=170+random(30);
  pot=90+random(20);
  coin=who->query("max_pot");
  who->add("combat_exp",exp);
  who->add("potential",pot);
  if(who->query("potential")>who->query("max_pot"))
  who->set("potential",who->query("max_pot"));
  who->add("deposit",coin);

  who->add_temp("yaojob/level",1);//�ۼ�����һ�����������
  who->add("famous",1);
       if (who->query_temp("yaojob/level")>=10) {
          who->add("office_number",1);
          who->add("job_office_number/"+YAOSHI_JOB,1);
          who->delete_temp("yaojob/level");
          tell_object(who,HIG"\n��õ���һ�㹦����\n"NOR);
          tell_object(who,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
        
       }  
}
  add_shili(who,exp/10,coin/10);
  tell_object(who,"ҩʦ��������"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ��\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��,"+MONEY_D->money_str(coin)+"��\n");
  tell_object(who,"��Ĵ�������ˣ�\n");
  
  do_action(who,1);

}


void give_reward_mazei(object ob)
{
   
   int exp,pot,silver;
   
   exp=120+random(20);
   pot=50+random(20);
   silver=100+random(100)+ob->query("job_office_number/"+MAZEI_JOB)*3/2;
   
   ob->delete_temp("mazei_job");
   ob->set_temp("busy_time",time());
   
   ob->add("combat_exp",exp);
   ob->add("deposit",silver);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
   ob->set("potential",ob->query("max_pot"));
   
   tell_object(ob,"��õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
   HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�"+MONEY_D->money_str(silver)+"��\n");
   
   add_shili(ob,exp/10,silver/10);
        
   ob->add("famous",1);
   ob->add_temp("mazei_job_times",1);
   ob->delete_temp("dtsl_job",1);
   
   if(ob->query_temp("mazei_job_times")>=10){
     ob->delete_temp("mazei_job_times");
     ob->add("office_number",1);
     ob->add("job_office_number/"+MAZEI_JOB,1);
     tell_object(ob,HIG"\n��õ���һ�㹦����\n"NOR);
     tell_object(ob,HIG"\n��õ���һ�������Ĺ�����\n"NOR);
    }   
    
      do_action(ob,0);
   
   return;
}
   
//��������������ļ��ϣ�

void do_cancel_job(string arg,object ob,object owner)
{
    switch(arg){
  
  case "chujichanyuan_job":
  
  ob->delete_temp("budian_job");
  ob->add("job_office_number/"+CHUJICHANYUAN_JOB,-1);
  break;
    case "wakuang_job":
  
  ob->delete_temp("wakuang_job");
  ob->add("job_office_number/"+WAKUANG_JOB,-1);
  break;
  
  case "sjbzahuo":
  
  ob->delete_temp("sjb_saochu");
  ob->delete_temp("sjb_saochu_times");
  ob->add("job_office_number/"+SJBZAHUO_JOB,-1);
  break;
  
  case "dmchujijob":
  
  ob->delete_temp("popo_job");
  ob->delete_temp("popo_job1");
  ob->delete_temp("popo_job2");
  ob->delete_temp("popo_job3");
  ob->delete_temp("popo_ok");
  ob->add("job_office_number/"+DMCHUJI_JOB,-1);
  break;
  
  case "gaolixunluo":
  
  ob->delete_temp("xunluo_dir");
  ob->delete_temp("gaoli_xunluo");
  ob->add("job_office_number/"+GAOLIXUNLUO_JOB,-1);
  break;
  
  case "chchujijob":
  
  ob->delete_temp("cihang-job");
  ob->delete_temp("cihang-job-ok");
  ob->delete_temp("cihang-job-times");
  ob->add("job_office_number/"+CHCHUJI_JOB,-1);
  break;
  
  case "tjchujijob":
  
  ob->delete_temp("tujue_fangmu");
  ob->add("job_office_number/"+TJCHUJI_JOB,-1);
  break;
  
  case "chanyuan_job":
  
  ob->delete_temp("buzhi_jiangjing");
  ob->delete_temp("chanyuan_job_times");
  ob->add("job_office_number/"+CHANYUAN_JOB,-1);
  break;
  
  case "dmshouzhang":
  
  ob->delete_temp("dm_shouzhang");
  ob->add("job_office_number/"+DMSHOUZHANG_JOB,-1);
  ob->delete_temp("shouzhang_job_times");
  break;
  
  case "gaolijob":
  
  ob->delete_temp("gaoli_kill_job");
  ob->add("job_office_number/"+GAOLI_JOB,-1);
  ob->delete_temp("gaoli_job_times");
  break;
  
  case "tradejob":
  
   ob->delete_temp("order_job");
   ob->delete_temp("need_killer");
   ob->delete_temp("need_killer_flags");
   if(objectp(present("order",ob)))
   destruct(present("order",ob));
   ob->add("job_office_number/"+TRADE_JOB,-1);
   ob->delete_temp("tradejob_job_times");
  break;
  
  case "tujuejy":
  
  ob->delete_temp("tujue_jieying_job");
  ob->delete_temp("come_killer");
  ob->add("job_office_number/"+TUJUEJY_JOB,-1);
  ob->delete_temp("tujuejy_job_times");
  break;
  
  case "fanmaijob":
  
        ob->delete_temp("fanmai_job");
        ob->add("dtsl_job_xiang_jobtimes",-1);
        ob->add("job_office_number/"+FANMAI_JOB,-1);
        ob->delete_temp("fanmai_job_times");
        break;
 
 case "songxin":
 
   ob->delete_temp("zhu_sx");
   ob->delete_temp("need_killer");
   ob->delete_temp("need_killer_flags");
   ob->add("job_office_number/"+YGSONGXIN,-1);
   ob->delete_temp("songxin_job_times");
   break;
 
  case "yunyan":
  
  ob->delete_temp("yunyan_job");
  ob->delete_temp("track");
  ob->delete_temp("need_killer");
  ob->delete_temp("need_killer_flags");
  ob->add("job_office_number/"+YUNYAN_JOB,-1);
  ob->delete_temp("yunyan_job_times");
  break;
  
  case "killerjob":
  
  ob->delete_temp("cisha/ob");
  ob->delete_temp("cisha/name");
  ob->delete_temp("cisha/time_start");
  ob->set_temp("cisha_job/level",0);
  ob->add("job_office_number/"+KILLER_JOB,-1);
  break;
  
  case "tiejiangjob1":
  
  ob->delete_temp("quest/tie");
  ob->delete_temp("tiejob");
  ob->add("job_office_number/"+TIEJIANG_JOB,-1);
  break;
  
  case "tiejiangjob2":
  
  ob->delete_temp("quest");
  ob->delete_temp("tiejobkiller_come");
  ob->delete_temp("tiejob");
  ob->add("job_office_number/"+TIEJIANG_JOB,-1);
  break;
  
  case "yishengjob1":
  
  ob->delete_temp("quest");
  ob->delete_temp("yaojob");
  ob->add("job_office_number/"+YAOSHI_JOB,-1);
  break;
  
  case "yishengjob2":
  
  ob->delete_temp("quest/yaoitem");
  ob->delete_temp("yaojob");
  ob->delete_temp("yaojobkiller_come");
  ob->delete_temp("yaojobkiller");
  ob->add("job_office_number/"+YAOSHI_JOB,-1);
  break;
  
  case "mazeijob":
  
  ob->delete_temp("mazei_job");
  ob->add("job_office_number/"+MAZEI_JOB,-1);
  break;
  
  default:
  tell_object(ob,"����������������⣬��챨����ʦ����\n");
  return;
  }
  
  do_action(ob,1);
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time()+100+random(20));
  tell_object(ob,"������˴�����\n");
  tell_object(ob,HIG"\n������񹦼������ˣ�\n"NOR);
  return;
}

