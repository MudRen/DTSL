
inherit F_CLEAN_UP;

#define NID_PATH "/data/"
#define ID_PATH "/data/"

int change_id(string file, string id, string nid)
{
        string stat;
        
        stat = read_file(file);
	stat = replace_string(stat, "\"id\":\""+id+"\",", "\"id\":\""+nid+"\",");
        if (!write_file(file, stat, 1)) {
                write("�ļ� "+ file +" �洢ʧ�ܡ�\n");
                return 0;
        }
        return 1;
}

int copy_file(string id, string nid, int t)
{
        if (t) {
                if (cp(NID_PATH +"login/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__, 
                        ID_PATH +"login/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__)
                 && cp(NID_PATH +"user/" + id[0..0] +"/"+ id + __SAVE_EXTENSION__, 
                        ID_PATH +"user/" + id[0..0] +"/"+ id + __SAVE_EXTENSION__))
                        return 1;
                else
                        return 0;
        }
        if (cp(NID_PATH +"login/" + id[0..0] +"/"+ id + __SAVE_EXTENSION__, 
                ID_PATH +"login/"+ nid[0..0] +"/"+nid + __SAVE_EXTENSION__)
         && cp(NID_PATH +"user/"  + id[0..0] +"/"+ id + __SAVE_EXTENSION__, 
                ID_PATH +"user/" + nid[0..0] +"/"+nid + __SAVE_EXTENSION__))
                return 1;
        else
                return 0;
}

int del_file(string id)
{
        if (rm(NID_PATH +"login/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__)
         && rm(NID_PATH +"user/" + id[0..0] +"/"+ id + __SAVE_EXTENSION__))
                return 1;
        return 0;
}

int check_legal_id(string id)
{
        int i;
        i = strlen(id);
        if( i < 3 || i > 8 ) {
                write("�Բ�����ID������ 3 �� 8 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--)
                if( id[i] < 'a' || id[i] > 'z' ) {
                        write("�Բ�����IDֻ����СдӢ����ĸ��\n");
                        return 0;
                }
        return 1;
}

int main(object me, string arg)
{
        object ob;
        string id, nid;

        seteuid(ROOT_UID);      
        if (!arg)
                return notify_fail("ָ���ʽ��change <ID> <new ID>.\n");
        if (sscanf(arg, "%s %s", id, nid) != 2) {
		id = arg;
		nid = arg[0..7];
	}
	//if (strlen(id) < 9) return notify_fail("ֻ�г��� 8 ����ĸ�� ID ����Ҫת����\n");
        if (!check_legal_id(nid))
                return notify_fail("ָ���ʽ��change <ID> <new ID>.\n");
        if (file_size(NID_PATH +"login/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__) <0)
                return notify_fail(capitalize(id) +" ��¼���������ڣ��޷�����ID��\n");
        if (file_size(NID_PATH +"user/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__) <0)
                return notify_fail(capitalize(id) +" ���ݵ��������ڣ��޷�����ID��\n");
        ob = new(LOGIN_OB);
        ob->set("id", nid);
        if (ob->restore()) {
                destruct(ob);
                return notify_fail(capitalize(nid) +"�Ѿ����ڣ��������ID����ת����\n");
        }
        destruct(ob);
        ob = new(LOGIN_OB);
        ob->set("id", id);
        if (!ob->restore()) {
                destruct(ob);
                if (copy_file(id, id, 1))
                        return notify_fail(capitalize(id) +" ������ģ��ļ������ɹ���"+
                                capitalize(id) +"����ֱ�ӵ�¼��\n");
		return notify_fail(capitalize(id) +" ������ģ��ļ�����ʧ�ܡ�\n");
        }
        destruct(ob);
// changing login data id
	if (!change_id(NID_PATH +"login/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__, id, nid))
                return notify_fail("��¼�ļ�����IDʧ�ܡ�\n");
// changing user data id
	if (!change_id(NID_PATH +"user/"+ id[0..0] +"/"+ id + __SAVE_EXTENSION__, id, nid))
                return notify_fail("�����ļ�����IDʧ�ܡ�\n");
        if (!copy_file(id, nid, 0))
                return notify_fail("�����ļ�ʧ�ܡ�\n");
        if (!del_file(id))
                return notify_fail("ɾ��ԭʼ�ļ�ʧ�ܡ�\n");
        write("���"+ capitalize(id) +"�Ѿ�����Ϊ"+ capitalize(nid) +"��\n");
// log file
        log_file("CHANGE",sprintf("%s %s(%s) �� %s ����Ϊ %s .\n", ctime(time())[4..19], me->name(1), geteuid(me), id, nid));
        return 1;
}

int help()
{
        write(@HELP

ָ���ʽ��change <ID> <new ID>.

��ָ�������������ID��������ʹ�á�

HELP
        );
        return 1;
}

