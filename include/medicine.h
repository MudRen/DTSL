

#include <ansi.h>

#define M_RAND 100
#define P_RAND 100

void add_food(object ob,int i);
void add_water(object ob,int i);
void heal_sen(object ob,int i);
void heal_gin(object ob,int i);
void heal_kee(object ob,int i);
void add_food_water_heal_sen(object ob,int i);
void add_force(object ob,int i);

void reduce_food(object ob,int i);
void reduce_water(object ob,int i);
void damage_sen(object ob,int i);
void damage_gin(object ob,int i);
void damage_kee(object ob,int i);
void busy(object ob,int i);
void damage_sen_kee_busy(object ob,int i);
void reduce_force(object ob,int i);

void add_parry(object ob,int i);
void add_dodge(object ob,int i);
void temp_add_force(object ob,int i);
void temp_add_maxforce(object ob,int i);
void temp_add_str(object ob,int i);
void temp_add_con(object ob,int i);
void temp_add_dex(object ob,int i);
void temp_add_int(object ob,int i);
void add_max_force(object ob,int i);
void add_str(object ob,int i);
void add_con(object ob,int i);
void add_dex(object ob,int i);
void add_int(object ob,int i);
void add_exp(object ob,int i);
void add_pot(object ob,int i);

//��ҩʦ
mapping medicine_type=([
"����ʳ��":(:add_food:),//75%
"������ˮ":(:add_water:),//65%
"�ָ�����":(:heal_sen:),//60%
"�ָ���Ѫ":(:heal_gin:),//50%
"�ָ���Ѫ":(:heal_kee:),//40%
"��Ʒ":(:add_food_water_heal_sen:),//20%
"��������":(:add_force:),//5%

]);// Ч�������ң����ֵļ������ν��͡�
//��Ʒ Ч���� +ˮ +ʳ�� +����

//��ҩʦ
mapping poison_type=([
"����ʳ��":(:reduce_food:),//90%
"������ˮ":(:reduce_water:),//80%
"�𺦾���":(:damage_sen:),//70%
"�𺦾�Ѫ":(:damage_gin:),//60%
"����Ѫ":(:damage_kee:),//40%
"���":(:busy:),//20%
"�綾":(:damage_sen_kee_busy:),//15%
"������":(:reduce_force:),//5%
]);// Ч�������ң����ֵļ������ν��͡�
//�綾Ч���� -���� -��Ѫ ���


string get_medicine_type(int dtype,string *types)
{
  if(dtype>=95)
   return types[sizeof(types)-1];
  if(dtype>=80)
   return types[sizeof(types)-2];
  if(dtype>=60)
   return types[sizeof(types)-3];
  if(dtype>=50)
   return types[sizeof(types)-4];
  if(dtype>=40)
   return types[sizeof(types)-5];
  if(dtype>=35)
   return types[sizeof(types)-6];
  
   return types[sizeof(types)-7];

}

string get_poison_type(int dtype,string *types)
{
  if(dtype>=95)
   return types[sizeof(types)-1];
  if(dtype>=85)
   return types[sizeof(types)-2];
  if(dtype>=80)
   return types[sizeof(types)-3];
  if(dtype>=60)
   return types[sizeof(types)-4];
  if(dtype>=40)
   return types[sizeof(types)-5];
  if(dtype>=30)
   return types[sizeof(types)-6];
  if(dtype>=20)
   return types[sizeof(types)-7];
  
  return types[sizeof(types)-8];

}

mapping medicine_add_type=([

"��ʱ���ӷ���":(:add_parry:),
"��ʱ��������":(:add_dodge:),
"��ʱ��������":(:temp_add_force:),
"��ʱ������������":(:temp_add_maxforce:),
"��ʱ���ӱ���":(:temp_add_str:),
"��ʱ���Ӹ���":(:temp_add_con:),
"��ʱ������":(:temp_add_dex:),
"��ʱ��������":(:temp_add_int:),
"������������":(:add_max_force:),
"���ӱ���":(:add_str:),
"���Ӹ���":(:add_con:),
"��������":(:add_dex:),
"��������":(:add_int:),
"���Ӿ���":(:add_exp:),
"����Ǳ��":(:add_pot:),

]);



void set_medicine_add_type(object ob,mapping type)
{
    int lev;
    
    lev=ob->query_skill("bencao-shuli",1);
    
    if(lev<200)
     return;
    
    if(random(100)>90)
     type+=([ "��ʱ���ӷ���":random(lev/10) ]);
    
    if(random(100)>90)
     type+=([ "��ʱ��������":random(lev/10) ]);
    
    if(random(100)>96)
     type+=([ "��ʱ��������":lev*(1+random(4)) ]);
    
    if(random(100)>96)
     type+=([ "��ʱ������������":lev*(1+random(4)) ]);
    
    if(random(200)==ob->query_kar())
     type+=([ "��ʱ���ӱ���":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "��ʱ���Ӹ���":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "��ʱ������":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "��ʱ��������":random(lev/200) ]);
    
    if(random(500)==ob->query_kar())
     type+=([ "������������":random(lev/100) ]);
    
    if(random(3000)==ob->query_kar())
     type+=([ "���ӱ���":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "���Ӹ���":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "��������":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "��������":random(lev/200) ]);
    
    if(random(3000)==ob->query_kar())
     type+=([ "���Ӿ���":random(lev/10) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "����Ǳ��":random(lev/10) ]);
    
    
	
}

