//by yanyan.
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int pts;string *force;

   if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
     return notify_fail("ָ���ʽ��enforce <ʹ�����������˵�>|none\n");
   force=me->query("force_skill");
   if(sizeof(force)==0)
	   return notify_fail("�������ѧһ���ڹ�!\n");
   if( arg=="none")
     me->delete("jiali");
   else {
     if( pts < 0 || pts > 10)
        return notify_fail("��ֻ���� none ��ʾ����������������0~10��ʾʹ�ü��ɵ�������\n");
     me->set("jiali", pts*me->query_skill("force",1)/10);
   }

   write("�������ս����ʹ��"+pts+"����������.\n");
   return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enforce|jiali <ʹ�����������˵�>|none
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�

enforce none ���ʾ�㲻ʹ�������� 
HELP
        );
        return 1;
}
