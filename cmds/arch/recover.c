#define CUT_EXP 7/10
#define CUT_FORCE 8/10
#define DP 1000
int main(object me, string arg)
{
   object ob;
   mapping skl;
   string *skills;
   int i;
   if(!arg)
   return notify_fail("������all��ĳһ����������id!\n"); 
  ob=find_player(arg);
  if(!objectp(ob))
  return notify_fail("���������ڲ������ߣ�\n");
  ob->set("combat_exp",ob->query("combat_exp")*100/99);
 ob->add("deadtimes",-1);
  skl=ob->query_skills();
  if(mapp(skl)){
  skills=keys(skl);
 for(i=0;i<sizeof(skills);i++){
  ob->set_skill(skills[i],ob->query_skill(skills[i],1)+1);}
}
  ob->save();
  tell_object(me,"�ɹ���"+arg+"�����ݻָ���һ�Σ�\n");
  log_file("recover_player",sprintf("%s recover %s exp and skills  %s\n",me->query("id"),arg,ctime(time())));
   return 1;
}
