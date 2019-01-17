// abandon.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        int level, exp1,lvl = 0;string skill_type,*type_class;int flag,skill_flag;
        flag=0,skill_flag=0;
        if( !arg ||sscanf(arg, "%s %d", arg, lvl)!=2) return notify_fail("ָ���ʽ��abandon|fangqi <��������|ԭ��EXP> [����]|<����EXP>\n");
                
          if(arg=="exp") {
          exp1=me->query("combat_exp");
//         if (!intp(lvl)) return notify_fail("ָ������������顣\n");
          if(lvl<0||lvl>exp1) {
           write("\nexp���ܷ�����С������ߴ����㱾��ԭ�е�exp!\n");
          return 1;
         }
             write(HIY"��ѡ�����exp��"+lvl+"�������\n"
        "��������������Ļ����exp��Ϊ"HIR BLINK+chinese_number(lvl)+NOR HIY"��ȷ���Ļ��������������룺"NOR);
    input_to("check_password", 1, me, 1,lvl);
       return 1;
       }
        level = me->query_skill(arg, 1);
       
        if (!intp(lvl) || lvl < 0) 
                return notify_fail("��������Ϊ������\n");
        if(!me->query_skill(arg,1))
        return notify_fail("��û��ѧ��������ܣ�\n");
 if(arg=="sashoufa") {
     if(me->query_skill(arg,1))
    return notify_fail("������ܲ��ܷ�����\n");
  return 1;
    }
 if(arg=="siguanfa") {
     if(me->query_skill(arg,1))
    return notify_fail("������ܲ��ܷ�����\n");
  return 1;
    }
        if (lvl <= 0 || lvl >= level) {
                write("\nע�⣡�㽫Ҫ����ȫ�� "HIW + to_chinese(arg) + "("+arg+")"NOR" ��ȷ����[Y|N]\n>");
                input_to("delete_all", me, arg);
                                
                                return 1;
                } 
        else if (level < 100)
                return notify_fail("������ܻ�û�е����շ�����ĵز���\n");
        else {
                write("\nע�⣡�㽫Ҫ����" + chinese_number(lvl)+ "�� "HIW+to_chinese(arg)+"("+arg+")"NOR" ��ȷ����[Y|N]\n>");
                input_to("delete_skill", me, arg, level, lvl);
                }
        return 1;
   
}

private void delete_all(string arg, object me, string skill)
{   string skill_type;int flag,skill_flag;
        flag=0;
        
                skill_type=SKILL_D(skill)->query_type();
                if(skill_type!="base"&&skill_type!="knowledge")
                        flag=1;
        if( arg[0]=='y' || arg[0]=='Y' ){
                me->delete_skill(skill);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned ALL  %s  on %s\n",
                          me->name(1),me->query("id"), to_chinese(skill) , ctime(time()) ));
                write("�������"+ to_chinese(skill) +"��\n\n");
                                if(flag)
                                me->reduce_array(skill_type,skill);
                               if(me->query(skill_type)==({}))
                                me->delete(skill_type); 
                                
                }
        else write("���������"+ to_chinese(skill) +"("+skill+")��\n\n");
        
}

private void delete_skill(string arg, object me, string skill, int level, int lvl)
{
        if( arg[0]=='y' || arg[0]=='Y' ){
                me->set_skill(skill, level - lvl);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned  %d levels of %s  on %s\n",
                          me->name(1),me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
                write("�������" + chinese_number(lvl)+ "��"+ to_chinese(skill) +"("+skill+")��\n\n");
                }
        else write("���������"+ to_chinese(skill) +"("+skill+")��\n\n");
        
}

private void check_password(string passwd, object me, int forever,int lvl)
{
    object link_ob;
    string old_pass;

    if (!link_ob = me->query_temp("link_ob"))
    {
    write(HIR "�����γɲ���ȫ����quit�����½��롣\n"NOR);
    return;
    }
    if (!link_ob->query("password"))
    {
    write(HIR "�����γɲ���ȫ����quit�����½��롣\n"NOR);
    return;
    }
    old_pass = link_ob->query("password");
    if (!stringp(old_pass) || crypt(passwd, old_pass) != old_pass)
    {
        write(HIR "���������ע�⣬����exp�����������롣\n"NOR);
        return;
    }

    if (forever)
    {
        tell_object(me, HIR BLINK"\n�������exp������"+chinese_number(lvl)+"!\n\n" NOR);
        me->set("combat_exp",lvl);
    }
}

int help()
{
        write("
ָ���ʽ��abandon|fangqi <��������|ԭ��exp> [����]|<����exp>

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

���߿���ѡ�����ָ���ļ�������Χ������ 1 �����м���֮�����Ŀ�����ڼ�
����ζ��ȫ��������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������

���� abandon exp 100.       �������鵽100��
���� abandon dodge 10.      ���� 10 �������Ṧ��
     abandon dodge.         ���������Ṧ��
     

ע�⣺��ʦ����ָ���������书��һ�к���Ը���
     
\n");
        return 1;
}

