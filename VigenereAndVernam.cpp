#include <iostream>
#include<string>
#include <stdio.h>
using namespace std;

int main()
{
   string plainText,key,CipherText="";
   cin>>key;
   cin>>plainText;
   int x=0,y=0,num=0,start=0;
   int LP=plainText.length();
   int LK=key.length();
   int Diff=LP-LK;
   int aa=0,bb=0;
   bool oneTimePad;
   string Vernam="";
   char v;
   //cout<<Diff<<endl;
   string a,b,letter;
   string letters[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
   if(key.length()<plainText.length())
   {
       oneTimePad=false;
       for(int i=0;i<Diff;i++)
       {
        key=key+key[num];
        if(num<key.length())
            num++;
        else
            num=0;
       }
   }
   else if(key.length()== plainText.length())
   {
    oneTimePad=true;
   }
   //cout<<"key= "<<key<<endl;
   for(int i=0;i<plainText.length();i++)
   {
       for(int j=0;j<26;j++)
       {
           a=plainText[i];
           b=letters[j];
           if(a==b)
            x=j;
        a=key[i];
        b=letters[j];
            if(a==b)
            y=j;
            }
            num=x+y;
        while((num)>25||start==0){
            num=(num)%26;
            start=1;
       }
      CipherText= CipherText+letters[num];

   }

   cout<<"Vigenere: "<<CipherText<<endl;
   printf("Vernam: ");
     for(int i=0;i<plainText.size();i++)
   {
       /*aa=0,bb=0;
       aa=aa+plainText[i];
       cout<<"aa= "<<aa<<endl;
       bb=bb+key[i];
       cout<<"bb= "<<bb<<endl;
       Vernam=aa^bb;
       cout<<"Vernam: "<<Vernam<<endl;*/
       v=(char)(plainText[i]^key[i]);
     //  printf("0x%X    0x%X=   ",plainText[i],key[i]);
     //  printf("0x%X \n",v);
      // Vernam=Vernam+v;
     printf("%02X",v);
   }
   cout<<endl;
  // printf("Vernam: 0x%X",Vernam);
  if(oneTimePad==true)
    cout<<"One-Time Pad: YES"<<endl;
  else if(oneTimePad==false)
    cout<<"One-Time Pad: NO"<<endl;


}
