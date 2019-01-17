inherit ITEM;
void create()
{
	set_name("�׼�", ({ "shouji"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "meat");
		}
	if(clonep(this_object())) call_out("decay", 1200, 1);
        setup();
}

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        switch(phase) {
                case 1:
                        say( query("name")+"��ʼ�𽥸����ˣ�����һ�����ŵĶ����\n");
                        delete_temp("apply");
                        set_name("���õ���ͷ", ({ "head" }));
                        set("long", "����һ�Ÿ����˵���ͷ����ɢ����һ�ɸ�ʬ��ζ����\n");
                        delete("victim_user");  
                        delete("kill_by");
                        call_out("decay", 180, phase + 1);
                        break;
                case 2:
                        say( query("name")+"���紵���ˣ����һ�����á�\n" );
                        set_name("����", ({ "skull" }) );
                        set("long", "����һ����������á�\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 3:
                        say( "һ��紵������"+query("name")+"���ɻҴ�ɢ�ˡ�\n");                       
                        destruct(this_object());
                        break;
        }
}
