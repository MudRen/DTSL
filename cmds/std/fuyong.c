

inherit F_CLEAN_UP;

#include <ansi.h>
#include <medicine.h>
#include <poison.h>

int main(object me,string arg)
{
    object medicine;int i;
    mapping heal;
    string *types;
    int poison_flag=0;
    
    if(!arg) return  notify_fail("��Ҫ����ʲô?\n");
    
    if(!objectp(medicine=present(arg,me)))
    return notify_fail("������û���ֶ�����\n");
    
    heal=medicine->query("heal_up");
    if(!mapp(heal)) return notify_fail("���ֶ������ܵ�ҩ�����ã�\n");
    if(me->is_busy())
    return notify_fail("��������æ���أ�\n");
    
    heal=medicine->query("heal_up");
    types=keys(heal);
    
    if(medicine->query("medicine_class")=="poison"){
       	 medicine->set("poison",heal);
         POISON_D->apply_poison(me,medicine);
         poison_flag=1;
    }
    else
    for(i=0;i<sizeof(types);i++){
       if(!functionp(medicine_type[types[i]])
        &&!functionp(medicine_add_type[types[i]])){
          continue;
       }
       if(heal[types[i]]<=0) continue;
              
       if(functionp(medicine_type[types[i]]))
       evaluate(medicine_type[types[i]],me,heal[types[i]]);
       else
       evaluate(medicine_add_type[types[i]],me,heal[types[i]]);
    }
    
    if(!poison_flag)
    message_vision(HIY"$N"+HIY+"������"+medicine->query("name")+HIY+"������������ˡ�\n"NOR,me);
    else
    message_vision(HIR"$N"+HIR+"������"+medicine->query("name")+HIR+"��\n"NOR,me);
    
    if(me->is_fighting())
    me->start_busy(1+random(1));
    if(medicine->query_amount()>1)
    medicine->set_amount(medicine->query_amount()-1);
    else
    destruct(medicine);

    return 1;
}

