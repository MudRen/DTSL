
inherit ITEM;

int do_linghui();

void create()
{
        set_name("��ս���ķ���", ({"book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   set("long", "����һ����ս���ķ�������������������[linghui]�Լ��ľ��顣\n");
               set("no_give",1);
               set("no_drop",1);
               set("no_get",1);
        set("material", "paper");}
        setup();
}

void init()
{

  add_action("do_linghui","linghui");
}

int do_linghui()
{
   object ob;
   int exp;
   
   ob=this_player();
   
   exp=300+random(10);
   
   ob->add("combat_exp",exp);
   
   tell_object(ob,"��õ���"+chinese_number(exp)+"�㾭�顣\n");
   destruct(this_object());
   return 1;
}