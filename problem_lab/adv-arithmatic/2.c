#include<stdio.h>
#include<string.h>
int main(){
	char s1[51],s2[51];
	scanf("%s %s",s1,s2);
	char sum[52];

	int l1 = strlen(s1),l2 = strlen(s2),index = 0,carry=0,value,i,j;
	for(i=l1-1,j=l2-1;i>=0 || j>=0;){

		value = carry;
		if(i>=0){
			value+=(s1[i]-'0');
			i--;
		}
		if(j>=0){
			value+=(s2[j]-'0');
			j--;
		}
		sum[index++]=(char)(value%10 + '0');
		carry = value/10;
	}
	//take care of the cases like 99+1
	if(carry)
		sum[index++]='1';

	for(i=index-1;i>=0;i--)
		printf("%c",sum[i]);
	puts("");
	return 0;
}