mapping names=([
HIG"����"NOR:"lancao", YEL"ɽ����"NOR:"shanzhuyu",WHT"�� ��"NOR:"baizhu",
WHT"�� ��"NOR:"baizhi",HIW"�� ޱ"NOR:"baiwei",WHT"�׸���"NOR:"baifuzi",
WHT"�� ��"NOR:"bailian",WHT"������"NOR:"baishouwu",WHT"�ٺ�"NOR:"baihe",
YEL"������"NOR:"beidougen",YEL"��ɳ��"NOR:"beishashen",WHT"�� ��"NOR:"cangshu",
HIG"�� ��"NOR:"chaihu",YEL"ʯ����"NOR:"shiChangpu",HIY"�� ɽ"NOR:"changshan",
HIG"����"NOR:"chishao",YEL"�� ܺ"NOR:"chuanxiong",MAG"��ľ��"NOR:"chuanmuxiang",
MAG"����ĸ"NOR:"chuanbeimu",YEL"��ţϥ"NOR:"chuanniuxi",YEL"�����"NOR:"ciwujia",
YEL"�� ��"NOR:"dahuang",HIR"�� ��"NOR:"danshen",MAG"�� ��"NOR:"danggui",
HIG"�� ��"NOR:"dangshen",MAG"�� ��"NOR:"dihuang",MAG"�� ��"NOR:"diyu",
MAG"�� ��"NOR:"duhuo",HIM"�� ��"NOR:"yujin",HIY"���Z"NOR:"bixie",

MAG"������"NOR:"zisuzi",YEL"�� ʵ"NOR:"zhishi",WHT"�� ��"NOR:"zhiqiao",
WHT"Ԥ֪��"NOR:"yuzhizi",HIG"������"NOR:"yuliren",HIB"��ڿ�"NOR:"yingsuqiao",
WHT"޲����"NOR:"yiyiren",HIG"�� ��"NOR:"yizhi",MAG"ܾݴ��"NOR:"yuanxuzi",
BLU"������"NOR:"yamazi",YEL"ѻ����"NOR:"yadanzi",YEL"С����"NOR:"xiahuixiang",
WHT"�� ��"NOR:"xiangyuan",HIG"���ϴ�"NOR:"xiguacui",HIG"��ζ��"NOR:"wuwezi",
HIG"��ͩ��"NOR:"wutongzi",YEL"������"NOR:"wuzhuyu",HIG"�� ÷"NOR:"wumei",
HIG"�� ��"NOR:"zhizi",HIG"��������"NOR:"wangbuliuxing",YEL"��˿��"NOR:"tusizi",
YEL"������"NOR:"tinglizi",YEL"�����"NOR:"tianguazi",MAG"������"NOR:"tianxianzi",
HIM"�� ��"NOR:"taoren",YEL"������"NOR:"suanzaoren",HIG"˿����"NOR:"sigualuo",
YEL"�� ��"NOR:"shidi",YEL"ʹ����"NOR:"shijunzi",HIG"ʯ��Ƥ"NOR:"shiliupi",

WHT"�� Ҷ"NOR:"aiye",HIR"���Ҷ"NOR:"cebaiye",YEL"����ͩ"NOR:"chouwutong",
YEL"����Ҷ"NOR:"daqingye",MAG"�� ��"NOR:"dingxiang",HIY"��кҶ"NOR:"fanxieye",
HIY"ܾ ��"NOR:"yuanhua",RED"�޲���Ҷ"NOR:"luobumaye",YEL"ɣ Ҷ"NOR:"sangye",
HIY"�� ��"NOR:"juhua",YEL"����Ҷ"NOR:"pipaye",YEL"�� ��"NOR:"puhuang",
RED"���컨"NOR:"fanhonghua",HIR"�� ��"NOR:"honghua",HIG"�� ��"NOR:"huaihua",
YEL"�Ⱦ���"NOR:"gujingcao",RED"�ϻ���"NOR:"hehuanhua",MAG"������"NOR:"jinyinhua",
MAG"���ɻ�"NOR:"mimenghua",MAG"���"NOR:"kuandonghua",WHT"������"NOR:"xuanfuhua",
WHT"���Ļ�"NOR:"xinyihua",YEL"���"NOR:"yangjinghua",YEL"������"NOR:"yumixu",
HIY"����"NOR:"naoyanghua",YEL"ľ�Ȼ�"NOR:"mujinghua",MAG"õ�廨"NOR:"meiguihua",
MAG"�Ŀݲ�"NOR:"xiakucao",YEL"�� ��"NOR:"zhangnao",MAG"�ϻ��ض�"NOR:"zihuadiding",

MAG"�� ��"NOR:"zisu",MAG"�� ��"NOR:"zelan",MAG"���Ȳ�"NOR:"yuxingcao",
YEL"����޽"NOR:"yinyanghuo",HIG"�� ��"NOR:"yinchen",MAG"��ĸ��"NOR:"yimucao",
WHT"Ѽ�Ų�"NOR:"yazhicao",YEL"Ѱ�Ƿ�"NOR:"xungufeng",HIG"С ��"NOR:"xiaoji",
WHT"�� ޸"NOR:"xiangru",	

]);

