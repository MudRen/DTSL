//ward.c
//written by Yanyan@dtsl

inherit F_CLEAN_UP;
inherit F_DBASE;

nosave mixed *file;
nosave int total;

void create()
{

   set("channel_id","城市监控精灵");
   CHANNEL_D->do_channel(this_object(),"sys","城市监控系统启动！");
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

        msg = "城市监控精力更新 ";
      msg += checkroom->query("short");
  }
  else{
      msg = "更新城市错误！";
  }
  CHANNEL_D->do_channel(this_object(),"sys",msg);

  if(i==total-1){

      call_out("checkcity",30,0);
      CHANNEL_D->do_channel(this_object(),"sys","城市更新完毕！共更新了"+total+"个城市。");
      return;

  }
    i++;
    call_out("startcheck",30,i);
    return;
}
