// The double -> int hack
int doule2int(double d)
{
  int i=0;
  d += 6755399441055744.0;
    return i = *((int *)(&d));
}

int main()
{
	
}