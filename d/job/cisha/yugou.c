
 
inherit ITEM;

void create()
{
   set_name("�㹳", ({"yu gou","gou"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������õ��㹳��\n");
                set("unit", "��");
                set("value",20);
                //set("no_decay",1);
                set("cisha_job",1);
                
        }
}

