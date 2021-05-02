#include <ansi.h>

mixed *exclude_array(mixed *arr, mixed x)
{
    return arr - ({x});
}

// todo 应该是返回唯一元素
mixed *uniq_array(mixed *arr)
{
    return arr;
}

// generate time
string log_time()
{
    string msg = ctime(time());

    msg = msg[4..6] + "/" + msg[8..9] + "/" + msg[20..23] + " " + msg[11..18];
    return msg;
}

// 进度条
string process_bar(int n)
{
    string sp;
    int start;

    if (n < 0)
        n = 0;
    else if (n > 100)
        n = 100;

    sp = "                                                  " NOR;

    if (n == 100)
    {
        sp[22] = '1';
        sp[23] = '0';
        sp[24] = '0';
        sp[25] = '%';
        start = 22;
    }
    else if (n >= 10)
    {
        sp[23] = (n / 10) + '0';
        sp[24] = (n % 10) + '0';
        sp[25] = '%';
        start = 23;
    }
    else
    {
        sp[24] = n + '0';
        sp[25] = '%';
        start = 24;
    }

    n /= 2;
    if (start > n)
    {
        sp = sp[0..start - 1] + HIY + sp[start..< 0];
        sp = sp[0..n - 1] + BBLU + sp[n..< 0];
    }
    else
    {
        sp = sp[0..n - 1] + BBLU + sp[n..< 0];
        sp = sp[0..start - 1] + HIY + sp[start..< 0];
    }

    sp = NOR + BCYN + sp;
    return sp;
}