void set_new_name(object obj)
{
  string *newnames,name;
  
  newnames=keys(names);
  name=newnames[random(sizeof(newnames))];
  
  obj->set_name(name,({ names[name] }) );
	
	
}

void add_food(object ob,int i)
{
  ob->add("food",i);
  
}

void add_water(object ob,int i)
{
  ob->add("water",i);
  
}

void heal_sen(object ob,int i)
{
  ob->receive_curing("sen",i);
  
}

void heal_gin(object ob,int i)
{
  ob->receive_curing("gin",i);
  
}

void heal_kee(object ob,int i)
{
  ob->receive_curing("kee",i);
 
}

void add_food_water_heal_sen(object ob,int i)
{
  ob->add("food",i);
  ob->add("water",i);
  ob->receive_curing("sen",i);

}

void add_force(object ob,int i)
{
  ob->add("force",i);
 
}

void reduce_food(object ob,int i)
{
  ob->add("food",-i);
  if(ob->query("food")<0)
  ob->set("food",0);

}

void reduce_water(object ob,int i)
{
  ob->add("water",-i);
  if(ob->query("water")<0)
  ob->set("water",0);

}

void damage_sen(object ob,int i)
{
  ob->receive_damage("sen",i*2);
  ob->receive_wound("sen",i);
  
}

void damage_gin(object ob,int i)
{
  ob->receive_damage("gin",i*2);
  ob->receive_wound("gin",i);
 
}

void damage_kee(object ob,int i)
{
  ob->receive_damage("kee",i*2);
  ob->receive_wound("kee",i);
 
}

void busy(object ob,int i)
{
  ob->start_busy(random(i/100));
  
}

void damage_sen_kee_busy(object ob,int i)
{
   ob->receive_damage("sen",i*2);
   ob->receive_damage("kee",i*2);
   ob->receive_wound("sen",i);
   ob->receive_wound("kee",i);
   ob->start_busy(random(i/100));
}

void reduce_force(object ob,int i)
{
   ob->add("force",-i*3);
  if(ob->query("force")<0)
  ob->set("force",0);
}

void add_parry(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_parry"))
    return;  
   info["number"]=i;
   info["times"]=i*2/5;
   
   ob->add_temp("apply/parry",i);
   ob->set_temp("medicine_add_temp_parry",1);
   
   ob->apply_condition("add_temp_parry",info);
   
}

void add_dodge(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_dodge"))
    return;  
   info["number"]=i;
   info["times"]=i*2/5;
   
   ob->add_temp("apply/dodge",i);
   ob->set_temp("medicine_add_temp_dodge",1);
   
   ob->apply_condition("add_temp_dodge",info);
   
}

void temp_add_str(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_str"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/strength",i);
   ob->set_temp("medicine_add_temp_str",1);
   
   ob->apply_condition("add_temp_str",info);
   
}

void temp_add_dex(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_dex"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/dodgeaction",i);
   ob->set_temp("medicine_add_temp_dex",1);
   
   ob->apply_condition("add_temp_dex",info);
   
}

void temp_add_int(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_int"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/intelligence",i);
   ob->set_temp("medicine_add_temp_int",1);
   
   ob->apply_condition("add_temp_int",info);
   
}

void temp_add_con(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_con"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/constitution",i);
   ob->set_temp("medicine_add_temp_con",1);
   
   ob->apply_condition("add_temp_con",info);
   
}

void temp_add_force(object ob,int i)
{
   int time;
   
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_force"))
    return;  
   info["number"]=i;
   time=i/100;
   if(time<2) time=2;
   if(time>20) time=20;
   info["times"]=time;
   
   ob->add("force",i);
   ob->set_temp("medicine_add_temp_force",i);
   
   ob->apply_condition("add_temp_force",info);
   
}

void temp_add_maxforce(object ob,int i)
{
   int time;
   
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_maxforce"))
    return;  
   info["number"]=i;
   time=i/100;
   if(time<2) time=2;
   if(time>20) time=20;
   info["times"]=time;
   
   ob->add("max_force",i);
   ob->set_temp("medicine_add_temp_maxforce",i);
   
   ob->apply_condition("add_temp_maxforce",info);
   
}

void add_max_force(object ob,int i)
{
  ob->add("max_force",i);
}

void add_str(object ob,int i)
{
   ob->add("str",i);
}
void add_con(object ob,int i)
{
   ob->add("con",i);
}   
void add_dex(object ob,int i)
{
   ob->add("dex",i);
}
void add_int(object ob,int i)
{
   ob->add("int",i);
}
void add_exp(object ob,int i)
{
   ob->add("combat_exp",i);
}
void add_pot(object ob,int i)
{
   ob->add("potential",i);
}