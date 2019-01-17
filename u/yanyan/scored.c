//���ػ��������ڲ����ڼ�ʹ��.

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
  set("name","���Ծ���");
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
     tell_object(me,"��ɹ��ظ�"+name+"�����"+score+"�֣�\n");
     return 1;
   }
   
   stores[index]["score"]+=score;
   tell_object(me,"��ɹ��ظ�"+name+"������"+score+"�֣�\n");
   save();
     
   return 1;
  
}

int checkall(object me)
{
  int i;
  string msg;
  msg="";
  
  for(i=0;i<sizeof(stores);i++){
   msg+="����:"+stores[i]["name"]+"   ����:"+stores[i]["score"];
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
   return notify_fail("���IDû�б���������\n");
  
  tell_object(me,"����:"+stores[index]["name"]+"   ����:"+stores[index]["score"]+"\n");
  
  return 1;
  
}

int RemoveOne(string id)
{
  int index;
  
  index=nameExits(id);
  
  if(index==-1)
   return 0;
  
  stores-=({stores[index]});
  
  save();
  
  return 1;
  
}
  