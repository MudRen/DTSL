
int do_action(string arg)
{
   object ob,target;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000)
   return notify_fail("����书��ô���ˣ����ǵ����洳�������ɣ�\n");
   
   if(ob->query("combat_exp")<10000)
   return notify_fail("����书̫���ˣ�����ȥ�ҵ����д�ɣ�\n");
   
   if(ob->is_fighting())
    return notify_fail("���ר��ս���ɣ�\n");
   
   if(ob->is_busy())
    return notify_fail("���ר��ս���ɣ�\n");
   
   if(time()-ob->query("busy_time")<5+random(4))
    return notify_fail("�㻹��Ъ�����д�ɣ�\n");
   
   if(!arg)
   return notify_fail("��Ҫ��˭�д輼�ܣ�\n");
   
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   
   if(!target->query("slwg_jiaotou"))
   return notify_fail("��ֻ�ܺ͵��ӻ��ͷ�д����գ�\n");
   
   if(COMBAT_D->status(ob,0)<60||COMBAT_D->status(ob,1)<60)
    return notify_fail("�������״��̫���ˣ�������ȥ��Ϣһ�°ɣ�\n");
   
   message_vision("$N��$nһʩ�������书��΢����������ָ�̣�\n",ob,target);
   
   ob->set("env/wimpy",50);
   ob->start_busy(1);
   target->fight_ob(ob);
   
   return 1;
}