// math.c

int random(float maxx)
{ 
	int max;   
  max=to_int(maxx);
    	if (max>1000000)
		return efun::random(max/10000) * 10000;
	if (max>10000) 
		return efun::random(max/100) * 100;
        return efun::random(max);

}
