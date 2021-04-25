//ward.c
//written by Yanyan@dtsl

inherit F_CLEAN_UP;
inherit F_DBASE;

nosave mixed *file;
nosave int total;

void create()
{

   set("channel_id","���м�ؾ���");
   CHANNEL_D->do_channel(this_object(),"sys","���м��ϵͳ������");
   file = get_dir( "/d/clone/room/cityroom"+"/*.c", -1 );
   total = sizeof(file);
   remove_call_out("checkcity");
   call_out("checkcity",30,0);
}

void checkcity(int times)
{

   if(times<240){
       times++;
       call_out("checkcity",30,times);
       return;
   }

   call_out("startcheck",2,0);

   return;
}

void startcheck(int i)
{
    object checkroom;
    string msg;

    if( file[i][1] > 0 ){
        checkroom = load_object("/d/clone/room/cityroom"+"/"+file[i][0]);
        checkroom->checkcity();

        msg = "���м�ؾ������� ";
      msg += checkroom->query("short");
  }
  else{
      msg = "���³��д���";
  }
  CHANNEL_D->do_channel(this_object(),"sys",msg);

  if(i==total-1){

      call_out("checkcity",30,0);
      CHANNEL_D->do_channel(this_object(),"sys","���и�����ϣ���������"+total+"�����С�");
      return;

  }
    i++;
    call_out("startcheck",30,i);
    return;
}
