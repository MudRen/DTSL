
inherit ITEM;

void create()
{
   set_name("[����ȭ��]ȭ��", ({ "quan pu","quan","pu","book" }));
   set_weight(600);
   set("unit", "��");
   set("long","����ר�Ž���[����ȭ��]�ĳ�������ȭ��.\n");
   set("value", 1000);
   set("skill", ([
     "name":      "unarmed",    
     "exp_required":   0, 
                         
     "sen_cost":     20,   
     "difficulty":   0, 
     "max_skill":   50,          
   ]) );
}
