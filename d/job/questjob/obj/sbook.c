
inherit ITEM;

int do_linghui(string arg);

void create()
{
        set_name("����ѧ�ķ���", ({"book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   set("long", "����һ������ѧ�ķ�������������������[linghui]�Լ����κ�һ��ܡ�\n"+
               "����ֻ��ʹ��3�Ρ�\n");
               set("use_times",3);
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

int do_linghui(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ���ʲô���ܣ�\n");
   if(!ob->query_skill(arg,1))
   return notify_fail("��ûѧ��������ܡ�\n");
   if(query("use_times")<=0){
   set("no_give",0);
   set("no_drop",0);
   set("no_get",0);
   return notify_fail("�Ȿ��ѧ�ķ��Ѿ�ûʲô���ˡ�\n");}
   add("use_times",-1);
   ob->improve_skill(arg,ob->query("max_pot")*ob->query_int());
   tell_object(ob,"���"+to_chinese(arg)+"����ˣ�\n");
   return 1;
}