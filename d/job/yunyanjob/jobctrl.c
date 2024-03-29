
inherit F_DBASE;

#include <ansi.h>

mapping place=([
"定襄":-7,
"碎叶":-10,
"太原":-7,
"长安":-8,
"成都":-8,
"洛阳":-5,
"襄阳":-4,
"巴陵":-2,
"山海关":-2,
"鱼阳":-2,
"荥阳":-2,
"黎阳":-3,
"合肥":-3,
"九江":-3,
"扬州":0,
"杭州":-1,
"许城":-3,
"马邑":-7,
"高丽":2,
]);

mapping placey=([
"定襄":6,
"碎叶":6,
"太原":5,
"长安":4,
"成都":-6,
"洛阳":4,
"襄阳":1,
"巴陵":-1,
"山海关":5,
"鱼阳":4,
"荥阳":2,
"黎阳":2,
"合肥":2,
"九江":0,
"扬州":0,
"杭州":-1,
"许城":4,
"马邑":6,
"高丽":7,
]);
//以扬州为参照。place 为X坐标，placey为Y坐标。

mapping *line; //运盐的路线。
nosave int tasks=0;//标记运盐的数量。

void create()
{
  set("name","运盐任务控制器");
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

   while(i--){//选择路线。

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
   }//选择路线完毕。
   return;
}

string get_line()
{
   string msg;
   int i;

   msg="\n";
   msg +=HIG"起点"+"        "+"终点\n\n"NOR;
   if(sizeof(line)<=0)
    return "error\n";
   for(i=0;i<sizeof(line);i++){

   msg +=WHT+line[i]["from"]+YEL+"━━━━"+WHT+line[i]["to"]+NOR"。现有盐车数量："+HIY+
     chinese_number(line[i]["counts"])+NOR+"辆\n";
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
