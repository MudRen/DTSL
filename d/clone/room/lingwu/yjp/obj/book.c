
inherit ITEM;

void create()
{
   set_name("�������ȷ����š�", ({ "leg book","book" }));
   set_weight(200);
   set("unit", "��");
   set("long","����һ�����ܻ����ȷ�����.\n");
   set("no_drop",1);
   set("no_give",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "leg",    
     "exp_required":   0, 
                         
     "sen_cost":     10,   
     "difficulty":   1, 
     "max_skill":200,          
   ]) );
}
