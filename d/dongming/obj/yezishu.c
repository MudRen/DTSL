
 
inherit ITEM;

void create()
{
   set_name("Ҭ����", ({"yezi shu","shu","tree"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��Ҭ���������泤�˺ܶ�Ҭ�ӣ�\n"+
                            "����ҡ������ҡ�����ɣ�\n");
                set("unit", "��");
                set("yezi",200);
               
        }
}

int is_get_of(object ob,object obj)
{
  return notify_fail("\nֻ�����˺�����"+ob->name()+"͵Ҭ�����ˣ���ҿ���������������\n"+
                     ob->name()+"��һ�죬��æ����������װ��û����������ӡ�\n");
}                

void init()
{
  add_action("do_action1","yao");
  
}

int do_action1()
{
    object ob,obj;
    
    ob=this_player();
    
    if(ob->is_busy())
    return notify_fail("����æ���أ�\n");
    ob->start_busy(3);
    
    if(random(query("yezi"))<100)
    return notify_fail("��ҡ�˰��죬����ʲôҲû�У�\n");
    add("yezi",20);
    obj=new(__DIR__"yezi");
    obj->move(environment(ob));
    message_vision("\nֻ���ҵ�һ����һ��Ҭ��������$N��ͷ�ϣ���\n",ob);
    return 1;
}