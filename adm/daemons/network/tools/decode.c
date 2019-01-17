// File: /adm/daemons/network/tools/decode.c
// it decode the 64 based encoding
// Windf@TLBB 15.Jan.98

string decode_base(string buf)
{
        string result = "";
        string str_base, vec, p, c;
        int idx, len, nw, val;
        int num, i, j, d;

        if(!buf || buf == "")
                return "ERROR: no arg!\n";

        vec = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
        str_base = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
        len = strlen(buf) - 1;
        
        for(i = 0; i < len; i += 4)
        {
                p = "";
                val = 0;
                num = 3;
                c = buf[i..i+3];

                if(c[2..2] == "=") num = 1;
                else if(c[3..3] == "=") num = 2;

                for(j = 0; j <= num; j++)
                {
                        d = strsrch(vec, c[j..j]);
                        if(!d) return "ERROR: no d!\n";

                        d <<= (3 - j) * 6;
                        val += d;
                }

                for(j = 2; j >= 0; j--)
                {
                        nw = val & 255;
                        p = str_base[nw-48..nw-48] + p;
                        val >>= 8;
                } 

                if(!result || result == "")
                        result = p;
                else result += p;
        }

        return result;
}
