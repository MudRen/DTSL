// vendor.c

#include <dbase.h>

int buy_object(object me, string what)
{
        mapping goods;
        string list, *name;
        int i;

        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++){
        if(what ==  name[i]->name() || what == (name[i]->query("id")))
                  return    (int)  (name[i]->query("value")) ;
				      }
        return 0;

}

void compelete_trade(object me, string what)
{
	string ob_file;
	object ob;
        mapping goods;
        string list, *name, last = "";
        int i;
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++){
        if(what ==  name[i]->name() || what == (name[i]->query("id")))
	{
	        if( stringp(ob_file = name[i]) ) {
                ob = new(ob_file);
// Let's decrement the amount if it goes to zero, delete it from vendor list
                goods[name[i]]--;
                if(goods[name[i]] <= 0){
                map_delete(goods,name[i]);
		last = "���";}
                if(ob->move(me)){
                printf("����%s����%sһ%s%s.\n",this_object()->query("name"),
				last,
                                ob->query("unit"), ob->name());
		}
		else
			destruct(ob);
		return;
						}

	}
                                      }

}

string price_string(int v)
{
	if( v%10000 == 0 )
		return (v/10000) + "���ƽ�";
	if( v%100 == 0 )
		return (v/100) + "������";
	return v + "��Ǯ";
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	if(!sizeof(name))
		return notify_fail("����Ķ���ȫ�����ˡ�\n");
	list = "����Թ���������Щ������\n";
	for(i=0; i<sizeof(name); i++)
		list += sprintf("%-10s %-20s ��%s\n",
			name[i]->name(),name[i]->query("id"),
			price_string(name[i]->query("value")) );
	write(list);
	return 1;	
}
