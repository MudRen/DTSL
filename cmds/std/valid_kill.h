

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
if(userp(victim) &&time()-killer->query("TIME_PKS_TIME")<killer->query("TIME_PKS")*1800&&killer->query("pker")
       && userp(killer))
       return notify_fail("�����ɱ��̫�࣬��ʱ��Ȼ�����������أ��²�ȥ�֡�\n");

if(userp(victim)&&userp(killer)&&killer->query("pk_target_id")==victim->query("id")&&time()-killer->query("pk_target_id_time")<3600*12)
return notify_fail("����ʱ��������ɱͬһ����ң�\n");
     return 1;
}

