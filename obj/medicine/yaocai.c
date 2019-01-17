
inherit ITEM;

#include <medicine.h>

void create()
{
   
   set_name(RED"ҩ��"NOR,({"yaocai"}));
   set_weight(100);   
   set("unit", "��");
   set("no_sell",1);
   set("no_save",1);
   set("long","����һ��û�о���ʶ�𣨣ӣȣɣ£ɣţ���ҩ�ģ��㻹��֪��������;��\n");
   set("dlev",(1+random(3))*50);//�� create ʱȷ�� dlev
   setup();
   
}

void init()
{
        add_action("do_shibie","shibie");
}

int do_shibie()
{
         
         int lev;
         int dlev;
         int dtype;
         int gongxiao;
         string *types,type;
         
         object me = this_player();    
         object drug = this_object();    
         
        if(me->query("vocation")!="ҩʦ")
        return notify_fail("�㲻��ҩʦ������ʶ��ҩƷ!\n");
        if(drug->query("no_shibie")==1)
                return notify_fail("���ҩƷ�Ѿ�ʶ�����!\n");
        
        if(me->query_skill("bencao-shuli",1))
        lev=(int)me->query_skill("bencao-shuli",1);
        else
        lev=(int)me->query_skill("poison",1);
        dlev=query("dlev");
        if(lev<dlev){
          if(me->query_skill("bencao-shuli",1))
          return notify_fail("��ı�������̫���ˣ�������ʶ���ҩƷ!\n");
          else
          return notify_fail("��Ķ���̫���ˣ�������ʶ���ҩƷ!\n");
        }
        
        gongxiao=dlev/50*20+random(10);
        //�������ҩʦ��
        if(me->query_skill("bencao-shuli",1)){
           types=keys(medicine_type);
           dtype=random(M_RAND);//M_RAND����ŵ� medicine.h �У��������ڼ���
           type=get_medicine_type(dtype,types);//�˺����ŵ� medicine.h �С�
           set("medicine_type/type",type);
           set("medicine_type/gongxiao",gongxiao);
        }
        else{//����ǰ�ҩʦ��
        
          types=keys(poison_type);
          dtype=random(P_RAND);//P_RAND����ŵ� medicine.h �У��������ڼ���
          type=get_poison_type(dtype,types);//�˺����ŵ� medicine.h �С� 
          set("poison_type/type",type);
          set("poison_type/gongxiao",gongxiao);
        }
                        
        if(me->query_skill("bencao-shuli",1))
        type=HIG+type+NOR;
        else 
        type=HIR+type+NOR;//��ҩʦҩ��������ɫ����ҩʦ��Ѫ��ɫ��
        
        drug->set("long","����һ��"+type+"���ҩƷ�����Ĺ�Чָ���ǣ�"+gongxiao+"��");
        drug->set("no_shibie",1);
        message_vision("$N��ҩ����ϸ������һ�飬����֪�����������ã�\n",me);
        set_new_name(this_object());//ҩ�ı�ʶ�������Ӧ����ʾ������
                                    //set_new_name �ŵ� medicine.h �С� 
        me->add("vocation_score",1);//�� 10 ̫����
        message_vision("$N��ְҵ���������ˡ�\n",me);

        return 1;
}


