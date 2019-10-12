#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

unsigned int countSetBits(long long int n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
      n &= (n-1) ; 
      count++; 
    } 
    return count; 
} 

long long int  min(long long int a,long long int b){
	long long int xmin=1000000000l;
	long long int min=-1l;
	for(long long int i=a;i>=0;i--){
		if( countSetBits(i)==countSetBits(b)  ){
			if( (a^i)<xmin ){
				xmin=a^i;
				min=i;
			}
		}
	}

	for(long long int k=a+1;k<=b;k++){
			if( countSetBits(k)==countSetBits(b)  ){
				if( (a^k)<xmin ){
					xmin=a^k;
					min=k;
				}
			}
		}
		return min;	
		
	}








long long int* splitt(string s,long long int arr[]){
	long long int i=0l;
	long long int j=0l;
	string k="";
	while(s[j]!='\0'){
		
		
		if(s[j]==' ' ){
			arr[i]=(long long int)atoi(k.c_str());
			k="";
			i++;
			j++;
			continue;
		}
		k+=s[j];
		j++;
	}
	arr[i]=(long long int)atoi(k.c_str());
	

	return arr;
}

int main(){
 	long long int t;
 	 	vector<long long int> result;
 	string s;
 	cin>>t;
    cin >> ws; // stream out any whitespace

 	for( int i=0;i<t;i++){
 		getline(cin,s);
 		long long int arr[2];
		result.push_back(min(splitt(s,arr)[0],splitt(s,arr)[1]));
 		
	 } 	
	 for(int k=0;k<t;k++){
	 	cout<<result[k]<<"\n";
	 }
	return 0;
}
