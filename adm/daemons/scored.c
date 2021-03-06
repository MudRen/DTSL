//此守护程序用于测试期间使用.

inherit F_SAVE;
inherit F_DBASE;

string query_save_file()
{
  return "/data/scored";
}

mapping *stores=({
([
]),

});

void create()
{
  set("name","测试精灵");
  set("id","scored.c");
  seteuid(getuid());
  restore();
  save();
  restore();
}

int nameExits(string name)
{
  int i;
  
  for(i=0;i<sizeof(stores);i++){
    if(stores[i]["name"]==name){
      return i;
      break;
    }
  }
  
  return -1;
}

int givereward(object me,string name,int score)
{
   int index;
   mapping newname;
   
   index=nameExits(name);
   
   if(index==-1){
     newname=allocate_mapping(3);
     newname["name"]=name;
     newname["score"]=score;
     stores+=({newname});
     save();
     tell_object(me,"你成功地给"+name+"添加了"+score+"分！\n");
     return 1;
   }
   
   stores[index]["score"]+=score;
   tell_object(me,"你成功地给"+name+"增加了"+score+"分！\n");
   save();
     
   return 1;
  
}

int checkall(object me)
{
  int i;
  string msg;
  msg="";
  
  for(i=0;i<sizeof(stores);i++){
   msg+="名字:"+stores[i]["name"]+"   分数:"+stores[i]["score"];
   msg+="\n";
  }
 
  me->start_more(msg);
  return 1;
}

int checkone(object me,string name)
{
  int index;
  
  index=nameExits(name);
  
  if(index==-1)
   return notify_fail("这个ID没有被奖励过。\n");
  
  tell_object(me,"名字:"+stores[index]["name"]+"   分数:"+stores[index]["score"]+"\n");
  
  return 1;
  
}