
inherit F_DBASE;

#include <ansi.h>

mapping place=([
"����":-7,
"��Ҷ":-10,
"̫ԭ":-7,
"����":-8,
"�ɶ�":-8,
"����":-5,
"����":-4,
"����":-2,
"ɽ����":-2,
"����":-2,
"����":-2,
"����":-3,
"�Ϸ�":-3,
"�Ž�":-3,
"����":0,
"����":-1,
"���":-3,
"����":-7,
"����":2,
]);

mapping placey=([
"����":6,
"��Ҷ":6,
"̫ԭ":5,
"����":4,
"�ɶ�":-6,
"����":4,
"����":1,
"����":-1,
"ɽ����":5,
"����":4,
"����":2,
"����":2,
"�Ϸ�":2,
"�Ž�":0,
"����":0,
"����":-1,
"���":4,
"����":6,
"����":7,
]);
//������Ϊ���ա�place ΪX���꣬placeyΪY���ꡣ

mapping *line; //���ε�·�ߡ�
static int tasks=0;//������ε�������

void create()
{
  set("name","�������������");
  set("id","jobctrl.c");
  seteuid(getuid());

}

void start_job()
{
   string *here,from_name,to_name;
   mapping new_line;
   int i,j;
   int x_point,y_point;
   
   for(i=0;i<sizeof(line);i++)
     if(line[i]["counts"]>0) 
      return;
   
   if(time()-query("inter_job")<1800)
   	return;
   
   set("inter_job",time());
   
   line=({ });
      
   here=keys(place);i=sizeof(here)/2;
   
   tasks=0;
   
   while(i--){//ѡ��·�ߡ�
   
   from_name=here[random(sizeof(here))];
   
   here -=({from_name});
   
   to_name=here[random(sizeof(here))];
   
 //  here -=({to_name});
   
   new_line=allocate_mapping(4);
   new_line["from"]=from_name;
   new_line["to"]=to_name;
   j=random(10)+random(10)+1;
   tasks +=j;
   new_line["counts"]=j;
   
   x_point=place[from_name]-place[to_name];
   if(x_point<0) x_point=-x_point;
   
   y_point=placey[from_name]-placey[to_name];
   if(y_point<0) y_point=-y_point;
   
   x_point=x_point*x_point;
   y_point=y_point*y_point;
   
   new_line["dif"]=to_int(sqrt(x_point+y_point));
   if(new_line["dif"]<0)
    new_line["dif"]=-new_line["dif"];
   
   if(sizeof(line)<=0)
    line=({new_line});
   else
    line +=({new_line});
   }//ѡ��·����ϡ�
   return;
}

string get_line()
{
   string msg;
   int i;
   
   msg="\n";
   msg +=HIG"���"+"        "+"�յ�\n\n"NOR;
   if(sizeof(line)<=0)
    return "error\n";
   for(i=0;i<sizeof(line);i++){
   
   msg +=WHT+line[i]["from"]+YEL+"��������"+WHT+line[i]["to"]+NOR"�������γ�������"+HIY+
     chinese_number(line[i]["counts"])+NOR+"��\n";
   }
   msg +="\n";
   return msg;
}

mapping *get_clear_line()
{
   return line;
}

int give_job(string name)
{
   int i,flag;
   
   flag=0;
   for(i=0;i<sizeof(line);i++){
   
    if(line[i]["from"]==name&&line[i]["counts"]>0)
     flag=i+1;
   }
   return flag;
}

void reset_job(int i)
{
    line[i-1]["counts"]--;
    
    return;
}

mapping get_this_line(int i)
{
   return line[i-1];
}
   