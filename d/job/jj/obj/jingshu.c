
inherit ITEM;

#include <ansi.h>

string *name=({
"������","��Ե��","������","������","���Ͼ�"
});

void create()
{
   set_name(YEL+name[random(sizeof(name))]+NOR, ({ "jing shu","jing","shu"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�����顣\n");
     set("material", "paper");
     set("unit", "��");
     set("no_give",1);
     set("no_get",1);
     set("no_drop",1);
     set("jj_job",1);
   
   }
   setup();
}

string long()
{
   object ob;
   
   ob=this_player();
   
   if(query("no_use"))
   return query("long");
   
   ob->improve_skill("chanzong-fofa",ob->query_int()*5);
   tell_object(ob,"�㿴�˿��𾭣�����"+to_chinese("chanzong-fofa")+"����Ϊ����ˣ�\n");
   set("no_use",1);
   return query("long");
}