int main()
{
	int num, sh, h;
	while(num)
	{
		int rem=num%10;
		if(rem>h)
		{
			sh=h;
			h=rem;
		}
		else if(rem>sh && rem!=sh)
		{
			sh=rem;
		}
		num =num/10;
	}
while(1);
}
