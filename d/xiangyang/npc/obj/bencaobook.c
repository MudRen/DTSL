
inherit ITEM;

void create()
{
   set_name("����������", ({ "bencao book","shu","book" }));
   set_weight(600);
   set("unit", "��");
   set("long","����һ����������������顣\n");
   set("skill", ([
     "name":      "bencao-shuli",    
     "exp_required":400000, 
                         
     "sen_cost":     40,   
     "difficulty":   1, 
     "max_skill":   50,          
   ]) );
}
