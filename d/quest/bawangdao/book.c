
inherit ITEM;

void create()
{
   set_name("�Ե�����", ({ "book"}));
   set_weight(600);
   set("unit", "��");
   set("long","����һ�������ؼ�.\n");
   set("value", 0);
set("no_give",1);
set("no_get",1);
   set("skill", ([
     "name":      "badao",    
     "exp_required":   100000, 
                         
     "sen_cost":     150,   
     "difficulty":   5, 
     "max_skill":   300,          
   ]) );
}
