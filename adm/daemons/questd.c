//questd.c
//written by Yanyan@dtsl
//for a random quest. the path is: /d/quest/randomquest/

inherit F_CLEAN_UP;
inherit F_DBASE;

string *qmember=({"/d/quest/randomquest/quest_ctrl.c"});

int flag;

void create()
{
   remove_call_out("loop_quest");
   flag=10;
   call_out("loop_quest",15);
}

void loop_quest()
{
   int i;
   object ob;
   flag++;
  if(flag>=10){
   for(i=0;i<sizeof(qmember);i++)
     if(ob=load_object(qmember[i]))
         ob->start_quest();
   flag=0;
   }
   call_out("loop_quest",180);
   return;
}