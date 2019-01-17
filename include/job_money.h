/*

Last Update By Yanyan@dt 2003.9.9
*/
#define JOBSYS_D "/adm/daemons/jobsysd.c"
#define JOBNPC_D "/adm/daemons/jobnpcd.c"


//�˺���Ϊ�������Ĵ�����
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

static int sort_keys(string one, string two) 
{
   return strcmp(one, two);  

}


//�����书��source ΪԴ�����target ΪĿ��������书���� source-->target
void copy_all_skill(object source,object target)
{
     mapping skills;mixed *skl;
     int i;
     
     skills=source->query_skills(); //�õ� ���ܵ� mapping ������ʽ��
     if(!skills) return;//���û�м��ܣ��򷵻ء�
     skl=keys(skills);//ʹ�� keys() ������ʹ�÷������Կ� mudosfun.hlp
     
     for(i=0;i<sizeof(skl);i++){
       if(!SKILL_D(skl[i])->query_no_copy())//�жϴ˼����Ƿ���Ա�����                                            
          target->set_skill(skl[i],skills[skl[i]]);
     }
     
     target->reset_action(target->query_temp("weapon"));
     //ȷ��targetʹ�õļ��ܣ����Ҳ���Բ��ӡ�
    //������Ǽ��ϡ�
     return;
}

//��ÿһ�������趨 level ����
void set_all_skill(object ob,int level)
{
  mapping skills;mixed *skl;
  int i;
  skills=ob->query_skills();
  if(!skills) return;
  skl=keys(skills);
  for(i=0;i<sizeof(skl);i++)
  ob->set_skill(skl[i],level);
  return;
}


//���� ����������
//���һ������Ϊ������
//�������ӱ��������ʹ�� copy_hp_item(source,target,arg);
//������� target ��ĳ���� source �ı������� 2 ����
//�����ʹ�� copy_hp_item(source,target,arg,2);
//������� target ��ĳ���� source �ı������� 1.5 ����
//�����ʹ�� copy_hp_item(source,target,arg,3,2);
varargs void copy_hp_item(object source,object target,string arg,int i,int j)
{
	if(!source||!target) return;
	if(!i)  i= 1;
	if(!j||j<=0) j = 1;
 	target->set("eff_"+arg,source->query("max_"+arg)*i/j);
 	target->set("max_"+arg,source->query("max_"+arg)*i/j);
 	target->set(arg,source->query("max_"+arg)*i/j);
}
//��������
//���һ������Ϊ������
//�������ӱ��������ʹ�� copy_force(source,target);
//������� target �� source �ı������� 2 ����
//�����ʹ�� copy_force(source,target,2);
//������� target ��ĳ���� source �ı������� 1.5 ����
//�����ʹ�� copy_hp_item(source,target,arg,3,2);
varargs void copy_force(object source,object target,int i,int j)
{
   if(!source||!target) return;
   if(!i) i=1;
   if(!j||j<=0) j = 1;
   target->set("max_force",source->query("max_force")*i/j);
   target->set("force",source->query("max_force")*i/j);
   
}

//�� ��� me ����ƶ��� *dirs ������һ����
int random_place(object me, string *dirs)
{
        int  i, j, k;
        object  newob;
        mixed *file, exit;
                

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        
        if(!sizeof(file))
         return 1;
                                 
	for(k=0;k<30;k++) { // try 20 times
		
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                  newob->query("sleep_room")||
                  newob->query("no_death")||
                  newob->query("no_select")||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
               
		   message_vision("$N���˹�����\n",me);
		   break;
	       }
	     }
	   }
	}

        return 1;
}

//�õ� *dirs ���������һ���ص㡣
//�� *dirs=({"/d/yangzhou","/d/xiangyang"});
//������õ� ����(/d/yangzhou) �� ����(/d/xiangyang) Ŀ¼�е��κ�һ���ص㡣
string get_random_place(string *dirs)
{
        int  i, j, k;
        object  newob;
        mixed *file, exit;
                

        if( !sizeof(dirs) )  return "error";

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        
        if(!sizeof(file))
         return "error";
                                 
	for(k=0;k<30;k++) { // try 20 times
		
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob)  
               if(newob->query("no_fight") ||
                  newob->query("sleep_room")||
                  newob->query("no_death")||
                  newob->query("no_select")||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;
	    break;
	}
	}

              
        return dirs[i]+"/"+file[j][0];
}

int valid_do_job(object ob,string jobname)
{
	return 1;
}

//�������������̫����ò��á�
void copy_object(object newob,object ob)
{       
  mixed *klist;int i;mapping list;
	mapping skills;mixed *skl;
  
  list=(mapping)ob->query_entire_dbase();
	klist=keys(list);
        for(i=0;i<sizeof(klist);i++)
	newob->set(klist[i],list[klist[i]]);
        skills=ob->query_skills();
        if(!skills) return;
	skl=keys(skills);
	for(i=0;i<sizeof(skl);i++){
	if(skl[i]=="busi-yin") continue;
	newob->set_skill(skl[i],skills[skl[i]]);}
  newob->delete("env");
	newob->reset_action(newob->query_temp("weapon"));
        return;
}