
inherit ITEM;

void create()
{
   set_name("���̱������š�", ({ "dagger book","book" }));
   set_weight(600);
   set("unit", "��");
   set("long","����һ�����̱ܶ��е���.\n");
   set("value",300);
   set("skill", ([
     "name":      "dagger",    
     "exp_required":1000, 
                         
     "sen_cost":20,   
     "difficulty":3, 
     "max_skill":200,          
   ]) );
}
