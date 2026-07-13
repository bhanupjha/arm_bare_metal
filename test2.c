//copy rom to ram using attribute
const char s[]__attribute__((at(0x00000010)))= "Welcome Bhanu";
char d[10]__attribute__((at(0x40000010)));
int main()
{
	int i;
	for(i=0; s[i]; i++)
	{
		d[i]=s[i];
	} 
	while(1);
}
